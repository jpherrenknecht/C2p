#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>

int main()
{

// Ecriture dans un fichier, si necessaire ce fichier sera créé
         
    std::ofstream fichier { "sortie.txt", std::ios::app };  //le app est si l'on veut ajouter à la suite
    fichier << 3 << " " << 4;
    int x { 0 };
    fichier << '\n' << x << " + 2 = " << x + 2; // On va à la ligne puis on écrit une équation.
    std::string texte { "Voici une phrase." };// Pas de problème avec le texte non plus.
    fichier << '\n' << texte;
// pour ecrire de l utf8

    std::vector<std::string> const phrases
    {   "\n",
        u8"Voici un mot important.",
        u8"Russe : резиновые перчатки",
        u8"Polonais : gumowe rękawiczki",
        u8"Roumain : mănusi de cauciuc"
    };

    for (auto const & phrase : phrases)
    {     fichier << phrase << std::endl;  }

    fichier << 10 << " " << 20;


// maintenat on va lire le fichier     

 //   std::ifstream fichier { "entrée.txt" };

    

// la je vais ecrire un fichier avec des valeurs sur 2 lignes 
// premiereligne 1 a 70 
// deuxieme ligne 5 a 75
// troisieme ligne 10 a 80 

std::array<double,70>  tws1 {};
std::array<double,70>  tws2 {};
std::array<double,70>  tws3 {};

for ( int i=0; i<70;i++ ){ tws1[i]=i; tws2[i]=5+i ; tws3[i]=10+i;}


std::cout <<tws1[10] <<std::endl;
std::cout <<tws2[10] <<std::endl;
std::cout <<tws3[10] <<std::endl;

// on va sauver tws1 dans un fichier 

std::ofstream file("polaires.txt", std::ios::app );

for (int i=0; i<70; i++)
{file << tws1[i] <<",";}
file<<std::endl;

for (int i=0; i<70; i++)
{file << tws2[i] <<",";}
file<<std::endl;

for (int i=0; i<70; i++)
{file << tws3[i] <<",";}







    return 0;
}