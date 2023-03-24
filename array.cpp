#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <list>
#include <cstdlib>  // necessaire pour rand
//#include <bits/stdc++.h> 
//using namespace std;

// Attention a ne pas faire du hors indice car contrairement a python l'erreur n'est pas signalee et le programme peut faire n importe quoi 
// on ne ppeut pas copier un tableau dans un autre directement, il faut passer par les indices
// un array ne peut pas etre un argument de fonction, il faut passer par le pointeur 

template <size_t r, size_t c>      // ici on ecrit un modèle de fonction avec des parametres size_t definit un parametres a venir ulterieurement int ou autre  
void rempli(float (&arr)[r][c]);   // on est obligé d'utiliser le template dans le prototype


bool IsOdd (int i) { return ((i%2)==1);}
void cube(int *tab ,int num) ;       //exemple de fonction manipulation d'un array en place avec un pointeur 






int main()
{
    // int has=rand();
    // std::cout<<"nombre au hasard : "<< has <<std::endl;
    // on ne peut pas creer un tableau de taille variable par ex :  tab [taille]



    //Declaration sans remplissage
    int sample[10];    //initialisation d un tableau de 10 elements entiers
    sample[5]=23;
    std::cout <<"\nsample[5]"<<sample[5]<<std::endl;
    double t2d [5][5];    //initialisation d un tableau de doubles a 2 dimensions les valeurs ne sont pas precisees
    t2d[5][3]=55;
    std::cout <<"t2d[5][3] : "<<t2d[5][3]<<std::endl;


    //Declaration avec remplissage 
    int tab8[8]={0,1,2,3,4,5,6,7}; 
    std::cout <<"\ntab8[5] : "<<tab8[5]<<std::endl;
    char phrase[20]="ceci est une phrase";
    std::cout <<"\nphrase[2] : "<<phrase[2]<<std::endl;

    //declaration avec remplissage dun tableau 2d
    int sqrs[10][3]={
        1,1,1,
        2,4,8,
        3,9,27,
        4,16,64,
        5,25,125,
        6,36,216,
        7,49,343,
        8,64,512,
        9,81,729,
        10,100,1000
    };

    // autre methode
    int sqrs2[10][3]={
        {1,1,1},
        {2,4,8},
        {3,9,27},
        {4,16,64},
        {5,25,125},
        {6,36,216},
        {7,49,343},
        {8,64,512},
        {9,81,729},
        {10,100,1000}
    };

    std::cout <<"\nsqrs[2][1] :  "<<sqrs[2][1]<< " -- sqrs[2][2] " <<sqrs[2][2]<<    std::endl;
    std::cout <<"\nsqrs2[2][1] : "<<sqrs2[2][1]<<" -- sqrs2[2][2] " <<sqrs[2][2]<<    std::endl;
    std::cout<<'\n'<<std::endl;

    
    // declaration sans dimensions 
    int toto[]={1,2,3,4,5,6,7};
    std::cout <<"toto[2] : "<<toto[2]<<    std::endl;

    // Tableau contenant des valeurs explicitement précisés.eventuellement tableau constant
    std::array<int, 5>  tab5 { 1, 2, 3, 4, 5 };
    std::array<double, 7> const tab7 { 3.14159, 2.1878 ,4.57888,10.325};   // attention les valeurs 4 5 6 ne sont pas definies 


    // parcours des elements d'un array pour impression ou autre
    for (auto const element : tab5)
    {  std::cout << element << " "; }




    
   // on ne peut pas copier par egalite mais on peut le faire de la manière suivante :
    std::cout << std::endl<< "\n Copie de tableau " << std::endl;   
    auto copie { tab5 };
    for (auto const element : copie)
    {   std::cout << element << " " ;  }
   
    std::cout << std::endl;
    std::cout<< "\nRemplissage avec  des valeurs par ex 42 toutes identiques"<<std::endl;
    tab5.fill(42);
    for (auto const valeur : tab5)
    {    std::cout << valeur << " ";   }


    // Connaitre la taille
    std::cout << "\nTaille d'un tableau  " << std::size(tab7) << "." << std::endl;



    std::cout <<"\nAccès au premier element : " << tab7.front() << std::endl;     // lecture du tableau 
    std::cout <<" Accès au  dernier element : "   << tab7.back() << std::endl;
    std::cout <<" Accès au  quatrieme element du tableau : " << tab7[3] << std::endl;
    std::cout << "Est-ce que mon tableau est vide ? " << std::empty(tab7) << "\n Ah, je le savais !" << std::endl;
   



int meilleurScore[5];       //Déclare un tableau de 5 int methode openclassrooms
   for (int i=0;i<5;i++)
    {meilleurScore[i]=i+5;}
   for (auto const element : meilleurScore)
    {  std::cout << element << " "; }

std::cout << std::endl ;
std::cout << std::endl ;

//inversion de liste
std::cout <<"Inversion de liste avec reverse" <<std::endl ;
std::array<double,6>  tableauD{ 1.1, 10.35,2.2, 83.5, 4.653, 5.957 };
for (auto const element : tableauD)    {  std::cout << element << "-"; } std::cout << std::endl ;
std::reverse(std::begin(tableauD), std::end(tableauD));
for (auto const element : tableauD)    {  std::cout << element << "-"; }std::cout << std::endl ;

// tri de liste 
std::cout <<"\nTri de liste decroissant avec greater" <<std::endl ;
std::sort(std::begin(tableauD), std::end(tableauD), std::greater<double> {});
for (auto const element : tableauD)    {  std::cout << element << "-"; }std::cout << std::endl ;

std::cout <<"\nTri de liste croissant avec fonction lambda " <<std::endl ;// tri avec une fonction lambda
std::sort(std::begin(tableauD), std::end(tableauD), [](double a, double b) -> bool   { return a < b;  });
for (auto const element : tableauD)    {  std::cout << element << "-"; }std::cout << std::endl ;

std::cout <<"\nRecherche de tous les elements superieurs a une valeur avec fonction lambda " <<std::endl ;// tri avec une fonction lambda
double ref=4.653;

//auto iterateur { std::begin(tableauD) }; // on declare unt iterateur egal au premier element du tyableau 

// std::vector<int> const nombres { 2, 4, 6, 8, 9, 10, 11, 13, 16 };
auto iterateur { std::begin(tableauD) };

    do
    {
        iterateur = std::find_if(iterateur, std::end(tableauD), [ref](double nombre) -> bool  {  return nombre >ref ; });

        if (iterateur != std::end(tableauD))      // ici iterateur est une adresse d ou la necessité de dereferencer 
        {
            std::cout <<*iterateur<< " " ;
            
            ++iterateur;   // on incremente l adresse 
        }
    } while (iterateur != std::end(tableauD));

std::cout << std::endl ;
std::cout << std::endl ;







std::cout <<"\nRecherche de l indice d'un element " <<std::endl ;// tri avec une fonction lambda
 int arr[] = {1, 3, 5, 7, 9};
    int target = 7;
    auto it = std::find(std::begin(arr), std::end(arr), target);
 
    if (it != std::end(arr)) {
        int index = std::distance(arr, it);
        std::cout << "Element " <<target <<" trouvé a l'index " << index << std::endl;
    } else {
        std::cout << "Element pas trouvé" << std::endl;
    }
 

std::cout <<"\nRecherche de l indice d'un element inferieur  " <<std::endl ;// tri avec une fonction lambda
auto it2 { std::begin(arr) };


int cpt=0;


std::cout<<" pour la Taille d'un array c'est nous qui l' avons inventée donc on doit la connaitre sinon methode détournee" << std::endl;
{std::cout<<"Taille pour un tableau de int "<< sizeof(arr)/4 <<std::endl;}

double arrd[] = {1, 3, 5, 7, 9,9.4};
{std::cout<<"Taille pour un tableau de doubles "<< sizeof(arrd)/8 <<std::endl;}

float arrf[] = {1, 3, 5, 7, 9,9.4};
{std::cout<<"Taille pour un tableau de float "<< sizeof(arrd)/8 <<std::endl;}



//recherche de l indice inferieur
int val=4;
int taille =sizeof(arr)/4; // tableau d'entiers
int i=0 ;

for (auto const element : arr)  {  std::cout << element << " "; }
for ( i< taille ;++i;)          { if (arr [i]>val)break; }

std::cout<<"recherche de la valeur  inferieure a "<< val<< "et de son indice ";
std::cout<<"\nIndice "<<i<<" et valeur inferieure " <<arr [i-1]<<std::endl;


// fonction sur array avec pointeur 

 int tab10[]={0,1,2,3,4,5,6,7,8,9,10,11,12}; 
 int taille1=std::end(tab10)- std::begin(tab10);    //maniere d'obtenir la taille 
for (auto const element : tab10)  {  std::cout << element << " "; }
std::cout<<std::endl;
cube (tab10,taille1);     // tab10 est l'adresse du premier element c'est en fait un pointeur 
for (auto const element : tab10)  {  std::cout << element << " "; }


//std::cout<<"\nTaille: "<< <<std::endl;



std::cout << std::endl ;
std::cout << std::endl ;

for (auto const element : tableauD)    {  std::cout << element << "-"; }std::cout << std::endl ;
std::cout << std::endl ;
std::cout << std::endl ;




// declaration d'un tableau a 2 dimensions et de 2 variables int
int nums[3][4],t,k;
nums[2][3]=23;
std::cout <<"\n nums[2][3] ="<<nums[2][3]<< std::endl;






std::cout <<"\nTableau de float à 2 dimensions " <<std::endl ;
float arr2[10][5]; 
    rempli(arr2);      // on utilise la fonction rempli qui rempli le tableau a 2 dimensions avec des valeur 10*i+j

std::cout<<"arr[2][3] = " <<arr2[2][3]<<std::endl;
std::cout << std::endl ;
std::cout << std::endl ;







std::cout <<"Decomposition d'un nombre entier en partie entière et decimale "<<std::endl ;
double a{10.375};

double b=a-int (a);
std::cout <<"Partie entière "<<int (a) <<std::endl ;
std::cout <<"Partie decimale "<<b <<std::endl ;







std::cout<<"essais jp"<<std::endl;
// std::size_t li =5;
// std::size_t co=6;
// double matrice[li][co];
// double ligne[3];

// std::fill(*ligne.begin(), *ligne.end(), -1);
// std::cout<<ligne[1];

// remplissage automatique tableau 1d
double staticArray[3000];
const double InitValue = 10.5;

    std::cout << "Tableau non initialisé:"<<staticArray[3000-1] << std::endl;
    std::fill(staticArray,staticArray+(std::end(staticArray) - std::begin(staticArray)),InitValue);
    std::cout << "Valeur du Tableau rempli :"<<staticArray[3000-1]<< std::endl;






return 0;
}


template <typename T>
void afficher(std::vector<T> const & v)
{
    for (auto const & e : v)
    {
        std::cout << e << std::endl;
    }
}
void cube(int *tab ,int num)        //exemple de fonction manipulation d'un array en place avec un pointeur 
{  
    while (num)
    {
    *tab=*tab * *tab * *tab;
    num--;
    tab++;
    }
}

template <size_t r, size_t c>      // ici on ecrit un modèle de fonction avec des parametres size_t definit un parametres a venir ulterieurement int ou autre  
void rempli(float (&arr)[r][c])
{    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++) {
            arr[i][j] = 10*i + j+0.01;
        }
    }
}