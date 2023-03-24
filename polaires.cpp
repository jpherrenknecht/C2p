#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>  //necessaire pour ostringstream affichage scientifique 
#include <stdlib.h>     /* strtod */
using json = nlohmann::json;

void   tokenize(std::string const &str,  std::string delim,   std::vector<std::string> &out);  //prototype
double coefffoil( double ttwa,double ttws,double speedRatio,double twaMin,double twaMax,double twaMerge,double twsMin,double twsMax,double twsMerge);
int    indiceinf(std::vector<double> const &vecteur, double val );
double interpolaire (std::vector< std::vector<double>> polaires    ,std::vector< double  > tabtws,std::vector< double > tabtwa,double ttws,double ttwa);






int main()
{
std::ifstream f("courses2.json");
json data = json::parse(f);
std::string bateau;

bateau= data["512.5"]["bateau"];

std::cout<<"Type de bateau : " << bateau <<std::endl;
std::cout<<"\n"<<std::endl;

std::ifstream f2("polars2.json");
json data2 = json::parse(f2);
std::string polaires;
std::vector<std::string> nomvoiles;
std::string tws,twa;
double speedRatio,twaMin,twaMax,twaMerge,twsMin,twsMax,twsMerge,hull;
tws=         data2 [bateau]["polar"]["tws"].dump();
twa=         data2 [bateau]["polar"]["twa"].dump();

polaires   =  data2 [bateau]["polar"]["sail"].dump();
speedRatio =  data2 [bateau]["polar"]["foil"]["speedRatio"];
twaMin     =  data2 [bateau]["polar"]["foil"]["twaMin"];
twaMax     =  data2 [bateau]["polar"]["foil"]["twaMax"];
twaMerge   =  data2 [bateau]["polar"]["foil"]["twaMerge"];
twsMin     =  data2 [bateau]["polar"]["foil"]["twsMin"];
twsMax     =  data2 [bateau]["polar"]["foil"]["twsMax"];
twsMerge   =  data2 [bateau]["polar"]["foil"]["twsMerge"];
hull       =  data2 [bateau]["polar"]["hull"]["speedRatio"];
std::cout<<"\nSpeedRatio   : "<<speedRatio<<std::endl;

std::cout<<"twaMin       : "<< twaMin<<std::endl;
std::cout<<"twaMax       : "<< twaMax<<std::endl;
std::cout<<"twaMerge     : "<<twaMerge <<std::endl;
std::cout<<"twsMin       : "<< twsMin<<std::endl;
std::cout<<"twsMax       : "<< twsMax<<std::endl;
std::cout<<"twsMerge     : "<<twsMerge <<std::endl;
std::cout<<"hull         : "<< hull <<std::endl;
std::cout<<" \n " <<std::endl;






//"foil":{"speedRatio":1.04,"twaMin":80,"twaMax":160,"twaMerge":10,"twsMin":16,"twsMax":35,"twsMerge":5},
//  "hull":{"speedRatio":1.003},
//std::cout<<"Tws      : " << tws <<std::endl;
//std::cout<<"Twa      : " << twa <<std::endl;
//std::cout<<"Polaires : " << polaires<<std::endl;
std::string delim = "},{";
std::string delim1 = "\":[[";
std::string delim2 = "],[";
std::string delim3 = ":";
std::string delim4 = ",";
std::vector<std::string> out,intermediaire,intermediaire1,intermediaire2,inter2,sttws,sttwa;
std::vector<std::vector<std::string>>tableau;
std::vector<std::vector<std::vector< double  >>> complet;
std::vector< double  > tabtws,tabtwa;
int h,l;

//constitution de tableau de tws
tws=tws.substr(1, tws.length() - 2); 
tokenize(tws, delim4, sttws); 
for (auto const valeur : sttws)
{  tabtws.push_back(std::stod(valeur) ); }
std::cout <<"Tws : ";
for (auto const valeur : tabtws)
{ std::cout << valeur << " ";   }
l=tabtws.size();


//constitution du tableau de twa
twa=twa.substr(1, twa.length() - 2); 
tokenize(twa, delim4, sttwa); 
for (auto const valeur : sttwa)
{  tabtwa.push_back(std::stod(valeur) ); }
std::cout <<" \nTwa : ";
for (auto const valeur : tabtwa)
{ std::cout << valeur << " ";   }
h=tabtwa.size();
std::cout <<"\nTaille tabtws : "<<l <<"  Taille tabtwa : "<<h<<std::endl;;

//on separe les voiles 
tokenize(polaires, delim, out);      
std::cout << "\n" << std::endl;




std::cout<<"*******************************************************************************"<<std::endl;

std::vector<std::vector<double>> voileunit(h, std::vector<double>(l, 1.));
for (int k=0;k<7;k++)
{
    
//recuperation du nom
    intermediaire.clear();intermediaire1.clear();intermediaire2.clear();inter2.clear();tableau.clear();
    tokenize(out[k], delim1, intermediaire);                        // delim1 = "\":[[";    
    tokenize(intermediaire[0], delim4, intermediaire1);             // delim4 = ",";
    tokenize(intermediaire1[1], delim3, intermediaire2);            // delim3 = ":";
    nomvoiles.push_back(intermediaire2[1].substr(1, intermediaire2[1].length() - 2)); 
    std::cout<<"\n"<<"ligne 179  Voile : "<<k+1<<" "<<nomvoiles[k]<<"\n*******************************"<<std::endl;
// recuperation des polaires
    intermediaire1.clear();intermediaire2.clear();
    intermediaire[1]=intermediaire[1].substr(0, intermediaire[1].length() - 2);       // on retire les deux derniers crochets ]] 
    tokenize(intermediaire[1], delim2, intermediaire1);              // delim2 = "],[";
    l=intermediaire1.size();
   // std::cout <<"intermediaire1.size()"<<<<std::endl;

    for (int i=0;i<l;i++)
    { inter2.clear();
    tokenize(intermediaire1[i], delim4, inter2 );                    // delim4 = ",";
    tableau.push_back(inter2);
    }
    h=  std::end(tableau)-std::begin(tableau);// dimensions de tableau 
    l=  std::end(tableau[0])-std::begin(tableau[0]);

    // transformation en double
    // ecriture d une ligne de tws
    std::cout<<"\t";
    for (int j=0; j<l ;j++)
    
    {std::cout<<tabtws[j]<<"\t"; }
    std::cout<<std::endl;

    for (int i=0;i <h ;i++)                      // constitution et ecriture du tableau 
        {    std::cout<<tabtwa[i]<<"\t";
            for (int j=0; j<l ;j++)
                {   voileunit[i][j]=std::stod(tableau[i][j]);
                    std::cout<<voileunit[i][j]<< "\t";
                }
            std::cout<<std::endl;
        }

complet.push_back(voileunit);

}


int ivoile,itwa,itws;

// on va calculer le max pour une position 
std::vector< double  > conditions;        // conditions est une valeur de twa et de tws fixe 

double   maximum;        // conditions est une valeur de twa et de tws fixe 
// itwa   = 16;
// itws   = 4;

// for (int k=0 ; k<7 ;k++)
// {conditions.push_back(complet[k][itwa][itws]); }
// maximum= *max_element(conditions.begin(), conditions.end());
// std::cout<<"maximum "<<maximum<<std::endl;
std::cout<<"\n Voiles FP "<<std::endl;

for (int i=0;i <h ;i++)                      // constitution et ecriture du tableau 
        {    std::cout<<tabtwa[i]<<"\t";double cfoil;
            for (int j=0; j<l ;j++)
                {   conditions.clear();
                    for (int k=0 ; k<7 ;k++)
                        {conditions.push_back(complet[k][i][j]); }
                        maximum= *max_element(conditions.begin(), conditions.end());
                        cfoil=coefffoil(  tabtwa[i], tabtws[j],speedRatio,twaMin,twaMax,twaMerge,twsMin,twsMax,twsMerge);
                        voileunit[i][j]=maximum*cfoil*hull;
                    std::cout<<voileunit[i][j]<< "\t"; // twa est egal a tbtwa[i] tws a tabtws[j]


                }
            std::cout<<std::endl;
        }

complet.push_back(voileunit); // la voile fullpack avec foils et hull est complet[7]



double ttws,ttwa,vitesse;
ttws=10.7;
ttwa=60;
vitesse=interpolaire (complet[7],tabtws, tabtwa,ttws, ttwa);
std::cout<<"\nPour une Tws de "<< ttws <<" et une twa de "<< ttwa <<" La vitesse est de : "<< vitesse <<" Noeuds \n"<<std::endl;



return 0;
}


