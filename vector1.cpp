#include <string>
#include <vector>
#include <iostream>
#include <algorithm>    // necessaire pour std::min_element, std::max_element
//#include <bits/stdc++.h> 
//definition de vecteurs 
bool IsOdd (int i) {  return ((i%2)==1);}         // fonction de predicat


std::array<double,3> test (std::vector<double> vecteur, double value )         // fonction retournant 3 valeurs dont 2 elements d'un vecteur sous forme de tableau 

{ // on retourne le premier et le deuxieme element du vecteur 
  std::array<double,3>  arr;
  double val1;
  double val2;
  arr[0] = vecteur[0];
  arr[1] = vecteur[1];
  arr[2] = value*2;
  return arr; 
   }


// Si on veut supprimer des elements au milieu d'un grand vecteur, il vaut mieux prendre une liste


int main()
{

// initialisation de vecteurs    

double value {18.8};
std::vector <double> const tabjp  {2.71,4.25,3.28};
std::array<double,3>  resultat;
resultat=test (tabjp, value );

std::cout<< " Fonctions pouvant retourner plusieurs valeurs Dans un tableau : "<< std::endl;
std::cout<<"Resultat1 : "  <<resultat[0]<<" Resultat 2 : "<<resultat[1]<<" Resultat 3 :  "<<resultat[2]<<"\n"<<std::endl;
std::vector <int>  tableau_de_int {1,2,3,8,4,5};
std::vector <double> const tableau_de_double  {2.71,4.25,3.28};
std::vector <std::string> const tableau_de_string  {" une phrase 0"," Une autre phrase ", "Une troisième phrase"};

// Remplissage d'un vecteur taille 3000 avec une valeur redimensionnée

std::vector<int> dynArray;
const int InitValue = 9990;

dynArray.resize(3000);
std::cout << "Uninitialized Array:"<<dynArray.back() << std::endl;
std::fill(dynArray.begin(),dynArray.end(),InitValue);
std::cout << "Array filled with:"<<dynArray.back() << std::endl;


// autre methode 

std::vector<double> vxxx {};      // vecteur non rempli 
vxxx.assign(50, 6.3);            // on assigne la taille 50 et on remplit avec des 6.3                
std::cout << "valeur de : vxxx[45] "<<vxxx[45] << std::endl;
std::cout << "valeur du dernier element de vxxx:"<<vxxx.back() << std::endl;

// ou tout simplement 
std::vector<double> vyyy (10,2);      // 10 elements de valeur 2
std::cout << "valeur du dernier element de vyyy:"<<vyyy.back() << std::endl;
std::cout << "valeur de vyyy[3] :"<<vyyy[3] << std::endl;
std::vector<double> vzzz (15,0);      // 10 elements de valeur 2
// parcours du vecteur de maniere automatique 
std::cout<<"Tableau de int : "<<std::endl;
for (auto const valeur : tableau_de_int)
    { std::cout << valeur << " ";   }
std::cout<<std::endl;

// recuperation d'un élément particulier 
std::cout << "2eme element du tableau de int :  " << tableau_de_int[1]<<std::endl;
std::cout << "Le premier élément du tableau est " << tableau_de_int.front() << "." << std::endl;
std::cout << "Le dernier élément du tableau est " << tableau_de_int.back() << "." << std::endl;
std::cout << "Le dernier élément du tableau est " << tableau_de_int [std::size(tableau_de_int) - 1] << std::endl;

// valeurs minimum et maximum
std::cout<<std::endl;
int max= *std::max_element (tableau_de_int.begin(), tableau_de_int.end());  //<algorithm> necessaire
std::cout<<" Valeur  maximum du tableau : "<< max<<std::endl;
std::cout<<" Valeur  minimum du tableau : "<< *std::min_element (tableau_de_int.begin(), tableau_de_int.end())<<std::endl;
std::cout<<std::endl;

// taille du tableau 
auto const taille { std::size(tableau_de_int) };                                    //declaration automatique d'une variable taille de tableau  
std::cout << "La taille du tableau est " << tableau_de_int.size()<< std::endl;

// affichage du tableau elément par élément
std::cout << "Je vais afficher mon tableau en entier.\n";
    for (auto const element : tableau_de_int)     /* type d'un élément du tableau ou auto */ /*identifiant    :*/ /* tableau à parcourir */
    {  std::cout << element << " ";    }

std::cout<<std::endl;
std::cout << "Mon tableau contient " << taille << " éléments." << std::endl;
std::cout << "Est-ce que tableau_rempli est vide ? Réponse : " << std::empty(tableau_de_int) << std::endl;
std::cout <<" Je rajoute 36 a la fin"<<std::endl;

// push_back et pop_back

tableau_de_int.push_back(36);
for (auto const element : tableau_de_int)     /* type d'un élément du tableau ou auto */ /*identifiant    :*/ /* tableau à parcourir */
    {   std::cout << element << " ";    }
 std::cout << "Taille après l'ajout : " << std::size(tableau_de_int) << std::endl;

std::cout <<" Je retire le dernier élément."<<std::endl;
tableau_de_int.pop_back();
std::cout << "Taille après avoir retiré le dernier élément : " << std::size(tableau_de_int) << std::endl;


std::cout << "Je change la valeur du premier element a 15 la taille du tableau est toujours de  : " << std::size(tableau_de_int) << std::endl;
tableau_de_int[0] = 15;
for (auto const valeur : tableau_de_int)
{   std::cout << valeur << " ";   }


std::cout <<" Je vide le tableau. "<<std::endl;
tableau_de_int.clear();
std::cout << "Taille après avoir vidé le tableau : " << std::size(tableau_de_int) << std::endl;    

std::cout << "Nouveau tableau rempli avec une valeur unique "<< std::endl;



std::vector<int> valeurs {};
std::cout << "Taille actuelle de mon tableau : " << std::size(valeurs) << " éléments.\n";
std::cout << " Remplissage du tableau avec un certain nombre d'elements identiques";
    // On ajoute 5 fois la valeur 42.
valeurs.assign(3, 42);
std::cout << "Taille actuelle de mon tableau : " << std::size(valeurs) << " éléments.\n";

for (auto const valeur : valeurs)
{   std::cout << valeur << " ";    }

    std::cout << '\n';

valeurs.assign(5, 3);
    std::cout << "Nouveau remplissage du tableau avec des 3 : " << std::size(valeurs) << " éléments.\n";

    for (auto const valeur : valeurs)
    {  std::cout << valeur << " " ; }

    std::cout << '\n';




// cherche si un element est negatif dans un vecteur a l aide d'une fonction lambda
    std::cout << "Cherche si au moins un nb est négatif." << std::endl;
    std::vector<int> const nombres { 1, 2, 3, 4, 5, 6, -7 };
    for (auto const valeur : nombres)
    {  std::cout << valeur << " " ; }
    std::cout << '\n';

    if (std::any_of(std::cbegin(nombres), std::cend(nombres), [](int nombre) -> bool { return nombre < 0; })) // la fonction lambda prend un nombre et renvoie 1 si le nombre est négatif
       {  std::cout << "Au moins un nombre est négatif." << std::endl;  }
    else
       {  std::cout << "Tous les nombres sont positifs." << std::endl;  }

// tri par valeur absolues a l'aide d'une fonction lambda
    std::cout << "Tri par valeurs absolues." << std::endl;
    std::vector<int> nombres2 { -8, 5, 97, -789, 0, 87, -88, -8555, 10000, 3 };
    std::sort(std::begin(nombres2), std::end(nombres2), [](int a, int b) -> bool
    {  return std::abs(a) < std::abs(b); });
    for (int nombre : nombres2)                // Affichons pour vérifier.
    {  std::cout << nombre << " " ;  }
    std::cout << '\n';

// somme de tous les elements divisibles par un diviseur a l'aide d'une fonction lambda
    std::vector<int> const nombres3 { 8, 6, 5, 4, 33, 98, 2, 78, 648 };
    int const diviseur { 3 };
    int somme { 0 };
    // Il n'y a aucun problème à mélanger les captures par valeur et par référence.
    std::for_each(std::cbegin(nombres3), std::cend(nombres3), [diviseur, &somme]        (int element             ) -> void  {  if (element % diviseur == 0) {  somme += element;   }   });
    // fonction lambda----------------------------------------[champ valeurs utilisees]  ( parametre de la lambda ) -> type retour  {fonction} 
    

    std::cout << "La somme de tous les éléments divisibles par " << diviseur << " vaut " << somme << "." << std::endl;


//  std::cout << "Recherche  du premier element impair " <<  std::endl;
//  std::vector<int>  myvector { 6,  3, 4, 5, 6, 7 };
//  std::vector<int>::iterator it = std::find_if (myvector.begin(), myvector.end(), IsOdd);

// int valueref { 5 };
// int index0   { 0 };

//  std::vector<int>::it4erator it {};

// it = std::find_if (myvector.begin(), myvector.end(),   [valueref,index0]  (int element             ) -> void  {  if (element <valueref) { std::cout <<"trop fort";  }   });

//  std::cout << "La première valeur impaire est  " << somme << '\n';

std::cout <<"\nRecherche de valeur inferieure dans un vecteur dans un but d interpolation      : "<<std::endl;

std::vector<int> const nombres4 { 2, 4, 6, 8,  12, 15, 17, 19 };
    //auto it4 { std::begin(nombres4) };                    // on declare un itérateur de type automatique positionné sur le premier
    int val=11;
    int valinf,indiceinf,valsup ;
    auto  it4 = std::find_if(std::begin(nombres4), std::end(nombres4), [val](int nombre) -> bool      // nb les valeurs capturees ne peuvent etre modifiees dans la fonction lambda 
        { if (nombre>val)   {return true;} else { return false;}  });
        if (it4!= std::end(nombres4))
        {   valinf= *(it4-1);
            indiceinf=it4 - std::begin(nombres4)-1;
            valsup=*it4;
            ++it4; // On n'oublie pas d'incrémenter, sinon on bouclera indéfiniment.
        }

   
std::cout <<"valinf      : "<< valinf<<std::endl;
std::cout <<"indiceinf   : "<< indiceinf<<std::endl;
std::cout <<"valsup      : "<< valsup<<std::endl;
std::cout <<"\nVecteur 2d    : "<<std::endl;



// transformation d'un vecteur en array avec copy 

std::vector<double> input({ 1, 2.1, 3, 4, 5 });
double arr[input.size()];
std::copy(input.begin(), input.end(), arr);
std::cout <<"\nElements de l array     : "<<std::endl;
  for (auto const element : arr)     /* type d'un élément du tableau ou auto */ /*identifiant    :*/ /* tableau à parcourir */
    {  std::cout << element << " ";    }



std::cout<<std::endl;
return 0;

}

