/*
    Name : Moyenne olympique
    Goal : Calculer la moyenne d'une s�rie de nombres diff�rents saisi par l'utilisateur en excluant le minimum et le maximum
    Author : DOUMEYAN Eli Jean
    Date : 07-06-2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

int main()
{
    setlocale(LC_CTYPE, "");

    bool appartient;
    int nb, i, j;
    float moy_olymp, min, max, valeur, somme, nombres[50];

    printf("Bienvenue sur notre programme de calcul de la moyenne olympique d'une s�rie de nombres\n");

    // Demande du nombres de valeurs � saisir � l'utilisateur
    do
    {
        printf("\nEntrez le nombre de valeurs que vous voulez saisir(compris entre 0 et 50) : ");
        scanf("%d", &nb);

        // Message affich� en fonction de la valeur entr�e par l'utilisateur
        if (nb<0)
        {
            printf("\nVous avez entr� un nombre inf�rieur � z�ro (0). Recommencez");
        }
        else
        {
            if (nb>50)
            {
                printf("\nLa valeur entr�e est sup�rieur � cinquante(50). Recommencez");
            }
            else
            {
                if (nb == 0)
                {
                    printf("\nVous avez saisi z�ro(0). Recommencez");
                }
            }
        }
    }
    while (nb<=0 || nb>50);

    // Saisie control�e des valeurs
    for (i=0; i<nb; i++)
    {
        printf("Veuillez entrer la valeur %d : ", i+1);
        scanf("%f", &valeur);
        // V�rification de l'existence de la valeur entr�e s'il s'agit du deuxi�me (ou plus) �l�ment saisi
        if (i>0)
        {
            appartient = false;
            for (j=0; j<i; j++)
            {
                if (nombres[j] == valeur)
                {
                    appartient = true;
                    break;
                }
            }

            // Travail en fonction de l'appartenance de la valeur au tableau ou non
            // Si la valeur n'appartient pas d�j� au tableau, on l'ajoute, dans le cas contraire, on redemande une valeur � l'utilisateur
            if (appartient)
            {
                printf("\nVous avez d�j� saisi la valeur %.2f. Veuillez en saisir une autre\n", valeur);
                i--;
            }
            else
            {
                nombres[i] = valeur;
            }
        }
        else   // Dans le cas o� l'on est � la premi�re saise, on ajoute directement le nombre au tableau
        {
            nombres[i] = valeur;
        }
    }

    // D�termination du maximun et du minimum des valeurs saisies et calcul de la somme des valeurs
    min = nombres[0];
    max = nombres[0];
    somme = 0;
    for (i=0; i<nb; i++)
    {
        if (nombres[i]<min)
        {
            min =  nombres[i];
        }
        if (nombres[i]>max)
        {
            max = nombres[i];
        }
        somme = somme + nombres[i];
    }
    // Retrait du maximun et du minimun de la somme
    somme = somme - min - max;

    // Calcul et affichage de la moyenne olympique
    moy_olymp = somme / (nb-2);
    printf("\nLa moyenne olympique des valeurs saisies est : %.2f", moy_olymp);

    return 0;
}
