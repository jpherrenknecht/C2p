#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>  //necessaire pour ostringstream affichage scientifique 
#include <stdlib.h>     /* strtod */


using json = nlohmann::json;


void tokenize(std::string const &str,  std::string delim,
            std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;
 
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}


int main()
{
std::ifstream f("courses2.json");
json data = json::parse(f);
std::string bateau;
bateau= data["512.5"]["bateau"];

std::cout<<"Type de bateau : " << bateau <<std::endl;

//bateau='"'+bateau+'"';
std::cout<<"\n"<<std::endl;
std::ifstream f2("polars2.json");
json data2 = json::parse(f2);
std::string polaires;
polaires= data2 [bateau]["polar"]["sail"].dump();
//std::cout<<"Polaires : " << polaires<<std::endl;

// on va decouper polaires suivant les voiles 
std::string delim = "},{";
 
    std::vector<std::string> out;
    tokenize(polaires, delim, out);
    //  for (auto &s: out) {
    //     std::cout << s << std::endl;
    // }

std::cout << "\n" << std::endl;
std::cout << out[0] << std::endl;
std::cout << "\n" << std::endl;
std::cout << out[1] << std::endl;


std::vector<std::string> intermediaire;
std::string delim1 = "\":[";
tokenize(out[0], delim1, intermediaire);

intermediaire.erase( intermediaire.begin( ) );                          // on supprime le premier element 
intermediaire[0]=intermediaire[0].substr(0, intermediaire[0].length() - 2);       // on supprime les deux derniers elements  

std::cout << "\n" << std::endl;
std::cout << " jib \n" <<intermediaire[0] << std::endl;
// std::cout << "\n" << std::endl;
// std::cout << jib[1] << std::endl;

// on utilise le separateur 
std::vector<std::string> jib;
std::string delim2 = "],[";
tokenize(intermediaire[0], delim2, jib);
 
std::cout << jib [2] << std::endl; 

int l1 =jib.size();
// on transforme en tableau de valeurs on parcourt toutes les valeurs de jib soit jib [0] jib[1] 

std::vector<std::vector<std::string>>tableau;

std::string delimiteur= "," ;                   // delimiteur 
 for (int i=0;i<l1;i++)
 {
   std::vector<std::string> inter2; 
   tokenize(jib[i], delimiteur, inter2 );
   tableau.push_back(inter2);
 }
// }

std::cout<<" Ligne "<<"2" << " Colonne" <<"5  "<<tableau[2][5]<<std::endl; 



std::cout << "\n\nVoile2 \n" <<out[1] << std::endl;

std::vector<std::string> intermediaire2;
tokenize(out[1], delim1, intermediaire2);
std::cout << " \nvoile2 deuxieme terme \n" <<intermediaire2[1] << std::endl;
//std::cout << " \nvoile2 deuxieme terme  \n" <<intermediaire[1] << std::endl;


// intermediaire.erase( intermediaire.begin( ) );                          // on supprime le premier element 
// intermediaire[0]=intermediaire[0].substr(0, intermediaire[0].length() - 2);       // on supprime les deux derniers elements  

std::cout << "\n" << std::endl;


//std::vector<std::vector<std::string>>tableau;
// const char  delimiteur= "},{" ;                   // delimiteur 

// for (int i=0;i<7;i++)
// {
//     std::vector<std::string> out2; 
//     tokenize(polaires, delimiteur, out2 );
//     tableau.push_back(out2);

// }

// std::cout<<  "Voile 1 : " <<std::endl;



return 0;
//
}