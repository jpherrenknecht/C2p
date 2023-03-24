#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <string>
#include <tuple>

std::tuple<double, double> equations_mouvement_temps(double vitesse_initiale, double angle, double t)     // fonction retournant un tuple de double a partir de 3 données
{
    // Accélération sur Terre.
    double const g { 9.80665 };
    double const x { vitesse_initiale * std::cos(angle) * t };
    double const y { (-g * (t * t) / 2.) + (vitesse_initiale * std::sin(angle) * t) };

    return { x, y };
}


int main()
{
    // Vitesse de 8 mètres par seconde.
    double const vitesse_initiale { 8.0 };
    // On tire à un angle de pi / 4, soit 45°.
    double const angle { M_PI / 4 };

    // On simule sur 10 secondes, avec un calcul toutes les 100 millisecondes.
    for (double t { 0.0 }; t < 10; t += 0.1)
    {
        std::tuple coordonnees { equations_mouvement_temps(vitesse_initiale, angle, t) };

        if (std::get<1>(coordonnees) < 0)
        {
            // On ne continue plus la simulation dès que y est au niveau du sol.
            break;
        }

        std::cout << "À l'instant t = " << t << ", on a : " << std::endl;
        std::cout << "x = " << std::get<0>(coordonnees) << std::endl;
        std::cout << "y = " << std::get<1>(coordonnees) << std::endl << std::endl;
    }

    return 0;
}