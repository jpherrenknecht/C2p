#include <fstream>      // permet de lire et ecrire des fichiers
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>  //necessaire pour ostringstream affichage scientifique transforme
#include <stdlib.h>     /* strtod */

// le but de ce fichier est de lire et ecrire un bloc de donnees de double a 1 2 3 dimensions dans un fichier texte puis binaire

using namespace std;
void   tokenize(std::string const &str,  std::string delim,   std::vector<std::string> &out);  //prototype
void   tokenize(std::string const &str,  std::string delim,   std::vector<double> &out);
bool   isSpace(unsigned char c);       // predicat pour retirer les caracteres nuisibles  
void   affichage(std::vector<double> tableau);
void   affichage(std::vector<std::vector<double>> tableau2d);
void   affichage(std::vector<std::vector<std::vector<double>>> tableau3d);
std::vector<double>                           transforme1d  (std::string  &contenu);    // contenu est de la forme [x,x,x]
std::vector<std::vector<double>>              transforme2d  (std::string  &contenu) ;   // contenu est de la forme [[x,x,x],[x,x,x]]
std::vector<std::vector<std::vector<double>>> transforme3d  (std::string  &contenu) ;   // contenu est de la forme,[[[x,x,x],[x,x,x]],[[y,y,y],[y,y,y]]]
std::string   vectochaine( std::vector<double> tab);
std::string   vectochaine( std::vector <std::vector <double>> tab) ;
std::string   vectochaine( std::vector<std::vector<std::vector<double>>>tab) ;

string  litfichier (string nomfichier){

  
std::ifstream istreamfichier { nomfichier };
string ligne;
string contenu;

while (std::getline(istreamfichier, ligne)) { contenu+=ligne;}
return contenu;
}


//********************************************************************************************************************************
//********************************************************************************************************************************
//********************************************************************************************************************************

int main()
{

string const nomfichier1 ("tableau1d.txt");
string const nomfichier2 ("tableau2d.txt");
string const nomfichier3 ("tableau3d.txt");

std::ifstream istreamfichier1 { nomfichier1 };             //stream pour Ouverture d'un fichier en lecture
std::ifstream istreamfichier2 { nomfichier2 };             //stream pour Ouverture d'un fichier en lecture
std::ifstream istreamfichier3 { nomfichier3 };             //stream pour Ouverture d'un fichier en lecture
std::string ligne1 { "" };
string contenu;
//out<<"[10,20,30,40,50]"<<endl;   //1d
//out<<"[[0,1,2.],[10,11,12],[20,21,22],[30,31,32]]\n"<<endl;//2d 
//out<<"[[[111,112,113,114],[121,122,123,124 ]] , [[211,212,213,214],[221,222,223,224]],  [[311,312,313,314],[321,322,323,324]] ]\n"<<endl; //3d




if(istreamfichier1)   // lecture du fichier
{
while (std::getline(istreamfichier1, ligne1)) { contenu+=ligne1;}
//std::cout << "contenu du fichier : " << contenu << std::endl;
      
int dim=0;
while (contenu[dim]== '['){dim++;}    
contenu.erase(std::remove_if(contenu.begin(), contenu.end(), isSpace), contenu.end());  // utilisation du predicat personnalisé pour supprimer les caracteres parasites
                                                  //cout<<" Le tableau est de dimension : "<<dim<<endl;

if (dim==1)
{cout<<"dim = "<< dim <<endl; 
std::vector<double> tableau1d;
tableau1d=transforme1d(contenu);
affichage(tableau1d);
istreamfichier1.close();
}

if (dim==2)
{ cout<<"dim = "<< dim <<endl;
  std::vector<std::vector<double>> tableau2d;
  tableau2d=   transforme2d  (contenu); //contenu est le contenu  sans le premier et le dernier terme soit 
  affichage(tableau2d);
istreamfichier2.close();
} 
    

if (dim==3) {
cout<<"dim = "<< dim <<endl;
std::vector<std::vector<std::vector<double>>> tableau3d;
tableau3d=    transforme3d  (contenu);
affichage(tableau3d);
// le premier indice est le tableau, le deuxieme la ligne le troisieme le terme 
// cout << "\n tableau3d [2][1][1] = " << tableau3d[2][1][1];    // troisieme tableau deuxieme ligne deuxieme terme
istreamfichier3.close();
}  

}
else
{ cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;}


// ecriture d'un tableau dans un fichier 


std::vector <double>  tab  {2.71,4.25,3.28};
std::vector <std::vector <double>> tab2 {{2,3,4,5},{21,22,23},{31,32,33}};
std::vector <std::vector <std::vector <double>>> tab3 {{{21,13,14,15},{121,122,123},{31,132,133}},{{212,213,214,215},{221,222,223},{231,232,233}},{{32,33,34,35},{321,322,323},{331,332,333}}};
//affichage(tab);
//affichage(tab2);
//affichage (tab3);

// dimension d'un vecteur 
string texte;
texte=vectochaine(tab3);        // transformation d'un vecteur en chaine le vecteur peut etre de dimension 1,2,3
//cout <<"texte \n "<< texte<<endl;

// sauvegarde d'une chaine dans un fichier texte

ofstream fluxversfichier(nomfichier1);
if(fluxversfichier){fluxversfichier << vectochaine(tab);
fluxversfichier.close();}
else{cout<<"Erreur ecriture dans fichier";}



ofstream fluxversfichier2(nomfichier2);
if(fluxversfichier2){fluxversfichier2 << vectochaine(tab2);fluxversfichier2.close();}
else{cout<<"Erreur ecriture dans fichier";}



ofstream fluxversfichier3(nomfichier3);
if(fluxversfichier3){fluxversfichier3 << vectochaine(tab3);fluxversfichier2.close();}
else{cout<<"Erreur ecriture dans fichier";}


// Lecture d'un fichier et transformation en tableau

string const nomfichier4 ("tableau3d.txt");
string contenu4;
contenu4=litfichier(nomfichier4);

cout<<"\nContenu du fichier \n"<<contenu4<<"\n"<<endl;;
cout<<"\n"<<endl;



cout<<endl;
return 0;

}







