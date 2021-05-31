#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>//library pour gere le temp
#include "head.h"//la library ou tous mes fonction sont stocker
int main()
{
	sizeofscreen();
	/*cette fonction permet de cree les fichier candidat bacc et choix s'il n'existe pas*/
	creat_files(FICCAN,FICBACC,FICCHOIX);
	char ncin[30];
	char reponse,quit;
	Bacc st1[Max];
	decor();
	clrscr();
	acceuill();
	SetConsoleTitle("My Program");
	/*cette fontion permet de donner un nom a la console
	* de facon a ce que meme si quelle qu'un nomme lefichier hors du programme le
	* nom de mon projet restera <TP 1031 DE Dr Tsopze>
	*/
	do
	{
		ClearConsoleToColors(11,0);
		clrscr();
		gotoxy(10,2);printf(" _________________________________________________________");
		gotoxy(10,3);printf("|                                                         |");
		gotoxy(10,4);printf("|                                                         |");
		SetColor(10);
		gotoxy(10,5);printf("|                      MENU PRINCIPAL                     |");
		SetColorAndBackground(11,0);
		gotoxy(10,6);printf("|                                                         |");
		gotoxy(10,7);printf("|             SYSTEM INTELLIGENT DE SELECTION %c           |",14);
		SetColorAndBackground(15,0);
		gotoxy(10,8);printf("|                                                         |");
		gotoxy(10,9);printf("|   1- Ajouter un candidat  %c                             |",16);
		gotoxy(10,10);printf("|                                                         |");
		gotoxy(10,11);printf("|   2- Modifier les information d'un candidat %c           |",18);
		gotoxy(10,12);printf("|                                                         |");
		gotoxy(10,13);printf("|   3- Supprimer le un candidat enregistre %c              |",27);
		gotoxy(10,14);printf("|                                                         |");
		gotoxy(10,15);printf("|   4- Afficher les Resultat    %c                         |",1);
		gotoxy(10,16);printf("|                                                         |");
		gotoxy(10,17);printf("|   5- Voir les admis en informatic                       |");
		gotoxy(10,18);printf("|                                                         |");
		gotoxy(10,19);printf("|   6- Voir les statistic                                 |");
		gotoxy(10,20);printf("|                                                         |");
		gotoxy(10,21);printf("|   7- Supprimer les plus agee(>20)                       |");
		gotoxy(10,22);printf("|                                                         |");
		gotoxy(10,23);printf("|   8- Afficher etudiant par filliers  %c                  |",15);
		gotoxy(10,24);printf("|                                                         |");
		gotoxy(10,25);printf("|   9- Voir les participants                              |");gotoxy(45,25);SetColor(14);printf("H- Help");SetColor(15);
		gotoxy(10,26);printf("|                                                         |");
		gotoxy(10,27);printf("|   0- Quitter le programme                               |");
		gotoxy(10,28);printf("|                                                         |");SetColor(15);
		gotoxy(10,29);printf("|   A- Afficher les candidat   %c                          |",29);
		gotoxy(10,30);printf("|                                                         |");SetColor(8);
		gotoxy(10,31);printf("|   R- Renitialiser les fichiers (Vider le contenu)       |");
		gotoxy(10,32);printf("|                                                         |");
		SetColor(2);
		gotoxy(10,33);printf("|                      copyright %c 2021 Navi coperation   |",184);
		SetColor(11);
		gotoxy(10,34);printf("|_________________________________________________________|");
		SetColor(11);
		draw_box();
		SetColor(10);
		gotoxy(10,35);printf("Entre ");SetColor(14);printf("votre ");SetColor(15);printf("choix :");SetColor(30);printf(" ___");
		gotoxy(31,35);reponse=getch();
		switch(reponse)
		{
			case '1':
				clrscr();
				ajouter();
				break;
			case '2':
				clrscr();
				ClearConsoleToColors(11,0);
				modifier_info();
				break;
			case '3':
				clrscr();
				gotoxy(10,2);printf("Entre Le NCIN que vous voulez supprimer : ");
				gotoxy(10,4);printf(">NCIN :");scanf("%s",ncin);
				supprimer(ncin);
				break;
			case '4':
				clrscr();
				resultat();
				break;
			case '5':
				clrscr();
				admis();
				break;
			case '6':
				clrscr();
				voir_les_statistique();
				break;
			case '7':
				Supprimer();
				break;
			case '8':
				clrscr();
				affiche_filiere();
				break;
			case '9':
				clrscr();
				participant();
				break;
			case '0':
			case 27://27=touche echape en entier
				clrscr();
				gotoxy(25,10);
				SetColor(12);
				printf("Voulez vous vraiment quitter! (y/oui)  :");
				quit=getch();
				if(quit=='y' || quit=='Y')
				{
					SetColor(11);
					gotoxy(30,30);printf("Merci d'utiliser Mon application!");
					sleep(1);
					SetColor(15);
					exit(0);
				}
				break;
			case 'a':
			case 'A':
				clrscr();
				afficher();
				break;
			case 'r':
			case 'R':
				clrscr();
				vider_menu();
				break;
			case 'h':
			case 'H':
				clrscr();
				aide();
		}
	}while(reponse!='0');
	return (EXIT_SUCCESS);
}
