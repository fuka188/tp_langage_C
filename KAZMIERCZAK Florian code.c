#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int score_total = 0;  // Variable globale pour le score total
char nom_joueur[100]; // Variable pour le nom du joueur

// Fonction pour sauvegarder le score dans un fichier
void sauvegarder_score() {
	FILE *file;
	time_t now;
	struct tm *tm_info;
	char date_heure[100];

	// Obtenir la date et l'heure actuelle
	time(&now);
	tm_info = localtime(&now);
	strftime(date_heure, 100, "%Y-%m-%d %H:%M:%S", tm_info);

	// Ouvrir le fichier pour ajouter le score
	file = fopen("scores.txt", "a");
	if (file != NULL) {
		fprintf(file, "Nom: %s, Date: %s, Score: %d\n", nom_joueur, date_heure, score_total);
		fclose(file);
	} else {
		printf("Erreur lors de l'enregistrement du score.\n");
	}
}

// Fonction pour charger le score depuis un fichier
void charger_score() {
    FILE *file;
    char ligne[200];
    int trouve = 0;
    char nom_lu[200];
    int score_lu;

    // Demander a l'utilisateur son nom
    printf("Entrez votre nom: ");
    scanf("%s", nom_joueur);

    // Ouvrir le fichier pour lire les scores
    file = fopen("scores.txt", "r");
    if (file != NULL) {
        while (fgets(ligne, sizeof(ligne), file)) {
            sscanf(ligne, "Nom: %[^,], Date: %*[^,], Score: %d", nom_lu, &score_lu);
            if(strcmp(nom_lu,nom_joueur)==0){
                score_total= score_lu;
                trouve = 1;
            }
        }
    }
    if (trouve) {
        printf("Bienvenue %s votre score precedent etait: %d\n", nom_joueur, score_total);
    }
    else {
        printf("Bienvenue %s, vous n'avez pas de score precedent.\n", nom_joueur);
    }
}

// Fonction pour ajouter un score au total
void ajouter_score(int points) {
    score_total += points;
    sauvegarder_score();  // Sauvegarder le score dans un fichier dès qu'il est modifié
}



// Fonction pour l'addition
void addition() {
    int a, b, reponseUtilisateur, sommeCorrecte,essais = 0;

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    a = rand() % 101;      // Nombre entre 0 et 100
    b = rand() % 100 + 1;  // Nombre entre 1 et 100
    sommeCorrecte = a + b;

    // Affichage de l'opération
    printf("%d + %d = ?\n", a, b);

    // Demande à l'utilisateur d'entrer le résultat


    // Vérification de la réponse
    while (essais < 3) {
		scanf("%d", &reponseUtilisateur);
		printf("Vous avez entre %d\n", reponseUtilisateur);
		if (reponseUtilisateur == a + b) {
			if (essais == 0) {
				ajouter_score(10);  // 10 points pour le premier essai
			} else if (essais == 1) {
				ajouter_score(5);  // 5 points pour le deuxième essai
			} else {
				ajouter_score(1);  // 1 point pour le troisième essai
			}
			printf("Bravo\n");
			return;
		} else {
			printf("Mauvaise reponse :/\n");
			essais++;
			if (essais < 3) {
				printf("Essayez encore (essai %d sur 3)\n", essais + 1);
			}
		}
	}
	printf("Perdu ! La bonne reponse était %d\n", a + b);
}


void soustraction(){
int a, b, reponseUtilisateur, sommeCorrecte,essais=0;

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    a = rand() % 101;      // Nombre entre 0 et 100
    b = rand() % 100 + 1;  // Nombre entre 1 et 100
    while (a>b){
        a = rand() % 101;      // Nombre entre 0 et 100
    }
    sommeCorrecte = b-a;

    // Affichage de l'opération
    printf("%d - %d = ?\n", b, a);

    // Demande à l'utilisateur d'entrer le résultat
    printf("Entrez le résultat\n");

    while (essais < 3) {
		scanf("%d", &reponseUtilisateur);
		printf("Vous avez entre %d\n", reponseUtilisateur);
		if (reponseUtilisateur == b - a) {
			if (essais == 0) {
				ajouter_score(10);
			} else if (essais == 1) {
				ajouter_score(5);
			} else {
				ajouter_score(1);
			}
			printf("Bravo\n");
			return;
		} else {
			printf("Mauvaise reponse :/\n");
			essais++;
			if (essais < 3) {
				printf("Essayez encore (essai %d sur 3)\n", essais + 1);
			}
		}
	}
	printf("Perdu ! La bonne reponse était %d\n", a - b);
}

    // Affichage de la réponse entrée par l'utilisateur

    // Vérification de la réponse


void multiplication(){
    int a,b,reponse,produit,essais=0;
    srand(time(NULL));
    a = rand() % 10+1;      // Nombre entre 1 et 10
    b = rand() % 10 +1;  // Nombre entre 1 et 10
    produit = a*b;
    // Affichage de l'opération
    printf("%d * %d = ?\n", a, b);

    // Demande à l'utilisateur d'entrer le résultat
    printf("Entrez le résultat\n");
    // Affichage de la réponse entrée par l'utilisateur
    while (essais < 3) {
		scanf("%d", &reponse);
		printf("Vous avez entre %d\n", reponse);
		if (reponse == a * b) {
			if (essais == 0) {
				ajouter_score(10);
			} else if (essais == 1) {
				ajouter_score(5);
			} else {
				ajouter_score(1);
			}
			printf("Bravo\n");
			return;
		} else {
			printf("Mauvaise reponse :/\n");
			essais++;
			if (essais < 3) {
				printf("Essayez encore (essai %d sur 3)\n", essais + 1);
			}
		}
	}
	printf("Perdu ! La bonne reponse était %d\n", a * b);
}