//********************************************************************************************************************************
//********************************************************************************************************************************
//********************************************************************************************************************************
//********************************************************************************************************************************




void tokenize(std::string const &str,  std::string delim,   std::vector<std::string> &out)
{   size_t start;
    size_t end = 0;
     while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

void tokenize(std::string const &str,  std::string delim,   std::vector<double> &out)     // version surchargée la sortie est un tableau de doubles 
{   size_t start;
    size_t end = 0;
     while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(std::stod(str.substr(start, end - start)));
    }
}





bool isSpace(unsigned char c) {return (c == ' ' || c == '\n' || c == '\r' ||  c == '\t' || c == '\v' || c == '\f');}  //predicat pour eliminerles caracteres 



std::vector<double> transforme1d  (std::string  &contenu)
    {
    std::vector<double> tableau1d;
    std::string delim1 = ",";
    contenu=contenu.substr(1, contenu.length() - 2); 
    tokenize(contenu, delim1, tableau1d); 
    return tableau1d;
    }


std::vector<std::vector<double>>       transforme2d  (std::string  &contenu)   // contenu est de la forme[x,x,x],[x,x,x]
    {
    std::vector<std::vector<double>> tableau2d;
    std::vector<std::string>         tableauinter;
    std::vector<double>              tableauinter2;
    std::string delim1 = ",";
    std::string delim2 = "],[";
    contenu=contenu.substr(1, contenu.length() - 2); 
    contenu=contenu.substr(1, contenu.length() - 2); 
    //std::cout<< " valeur de contenu dans la fonction 2d : "<<contenu<<endl;
    tokenize(contenu, delim2, tableauinter);
    for (int t=0; t<tableauinter.size();t++)
    {
    tableauinter2.clear();
    tokenize(tableauinter[t], delim1, tableauinter2); 
    tableau2d.push_back(tableauinter2);
    }
    //int l=tableau2d[0].size();
    return tableau2d;
    }  

std::vector<std::vector<std::vector<double>>> transforme3d  (std::string  &contenu) 
    {
    std::string delim1 = ",";
    std::string delim2 = "],[";  
    std::string delim3 = "]],[["; 
    std::vector<std::string> stcontenu; // destiné a recevoir le contenu du tableau sous forme de vecteur de string
    std::vector<std::vector<double>> tableau2d;
    std::vector<std::vector<std::vector<double>>> tableau3d;
    contenu=contenu.substr(1, contenu.length() - 2); 
    contenu=contenu.substr(2, contenu.length() - 4); 
    tokenize(contenu, delim3, stcontenu);                                   // le premier terme est une string le dernier un vecteur 
    for (int k=0;k<stcontenu.size();k++)
        {
        while(tableau2d.size()!=0){tableau2d.pop_back();}
        stcontenu[k].insert(0,1,'[');
        stcontenu[k].push_back(']');
        tableau2d=   transforme2d  (stcontenu[k]);
        tableau3d.push_back(tableau2d);
        }
    return tableau3d;
    }



void affichage(std::vector<double> tableau)
    {cout<<endl;
    for (int i=0;i<tableau.size()-1;i++)
    cout<<tableau[i]<< "-";
    cout<<tableau[tableau.size()-1];} 

void   affichage(std::vector<std::vector<double>> tableau2d)
    {   for (int i=0;i<tableau2d.size();i++)
        affichage(tableau2d[i]);
        cout<<endl;
    }


void   affichage(std::vector<std::vector<std::vector<double>>> tableau3d)
    {  for (int i=0;i<tableau3d.size();i++)
        affichage(tableau3d[i]);
        cout<<endl;
    }


std::string   vectochaine( std::vector<double> tab)
{ string  texte;
  texte = "[";
  for (int i=0; i<tab.size()-1 ;i++)
    {texte= texte + std::to_string(tab[i])+ ",";}
    texte=texte+std::to_string(tab[tab.size()-1])+"]\n";
 return texte;
}

std::string   vectochaine( std::vector <std::vector <double>> tab2) 
{ string  texte;
  texte= "[\n";
for (int i=0; i<tab2.size()-1 ;i++)
{texte += vectochaine(tab2[i])+',';}
 texte +=vectochaine(tab2[tab2.size()-1] ) +']';
 texte +='\n';
 return texte;
}


std::string   vectochaine( std::vector<std::vector<std::vector<double>>>tab2) 
{ string  texte;
  texte = "[\n";
for (int i=0; i<tab2.size()-1 ;i++)
{texte+= vectochaine(tab2[i])+',';}
texte+=vectochaine(tab2[tab2.size()-1])+']';
return texte;
}    
