# ft_printf
📌 Description
Le projet ft_printf consiste à recréer la fonction standard printf de la bibliothèque C (<stdio.h>). L'objectif est d'implémenter une version personnalisée de cette fonction en respectant certaines spécifications, sans utiliser directement printf ni ses fonctions associées. Ce projet permet de développer une compréhension approfondie de la gestion des arguments variadiques et de la manipulation des sorties formatées en C.

🛠️ Fonctionnalités
La fonction ft_printf prend une chaîne de format et affiche les arguments correspondants en fonction des spécificateurs de format pris en charge. Voici les conversions implémentées :

%c : Affiche un caractère.
%s : Affiche une chaîne de caractères.
%p : Affiche un pointeur sous forme hexadécimale.
%d / %i : Affiche un entier signé (décimal).
%u : Affiche un entier non signé (décimal).
%x / %X : Affiche un entier en hexadécimal (minuscule / majuscule).
%% : Affiche le caractère %.

🏗️ Contraintes et limitations
L’utilisation des fonctions standard comme printf, sprintf ou snprintf est interdite.
L’implémentation doit être efficace et respecter les contraintes de gestion mémoire.
La gestion des arguments variadiques (va_list) est requise.

🚀 Compilation et Utilisation
#include "ft_printf.h"

int main(void) {
    ft_printf("Hello, %s!\n", "world");
    return (0);
}
Compilation :
📝 Auteur
Projet réalisé dans le cadre de l’école 42.