//******************************************Fonctions*****************************************************************************************



void tokenize(std::string const &str,  std::string delim,   std::vector<std::string> &out)
{   size_t start;
    size_t end = 0;
     while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}


double coefffoil( double ttwa,double ttws,double speedRatio,double twaMin,double twaMax,double twaMerge,double twsMin,double twsMax,double twsMerge)
{   double coeff,coeff1,coeff2,coeff3,coeff4;
if ((ttwa>twaMin-twaMerge)&&(ttwa<twaMax+twaMerge)&&(ttws>twsMin-twsMerge)&&(ttws<twsMax+twsMerge))

    {   if (ttwa>(twaMin-twaMerge) && (ttwa<twaMin))       // on est dans la phase croissante de la twa
             { coeff1=(ttwa-twaMin+twaMerge)/twaMerge; }
        else { coeff1=1; }

        if (ttwa>(twaMax) && ttwa<(twaMax+twaMerge))        // on est dans la phase de decroissance
             { coeff2=(twaMerge+twaMax-ttwa)/twaMerge; }
        else { coeff2=1; }

        if (ttws>(twsMin-twsMerge) && (ttws<twsMin))        // on est dans la phase de croissance de tws  
             { coeff3=(ttws-twsMin+twsMerge)/twsMerge; }
        else { coeff3=1; }

        if (ttws>twsMax && ttws<(twsMax+twsMerge))           // on est dans la phase de decroissance pour trop de vent 
             { coeff4=(twsMerge+twsMax-ttws)/twsMerge; }
        else { coeff4=1; }     

        coeff=1+(speedRatio-1)*coeff1*coeff2*coeff3*coeff4;
}
else{ coeff=1; }

return coeff;
}


