#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

using namespace std;
#include <iostream>


#include <string>

class Arme
{
    public:
 
    Arme();
    Arme(std::string nom, int degats);
    void changer(std::string nom, int degats);
    void afficher() const;
    int  getDegats() const;
    private:
 
    std::string m_nom;
    int         m_degats;
};
 


class Personnage
{
    public:
    
    Personnage();                                           //Prototype Constructeur de base
    Personnage(std::string nomArme, int degatsArme);        // Prototype Constructeur surchargé 
    //Personnage::~Personnage();                              // prototype destructeur    

    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();
    void afficherEtat();

    private:

    int m_vie;
    int m_mana;
    Arme m_arme;                             // on peut considerer que c'est une definition de valeurs pour un type arme 

    //valeurs initiales avant encapsulation
    //std::string m_nomArme; //Pas de using namespace std, il faut donc mettre std:: devant string
    //int m_degatsArme;
};


 



Arme::Arme()                            // constructeur de base par defaut épée rouillée 
{   m_nom ="Epée rouillée";
    m_degats = 20; 
}


Arme::Arme(string nom,int degats) : m_nom(nom),m_degats(degats){}   // constructeur avec une nouvelle arme assortie de ses degats

void Arme::changer(string nom, int degats)                                                  // fonction pour la classe arme
{   m_nom = nom;  m_degats = degats;}
 
void Arme::afficher() const                                                                 // fonction pour la classe arme
{   std::cout << "Arme : " << m_nom << " (Degats : " << m_degats << ")" << std::endl;}

int Arme::getDegats() const {return m_degats;}





// syntaxe de base
/*
Personnage::Personnage()                            // constructeur de base
{
    m_vie = 100;
    m_mana = 100;
    m_arme("épée rouillée",10)                      // on utilise le constructeur   de arme 

   // m_nomArme = "Epee rouillee";
   // m_degatsArme = 10;
}
*/
//autre syntaxe pour le constructeur

Personnage::Personnage() : m_vie(100), m_mana(100), m_arme("Epee rouillee",10)     
{  //Rien à mettre dans le corps du constructeur, tout a déjà été fait !
}




// constructeur surchargé on a rajouté 2 parametres nomarme et degatsarme la notation m_nomarme permet de voir que c'est un attribut de la classe 
Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100),m_arme(nomArme,degatsArme)
{    }

//Personnage::~Personnage() {}     //Destructeur 


void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;
    //On enlève le nombre de dégâts reçus à la vie du personnage

    if (m_vie < 0) //Pour éviter d'avoir une vie négative
    {
        m_vie = 0; //On met la vie à 0 (cela veut dire mort)
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats());
    //On inflige à la cible les dégâts que cause notre arme
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) //Interdiction de dépasser 100 de vie
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
  m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant()
{
    return m_vie > 0;
}


void Personnage::afficherEtat()
{ 

cout<<"vie : "<< m_vie << std::endl;
m_arme.afficher();

 }




#endif 