void table_de_multiplication() {
    int numero, reponse, resultat, essais;
 
    printf("Quelle table souhaitez-vous ? (1 à 10)\n");
    scanf("%d", &numero);
 
    if (numero < 1 || numero > 10) {
        printf("Table invalide. Veuillez entrer un nombre entre 1 et 10.\n");
        return;
    }
 
    for (int i = 1; i <= 10; i++) {
        resultat = numero * i;
        essais = 0;
 
        printf("%d * %d = ?\n", numero, i);
 
        while (essais < 3) {
            scanf("%d", &reponse);
            printf("Vous avez entré : %d\n", reponse);
 
            if (reponse == resultat) {
                if (essais == 0) {
                    ajouter_score(10);
                } else if (essais == 1) {
                    ajouter_score(5);
                } else {
                    ajouter_score(1);
                }
                printf("Bravo !\n");
                break;
            } else {
                essais++;
                printf("Mauvaise réponse :/\n");
                if (essais < 3) {
                    printf("Essayez encore (essai %d sur 3)\n", essais + 1);
                } else {
                    printf("La bonne réponse était : %d\n", resultat);
                }
            }
        }
    }
}

void division() {
	int a, b, quotient, reste, essais = 0;
	printf("Division\n");
	a = rand() % 101;
	do {
		b = rand() % 10 + 1;
	} while (a < b);
	printf("%d / %d = ?\n", a, b);
	printf("Entrez le quotient\n");

	while (essais < 3) {
		scanf("%d", &quotient);
		printf("Vous avez entre %d en quotient\n", quotient);
		printf("Entrez le reste\n");
		scanf("%d", &reste);
		printf("Vous avez entre %d en reste\n", reste);
		if (quotient == a / b && reste == a % b) {
			if (essais == 0) {
				ajouter_score(10);
			} else if (essais == 1) {
				ajouter_score(5);
			} else {
				ajouter_score(1);
			}
			printf("Bravo\n");
			return;
		} else {
			printf("Mauvaise reponse\n");
			essais++;
			if (essais < 3) {
				printf("Essayez encore (essai %d sur 3)\n", essais + 1);
			}
		}
	}
	printf("Perdu ! La bonne reponse o?=tait %d quotient et %d reste\n", a / b, a % b);
}

void carre(){
int a,b,reponse,produit,essais=0;
    srand(time(NULL));
    a = rand() % 10+1;      // Nombre entre 1 et 10

    produit = a*a;
    // Affichage de l'opération
    printf("Un nombre au carré c'est un nombre multiplié par lui même , exemple : 6 au carré = 6*6=36 \n");
    printf("Donne le resultat de %d au carré = ?\n", a );

    // Demande à l'utilisateur d'entrer le résultat
    printf("Entrez le résultat\n");
    // Affichage de la réponse entrée par l'utilisateur
    while (essais < 3) {
		scanf("%d", &reponse);
		printf("Vous avez entre %d\n", reponse);
		if (reponse == produit) {
			if (essais == 0) {
				ajouter_score(10);
			} else if (essais == 1) {
				ajouter_score(5);
			} else {
				ajouter_score(1);
			}
			printf("Bravo\n");
			return;
		} else {
			printf("Mauvaise reponse :/\n");
			essais++;
			if (essais < 3) {
				printf("Essayez encore (essai %d sur 3)\n", essais + 1);
			}
		}
	}
	printf("Perdu ! La bonne reponse était %d\n", a * b);
}



int main() {
    int choix;
    charger_score();

    // Demande du choix à l'utilisateur
    do{
        printf("+-----------------------------------+\n");
        printf("|1 : Addition                       |\n");
        printf("|2 : Soustraction                   |\n");
        printf("|3 : Multiplication                 |\n");
        printf("|4 : Tables des multiplications     |\n");
        printf("|5 : Division                       |\n");
        printf("|6 : Carré                          |\n");
        printf("|0 : Sortir du jeu                  |\n");
        printf("+-----------------------------------+\n");
        printf("Quel est votre choix ?\n");
        
        scanf("%d", &choix);

     
        while (choix < 0 || choix > 6) {
            printf(" chiffre incorrect . Veuillez ressayer.\n");
            printf("Quel est votre choix ?\n");
            scanf("%d", &choix);
        }

        // Exécution selon le choix
        
        switch (choix) {
            case 1:
                addition();
                break;
            case 2:
                soustraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                table_de_multiplication();
                break;
            case 5:
                division();
                break;
            case 6:
                carre();
                break;
            default:
                printf("Option non valide.\n");
        }
    }while (choix != 0);
    printf("Merci de votre visite\n");
	printf("Votre score total est : %d\n", score_total);  // Affichage du score total
	return 0;

}