int indiceinf(std::vector<double> const &vecteur, double val )

{ // Dans cette fonction pour accelerer on ne verifie pas l indice inferieur et superieur
  int indice=0;
  for (auto it = std::begin(vecteur);it< std::end(vecteur); it++ )    
         { if (*it<val)   { indice++;} };
return indice-1;
}

double interpolaire (std::vector< std::vector<double>> polaires    ,std::vector< double  > tabtws,std::vector< double > tabtwa,double ttws,double ttwa)
{
        double deltax,deltay,dtws,dtwa;
        double vx0y0,vx0y1,vx1y0,vx1y1,vxy;
        int itws,itwa;
        itws=indiceinf(tabtws,  ttws );
        itwa=indiceinf(tabtwa,  ttwa );  
        deltax= tabtws[itws+1]-tabtws[itws];
        deltay= tabtwa[itwa+1]-tabtwa[itwa];
        dtws=ttws-tabtws[itws];
        dtwa=ttwa-tabtwa[itwa];
        vx0y0=polaires[itwa][itws];     // x est la tws 
        vx1y0=polaires[itwa][itws+1];
        vx0y1=polaires[itwa+1][itws];
        vx1y1=polaires[itwa+1][itws+1];
        vxy=vx0y0+ (dtws*(vx1y0-vx0y0)/deltax) + (dtwa*(vx0y1-vx0y0)/deltay) + ((dtwa*dtws)/deltax/deltay*(vx1y1+vx0y0-vx1y0-vx0y1));
        return vxy    ;
}