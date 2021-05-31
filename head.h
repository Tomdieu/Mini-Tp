#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include "special.h"

#ifndef __HEAD__H
#define __HEAD__H

#include "type.h"

/*#ifndef and
#define and &&
#endif*/

#ifndef True
#define True 1
#endif

#ifndef False
#define False 0
#endif

#ifndef Max
#define Max 1000
#endif

#ifndef Max_chain_character
#define  Max_chain_character 50
#endif

#ifndef s1
#define s1 14.00
#endif

#ifndef s2
#define s2 10.00
#endif

#ifndef s3
#define s3 13.00
#endif

typedef int Bool;

#define FICCAN "candidat.txt"
#define FICBACC "bacc.txt"
#define FICCHOIX "choix.txt"
#define FICRESU "resultat.txt"
#define FICADMIS "admis.txt"
#define FICMATH  "FILIERE MATHEMATIQUE.txt"
#define FICPHY "FILIERE PHYSIQUE.txt"
#define FICBIOS "FILIERE BIO SCIENCE.txt"
#define FICGEOS "FILIERE GEO SCIENCE.txt"
#define FICCHM "FILIERE CHIMIE.txt"
#define FICICT "FILIERE ICT.txt"
#define FICINFO "FILIERE INFORMATIQUE.txt"


/*ce que je definit ici ce sont mes touche*/
#define LEFT 75 //left=75 represent la direction gauche en entier
#define RIGHT  77 //right=77 represent la direction droit en entier
#define ESCAPE 27 //qui represent la touche echape en entier

typedef struct Candidat
{
    char NCIN[Max_chain_character];
    char NOM[Max_chain_character],PRENOM[Max_chain_character];
    int AGE;
}Candidat;

typedef struct Bacc
{
    char NCIN[Max_chain_character],SERIEBACC[10];
    float MOYENNE,NOTEMATH,NOTEPHY;
}Bacc;

typedef struct Choix
{
    char NCIN[Max_chain_character],CHOIX2[Max_chain_character],CHOIX3[Max_chain_character];
}Choix;

typedef struct decision
{
	char decision[Max];
}CandDec;
typedef struct AIDE_MOI
{
	char nom[Max_chain_character],prenom[Max_chain_character];
}AIDE_MOI;//comme le nom de la structure le dit il est la pour m'aider

typedef struct RESU //cette structure va m'aider a recupere les resultat
{
	char NCIN[Max_chain_character];
	char NOM[Max_chain_character];
	char PRENOM[Max_chain_character];
	int AGE;
	float MOYENNE;
	float MOYENNE_NOTEMATH_NOTEPHY;
	char decision[Max_chain_character];
}RESU;

Candidat ajouter_candidat(char ncin[],char nom[],char prenom[],int age)
{
    FILE *fp;
    fp=fopen(FICCAN,"a");
    if(fp==NULL)
    {
        printf("impossible d'ouvrir le fichier %s !\n",FICCAN);
        
    }
    else
    {
    	strupr(nom);
	    strupr(prenom);
	    fprintf(fp,"%s ; %s ; %s ; %d \n",ncin,nom,prenom,age);
	    fclose(fp);
    }
}

Bacc ajouter_bacc(char ncin[],float moyenne,char serie[],float notemath,float notephy)
{
	FILE *fp;
	fp=fopen(FICBACC,"a");
	if(fp==NULL)
	{
		printf("impossible d'ouvrir le fichier %s !\n",FICBACC);
		
	}
	else
	{
		fprintf(fp,"%s ; %.2f ; %s ; %.2f ; %.2f\n",ncin,moyenne,serie,notemath,notephy);
		fclose(fp);
	}
}

Choix ajouter_choix(char ncin[],char choix2[],char choix3[])
{
	FILE *fp;
	fp=fopen(FICCHOIX,"a");
	if(fp==NULL)
	{
		printf("impossible d'ouvrir le fichier %s !\n",FICCHOIX);
 		
 	}
	else
	{
		fprintf(fp,"%s ; %s ; %s\n",ncin,choix2,choix3);
		fclose(fp);
	}
}

int ctr_cand,ctr_bacc,ctr_choix;

Bool is_empty(const char* filename)
{
	//cette fonction a ete cree dans le but de voir si un fichier est vide
	FILE *fp;
	fp=fopen(filename,"r");
	if(fp!=NULL)
	{
		fseek(fp,0,SEEK_END);
		int size=ftell(fp);
		if(size==0)
		{
			return True;
		}
		return False;
	}
}

Bool file_exist(const char *filename)
{
	//cette fonction permet de tester si un fichier existe
	FILE *fp;
	if(fp=fopen(filename,"r"))
	{
		fclose(fp);
		return True;
	}
	return False;
}

void creat_files(const char *FicCan,const char *FicBac,const char *FicCho)
{
	//cette fonction permet de cree les fichier passer comme parametre en appelent
	// la fonction file_exist
	FILE *fp1;
	if(!file_exist(FicCan))
	{
		fp1=fopen(FicCan,"w");
		fclose(fp1);
	}
	if(!file_exist(FicBac))
	{
		fp1=fopen(FicBac,"w");
		fclose(fp1);
	}
	if(!file_exist(FicCho))
	{
		fp1=fopen(FicCho,"w");
		fclose(fp1);
	}
}

void renitialiser_les_fichier(const char *FicCan,const char *FicBac,const char *FicCho)
{
	//permet de vider les fichier passer en parametre
	FILE *fp,*fp1,*fp2;
	fp=fopen(FicCan,"w+");
	if(fp==NULL)
		printf("Erreur de renitialisation du fichier %s!\n",FicCan);
	fp1=fopen(FicBac,"w+");
	if(fp1==NULL)
		printf("Erreur de renitialisation du fichier %s!\n",FicBac);
	fp2=fopen(FicCho,"w+");
	if(fp2==NULL)
		printf("Erreur de renitialisation du fichier %s!\n",FicCho);
	//printf("renitialisation parfait!\n");
	fclose(fp);
	fclose(fp1);
	fclose(fp2);

}



void clrscr()
{//permet de netoyer l'ecran
	system("cls");
}

Bacc recuperer_bacc(Bacc st1[Max],int *ci)
{
	Bacc c;
	FILE *fp;
	int i=0;
	fp=fopen(FICBACC,"r");
	if(fp!=NULL)
	{
		while(fscanf(fp,"%s ; %f ; %s ; %f ; %f",c.NCIN,&c.MOYENNE,c.SERIEBACC,&c.NOTEMATH,&c.NOTEPHY)!=EOF)
		{
			st1[i]=c;
			i++;
			if(i==Max) break;
		}
	}fclose(fp);
	*ci=i;
	int z;
}

Candidat recuperer_candidat(Candidat st1[Max],int *ci)
{
	Candidat c;
    int i=0;
	FILE *fp;
	fp=fopen(FICCAN,"r");
	if(fp!=NULL)
	{
		while(fscanf(fp,"%s ; %s ; %s ; %d",c.NCIN,c.NOM,c.PRENOM,&c.AGE)!=EOF)
		{
			st1[i]=c;
			i++;
			if(i==Max) break;
		}
		*ci=i;
		fclose(fp);
	}
	else
	{
		fprintf(stderr,"could not open %s \n",FICCAN);
		fclose(fp);
	}
}

Choix recuperer_choix(Choix st1[Max],int *cj)
{
	Choix c;
	int i=0;
	FILE *fp;
	fp=fopen(FICCHOIX,"r");
	if(fp!=NULL)
	{
		while(fscanf(fp,"%s ; %s ; %s",c.NCIN,c.CHOIX2,c.CHOIX3)!=EOF)
		{
			st1[i]=c;
			i++;
			if(i==Max) break;
		}
		*cj=i;
		fclose(fp);
		
	}
	else
	{
		fprintf(stderr,"could not open %s \n",FICCHOIX);
		fclose(fp);
	}
}

Candidat recuperer_resultat(RESU st1[Max],int *ck)
{
	RESU c;
	int i=0;
	FILE *fp;
	fp=fopen(FICRESU,"r");
	if(fp!=NULL)
	{
		while(fscanf(fp,"%s ; %s ; %s ; %d ; %f ; %f ; %s",c.NCIN,c.NOM,c.PRENOM,&c.AGE,&c.MOYENNE,&c.MOYENNE_NOTEMATH_NOTEPHY,c.decision)!=EOF)
		{
			st1[i]=c;
			i++;
			if(i==Max) break;
		}
		fclose(fp);
		*ck=i;
	}
}

void recuperer_admis(Candidat st1[Max],int *ci)
{
	Candidat c;
	int i=0;
	FILE *fp;
	fp=fopen(FICADMIS,"r");
	if(fp==NULL)
	{
		printf("Erreur d'ouverture du fichier %s !",FICADMIS);
	}
	else
	{
		while(fscanf(fp,"%s ; %s ; %s ; %d",c.NCIN,c.NOM,c.PRENOM,&c.AGE)!=EOF)
		{
			st1[i]=c;
			i++;
			if(i==Max) break;
		}
		fclose(fp);
		*ci=i;
		//printf("hello world\n");
	}
}

Bool does_it_exist(char NCIN[])
{
	/*la fonction  does_it_exist() permet de regarder si un NCIN existe deja dans 
	*	le fichier candidat.txt,bacc.txt,choix;txt 
	*/
	int i,j,k,ci,cj,ck,cm;
	Candidat st1[Max],a;
	Bacc st2[Max];
	Choix st3[Max];
	recuperer_candidat(st1,&ci);
	recuperer_choix(st3,&ck);
	recuperer_bacc(st2,&cj);
	for(i=0;i<ci;i++)
	{
		if((strcmp(NCIN,st1[i].NCIN)==0) || (strcmp(NCIN,st2[i].NCIN)==0) || (strcmp(NCIN,st3[i].NCIN)==0))
		{
			return True;
		}
	}
	return False;
}

Bool compare_les_nom_et_prenom(char NOM[],char PRENOM[])
{
	int i,j,n;
	//cette fonction permet a ce que deux nom et meme prenom ne puisse pa etre dans dans un fichier
	Candidat can[Max];
	strupr(NOM);
	strupr(PRENOM);
	recuperer_candidat(can,&n);
	for(i=0;i<n;i++)
	{
		if((strcmp(NOM,can[i].NOM)==0) && (strcmp(PRENOM,can[i].PRENOM)==0))
		{
			return True;
		}
	}
	return False;
}

/*ici netoyer a la possibiliter de crée le fichier et en même temp il vide le contenu du fichier*/
void netoyer(const char *fic)
{
	FILE *fp;
	fp=fopen(fic,"w");
	if(fp==NULL)
	{
		return;
	}
	fclose(fp);
}


void resultat()
{
	//resultat qui permet de cree le fichier resultat et affichier les resultat
	Candidat st1[Max],_ca;
	Bacc st2[Max],_ba;
	Choix st3[Max];
	CandDec st4[Max],_de;
	int ci=0,cj=0,ck=0,i=0,cm=0,j=0,k=0;
	FILE *fp;
	recuperer_candidat(st1,&ci);
	recuperer_bacc(st2,&cj);
	recuperer_choix(st3,&ck);
	for(i=0;i<cj;i++)
	{
		if(st2[i].MOYENNE>s1)
		{
			strcpy(st4[i].decision,"INFORMATIQUE");
		}
		else if((st2[i].MOYENNE>=s2 && st2[i].MOYENNE<=s1) && ((st2[i].NOTEMATH+ st2[i].NOTEPHY)/2>=s3))
		{
			strcpy(st4[i].decision,"INFORMATIQUE");
			//printf("%s\n",st4[i].decision);
		}
		else
		{
			strcpy(st4[i].decision,st3[i].CHOIX2);
			//printf("%s",st3[i].CHOIX2);
		}
	}
	/*ici , je vais trie les resultat pour avoir des inforamtion trie dans tous les autre fichier
	*	je vais utiliser le tri a bulle 
	*	le principe ici c'est de trie les noms des candidat
	*/
	/************************Debut de tri***********************************/
	// je vais d'abord convertis tous les nom et prenom en majuscule avec la foction strupr(<chain_de_charactere>);

	/*************************Debut de conversion en majuscule*/
	for(i=0;i<cj;i++)
	{
		strupr(st1[i].NOM);
		strupr(st1[i].PRENOM);
	}
	/************************Fin de conversion en majuscule*****/
	for(i=0;i<cj;i++)
	{
		for(j=0;j<cj-i-1;j++)
		{
			//ici je compare les deux noms si st1[j].NOM est superieur a st1[j+1].NOM je permute
			if(strcmp(st1[j].NOM,st1[j+1].NOM)>0)
			{
				/*********NCIN**********/
				strcpy(_ca.NCIN,st1[j].NCIN);
				strcpy(st1[j].NCIN,st1[j+1].NCIN);
				strcpy(st1[j+1].NCIN,_ca.NCIN);
				/*********NOM*************/
				strcpy(_ca.NOM,st1[j].NOM);
				strcpy(st1[j].NOM,st1[j+1].NOM);
				strcpy(st1[j+1].NOM,_ca.NOM);
				/*********PRENOM*******/
				strcpy(_ca.PRENOM,st1[j].PRENOM);
				strcpy(st1[j].PRENOM,st1[j+1].PRENOM);
				strcpy(st1[j+1].PRENOM,_ca.PRENOM);
				/***********AGE*****************/
				_ca.AGE=st1[j].AGE;
				st1[j].AGE=st1[j+1].AGE;
				st1[j+1].AGE=_ca.AGE;
				/**********MOYENNE***********/
				_ba.MOYENNE=st2[j].MOYENNE;
				st2[j].MOYENNE=st2[j+1].MOYENNE;
				st2[j+1].MOYENNE=_ba.MOYENNE;
				/*********NOTEMATH************/
				_ba.NOTEMATH=st2[j].NOTEMATH;
				st2[j].NOTEMATH=st2[j+1].NOTEMATH;
				st2[j+1].NOTEMATH=_ba.NOTEMATH;
				/********NOTEPHY**************/
				_ba.NOTEPHY=st2[j].NOTEPHY;
				st2[j].NOTEPHY=st2[j+1].NOTEPHY;
				st2[j+1].NOTEPHY=_ba.NOTEPHY;
				/*********DECISION*************/
				strcpy(_de.decision,st4[j].decision);
				strcpy(st4[j].decision,st4[j+1].decision);
				strcpy(st4[j+1].decision,_de.decision);

			}
		}
	}
	/////tous deja trier et maintenant on peut ecrie ans le fichier
	/*************************Fin de tri************************************/

	fp=fopen(FICRESU,"w");
	if(fp!=NULL)
	{
		for(i=0;i<ci;i++)
		{
			fprintf(fp,"%s ; %s ; %s ; %d ; %.2f ; %.2f ; %s\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE,st2[i].MOYENNE,(st2[i].NOTEMATH+st2[i].NOTEPHY)/2,st4[i].decision);
		}
		fclose(fp);
	}
	else
		printf("impossible d'ecrire le resultat dans le fichier %s parce que l'ouverture n'a pas eu lieu !",FICRESU);
	/*gotoxy(10,3);printf("VOICI LES RESULTAT DES CANDIDAT\n");
	printf("NCIN\tNOM\tPRENOM\tAGE\tDECISION\n");
	for(j=0;j<ci;j++)
	{
		printf("%s  %s  %s  %d  %s\n",st1[j].NCIN,st1[j].NOM,st1[j].PRENOM,st1[j].AGE,st4[j].decision);
	}*/
	/*
	*	ici j'ai decider d'affichier sur l'ecran le NCIN,NOM,PRENOM,AGE ET DECISION m'est
	*	ce qui est ecrire dans le fichier c'est NCIN,NOM,PRENOM,AGE,MOYENNE,NOTEMATH,NOTEPHY,DECISION
	*/
	gotoxy(40-10,0);printf("RESULATS DES CANDIDATS");
	gotoxy(0,2);printf("N");
	gotoxy(6,2);printf("NCIN");
	gotoxy(34-5,2);printf("NOM");
	gotoxy(64-5,2);printf("PRENOM");
	gotoxy(94-10-6,2);printf("AGE");
	gotoxy(88-2,2);printf("DECISION");
	for(i=0;i<ci;i++)
	{
		gotoxy(0,4+i);printf("%d",i+1);
		gotoxy(6,4+i);printf("%s",st1[i].NCIN);
		gotoxy(34-5,4+i);printf("%s",st1[i].NOM);
		gotoxy(64-5,4+i);printf("%s",st1[i].PRENOM);
		gotoxy(94-10-6,4+i);printf("%d",st1[i].AGE);
		gotoxy(88-2,4+i);printf("%s",st4[i].decision);
		
	}
	getch();
}
Candidat admis()
{
	//qui permet de cree le fichier admis.txt et affichier les admis
	RESU st1[Max];
	int ci=0,i=0,cj,ck,compter_admis=0;
	FILE *fp;
	Bool ctr=True;
	netoyer(FICADMIS);
	fp=fopen(FICADMIS,"a");
	if(fp!=NULL)
	{
		/*st1,st2,ci=*/
		/*ici je passe en parametre st1,st2 et l'adress de ci pour recuperer les inforamtion 
		*des candidat du fichier resultat.txt 
		*/
		recuperer_resultat(st1,&ci);

		for (i = 0; i < ci; i++)
		{
			if(strcmp(st1[i].decision,"INFORMATIQUE")==0)
			{
				ctr=False;
				/*
				* ici j'ai decider d'ecrire dans le fichier admis.txt les information du candidat seulement
				*/
				fprintf(fp,"%s ; %s ; %s ; %d\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
			}
			if(ctr==False)
			{
				compter_admis+=1;
				ctr=True;
			}
		}
		fclose(fp);
	}

	Candidat st[Max];
	int n;
	recuperer_admis(st,&n);
	gotoxy(40-10,0);printf("CANDIDAT ADMIS EN INFORMATIQUE");
	gotoxy(0,2);printf("N");
	gotoxy(6,2);printf("NCIN");
	gotoxy(34-5,2);printf("NOM");
	gotoxy(64-5,2);printf("PRENOM");
	gotoxy(94-10,2);printf("AGE");
	for(i=0;i<n;i++)
	{
		gotoxy(0,4+i);printf("%d",i+1);
		gotoxy(6,4+i);printf("%s",st[i].NCIN);
		gotoxy(34-5,4+i);printf("%s",st[i].NOM);
		gotoxy(64-5,4+i);printf("%s",st[i].PRENOM);
		gotoxy(94-10,4+i);printf("%d",st[i].AGE);
		
	}
	getch();
}

void block()
{
		/*201 205 187
		186 205 186
		200 205 188*/
		int i;
		SetColor(7);

		gotoxy(50,1);printf("%c",201);
		
		for(i=51;i<99;i++)
		{
			SetColor(10);
			gotoxy(i,1);printf("%c",205);
			SetColor(14);
			gotoxy(i,28);printf("%c",205);
		}
		gotoxy(99,1);printf("%c",187);
		for(i=2;i<28;i++)
		{
			SetColor(12);
			gotoxy(50,i);printf("%c",186);
			SetColor(15);
			gotoxy(99,i);printf("%c",186);
		}
		gotoxy(50,1);printf("%c",201);
		gotoxy(99,1);printf("%c",187);
		gotoxy(50,28);printf("%c",200);
		gotoxy(99,28);printf("%c",188);
}

void supprimer(char ncin[])
{
	//qui supprime un NCIN passer en parametre
	int i,ci,cj,ck,j;
	Candidat st1[Max];
	Bacc st2[Max];
	Choix st3[Max];
	char r;
	int sup=True,NFP=True;
	recuperer_candidat(st1,&ci);
	recuperer_choix(st3,&ck);
	recuperer_bacc(st2,&cj);
	if(!does_it_exist(ncin))
	{
		SetColor(12);
		gotoxy(10,9);printf("CE NCIN N'EXISTE PAS !");
		getch();
	}
	else
	{	
		for(j=0;j<ci;j++)
		{
			if(strcmp(ncin,st2[j].NCIN)==0)
			{
				break;
			}
		}
		block();
		gotoxy(52,3);printf("NCIN : %s",st1[j].NCIN);
		gotoxy(52,5);printf("NOM  : %s",st1[j].NOM);
		gotoxy(52,7);printf("PRENOM : %s",st1[j].PRENOM);
		gotoxy(52,9);printf("AGE : %d",st1[j].AGE);
		gotoxy(52,11);printf("SERIE : %s",st2[j].SERIEBACC);
		gotoxy(52,13);printf("MOYENNE BACC : %.2f",st2[j].MOYENNE);
		gotoxy(52,15);printf("NOTE MATHEMATIQUE au BACC : %.2f",st2[j].NOTEMATH);
		gotoxy(52,17);printf("NOTE PHYSIQUE au Bacc : %.2f",st2[j].NOTEPHY);
		gotoxy(52,19);printf("Deuxieme Choix : %s",st3[j].CHOIX2);
		gotoxy(52,21);printf("Troisieme Choix : %s",st3[j].CHOIX3);
		gotoxy(5,10);printf("Voulez Vous Supprimer Ce Candidat %c",14);
		gotoxy(5,12);printf("Si oui presser la touche ");SetColor(10);printf("1");SetColor(15);
		gotoxy(5,14);printf("Si Non presser la touche ");SetColor(12);printf("0");SetColor(15);
		do
		{
			gotoxy(5,16);printf("Reponse : ");r=getch();
			switch(r)
			{
				case '1':
					NFP=False;
					break;
				case '0':
					SetColor(12);
					gotoxy(10,23);printf("Annulation de la Suppression!");
					sleep(1);
					return;
			}
		}while(NFP);
		
		renitialiser_les_fichier(FICCAN,FICBACC,FICCHOIX);
		FILE *fp,*fp1,*fp2;
		fp=fopen(FICCAN,"w");
		if(fp!=NULL)
			for(i=0;i<ci;i++)
			{
				if(strcmp(ncin,st1[i].NCIN)==0)
				{
					
				}
				else
				{
					fprintf(fp,"%s ; %s ; %s ; %d\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
				}
			}
			fclose(fp);
		fp1=fopen(FICBACC,"w");
		if(fp1!=NULL)
		{
			for(i=0;i<cj;i++)
			{
				if(strcmp(ncin,st2[i].NCIN)==0)
				{
					i+=1;
				}
				else
				{
					fprintf(fp1,"%s ; %.2f ; %s ; %.2f ; %.2f\n",st2[i].NCIN,st2[i].MOYENNE,st2[i].SERIEBACC,st2[i].NOTEMATH,st2[i].NOTEPHY);
				}
			}
			fclose(fp1);
		}
		fp2=fopen(FICCHOIX,"w");
		if(fp2!=NULL)
		{
			for(i=0;i<ck;i++)
			{
				if(strcmp(ncin,st3[i].NCIN)==0)
				{
					i+=1;
				}
				else
				{
					fprintf(fp2,"%s ; %s ; %s\n",st3[i].NCIN,st3[i].CHOIX2,st3[i].NCIN);
				}
			}
			fclose(fp2);
		}
		SetColor(10);
		gotoxy(10,23);printf("Candidat supprimer avec Succes !");getch();
	}
	
}

void cardre()
{
	/*Cette fonction permet de faire un cadre dans la fonction ajouter et modifier candidat*/
	 SetColor(11);
	 /*201 205 187
	186 205 186
	200 205 188*/
	 gotoxy(0,0);printf("%c",201);
	 int i;
	 for(i=1;i<49;i++)
	 {
	 	SetColor(11);
	 	gotoxy(i,0);printf("%c",205);
	 	gotoxy(i,28);printf("%c",205);
	 }
	 gotoxy(49,0);printf("%c",187);
	 for(i=1;i<=27;i++)
	 {
	 	SetColor(10);
	 	gotoxy(0,i);printf("%c",186);
	 	SetColor(14);
	 	gotoxy(49,i);printf("%c",186);
	 }
	 gotoxy(0,28);printf("%c",200);
	 gotoxy(49,28);printf("%c",188);
	 
}

/*
*cette fonction me permet de chercher un nom et un prenom dans un tableau a une meme position
*parceque je ne veut pas que deux personne on le meme nom meme s'il on different NCIN
*/
void chercher_nom_et_prenom_dans_les_tableau(AIDE_MOI nom[Max],AIDE_MOI prenom[Max],char nom_a_chercher[],char prenom_a_chercher[],int n,int *a)
{
	int i;
	for(i=0;i<n;i++)
	{
		if((strcmp(nom_a_chercher,nom[i].nom)==0) && (strcmp(prenom_a_chercher,prenom[i].prenom)==0))
		{
			*a=1;
			return;
		}
	}
	*a=0;
	return;
}

/*Fonction qui compare les NCIN ett retourne un entier en fonction des condidtion*/
int compare_this_NCIN(Candidat List_NCIN[Max],char new_ncin[],int size_of_the_list)
{
	/*know in this fonction if it compare the the new NCIN with the other in List_NCIN 
	*if the result after comparing is 0 meaning there are equal it will return 1 else return 0 
	*/
	int i;
	for(i=0;i<size_of_the_list;i++)
	{
		if(strcmp(List_NCIN[i].NCIN,new_ncin)==0)
		{
			return True;//True=1
		}
	}
	return False;//False=0 if it arrive at this level it means that the new NCIN is not present in the List_NCIN


}


void MoDiF_NcIn(char *NcIn)
{
	/*et maintenat quand je met le signe ! devant ma fonction does si la valeur retourner est 1
	* en faissant la negation le resulatat sera 0 qui est faut parcontre si la valeur retourner est 0 en 
	* faissant la negation le resultat serai 1  qui est
	* comme toujour je verifie ci le NCIN existe_it_exist
	*
	*/
	if(!does_it_exist(NcIn))
	{
		SetColor(12);
		gotoxy(10,9);printf("Ce NCIN n'existe pas");getch();

	}
	else
	{
		clrscr();
		Candidat st1[Max];
		Bacc st2[Max];
		Choix st3[Max];
		int i,j,n1,n2,n3,pos,MFP=1;
		char r;
		recuperer_candidat(st1,&n1);
		recuperer_bacc(st2,&n2);
		recuperer_choix(st3,&n3);
		/*
		*	Apres avoire verifier maintenat ce que je vais faire c'est de faire en sorte que 
		*	le nouveau NCIN entre par l'utilisateur ne correspond pas a l'un des NCIN dans les fichier
		*	et pour cela je vair cree une variable pour stocker tous les NCIN qui ne correspond 
		*	pas au NCIN a modiier 
		*/
		Candidat Stock_NCIN[Max];
		char Nouveau_NCIN[Max_chain_character];
		/*Maintenat je vais trouver la position du NCIN */
		for(i=0;i<n1;i++)
		{
			if(strcmp(st1[i].NCIN,NcIn)!=0)
			{
				//ici si je compare les ncin est c'est different je stock dans Stock_NCIN
				strcpy(Stock_NCIN[i].NCIN,st1[i].NCIN);
			}
		}

		//je doit touver a position de l'ancien NCIN
		for(i=0;i<n1;i++)
		{
			if(strcmp(st1[i].NCIN,NcIn)==0)
			{
				//ici si la position de l'ancien NCIN est trouver
				break;
			}
		}
		//je vais cree une fonction pour comparer le Nouveau NCIN avec les autres
		do
		{
			block();
			gotoxy(52,3);printf("NCIN : %s",st1[i].NCIN);
			gotoxy(52,5);printf("NOM  : %s",st1[i].NOM);
			gotoxy(52,7);printf("PRENOM : %s",st1[i].PRENOM);
			gotoxy(52,9);printf("AGE : %d",st1[i].AGE);
			gotoxy(52,11);printf("SERIE : %s",st2[i].SERIEBACC);
			gotoxy(52,13);printf("MOYENNE BACC : %.2f",st2[i].MOYENNE);
			gotoxy(52,15);printf("NOTE MATHEMATIQUE au BACC : %.2f",st2[i].NOTEMATH);
			gotoxy(52,17);printf("NOTE PHYSIQUE au Bacc : %.2f",st2[i].NOTEPHY);
			gotoxy(52,19);printf("Deuxieme Choix : %s",st3[i].CHOIX2);
			gotoxy(52,21);printf("Troisieme Choix : %s",st3[i].CHOIX3);
			gotoxy(2,1);printf("_______________________________________________");
			gotoxy(2,2);printf("|                                              |");
			gotoxy(2,3);printf("|Ancien NCIN : %s",NcIn);
			gotoxy(49,4);printf("|");
			gotoxy(49,3);printf("|");
			gotoxy(2,4);printf("|                                              |");
			gotoxy(49,5);printf("|");
			gotoxy(2,6);printf("|______________________________________________|");
			gotoxy(2,5);printf("|Nouveau NCIN : ");SetColor(10);scanf("%s",Nouveau_NCIN);
			//gotoxy(5,6);printf("|__________________________________________________|");
			if(compare_this_NCIN(Stock_NCIN,Nouveau_NCIN,n1))
			{
				SetColor(12);
				gotoxy(5,9);printf("Ce NCIN appartient a un autre Candidat!");
				sleep(1);
				gotoxy(5,9);printf("                                       ");
				/*Ici j'efface ce que l'utilisateur a ecrire sur l'ecran*/
				SetColor(15);
				clrscr();
				
			}
			else
			{
				break;
			}
		}while(1);
		SetColor(15);
		gotoxy(5,10);printf("Voulez Vous Modifier Ce NCIN %c",14);
		gotoxy(5,12);printf("Si oui presser la touche ");SetColor(10);printf("1");
		gotoxy(5,14);printf("Si Non presser la touche ");SetColor(12);printf("0");
		do
		{
			gotoxy(5,16);printf("Reponse : ");r=getch();
			switch(r)
			{
				case '1':MFP=0;break;
				case '0':return;
			}
		}while(MFP);
		//comme j'ai deja trouver la position d'ou l'ancien NCIN etait je vais copier 
		//le nouveau a cette position
		strcpy(st1[i].NCIN,Nouveau_NCIN);
		strcpy(st2[i].NCIN,Nouveau_NCIN);
		strcpy(st3[i].NCIN,Nouveau_NCIN);
		//je renitialise d'aborb les fichier candidat bacc et choix
		renitialiser_les_fichier(FICCAN,FICBACC,FICCHOIX);
		FILE *fp;
		getch();
		//j'ouvre maintenat les fichier pour remplacer le NCIN
		fp=fopen(FICCAN,"a");
		if(fp!=NULL)
		{
			for(j=0;j<n1;j++)
			{
				fprintf(fp,"%s ; %s ; %s ; %d\n",st1[j].NCIN,st1[j].NOM,st1[j].PRENOM,st1[j].AGE);
			}
		}fclose(fp);
		fp=fopen(FICBACC,"a");
		if(fp!=NULL)
		{
			for(j=0;j<n2;j++)
			{
				fprintf(fp,"%s ; %.2f ; %s ; %.2f ; %.2f\n",st2[j].NCIN,st2[j].MOYENNE,st2[j].SERIEBACC,st2[j].NOTEMATH,st2[j].NOTEPHY);
			}
		}fclose(fp);
		fp=fopen(FICCHOIX,"a");
		if(fp!=NULL)
		{
			for(j=0;j<n3;j++)
			{
				fprintf(fp,"%s ; %s ; %s\n",st3[j].NCIN,st3[j].CHOIX2,st3[j].CHOIX3);
			}
		}fclose(fp);
		SetColor(10);
		gotoxy(10,23);printf("Modification Terminer Avec Succes!");
	}
	getch();
}
//------------------------------------------------------------------

//cette fonction permet de supprimer l'aide sur le remplisage du nom

void delet_help_name()
{
	int i,j;
	for(i=32;i<=46;i++)
	{
		for(j=19;j<=72;j++)
		{
			gotoxy(j,i);printf(" ");
		}
	}
}

void info_modification_box()
{
	int i;
	/*218 196 191
	  179     179
	  192 196 217*/
	//x,y=49,28
	gotoxy(19,32);printf("%c",218);
	for(i=20;i<72;i++)
	{
		SetColor(10);
		gotoxy(i,32);printf("%c",196);
		SetColor(14);
		gotoxy(i,46);printf("%c",196);
	}
	gotoxy(72,32);printf("%c",191);
	for(i=33;i<46;i++)
	{
		SetColor(12);
		gotoxy(19,i);printf("%c",179);
		SetColor(15);
		gotoxy(72,i);printf("%c",179);
	}
	gotoxy(19,46);printf("%c",192);
	gotoxy(72,46);printf("%c",217);
}

//permet d'afficher l'aide l'ors du remplisage du nom et prenom 
void aide_nom()
{
	int i;
	/*218 196 191
	  179     179
	  192 196 217*/
	//x,y=49,28
	gotoxy(19,32);printf("%c",218);
	for(i=20;i<72;i++)
	{
		SetColor(10);
		gotoxy(i,32);printf("%c",196);
		SetColor(14);
		gotoxy(i,46);printf("%c",196);
	}
	gotoxy(72,32);printf("%c",191);
	for(i=33;i<46;i++)
	{
		SetColor(12);
		gotoxy(19,i);printf("%c",179);
		SetColor(15);
		gotoxy(72,i);printf("%c",179);
	}
	gotoxy(19,46);printf("%c",192);
	gotoxy(72,46);printf("%c",217);
	SetColor(11);
	gotoxy(21,34);printf("Si Le Nom Du Candidat A Deux PARTI");SetColor(15);
	gotoxy(21,36);printf("Par Example ");SetColor(10);printf("NOM : IVAN NAVI");SetColor(15);
	gotoxy(21,38);printf("Utiliser ");SetColor(10);printf("_");SetColor(15);printf(" Pour Ecrire Le Nom");
	gotoxy(21,40);printf("Comme Ceci :");SetColor(10);printf("NOM : IVAN_NAVI");SetColor(15);
	gotoxy(21,42);printf("Meme Chose Pour Le Prenom");SetColor(12);
	gotoxy(21,44);printf("Sinon le programme tournera dans une boucle infini ");SetColor(15);
}

//------------------------------------------------------------------
/*
* cette fonction a ete fait pour modifier facillement les information du candidat 
* et d'autre fonction on ete cree pour modifier une partie specific
*/

Candidat modifier(char *ncin)
{
	//qui permet de corriger les donner d'un candidat don le NCIN est  passer en parametre

	/*je vais cree une fonction qui permet de modifier uniquement le NCIN d'un candidat 
	* parce que je prend en consideraion que au niveau de la lecture l'utilisateur peut avoir
	* une erreur au NCIN comme c'est impossible de rentre en arriere dans la console quand 
	* la touche entre et appuyer et la fonction je vais l'ecrire en haut de la fonction modifier
	*/

	/*
	*la variable st1,st2,st3 sont des variable qui recupere les information des fichier 
	* respective a leur nom
	*/
	Candidat NCIN,st1[Max],ai;
	Bacc st2[Max];
	Choix st3[Max];

	int i=0,j,ci,cj,ck,pos=0,cout=0,MFP=1;
	if(!does_it_exist(ncin))
	{
		SetColor(12);
		gotoxy(10,9);printf("CE NCIN N'EXISTE PAS !");
		getch();
	}
	else
	{
		
		recuperer_candidat(st1,&ci);
		recuperer_choix(st3,&cj);
		recuperer_bacc(st2,&ck);
		int check=0,sal=0;
		int exit=1,chech=1,modifying=0,MODIF=1;
		char valeur[30];
		char sr,ch,ch2,ch3,r,reso;//reso c'est une variable me permet de modifier chaque info du candidat
		/*ici je vais afficher le candidat correspondant au NCIN et demander si on voulez lui modifier*/

		/****ici je trouve d'abord la position du NCIN**/
		for(i=0;i<ci;i++)
		{
			if(strcmp(ncin,st1[i].NCIN)==0)
			{
				pos=i;
				break;//position du NCIN trouver qui est i
			}
		}
		/*************fin****************************************/
		clrscr();
		block();
		gotoxy(52,3);printf("NCIN : %s",st1[i].NCIN);
		gotoxy(52,5);printf("NOM  : %s",st1[i].NOM);
		gotoxy(52,7);printf("PRENOM : %s",st1[i].PRENOM);
		gotoxy(52,9);printf("AGE : %d",st1[i].AGE);
		gotoxy(52,11);printf("SERIE : %s",st2[i].SERIEBACC);
		gotoxy(52,13);printf("MOYENNE BACC : %.2f",st2[i].MOYENNE);
		gotoxy(52,15);printf("NOTE MATHEMATIQUE au BACC : %.2f",st2[i].NOTEMATH);
		gotoxy(52,17);printf("NOTE PHYSIQUE au Bacc : %.2f",st2[i].NOTEPHY);
		gotoxy(52,19);printf("Deuxieme Choix : %s",st3[i].CHOIX2);
		gotoxy(52,21);printf("Troisieme Choix : %s",st3[i].CHOIX3);

		/*ici je demande maintenant a l'utilisateur s'il veut le modifier*/
		SetColor(15);
		gotoxy(5,10);printf("Voulez Vous Aporter des Modification %c",14);
		gotoxy(5,12);printf("A Ce Candidat ?");
		gotoxy(5,14);printf("Si oui presser la touche ");SetColor(10);printf("1");SetColor(15);
		gotoxy(5,16);printf("Si Non presser la touche ");SetColor(12);printf("0");SetColor(15);
		do
		{
			gotoxy(5,18);printf("Reponse : ");r=getch();
			switch(r)
			{
				case '1':MFP=0;break;
				case '0':return;
			}
		}while(MFP);
		/*********************************************************/
		/*ici j'ai fait le copier coller de la fonction ajouter 
		*m'zst comme j'ai deja la position la ou le NCIN ce trouve
		* je vais directement entre les inforamtion a ce Niveau
		*/

		//ceci jai copier dans ma fonction pour modifier un candidat
		int e;
		AIDE_MOI nom[Max_chain_character],prenom[Max_chain_character];
		for(j=0;j<ci;j++)
		{
			if(strcmp(ncin,st1[j].NCIN)!=0)
			{
				strcpy(nom[j].nom,st1[j].NOM);
				strcpy(prenom[j].prenom,st1[j].PRENOM);
			}
		}
		//apres avoir ajouter les nom et prenom des candidat qui ne correspond au NCIN
		//quand l'utisateur entrera le nom je vais appeller la fonction
		//"chercher_nom_et_prenom_dans_les_tableau"

		char go[30]="";

			clrscr();
			cardre();//ici j'appelle mon cadre
			SetColor(10);
			gotoxy(50,1);printf("_________________________________________________");
			 gotoxy(50,2);printf("|                                                |");//  x ,x
			 gotoxy(50,3);printf("|                                                |");//(66,85)
			 gotoxy(66,3);SetColor(12);printf("INFORMATION A NOTER!");SetColor(10);
			 gotoxy(50,4);printf("|                                                |");
			 gotoxy(50,5);printf("|   I-Pour les SERIEBACC ENTRER LA TOUCHE:       |");
			 gotoxy(50,6);printf("|      1.Pour SERIE C                            |");
			 gotoxy(50,7);printf("|      2.Pour SERIE D                            |");
			 gotoxy(50,8);printf("|      3.Pour SERIE Ti                           |");
			 gotoxy(50,9);printf("|      4.Pour SERIE F4                           |");
			gotoxy(50,10);printf("|                                                |");
			gotoxy(50,11);printf("|                                                |");
			gotoxy(50,12);printf("|   II-Pour les CHOIX ENTRER LA TOUCHE:          |");
			gotoxy(50,13);printf("|      1.pour PHYSIQUE                           |");
			gotoxy(50,14);printf("|      2.pour MATHEMATIQUE                       |");
			gotoxy(50,15);printf("|      3.pour BIO SCIENCE                        |");
			gotoxy(50,16);printf("|      4.pour ICT                                |");
			gotoxy(50,17);printf("|      5.pour CHIMIE                             |");
			gotoxy(50,18);printf("|      6.pour GEO SCIENCE                        |");
			gotoxy(50,19);printf("|                                                |");
			gotoxy(50,20);printf("|   L'age du candidat doit etre compris entre    |");
			gotoxy(50,21);printf("|      10 et 100 ans                             |");
			gotoxy(50,22);printf("|                                                |");
			gotoxy(50,23);printf("|   La moyenne au bacc doit etre compris entre   |");
			gotoxy(50,24);printf("|      10 et 20                                  |");
			gotoxy(50,25);printf("|      5.pour E                                  |");
			gotoxy(50,26);printf("|   La moyenne des matiers doitetre compris entre|");
			gotoxy(50,27);printf("|      0 et 20                                   |");
			gotoxy(50,28);printf("|________________________________________________|");block();
			SetColor(15);
			gotoxy(7,2);printf("Modifier les information du candidat %d/%d",pos+1,ci);
			gotoxy(1,4);printf(">NCIN : ");printf("%s",st1[i].NCIN);
			gotoxy(1,6);printf(">NOM : ");SetColor(10);printf("%s",st1[i].NOM);SetColor(15);
			gotoxy(1,8);printf(">PRENOM : ");SetColor(10);printf("%s",st1[i].PRENOM);SetColor(15);
			gotoxy(1,10);printf(">AGE : ");SetColor(10);printf("%d",st1[i].AGE);SetColor(15);
			gotoxy(1,12);printf(">SERIEBACC : ");printf("%s",st2[i].SERIEBACC);SetColor(15);
			gotoxy(1,14);printf(">MOYENNE AU BACC : ");SetColor(10);printf("%.2f",st2[i].MOYENNE);SetColor(15);
			gotoxy(1,16);printf(">NOTE MATHEMATIQUE au Bacc : ");SetColor(10);printf("%.2f",st2[i].NOTEMATH);SetColor(15);
			gotoxy(1,18);printf(">NOTE PHYSIQUE au Bacc : ");SetColor(10);printf("%.2f",st2[i].NOTEPHY);SetColor(15);
			gotoxy(1,20);printf(">Deuxieme choix : ");SetColor(10);printf("%s",st3[i].CHOIX2);SetColor(15);
			gotoxy(1,22);printf(">Troisieme choix : ");SetColor(10);printf("%s",st3[i].CHOIX3);
			/*
			*	ici , comme j'ai deja afficher le nom et le prenom je vais demander a l'utilisateur de 
			*	selectionner 1 pour modifier le NOM 0 pour paser au prochain
			*/
			info_modification_box();
			do
			{
				gotoxy(21,34);printf("Voulez Vous Modifier Le NOM Et Le PRENOM ");SetColor(15);
				gotoxy(21,36);printf("Du Candidat ?");SetColor(15);
				gotoxy(21,38);printf("Si Oui Presser La Touche ");SetColor(10);printf("1");SetColor(15);
				gotoxy(21,40);printf("Si Non Presser La Touche ");SetColor(12);printf("0");SetColor(15);
				gotoxy(21,42);printf("(0) pour passer a l'age ");SetColor(14);
				gotoxy(21,44);printf("Reponse : ");SetColor(15);
				reso=getch();
				switch(reso)
				{
					case '1':
						modifying=1;
						MODIF=False;
						break;
					case '0':
						MODIF=0;
						modifying=0;
						delet_help_name();
				}
			}while(MODIF==True);
			
			if(modifying==1)
			{
				delet_help_name();
				aide_nom();
				gotoxy(1,6);printf(">NOM :                            ");
				gotoxy(1,8);printf(">PRENOM :                         ");
				do
				{
					gotoxy(1,6);printf(">NOM : ");SetColor(14);scanf("%s",st1[i].NOM);SetColor(15);
					gotoxy(1,8);printf(">PRENOM : ");SetColor(14);scanf("%s",st1[i].PRENOM);
					strupr(st1[i].NOM);
					strupr(st1[i].PRENOM);
					chercher_nom_et_prenom_dans_les_tableau(nom,prenom,st1[i].NOM,st1[i].PRENOM,ci,&e);
					if(e==1)
					{
						SetColor(12);
						gotoxy(50,30);printf("Ce Nom et ce Prenom existe deja!");
						sleep(1);
						SetColor(15);
						gotoxy(50,30);printf("                                ");
						gotoxy(1,6);printf(">NOM :                            ");
						gotoxy(1,8);printf(">PRENOM :                         ");
						e=0;
					}
					else
						break;
				}while(True);
				delet_help_name();
			}
			//here, i ask again if the user want to modify the age like in the name above
			MODIF=True;
			info_modification_box();
			do
			{
				gotoxy(21,34);printf("Voulez Vous Modifier L'AGE ");SetColor(15);
				gotoxy(21,36);printf("Du Candidat ?");SetColor(15);
				gotoxy(21,38);printf("Si Oui Presser La Touche ");SetColor(10);printf("1");SetColor(15);
				gotoxy(21,40);printf("Si Non Presser La Touche ");SetColor(12);printf("0");SetColor(15);
				gotoxy(21,42);printf("(0) pour Passer A la Serie ");SetColor(14);
				gotoxy(21,44);printf("Reponse : ");SetColor(15);
				reso=getch();
				switch(reso)
				{
					case '1':
						modifying=1;
						MODIF=False;
						break;
					case '0':
						MODIF=0;
						modifying=0;
						delet_help_name();
				}
			}while(MODIF==True);
			if(modifying==1)
			{
				gotoxy(1,10);printf(">AGE :       ");
				delet_help_name();
				do
				{
					SetColor(15);
					gotoxy(1,10);printf(">AGE : ");SetColor(8);
					fgets(valeur,10,stdin);
					if(strcmp(type_of(valeur),"int")==0)
					{
						sscanf(valeur,"%d%s",&st1[i].AGE,go);
						if(sscanf(valeur,"%d%s",&st1[i].AGE,go)==1)
						{
							if(st1[i].AGE<=10 || st1[i].AGE>=100)
							{
								SetColor(12);
								gotoxy(50,30);printf("AGE INVALID!");
								sleep(1);
								SetColor(15);
								gotoxy(50,30);printf("             ");
								gotoxy(1,10);printf(">AGE :          ");
							}
							else
								break;
						}
						else if(strcmp(go,"")!=0)
						{
							SetColor(12);
							gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER");
							sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("                              ");
							gotoxy(1,10);printf(">AGE :                                ");
						}
						
					}
					else
					{
						SetColor(12);
						gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER");
						sleep(1);
						SetColor(15);
						gotoxy(50,30);printf("                              ");
						gotoxy(1,10);printf(">AGE :                                ");
					}

				}while(True); 
			}
			//---same thing here as up
			MODIF=True;
			info_modification_box();
			do
			{
				gotoxy(21,34);printf("Voulez Vous Modifier LA SERIE DU BACC ");SetColor(15);
				gotoxy(21,36);printf("Du Candidat ?");SetColor(15);
				gotoxy(21,38);printf("Si Oui Presser La Touche ");SetColor(10);printf("1");SetColor(15);
				gotoxy(21,40);printf("Si Non Presser La Touche ");SetColor(12);printf("0");SetColor(15);
				gotoxy(21,42);printf("(0) pour Passer A la MOYENNE AU BACC ");SetColor(14);
				gotoxy(21,44);printf("Reponse : ");SetColor(15);
				reso=getch();
				switch(reso)
				{
					case '1':
						modifying=1;
						MODIF=False;
						break;
					case '0':
						MODIF=0;
						modifying=0;
						delet_help_name();
				}
			}while(MODIF==True);
			if(modifying==1)
			{
				gotoxy(1,12);printf(">SERIEBACC :      ");
				do
				{
					SetColor(14);
					gotoxy(1,12);printf(">SERIEBACC : ");
					sr=getch();
					switch(sr)
					{
						case '1':
							strcpy(st2[i].SERIEBACC,"C");
							exit=0;
							break;
						case '2':
							strcpy(st2[i].SERIEBACC,"D");exit=0;
							break;
						case '3':
							strcpy(st2[i].SERIEBACC,"Ti");exit=0;
							break;
						case '4':
							strcpy(st2[i].SERIEBACC,"F4");exit=0;
							break;
						default:
							SetColor(12);
							gotoxy(50,30);printf("SERIE INVALID!");
							sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("              ");
							
					}
				}while(exit);
				exit=1;
				SetColor(8);
				printf("%s",st2[i].SERIEBACC);
			}
			SetColor(15);
			check=1;
			if(check==1)
			{
				exit=1;
				MODIF=True;
				info_modification_box();
				do
				{
					gotoxy(21,34);printf("Voulez Vous Modifier LA MOYENNE AU BACC ");SetColor(15);
					gotoxy(21,36);printf("Du Candidat ?");SetColor(15);
					gotoxy(21,38);printf("Si Oui Presser La Touche ");SetColor(10);printf("1");SetColor(15);
					gotoxy(21,40);printf("Si Non Presser La Touche ");SetColor(12);printf("0");SetColor(15);
					gotoxy(21,42);printf("(0) pour Passer A la NOTE DE MATH AU BACC ");SetColor(14);
					gotoxy(21,44);printf("Reponse : ");SetColor(15);
					reso=getch();
					switch(reso)
					{
						case '1':
							modifying=1;
							MODIF=False;
							break;
						case '0':
							MODIF=0;
							modifying=0;
							delet_help_name();
					}
				}while(MODIF==True);
				if(modifying==1)
				{
					delet_help_name();
					gotoxy(1,14);printf(">MOYENNE AU BACC :      ");
					do
					{
						gotoxy(1,14);printf(">MOYENNE AU BACC : ");SetColor(6);
						fgets(valeur,20,stdin);
						if((strcmp(type_of(valeur),"int")==0) || (strcmp(type_of(valeur),"float")==0))
						{
							sscanf(valeur,"%f%s",&st2[i].MOYENNE,go);
							if(sscanf(valeur,"%f%s",&st2[i].MOYENNE,go)==1)
							{
								if((int)st2[i].MOYENNE>=10 && (int)st2[i].MOYENNE<=20)
								{
									break;
								}
								else//(st2.MOYENNE<10 || st2.MOYENNE>=21)
								{
									SetColor(12);
									gotoxy(50,30);printf("MOYENNE INVALID!");
									sleep(1);
									SetColor(15);
									gotoxy(50,30);printf("                ");
									gotoxy(1,14);printf(">MOYENNE AU BACC :      ");
								}
							}
							else if(strcmp(go,"")!=0)
							{
								SetColor(12);
								gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
							    sleep(1);
								SetColor(15);
								gotoxy(50,30);printf("                                                ");
								gotoxy(1,14);printf(">MOYENNE AU BACC :                   ");
							}
							
						}
						else
						{
							SetColor(12);
							gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
						    sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("                                                ");
							gotoxy(1,14);printf(">MOYENNE AU BACC :                   ");
						}
						
					
					}while(True);
				}
				MODIF=True;
				info_modification_box();
				do
				{
					gotoxy(21,34);printf("Voulez Vous Modifier LA NOTE DE MATHEMATIQUE ");SetColor(15);
					gotoxy(21,36);printf("Du Candidat ?");SetColor(15);
					gotoxy(21,38);printf("Si Oui Presser La Touche ");SetColor(10);printf("1");SetColor(15);
					gotoxy(21,40);printf("Si Non Presser La Touche ");SetColor(12);printf("0");SetColor(15);
					gotoxy(21,42);printf("(0) pour Passer A la NOTE DE PHYSIQUE ");SetColor(14);
					gotoxy(21,44);printf("Reponse : ");SetColor(15);
					reso=getch();
					switch(reso)
					{
						case '1':
							modifying=1;
							MODIF=False;
							break;
						case '0':
							MODIF=0;
							modifying=0;
							delet_help_name();
					}
				}while(MODIF==True);
				if(modifying==1)
				{
					delet_help_name();
					gotoxy(1,16);printf(">NOTE MATHEMATIQUE AU BACC :       ");
					SetColor(15);
					do
					{
						gotoxy(1,16);printf(">NOTE MATHEMATIQUE AU BACC : ");SetColor(14);
						fgets(valeur,20,stdin);
						if((strcmp(type_of(valeur),"float")==0) || (strcmp(type_of(valeur),"int")==0))
						{
							sscanf(valeur,"%f%s",&st2[i].NOTEMATH,go);
							if(sscanf(valeur,"%f%s",&st2[i].NOTEMATH,go)==1)
							{
								if(st2[i].NOTEMATH<=-1 || st2[i].NOTEMATH>=21)
								{
									SetColor(12);
									gotoxy(50,30);printf("NOTE DE MATHEMATIQUE INVALID!");
									sleep(1);
									SetColor(15);
									gotoxy(50,30);printf("                             ");
									gotoxy(1,16);printf(">NOTE MATHEMATIQUE au Bacc :       ");
								}
								else if(st2[i].NOTEMATH>=1 && st2[i].NOTEMATH<=20)
									break;
							}
							else if(strcmp(go,"")!=0)
							{
								SetColor(12);
							gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
							sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("                                                ");
							gotoxy(1,16);printf(">NOTE MATHEMATIQUE AU BACC :                   ");
							}
							
						}
						else
						{
							SetColor(12);
							gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
							sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("                                                ");
							gotoxy(1,16);printf(">NOTE MATHEMATIQUE AU BACC :                   ");
						}
						
					}while(True);
				}
				MODIF=True;
				info_modification_box();
				do
				{
					gotoxy(21,34);printf("Voulez Vous Modifier LA NOTE DE PHYSIQUE ");SetColor(15);
					gotoxy(21,36);printf("Du Candidat ?");SetColor(15);
					gotoxy(21,38);printf("Si Oui Presser La Touche ");SetColor(10);printf("1");SetColor(15);
					gotoxy(21,40);printf("Si Non Presser La Touche ");SetColor(12);printf("0");SetColor(15);
					gotoxy(21,42);printf("(0) pour Passer Au Deuxieme Choix ");SetColor(14);
					gotoxy(21,44);printf("Reponse : ");SetColor(15);
					reso=getch();
					switch(reso)
					{
						case '1':
							modifying=1;
							MODIF=False;
							break;
						case '0':
							MODIF=0;
							modifying=0;
							delet_help_name();
					}
				}while(MODIF==True);
				if(modifying==1)
				{
					delet_help_name();
					gotoxy(1,18);printf(">NOTE PHYSIQUE au Bacc :      ");
					SetColor(15);
					do
					{
						gotoxy(1,18);printf(">NOTE PHYSIQUE au Bacc : ");SetColor(14);
						fgets(valeur,10,stdin);
						if((strcmp(type_of(valeur),"int")==0) ||(strcmp(type_of(valeur),"float")==0))
						{
							sscanf(valeur,"%f%s",&st2[i].NOTEPHY,go);
							if(sscanf(valeur,"%f%s",&st2[i].NOTEPHY,go)==1)
							{
								if(st2[i].NOTEPHY<0 || st2[i].NOTEPHY>20)
								{
									SetColor(12);
									gotoxy(50,30);printf("NOTE DE PHYSIQUE INVALID!");
									sleep(1);
									SetColor(15);
									gotoxy(50,30);printf("                         ");
									gotoxy(1,18);printf(">NOTE PHYSIQUE au Bacc :      ");
								}
								else if(st2[i].NOTEPHY>=1 && st2[i].NOTEPHY<=20)
									break;
							}
							else if(strcmp(go,"")!=0)
							{
								SetColor(12);
								gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
								sleep(1);
								SetColor(15);
								gotoxy(50,30);printf("                                                ");
								gotoxy(1,18);printf(">NOTE PHYSIQUE au BACC :             ");
							}
						}
						else
						{
							SetColor(12);
							gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
							sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("                                                ");
							gotoxy(1,18);printf(">NOTE PHYSIQUE au BACC :             ");
						}
					}while(True);
				}
				MODIF=True;
				info_modification_box();
				do
				{
					gotoxy(21,34);printf("Voulez Vous Modifier Le Deuxieme Choix ");SetColor(15);
					gotoxy(21,36);printf("Du Candidat ?");SetColor(15);
					gotoxy(21,38);printf("Si Oui Presser La Touche ");SetColor(10);printf("1");SetColor(15);
					gotoxy(21,40);printf("Si Non Presser La Touche ");SetColor(12);printf("0");SetColor(15);
					gotoxy(21,42);printf("(0) pour Passer Au Troisieme Choix ");SetColor(14);
					gotoxy(21,44);printf("Reponse : ");SetColor(15);
					reso=getch();
					switch(reso)
					{
						case '1':
							modifying=1;
							MODIF=False;
							break;
						case '0':
							MODIF=0;
							modifying=0;
							delet_help_name();
					}
				}while(MODIF==True);
				if(modifying==1)
				{
					SetColor(15);
					gotoxy(1,20);printf(">Deuxieme choix :                     ");
					delet_help_name();
					do
					{
						gotoxy(1,20);printf(">Deuxieme choix : ");
						ch2=getch();
						switch(ch2)
						{
							case '1':
								strcpy(st3[i].CHOIX2,"PHYSIQUE");exit=0;
								break;
							case '2':
								strcpy(st3[i].CHOIX2,"MATHEMATIQUE");exit=0;
								break;
							case '3':
								strcpy(st3[i].CHOIX2,"BIO_SCIENCE");exit=0;
								break;
							case '4':
								strcpy(st3[i].CHOIX2,"ICT");exit=0;
								break;
							case '5':
								strcpy(st3[i].CHOIX2,"CHIMIE");exit=0;
								break;
							case '6':
								strcpy(st3[i].CHOIX2,"GEO_SCIENCE");exit=0;
								break;
							default:
								SetColor(12);
								gotoxy(50,30);printf("Deuxieme CHOIX2 INVALID!");
								sleep(1);
								SetColor(15);
								gotoxy(50,30);printf("                         ");
								exit=1;
						}
						if(strcmp(st3[i].CHOIX2,st3[i].CHOIX3)==0)
						{
							SetColor(12);
							gotoxy(50,30);printf("CE CHOIX ET DEJA ENTRE!");
							sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("                       ");
							exit=1;
						}

					}while(exit);
					SetColor(14);
					printf("%s",st3[i].CHOIX2);
				}
				exit=1;
				MODIF=True;
				info_modification_box();
				do
				{
					gotoxy(21,34);printf("Voulez Vous Modifier Le Troisieme Choix ");SetColor(15);
					gotoxy(21,36);printf("Du Candidat ?");SetColor(15);
					gotoxy(21,38);printf("Si Oui Presser La Touche ");SetColor(10);printf("1");SetColor(15);
					gotoxy(21,40);printf("Si Non Presser La Touche ");SetColor(12);printf("0");SetColor(10);
					gotoxy(21,42);printf("(0) pour Terminer ");SetColor(14);
					gotoxy(21,44);printf("Reponse : ");SetColor(15);
					reso=getch();
					switch(reso)
					{
						case '1':
							modifying=1;
							MODIF=False;
							break;
						case '0':
							MODIF=0;
							modifying=0;
							delet_help_name();
					}
				}while(MODIF==True);

				if(modifying==1)
				{
					delet_help_name();
					gotoxy(1,22);printf(">Troisieme choix :                       ");
					SetColor(15);
					do
					{
						gotoxy(1,22);printf(">Troisieme choix : ");
						ch3=getch();
						switch(ch3)
						{
							case '1':
								if(ch2!=ch3)
									strcpy(st3[i].CHOIX3,"PHYSIQUE");exit=0;
								break;
							case '2':
								if(ch2!=ch3)
									strcpy(st3[i].CHOIX3,"MATHEMATIQUE");exit=0;
								break;
							case '3':
								if(ch2!=ch3)
									strcpy(st3[i].CHOIX3,"BIO_SCIENCE");exit=0;
								break;
							case '4':
								if(ch2!=ch3)
									strcpy(st3[i].CHOIX3,"ICT");exit=0;
								break;
							case '5':
								if(ch2!=ch3)
									strcpy(st3[i].CHOIX3,"CHIMIE");exit=0;
								break;
							case '6':
								if(ch2!=ch3)
									strcpy(st3[i].CHOIX3,"GEO_SCIENCE");exit=0;
								break;
							default:
								SetColor(12);
								gotoxy(50,30);printf("Troisieme CHOIX2 INVALID!");
								sleep(1);
								SetColor(15);
								gotoxy(50,30);printf("                         ");
						}
						if(ch2==ch3)
						{
							SetColor(12);
							gotoxy(50,30);printf("CE CHOIX ET DEJA ENTRE!");
							sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("                       ");
							exit=1;
						}
					}while(exit);
				}
				exit=1;
				gotoxy(1,22);printf(">Troisieme choix : ");SetColor(14);
				printf("%s",st3[i].CHOIX3);		
			}
		renitialiser_les_fichier(FICCAN,FICBACC,FICCHOIX);

		/**********************************************************/
		
		//ici comme j'ai deja fini de corriger les donner du candidat maintenat j'ecris dans les fichier 
		//correspondant

		FILE *fp;
		fp=fopen(FICCAN,"a+");
		if(fp!=NULL)
		{
			for(i=0;i<ci;i++)
			{
				fprintf(fp,"%s ; %s ; %s ; %d\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
			}
			fclose(fp);
		}
		fp=fopen(FICBACC,"a+");
		if(fp!=NULL)
		{
			int j;
			for(j=0;j<cj;j++)
			{
				fprintf(fp,"%s ; %.2f ; %s ; %.2f ; %.2f\n",st2[j].NCIN,st2[j].MOYENNE,st2[j].SERIEBACC,st2[j].NOTEMATH,st2[j].NOTEPHY);
			}
			fclose(fp);
		}
		fp=fopen(FICCHOIX,"a+");
		if(fp!=NULL);
		{
			int k;
			for(k=0;k<ck;k++)
			{
				fprintf(fp,"%s ; %s ; %s\n",st3[k].NCIN,st3[k].CHOIX2,st3[k].CHOIX3);
			}
			fclose(fp);
		}
		SetColor(10);
		gotoxy(10,29);printf("\nLes information du Candidat on ete modifier correctement!");
		getch();
	}

}

void ajouter()
{
	SetColor(11);
	Candidat st1,s[Max];
	Bacc st2;
	Choix st3;
	int ci,check=1,exit=1,i;
	Bool run=True;
	recuperer_candidat(s,&ci);
	ctr_cand=ci;
	FILE *fp;
	char valeur[30],go[10]="";
	/*cette variable permet de recuperer tout les donner entre
	* au clavier a l'age moyenne et notemath,notephy
	*/
	char resp,sr,ch2,ch3,p1,gm,gp;
	char NO[Max_chain_character],PRE[Max_chain_character];
	/*
	*ou la variable sr correspond a la serie 
	*               ch2 correspond au choix 2
	*               ch3 ////////// /  choix 3
	*               p1 correspond au la moyenne du GCE  qui est passed
	*               gm correspond au grade de MATHEMATIQUE
	*               gp ////////////////////// PHYSIQUE
	*/
	char r;
	/*	
				*	218 196 191
				*	179		179
				*	192	196	217
				*/	
		/*201 205 187
		186 205 186
		200 205 188*/
	 gotoxy(10,2);printf("_____________________________________________");
	 gotoxy(10,3);printf("|                                            |");SetColor(14);
	 gotoxy(10,4);printf("|     Voulez vous Ajouter un Candidat        |");
	 gotoxy(10,5);printf("|                                            |");
	 gotoxy(10,6);printf("|               Appuyer                      |");
	 gotoxy(10,7);printf("|                                            |");SetColor(10);
	 gotoxy(10,8);printf("| 1. pour oui                                |");
	gotoxy(10,9);printf("|                                            |");SetColor(12);
	gotoxy(10,10);printf("| 0. pour Non                                |");
	gotoxy(10,11);printf("|                                            |");SetColor(11);
	gotoxy(10,12);printf("|Entre votre choix : ___                     |");
	gotoxy(10,13);printf("|____________________________________________|");
	gotoxy(10,2);printf("%c",201);
	for(i=11;i<55;i++)
	{
		SetColor(11);
		gotoxy(i,2);printf("%c",205);
		SetColor(15);
		gotoxy(i,13);printf("%c",205);
	}
	gotoxy(55,2);printf("%c",187);
	for(i=3;i<13;i++)
	{
		SetColor(11);
		gotoxy(10,i);printf("%c",186);
		SetColor(15);
		gotoxy(55,i);printf("%c",186);
	}
	gotoxy(10,13);printf("%c",200);
	gotoxy(55,13);printf("%c",188);
	do
	{
		gotoxy(32,12);r=getch();
		switch(r)
		{
			case '1':
				run=False;
				break;
			case '0':
				return;
		}
	}while(run);
	i=0;
	run=True;
	do
	{
		clrscr();
		cardre();//ici j'appelle mon cadre
		SetColor(10);
		gotoxy(50,1);printf("_________________________________________________");
		 gotoxy(50,2);printf("|                                                |");//  x ,x
		 gotoxy(50,3);printf("|                                                |");//(66,85)
		 gotoxy(66,3);SetColor(12);printf("INFORMATIQUE A NOTER!");SetColor(13);
		 gotoxy(50,4);printf("|                                                |");
		 gotoxy(50,5);printf("|   I-Pour les SERIEBACC ENTRER LA TOUCHE:       |");
		 gotoxy(50,6);printf("|      1.Pour SERIE C                            |");
		 gotoxy(50,7);printf("|      2.Pour SERIE D                            |");
		 gotoxy(50,8);printf("|      3.Pour SERIE Ti                           |");
		 gotoxy(50,9);printf("|      4.Pour SERIE F4                           |");SetColor(14);
		gotoxy(50,10);printf("|                                                |");
		gotoxy(50,11);printf("|                                                |");
		gotoxy(50,12);printf("|   II-Pour les CHOIX ENTRER LA TOUCHE:          |");
		gotoxy(50,13);printf("|      1.pour PHYSIQUE                           |");
		gotoxy(50,14);printf("|      2.pour MATHEMATIQUE                       |");
		gotoxy(50,15);printf("|      3.pour BIO SCIENCE                        |");
		gotoxy(50,16);printf("|      4.pour ICT                                |");
		gotoxy(50,17);printf("|      5.pour CHIMIE                             |");
		gotoxy(50,18);printf("|      6.pour GEO SCIENCE                        |");
		gotoxy(50,19);printf("|                                                |");SetColor(10);
		gotoxy(50,20);printf("|   L'age du candidat doit etre compris entre    |");
		gotoxy(50,21);printf("|      10 et 100 ans                             |");
		gotoxy(50,22);printf("|                                                |");
		gotoxy(50,23);printf("|   La moyenne au bacc doit etre compris entre   |");
		gotoxy(50,24);printf("|      10 et 20                                  |");
		gotoxy(50,25);printf("|      5.pour E                                  |");
		gotoxy(50,26);printf("|   La moyenne des matiers doitetre compris entre|");
		gotoxy(50,27);printf("|      0 et 20                                   |");
		gotoxy(50,28);printf("|________________________________________________|");block();
		SetColor(15);
		gotoxy(7,2);printf("Entre les information du candidat %d/%d",ctr_cand+1,Max);
		do
		{
			gotoxy(1,4);printf(">NCIN : ");SetColor(11);scanf("%s",st1.NCIN);
			if(does_it_exist(st1.NCIN))
			{
				SetColor(12);
				gotoxy(50,30);printf("Ce NCIN Existe Deja!");
				sleep(1);
				SetColor(15);
				gotoxy(50,30);printf("                     ");
				gotoxy(1,4);printf(">NCIN :                        ");
			}
			else
				break;
		}while(run);
		do
		{
			SetColor(15);
			aide_nom();
			gotoxy(1,6);printf(">NOM : ");SetColor(11);scanf("%s",st1.NOM);SetColor(15);
			gotoxy(1,8);printf(">PRENOM : ");SetColor(11);scanf("%s",st1.PRENOM);
			strupr(st1.NOM);
			strupr(st1.PRENOM);
			if(compare_les_nom_et_prenom(st1.NOM,st1.PRENOM))
			{
				SetColor(12);
				gotoxy(50,30);printf("Ce Nom et ce Prenom existe deja!");
				sleep(1);
				SetColor(15);
				gotoxy(50,30);printf("                                ");
				gotoxy(1,6);printf(">NOM :                            ");
				gotoxy(1,8);printf(">PRENOM :                         ");
			}
			else
				break;
		}while(True);
		delet_help_name();
		SetColor(15);
		do
		{
			SetColor(15);
			gotoxy(1,10);printf(">AGE : ");SetColor(11);
			fgets(valeur,20,stdin);
			if(strcmp(type_of(valeur),"int")==0)
			{
				sscanf(valeur,"%d%s",&st1.AGE,go);
				if(sscanf(valeur,"%d%s",&st1.AGE,go)==1)//strcmp(go,"")==0
				{
					if(st1.AGE<=10 || st1.AGE>=100)
					{
						SetColor(12);
						gotoxy(50,30);printf("AGE INVALID!");
						sleep(1);
						SetColor(15);
						gotoxy(50,30);printf("             ");
						gotoxy(1,10);printf(">AGE :          ");
					}
					else
						break;
				}
				else if(strcmp(go,"")!=0)
				{
					SetColor(12);
					gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER");
					sleep(1);
					SetColor(15);
					gotoxy(50,30);printf("                              ");
					gotoxy(1,10);printf(">AGE :                                ");
				}
			}
			else
			{
				SetColor(12);
				gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER");
				sleep(1);
				SetColor(15);
				gotoxy(50,30);printf("                              ");
				gotoxy(1,10);printf(">AGE :                                ");
			}

		}while(True);
		strcpy(st2.NCIN,st1.NCIN);
		strcpy(st3.NCIN,st1.NCIN);
		SetColor(15);
		do
		{
			gotoxy(1,12);printf(">SERIEBACC : ");
			sr=getch();
			switch(sr)
			{
				case '1':
					strcpy(st2.SERIEBACC,"C");
					exit=0;
					break;
				case '2':
					strcpy(st2.SERIEBACC,"D");exit=0;
					break;
				case '3':
					strcpy(st2.SERIEBACC,"Ti");exit=0;
					break;
				case '4':
					strcpy(st2.SERIEBACC,"F4");exit=0;
					break;
				default:
					SetColor(12);
					gotoxy(50,30);printf("SERIE INVALID!");
					sleep(1);
					SetColor(15);
					gotoxy(50,30);printf("              ");
					
			}
		}while(exit);
		exit=1;
		SetColor(11);
		printf("%s",st2.SERIEBACC);
		SetColor(15);
		if(check==1)
		{
			exit=1;
			do
			{
				gotoxy(1,14);printf(">MOYENNE AU BACC : ");SetColor(11);
				fgets(valeur,20,stdin);
				if((strcmp(type_of(valeur),"int")==0) || (strcmp(type_of(valeur),"float")==0))
				{
					sscanf(valeur,"%f%s",&st2.MOYENNE,go);
					if(sscanf(valeur,"%f%s",&st2.MOYENNE,go)==1)
					{
						if((int)st2.MOYENNE>=10 && (int)st2.MOYENNE<=20)
						{
							break;
						}
						else//(st2.MOYENNE<10 || st2.MOYENNE>=21)
						{
							SetColor(12);
							gotoxy(50,30);printf("MOYENNE INVALID!");
							sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("                ");
							gotoxy(1,14);printf(">MOYENNE Bacc :      ");
						}
					}
					else if(strcmp(go,"")!=0)
					{
						SetColor(12);
						gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
					    sleep(1);
						SetColor(15);
						gotoxy(50,30);printf("                                                ");
						gotoxy(1,14);printf(">MOYENNE AU BACC :                   ");
					}
				}
				else
				{
					SetColor(12);
					gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
				    sleep(1);
					SetColor(15);
					gotoxy(50,30);printf("                                                ");
					gotoxy(1,14);printf(">MOYENNE AU BACC :                   ");
				}   
				
			
			}while(True);
			SetColor(15);
			do
			{
				gotoxy(1,16);printf(">NOTE MATHEMATIQUE AU BACC : ");
				SetColor(11);fgets(valeur,20,stdin);
				if((strcmp(type_of(valeur),"float")==0) || strcmp(type_of(valeur),"int")==0)
				{
					sscanf(valeur,"%f%s",&st2.NOTEMATH,go);
					if(sscanf(valeur,"%f%s",&st2.NOTEMATH,go)==1)
					{
						if(st2.NOTEMATH<=0 || st2.NOTEMATH>=21)
						{
							SetColor(12);
							gotoxy(50,30);printf("NOTE DE MATHEMATIQUE INVALID!");
							sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("                             ");
							gotoxy(1,16);printf(">NOTE MATHEMATIQUE au Bacc :       ");
						}
						else if(st2.NOTEMATH>=1 && st2.NOTEMATH<=20)
							break;
					}
					else if(strcmp(go,"")!=0)
					{
						SetColor(12);
						gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
						sleep(1);
						SetColor(15);
						gotoxy(50,30);printf("                                                ");
						gotoxy(1,16);printf(">NOTE MATHEMATIQUE AU BACC :                   ");
					}
				}
				else
				{
					SetColor(12);
					gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
					sleep(1);
					SetColor(15);
					gotoxy(50,30);printf("                                                ");
					gotoxy(1,16);printf(">NOTE MATHEMATIQUE AU BACC :                   ");
				}
				
			}while(True);
			SetColor(15);
			do
			{
				gotoxy(1,18);printf(">NOTE PHYSIQUE AU BACC : ");SetColor(11);
				fgets(valeur,20,stdin);
				if((strcmp(type_of(valeur),"int")==0) || (strcmp(type_of(valeur),"float")==0))
				{
					sscanf(valeur,"%f%s",&st2.NOTEPHY,go);
					if(sscanf(valeur,"%f%s",&st2.NOTEPHY,go)==1)
					{
						if(st2.NOTEPHY<=0 || st2.NOTEPHY>20)
						{
							SetColor(12);
							gotoxy(50,30);printf("NOTE DE PHYSIQUE INVALID!");
							sleep(1);
							SetColor(15);
							gotoxy(50,30);printf("                         ");
							gotoxy(1,18);printf(">NOTE PHYSIQUE au BACC :      ");
						}
						else if(st2.NOTEPHY>=1 && st2.NOTEPHY<=20)
							break;
					}
					else if(strcmp(go,"")!=0)
					{
						SetColor(12);
						gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
						sleep(1);
						SetColor(15);
						gotoxy(50,30);printf("                                                ");
						gotoxy(1,18);printf(">NOTE PHYSIQUE au BACC :             ");
					}
					
				}
				else
				{
					SetColor(12);
					gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL");
					sleep(1);
					SetColor(15);
					gotoxy(50,30);printf("                                                ");
					gotoxy(1,18);printf(">NOTE PHYSIQUE AU BACC :                   ");
				}
				
			}while(True);
			do
			{SetColor(15);
				gotoxy(1,20);printf(">Deuxieme choix : ");
				ch2=getch();
				switch(ch2)
				{
					case '1':
						strcpy(st3.CHOIX2,"PHYSIQUE");exit=0;
						break;
					case '2':
						strcpy(st3.CHOIX2,"MATHEMATIQUE");exit=0;
						break;
					case '3':
						strcpy(st3.CHOIX2,"BIO_SCIENCE");exit=0;
						break;
					case '4':
						strcpy(st3.CHOIX2,"ICT");exit=0;
						break;
					case '5':
						strcpy(st3.CHOIX2,"CHIMIE");exit=0;
						break;
					case '6':
						strcpy(st3.CHOIX2,"GEO_SCIENCE");exit=0;
						break;
					default:
						SetColor(12);
						gotoxy(50,30);printf("Deuxieme CHOIX2 INVALID!");
						sleep(1);
						SetColor(15);
						gotoxy(50,30);printf("                         ");

				}

			}while(exit);
			exit=1;SetColor(11);
			printf("%s",st3.CHOIX2);
			do
			{SetColor(15);
				gotoxy(1,22);printf(">Troisieme choix : ");
				ch3=getch();
				switch(ch3)
				{
					case '1':
						if(ch2!=ch3)
						{
							strcpy(st3.CHOIX3,"PHYSIQUE");exit=0;
						}
						break;
					case '2':
						if(ch2!=ch3)
							strcpy(st3.CHOIX3,"MATHEMATIQUE");exit=0;
						break;
					case '3':
						if(ch2!=ch3)
							strcpy(st3.CHOIX3,"BIO_SCIENCE");exit=0;
						break;
					case '4':
						if(ch2!=ch3)
							strcpy(st3.CHOIX3,"ICT");exit=0;
						break;
					case '5':
						if(ch2!=ch3)
							strcpy(st3.CHOIX3,"CHIMIE");exit=0;
						break;
					case '6':
						if(ch2!=ch3)
							strcpy(st3.CHOIX3,"GEO_SCIENCE");exit=0;
						break;
					default:
						SetColor(12);
						gotoxy(50,30);printf("Troisieme CHOIX2 INVALID!");
						sleep(1);
						SetColor(15);
						gotoxy(50,30);printf("                         ");
				}
				if(ch2==ch3)
				{
					SetColor(12);
					gotoxy(50,30);printf("CE CHOIX ET DEJA ENTRE!");
					sleep(1);
					SetColor(15);
					gotoxy(50,30);printf("                       ");
					exit=1;
				}
			}while(exit);
			exit=1;SetColor(11);
			printf("%s",st3.CHOIX3);		
		}
		ajouter_candidat(st1.NCIN,st1.NOM,st1.PRENOM,st1.AGE);
		ajouter_choix(st3.NCIN,st3.CHOIX2,st3.CHOIX3);
		ajouter_bacc(st2.NCIN,st2.MOYENNE,st2.SERIEBACC,st2.NOTEMATH,st2.NOTEPHY);

		ctr_cand+=1;
		SetColor(14);gotoxy(10,30);printf("Voulez vous Continuer a ajouter des Candidat si oui entre 1:");
		resp=getch();
		check=1;
	}while(resp=='1');

}
/*
*	j'ai cree cette fonctio pour directement modifier ledeuxieme choix d'un candidat
*/
Bacc modif_choix_2()
{
	char ncin[30],resp;
	Choix choix2,st1[Max];
	int ck;
	Candidat can[Max];
	Bacc st2[Max];
	recuperer_choix(st1,&ck);
	int z,cj,ci;
	recuperer_candidat(can,&ci);
	recuperer_bacc(st2,&cj);
	char ch2,ch3;
	system("cls");
	do
	{
		clrscr();
		gotoxy(2,4);printf(">Entre le NCIN du Candidat que vous voulez modifier");
		gotoxy(2,5);printf("            le deuxieme choix              ");
		SetColor(15);
		gotoxy(2,6);printf(">NCIN : ");SetColor(13);scanf("%s",ncin);
		SetColor(10);
		if(!does_it_exist(ncin))
		{
			SetColor(12);
			gotoxy(10,7);printf("Ce NCIN n'existe pas! ");
			getch();
			SetColor(10);
		}

		
		
		else
		{
			for(z=0;z<ck;z++) 
			{
				if(strcmp(st1[z].NCIN,ncin)==0)
				{
					break;
				}		
			}
			clrscr();
			gotoxy(60,3); printf(" _____________________________________");
			gotoxy(60,4); printf("|                                     |");
			gotoxy(60,5); printf("| I-Pour les CHOIX ENTRER LA TOUCHE:  |");
			gotoxy(60,6); printf("|    1.pour PHYSIQUE                  |");
			gotoxy(60,7); printf("|    2.pour MATHEMATIQUE              |");
			gotoxy(60,8); printf("|    3.pour BIO SCIENCE               |");
			gotoxy(60,9); printf("|    4.pour ICT                       |");
			gotoxy(60,10);printf("|    5.pour CHIMIE                    |");
			gotoxy(60,11);printf("|    6.pour GEO SCIENCE               |");
			gotoxy(60,12);printf("|_____________________________________|");
			cardre();
			SetColor(8);
			gotoxy(5,2);printf("Modification du Deuxieme Choix");
			SetColor(15);
			gotoxy(1,4);printf(">NCIN : ");SetColor(11);printf("%s",st1[z].NCIN);SetColor(15);
			gotoxy(1,6);printf(">NOM : ");SetColor(11);printf("%s",can[z].NOM);SetColor(15);
			gotoxy(1,8);printf(">PRENOM : ");SetColor(11);printf("%s",can[z].PRENOM);SetColor(15);
			gotoxy(1,10);printf(">AGE : ");SetColor(11);printf("%d",can[z].AGE);SetColor(15);
			gotoxy(1,12);printf(">SERIEBACC : ");SetColor(11);printf("%s",st2[z].SERIEBACC);SetColor(15);
			gotoxy(1,14);printf(">MOYENNE AU BACC : ");SetColor(11);printf("%.2f",st2[z].MOYENNE);SetColor(15);
			gotoxy(1,16);printf(">NOTE MATHEMATIQUE AU BACC : ");SetColor(11);printf("%.2f",st2[z].NOTEMATH);SetColor(15);
			gotoxy(1,18);printf(">NOTE PHYSIQUE au Bacc : ");printf("%.2f",st2[z].NOTEPHY);SetColor(15);
			gotoxy(1,22);printf(">Troisieme choix : ");SetColor(11);printf("%s",st1[z].CHOIX3);SetColor(15);
			Bool chx=True;
			do
			{
				SetColor(10);
				gotoxy(1,20);printf(">Deuxieme choix : ");
				SetColor(11);
				ch2=getch();
				switch(ch2)
				{
					case '1':
							strcpy(choix2.CHOIX2,"PHYSIQUE");chx=0;
						break;
					case '2':
							strcpy(choix2.CHOIX2,"MATHEMATIQUE");chx=0;
						break;
					case '3':
							strcpy(choix2.CHOIX2,"BIO_SCIENCE");chx=0;
						break;
					case '4':
							strcpy(choix2.CHOIX2,"ICT");chx=0;
						break;
					case '5':
							strcpy(choix2.CHOIX2,"CHIMIE");chx=0;
						break;
					case '6':
							strcpy(choix2.CHOIX2,"GEO_SCIENCE");chx=0;
						break;
					default:
						SetColor(12);
						gotoxy(60,14);printf("Deuxieme CHOIX2 INVALID!");
						sleep(1);
						SetColor(14);
						gotoxy(60,14);printf("                         ");

				}
				
				if(strcmp(choix2.CHOIX2,st1[z].CHOIX3)==0)
				{
					SetColor(12);
					gotoxy(60,14);printf("CE CHOIX ET DEJA ENTRE!");
					sleep(1);
					SetColor(14);
					gotoxy(60,14);printf("                         ");
					chx=True;
				}

			}while(chx);
			printf("%s",choix2.CHOIX2);
			int i;
			Bool con=False;
			for(i=0;i<ck;i++)
			{
				if(strcmp(ncin,st1[i].NCIN)==0)
				{
					strcpy(st1[i].CHOIX2,choix2.CHOIX2);
					con=True;
				}
			}
			if(con)
			{
				SetColor(10);
				gotoxy(10,27);printf("La modification c'est bien passer!\n");
			}
			else
			{
				SetColor(12);
				gotoxy(10,27);printf("La modification n'a pas u lieu!\n");
			}
			FILE *fp;
			netoyer(FICCHOIX);
			fp=fopen(FICCHOIX,"a+");
			if(fp!=NULL)
			{
				for(i=0;i<ck;i++)
				{
					fprintf(fp,"%s ; %s ; %s\n",st1[i].NCIN,st1[i].CHOIX2,st1[i].CHOIX3);
				}
				fclose(fp);
			}
			else
			{
				SetColor(12);
				gotoxy(10,27);printf("Erreur d'ouverture du fichier %s !",FICBACC);
			}
		}
		SetColor(7);
		gotoxy(0,30);printf("Voulez vous modifier encore le Deuxieme choix d'un candidat Entre (1 pour oui ): ");
		resp=getch();
	}while(resp=='1');
}
/*
*j'ai cree cette fonction pour modifier directement le troisieme choix d'un candidat
*/
Bacc modif_choix_3()
{

	char ncin[30],resp;
	Choix choix3,st1[Max];
	int ck,z,j,cj,ci;
	Candidat can[Max];
	Bacc st2[Max];
	recuperer_candidat(can,&ci);
	recuperer_bacc(st2,&cj);
	Bool vrai=True;
	char ch3;
	recuperer_choix(st1,&ck);
	do
	{
		clrscr();
		gotoxy(2,4);printf("Entre le NCIN que vous voulez modifier"); 
		gotoxy(2,5);printf("      le troisieme choix  ");
		gotoxy(2,7);printf(">NCIN :");SetColor(11);scanf("%s",ncin);
		if(!does_it_exist(ncin))
		{
			SetColor(12);
			gotoxy(10,9);printf("Ce NCIN n'existe pas! ");
			getch();
		}
		
		
		else
		{
			clrscr();
			for(z=0;z<ck;z++) 
			{
				if(strcmp(st1[z].NCIN,ncin)==0)
				{
					break;
				}
				
			}
			SetColor(10);
			gotoxy(60,3); printf(" _____________________________________");
			gotoxy(60,4); printf("|                                     |");
			gotoxy(60,5); printf("| I-Pour les CHOIX ENTRER LA TOUCHE:  |");
			gotoxy(60,6); printf("|    1.pour PHYSIQUE                  |");
			gotoxy(60,7); printf("|    2.pour MATHEMATIQUE              |");
			gotoxy(60,8); printf("|    3.pour BIO SCIENCE               |");
			gotoxy(60,9); printf("|    4.pour ICT                       |");
			gotoxy(60,10);printf("|    5.pour CHIMIE                    |");
			gotoxy(60,11);printf("|    6.pour GEO SCIENCE               |");
			gotoxy(60,12);printf("|_____________________________________|");
			SetColor(11);
			cardre();
			SetColor(8);
			gotoxy(5,2);printf("Modification du Troisieme Choix");
			SetColor(15);
			gotoxy(1,4);printf(">NCIN : ");SetColor(11);printf("%s",st1[z].NCIN);SetColor(15);
			gotoxy(1,6);printf(">NOM : ");SetColor(11);printf("%s",can[z].NOM);SetColor(15);
			gotoxy(1,8);printf(">PRENOM : ");SetColor(11);printf("%s",can[z].PRENOM);SetColor(15);
			gotoxy(1,10);printf(">AGE : ");SetColor(11);printf("%d",can[z].AGE);SetColor(15);
			gotoxy(1,12);printf(">SERIEBACC : ");SetColor(11);printf("%s",st2[z].SERIEBACC);SetColor(15);
			gotoxy(1,14);printf(">MOYENNE AU BACC : ");SetColor(11);printf("%.2f",st2[z].MOYENNE);SetColor(15);
			gotoxy(1,16);printf(">NOTE MATHEMATIQUE AU BACC : ");SetColor(11);printf("%.2f",st2[z].NOTEMATH);SetColor(15);
			gotoxy(1,18);printf(">NOTE PHYSIQUE au Bacc : ");printf("%.2f",st2[z].NOTEPHY);SetColor(15);
			gotoxy(1,20);printf(">Deuxieme choix : ");SetColor(11);printf("%s",st1[z].CHOIX2);SetColor(15);
			do
			{
				SetColor(10);
				gotoxy(1,22);printf(">Troisieme choix : ");
				SetColor(11);
				ch3=getch();
				switch(ch3)
				{
					case '1':
							strcpy(choix3.CHOIX3,"PHYSIQUE");vrai=0;
						break;
					case '2':
							strcpy(choix3.CHOIX3,"MATHEMATIQUE");vrai=0;
						break;
					case '3':
							strcpy(choix3.CHOIX3,"BIO_SCIENCE");vrai=0;
						break;
					case '4':
							strcpy(choix3.CHOIX3,"ICT");vrai=0;
						break;
					case '5':
							strcpy(choix3.CHOIX3,"CHIMIE");vrai=0;
						break;
					case '6':
							strcpy(choix3.CHOIX3,"GEO_SCIENCE");vrai=0;
						break;
					default:
						SetColor(12);
						gotoxy(60,14);printf("Troisieme CHOIX2 INVALID!");
						sleep(1);
						SetColor(10);
						gotoxy(60,14);printf("                         ");

				}
				
				if(strcmp(choix3.CHOIX3,st1[z].CHOIX2)==0)
				{
					SetColor(12);
					gotoxy(60,14);printf("CE CHOIX ET DEJA ENTRE!");
					sleep(1);
					SetColor(10);
					gotoxy(60,14);printf("                         ");
					vrai=True;
				}
			}while(vrai);
			printf("%s",choix3.CHOIX3);
			int i;
			strcpy(st1[z].CHOIX3,choix3.CHOIX3);
			SetColor(10);
			gotoxy(10,27);printf("La modification c'est bien passer");
			FILE *fp;
			netoyer(FICCHOIX);
			fp=fopen(FICCHOIX,"w");
			if(fp!=NULL)
			{
				for(i=0;i<ck;i++)
				{
					fprintf(fp,"%s ; %s ; %s\n",st1[i].NCIN,st1[i].CHOIX2,st1[i].CHOIX3);
				}
				fclose(fp);
			}
			else
			{
				SetColor(12);
				gotoxy(10,27);printf("Erreur d'ouverture du fichier %s !",FICBACC);
			}
		}
		SetColor(7);
		gotoxy(10,30);printf("Voulez vous modifier encore le troisieme"); 
		gotoxy(14,32);printf("choix d'un candidat (1 pour oui ):");
		resp=getch();
	}while(resp=='1');
}

void modifier_cadidat()
{
	//qui permet de modifier le nom ,prenom ,et l'age d'un candidat 
	Candidat can[Max],st1;
	int i,n,j,check=0,MFP=1,x,y,cj,ck;
	FILE *fp;
	char r,go[20]="",valeur[30];
	Bacc st2[Max];
	Choix st3[Max];
	recuperer_candidat(can,&n);
	recuperer_bacc(st2,&cj);
	recuperer_choix(st3,&ck);
	gotoxy(1,3);printf("Entre le NCIN du Candidat que voulez modifier c'est information personnelle ");
	gotoxy(1,4);printf(">NCIN : ");scanf("%s",st1.NCIN);
	if(!does_it_exist(st1.NCIN))
	{
		SetColor(12);
		gotoxy(1,5);printf("Ce NCIN n'exist pas!");
		getch();
		SetColor(15);
		return;
	}
	clrscr();
	for(i=0;i<n;i++)
	{
		if(strcmp(st1.NCIN,can[i].NCIN)==0)
		{
			break;//position de NCIN trouver
		}
	}
	block();
	SetColor(10);
	gotoxy(52,3);printf("NCIN : %s",can[i].NCIN);
	gotoxy(52,5);printf("NOM  : %s",can[i].NOM);
	gotoxy(52,7);printf("PRENOM : %s",can[i].PRENOM);
	gotoxy(52,9);printf("AGE : %d",can[i].AGE);
	SetColor(15);
	gotoxy(52,11);printf("SERIE : %s",st2[i].SERIEBACC);
	gotoxy(52,13);printf("MOYENNE BACC : %.2f",st2[i].MOYENNE);
	gotoxy(52,15);printf("NOTE MATHEMATIQUE au BACC : %.2f",st2[i].NOTEMATH);
	gotoxy(52,17);printf("NOTE PHYSIQUE au Bacc : %.2f",st2[i].NOTEPHY);
	gotoxy(52,19);printf("Deuxieme Choix : %s",st3[i].CHOIX2);
	gotoxy(52,21);printf("Troisieme Choix : %s",st3[i].CHOIX3);
	SetColor(15);
	gotoxy(5,10);printf("Voulez Vous Modifier C'est inforamtion %c",14);
	gotoxy(5,12);printf("Personnelle : ?");
	gotoxy(5,14);printf("Si oui presser la touche ");SetColor(10);printf("1");SetColor(15);
	gotoxy(5,16);printf("Si Non presser la touche ");SetColor(12);printf("0");SetColor(15);
	do
	{
		gotoxy(5,18);printf("Reponse : ");r=getch();
		switch(r)
		{
			case '1':MFP=0;break;
			case '0':return;
		}
	}while(MFP);
	//ceci me permet de nettoyer la parie ou j'ai demander a l'utilisateur s'il voulait modifier seulement
	gotoxy(5,10);printf("                                         ");
	gotoxy(5,12);printf("                                         ");
	gotoxy(5,14);printf("                                         ");
	gotoxy(5,16);printf("                                         ");
	gotoxy(5,18);printf("                                         ");

	cardre();
	gotoxy(5,1);SetColor(15);printf("MODIFIER INFOR.. PERSONNELLE DU CANDIDAT");
	gotoxy(1,3);printf(">NCIN : ");SetColor(14);printf("%s",st1.NCIN);

	AIDE_MOI nom[Max_chain_character],prenom[Max_chain_character];
	for(j=0;j<n;j++)
	{
		if(strcmp(st1.NCIN,can[j].NCIN)!=0)
		{
			strcpy(nom[j].nom,can[j].NOM);
			strcpy(prenom[j].prenom,can[j].PRENOM);
		}
	}
	int e;
	do
	{
		aide_nom();
		gotoxy(1,5);printf(">NOM : ");SetColor(10);scanf("%s",st1.NOM);
		SetColor(15);
		gotoxy(1,7);printf(">PRENOM : ");SetColor(14);scanf("%s",st1.PRENOM);
		strupr(st1.NOM);
		strupr(st1.PRENOM);
		chercher_nom_et_prenom_dans_les_tableau(nom,prenom,st1.NOM,st1.PRENOM,n,&e);
		if(e==1)
		{
			SetColor(12);
			gotoxy(50,29);printf("CE NOM ET CE PRENOM EXISTE DEJA!");
			sleep(1);
			SetColor(11);
			gotoxy(50,29);printf("                                 ");
			gotoxy(1,5);printf(">NOM :                                   ");
			gotoxy(1,7);printf(">PRENOM :                                ");
			e=0;
		}
		else
			break;
	}while(True);
	delet_help_name();
	strcpy(can[i].NOM,st1.NOM);
	strcpy(can[i].PRENOM,st1.PRENOM);	
	do
	{
		gotoxy(1,9);printf(">AGE : ");SetColor(15);
		fgets(valeur,20,stdin);
		if(strcmp(type_of(valeur),"int")==0)
		{
			sscanf(valeur,"%d%s",&st1.AGE,go);
			if(sscanf(valeur,"%d%s",&st1.AGE,go)==1)
			{
				if(st1.AGE<=10 && st1.AGE>=100)
				{
					SetColor(12);
					gotoxy(50,29);printf("AGE INVALID!");
					sleep(1);
					SetColor(11);
					gotoxy(50,29);printf("            ");
					gotoxy(1,9);printf(">AGE :              ");
				}
				else
					break;
			}
			else if(strcmp(go,"")!=0)
			{
				SetColor(12);
				gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER");
				sleep(1);
				SetColor(15);
				gotoxy(50,30);printf("                              ");
				gotoxy(1,9);printf(">AGE :                                ");
			}
		}
		else
		{
			SetColor(12);
			gotoxy(50,30);printf("ENTRER UNIQUEMENT UN ENTIER");
			sleep(1);
			SetColor(15);
			gotoxy(50,30);printf("                              ");
			gotoxy(1,9);printf(">AGE :                                ");
		}		
	}while(True);
	SetColor(15);
	gotoxy(5,12);printf("Voulez Vous Sauvegarder La modification %c",14);
	gotoxy(5,14);printf("Si oui presser la touche 1");
	gotoxy(5,16);printf("Si Non presser la touche 0");
	MFP=1;
	do
	{
		gotoxy(5,18);printf("Reponse : ");r=getch();
		switch(r)
		{
			case '1':MFP=0;break;
			case '0':return;
		}
	}while(MFP);
	can[i].AGE=st1.AGE;
	netoyer(FICCAN);
	fp=fopen(FICCAN,"w+");
	if(fp!=NULL)
	{
		for(i=0;i<n;i++)
		{
			fprintf(fp,"%s ; %s ; %s ; %d\n",can[i].NCIN,can[i].NOM,can[i].PRENOM,can[i].AGE);
		}
		fclose(fp);
	}
	else
	{
		SetColor(12);
		gotoxy(10,11);fprintf(stderr,"La modification n'a pas u lieu!");
	}
	SetColor(7);
	gotoxy(1,12);printf("Appuyer sur n'importe quelle boutton"); 
	gotoxy(1,14);printf("      pour retourner au menu        ");
	getch();
}



void modifier_bacc()
{
	//qui permet de modifier les information du bacc d'un candidat
	Bacc bac[Max],st1;
	Candidat can[Max];
	Choix cho[Max];
	int i,n,exit=1,ci,ck;
	char s;
	FILE *fp;
	char valeur[10]="",go[20]="";
	recuperer_bacc(bac,&n);
	recuperer_candidat(can,&ci);
	recuperer_choix(cho,&ck);
	gotoxy(5,2);printf("Entrer le NCIN du Candidat que vous souhaiter modifier le information sur le BACC");
	gotoxy(5,4);printf("NCIN : ");scanf("%s",st1.NCIN);
	if(!does_it_exist(st1.NCIN))
	{
		gotoxy(10,6);SetColor(12);printf("Ce NCIN n'existe pas !");getch();return;
	}
	clrscr();
	for(i=0;i<n;i++)
	{
		if(strcmp(st1.NCIN,bac[i].NCIN)==0)
		{
			break;
		}
	}
	cardre();
	SetColor(10);
	gotoxy(50,3);printf("_________________________________________________");
	gotoxy(50,4);printf("|                                                |");
	gotoxy(50,5);printf("|   I-Pour les SERIEBACC ENTRER LA TOUCHE:       |");
	gotoxy(50,6);printf("|      1.Pour SERIE C                            |");
	gotoxy(50,7);printf("|      2.Pour SERIE D                            |");
	gotoxy(50,8);printf("|      3.Pour SERIE Ti                           |");
	gotoxy(50,9);printf("|      4.Pour SERIE F4                           |");
	gotoxy(50,10);printf("|                                                |");
	gotoxy(50,11);printf("|________________________________________________|");
	SetColor(7);
	gotoxy(5,1);printf("MODIFIER LES INFO.. SUR LE BACC");

	gotoxy(1,4);printf(">NCIN : ");SetColor(11);printf("%s",bac[i].NCIN);SetColor(15);
	gotoxy(1,6);printf(">NOM : ");SetColor(11);printf("%s",can[i].NOM);SetColor(15);
	gotoxy(1,8);printf(">PRENOM : ");SetColor(11);printf("%s",can[i].PRENOM);SetColor(15);
	gotoxy(1,10);printf(">AGE : ");SetColor(11);printf("%d",can[i].AGE);SetColor(15);
	gotoxy(1,20);printf(">Deuxieme choix : ");SetColor(11);printf("%s",cho[i].CHOIX2);SetColor(15);
	gotoxy(1,22);printf(">Troisieme choix : ");SetColor(11);printf("%s",cho[i].CHOIX3);SetColor(15);
	gotoxy(1,14);SetColor(15);printf(">MOYENNE AU BACC: ");
	gotoxy(1,16);SetColor(15);printf("NOTE MATHAMATIQUE: ");
	gotoxy(1,18);SetColor(15);printf("NOTE PHYSIQUE : ");
	do
	{
		gotoxy(1,12);SetColor(15);printf(">SERIEBACC : ");SetColor(10);
		s=getch();
		switch(s)
		{
			case '1':
				strcpy(st1.SERIEBACC,"C");
				exit=0;
				break;
			case '2':
				strcpy(st1.SERIEBACC,"D");exit=0;
				break;
			case '3':
				strcpy(st1.SERIEBACC,"Ti");exit=0;
				break;
			case '4':
				strcpy(st1.SERIEBACC,"F4");exit=0;
				break;
			default:
				SetColor(12);
				gotoxy(50,13);printf("SERIE INVALID!");
				sleep(1);
				SetColor(15);
				gotoxy(50,13);printf("              ");
					
		}
	}while(exit);
	printf("%s",st1.SERIEBACC);
	strcpy(bac[i].SERIEBACC,st1.SERIEBACC);

	do
	{
		gotoxy(1,14);SetColor(15);printf(">MOYENNE AU BACC: ");SetColor(10);
		fgets(valeur,10,stdin);
		if((strcmp(type_of(valeur),"float")==0) || (strcmp(type_of(valeur),"int")==0))
		{
			sscanf(valeur,"%f%s",&st1.MOYENNE,go);
			if(sscanf(valeur,"%f%s",&st1.MOYENNE,go)==1)
			{
				if(st1.MOYENNE<10 || st1.MOYENNE>20)
				{
					SetColor(12);
					gotoxy(50,13);printf("MOYENNE INVALID!");
					sleep(1);
					SetColor(15);
					gotoxy(50,13);printf("                ");
					gotoxy(1,14);printf(">MOYENNE BACC:           ");
				}
				else
					break;
			}
			else if(strcmp(go,"")!=0)
			{
				SetColor(12);
				gotoxy(50,13);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL!");
				sleep(1);
				SetColor(15);
				gotoxy(50,13);printf("                                                 ");
				gotoxy(1,14);printf(">MOYENNE BACC:           ");
			}
			
		}
		else
		{
			SetColor(12);
			gotoxy(50,13);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL!");
			sleep(1);
			SetColor(15);
			gotoxy(50,13);printf("                                                 ");
			gotoxy(1,14);printf(">MOYENNE BACC:           ");
		}
		
	}while(True);
	bac[i].MOYENNE=st1.MOYENNE;

	do
	{
		gotoxy(1,16);SetColor(15);printf("NOTE MATHEMATIQUE: ");SetColor(10);
		fgets(valeur,10,stdin);
		if((strcmp(type_of(valeur),"float")==0) || (strcmp(type_of(valeur),"int")==0))
		{
			sscanf(valeur,"%f%s",&st1.NOTEMATH,go);
			if(sscanf(valeur,"%f%s",&st1.NOTEMATH,go)==1)
			{
				if(st1.NOTEMATH>20 || st1.NOTEMATH<0)
				{
					SetColor(12);
					gotoxy(50,13);printf("NOTE MATHEMATIQUE INVALID!");
					sleep(1);
					SetColor(15);
					gotoxy(50,13);printf("                 ");
					gotoxy(1,9);printf("NOTE MATHEMATIQUE:             ");
				}
				else
					break;
			}
			else if(strcmp(go,"")!=0)
			{
				SetColor(12);
				gotoxy(50,13);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL!");
				sleep(1);
				SetColor(15);
				gotoxy(50,13);printf("                                                  ");
				gotoxy(1,9);printf("NOTE MATHEMATIQUE:             ");
			}
		}
		else
		{
			SetColor(12);
			gotoxy(50,13);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL!");
			sleep(1);
			SetColor(15);
			gotoxy(50,13);printf("                                                   ");
			gotoxy(1,9);printf("NOTE MATHEMATIQUE:             ");
		}
		
	}while(True);
	bac[i].NOTEMATH=st1.NOTEMATH;
	do
	{
		gotoxy(1,18);SetColor(15);printf("NOTE PHYSIQUE : ");SetColor(10);
		fgets(valeur,10,stdin);
		if((strcmp(type_of(valeur),"float")==0) || (strcmp(type_of(valeur),"int")==0))
		{
			sscanf(valeur,"%f%s",&st1.NOTEPHY,go);
			if(sscanf(valeur,"%f%s",&st1.NOTEPHY,go)==1)
			{
				if(st1.NOTEPHY<0 || st1.NOTEPHY>20)
				{
					SetColor(12);
					gotoxy(50,13);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL!");
					sleep(1);
					SetColor(15);
					gotoxy(50,13);printf("                                                  ");
					gotoxy(1,18);printf("NOTE PHYSIQUE:                 ");
				}
				else
					break;
			}
			else
			{
				SetColor(12);
				gotoxy(50,13);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL!");
				sleep(1);
				SetColor(15);
				gotoxy(50,13);printf("                                                   ");
				gotoxy(1,18);printf("NOTE PHYSIQUE:                 ");
			}
			
		}
		else
		{
			SetColor(12);
			gotoxy(50,13);printf("ENTRER UNIQUEMENT UN ENTIER OU UN NOMBRE DECIMAL!");
			sleep(1);
			SetColor(15);
			gotoxy(50,13);printf("                                                  ");
			gotoxy(1,18);printf("NOTE PHYSIQUE:                 ");
		}
		
	}while(True);
	bac[i].NOTEPHY=st1.NOTEPHY;
	netoyer(FICBACC);
	fp=fopen(FICBACC,"a+");
	if(fp!=NULL)
	{
		for (i = 0; i < n; i++)
		{
			fprintf(fp,"%s ; %.2f ; %s ; %.2f ; %.2f\n",bac[i].NCIN,bac[i].MOYENNE,bac[i].SERIEBACC,bac[i].NOTEMATH,bac[i].NOTEPHY);
		}
		fclose(fp);
	}
	else
	{
		SetColor(12);
		fprintf(stderr,"Erreur d'ouverture du fichier %s\n",FICCAN);
		SetColor(15);
	}
	
	SetColor(10);gotoxy(10,27);printf("Modification Terminer avec Succes!");
	SetColor(15);gotoxy(10,30);printf("Appuyer un boutton pour aller au menu");
	getch();
}

void modifier_info()
{
	//qui permet de modifier les information d'un candidat apparti de sont NCIN
	char resp,ncin[Max_chain_character];
	do
	{
		/*
		*dans ce menu de modifier d'autre option on ete ajouter pour faciliter 
		*la modification pas que si je veux modiier par example le choix 
		*d'un candidat je suis obliger de 
		*/
		clrscr();
		SetColor(11);
	 gotoxy(10,2);printf(" _________________________________________");
	 gotoxy(10,3);printf("|                                         |");
	 gotoxy(10,4);printf("|             MENU MODIFIER               |");
	 gotoxy(10,5);printf("|                                         |");
	 gotoxy(10,6);printf("|  1.Corriger candidat      5.Bacc        |");
	 gotoxy(10,7);printf("|                                         |");
	 gotoxy(10,8);printf("|  2.MODIFIER CHOIX 2       6.NCIN        |");
	 gotoxy(10,9);printf("|                                         |");
    gotoxy(10,10);printf("|  3.MODIFIER CHOIX 3       7.Retour      |");
	gotoxy(10,11);printf("|                                         |");
	gotoxy(10,12);printf("|  4.Candidat                             |");
	gotoxy(10,13);printf("|                                         |");
	gotoxy(10,14);printf("| Entre votre choix :___                  |");//33
	gotoxy(10,15);printf("|_________________________________________|");
	gotoxy(32,14);resp=getch();
	switch(resp)
	{
		case '1':
			clrscr();
			gotoxy(10,5);printf("Entre Le NCIN du candidat que vous voulez modifier : ");scanf("%s",ncin);
			modifier(ncin);
			break;
		case '2':
			clrscr();
			modif_choix_2();//modidfier choix 2 te permet de modifier directement le deuxiemme choix
			break;
		case '3':
			clrscr();
			modif_choix_3();//modidfier choix 3 te permet de modifier directement le troisiemme choix
			break;
		case '4':
			clrscr();
			modifier_cadidat();
			break;
		case '5':
			clrscr();
			modifier_bacc();
			break;
		case '6':
			clrscr();
			SetColor(14);
			gotoxy(5,5);printf(">>Entre Le NCIN que vous voulez Modifier : ");SetColorAndBackground(15,0);scanf("%s",ncin);
			MoDiF_NcIn(ncin);
	}
    }while(resp!='7');
}

void afficher()
{
	//qui permet d'affichier les candidat dans le fichier candidat.txt quand j'appuis le boutton A du clavier
	Candidat st1[Max];
	int ci;
	recuperer_candidat(st1,&ci);
	int i;
	char b='B';
	SetColorAndBackground(0,15);
	
	gotoxy(30,0);printf("CANDIDATS ENREGISTRE ");SetColor(15);
	SetColorAndBackground(0,0);SetColor(15);
	gotoxy(0,2);printf("N");SetColor(14);
	gotoxy(6,2);printf("NCIN");SetColor(11);
	gotoxy(34-5,2);printf("NOM");SetColor(11);
	gotoxy(64-5,2);printf("PRENOM");SetColor(8);
	gotoxy(94-10,2);printf("AGE");
	SetColor(10);
	//printf("N°\t\tNCIN\t\tNOM\t\tPRENOM\t\tAGE\n");
	for(i=0;i<ci;i++)
	{
		SetColor(15);
		gotoxy(0,4+i);printf("%d",i+1);SetColor(14);
		gotoxy(6,4+i);printf("%s",st1[i].NCIN);SetColor(11);
		gotoxy(34-5,4+i);printf("%s",st1[i].NOM);SetColor(11);
		gotoxy(64-5,4+i);printf("%s",st1[i].PRENOM);SetColor(8);
		gotoxy(94-10,4+i);printf("%d",st1[i].AGE);
		//printf("%d .>%s\t\t%s\t\t%s\t\t%d\n",i,st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
	}
	getch();
}

void participant()
{
	//fonction participant qui permet d'affichier ceux qui on concu le projet
	gotoxy(32,3);printf("PROGRAMMEUR");
	SetColor(15);
	gotoxy(10,4);printf("NOM :TOMDIEU IVAN");SetColor(10);printf("**");SetColor(15);
	gotoxy(10,6);printf("MATRICULE : XXXXXXX");
	gotoxy(10,8);printf("NIVEAU : L1");
	getch();
}

void statistiques(RESU dec[Max])
{
	//statique qui permet d'affichier les statistique de selection
	int i,n=0;
	recuperer_resultat(dec,&n);
	float infs;
	float math=0,phy=0,chm=0,info=0,bios=0,geos=0,ict=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(dec[i].decision,"INFORMATIQUE")==0)
		{
			info+=1;
		}
		else if(strcmp(dec[i].decision,"MATHEMATIQUE")==0)
		{
			math+=1;
		}
		else if(strcmp(dec[i].decision,"PHYSIQUE")==0)
		{
			phy+=1;
		}
		else if(strcmp(dec[i].decision,"BIO_SCIENCE")==0)
		{
			bios+=1;
		}
		else if(strcmp(dec[i].decision,"GEO_SCIENCE")==0)
		{
			geos+=1;
		}
		else if(strcmp(dec[i].decision,"CHIMIE")==0)
		{
			chm+=1;
		}
		else if(strcmp(dec[i].decision,"ICT")==0)
		{
			ict+=1;
		}
	}
	/*201 205 187
	186 205 186
	200 205 188*/
	gotoxy(3,1);printf("%c",201);
	for(i=4;i<50;i++)
	{
		gotoxy(i,1);printf("%c",205);
		gotoxy(i,19);printf("%c",205);
	}
	gotoxy(50,1);printf("%c",187);
	for(i=2;i<19;i++)
	{
		gotoxy(3,i);printf("%c",186);
		gotoxy(50,i);printf("%c",186);
	}
	gotoxy(3,19);printf("%c",200);
	gotoxy(50,19);printf("%c",188);
	SetColor(10);
	gotoxy(15,2);printf("STATISTIQUE DES SELECTION \n");
	SetColor(7);
	gotoxy(9,4);printf("POURCENTAGE DES CANDIDATS ADMIS EN :");
	SetColor(15);
	gotoxy(5,6);printf("FILIERE INFORMATIQUE  : ");SetColor(14);printf("%.2f%c",(info/n)*100,'%');SetColor(15);
	gotoxy(5,8);printf("FILIERE MATHEMATIQUE  : ");SetColor(14);printf("%.2f%c",(math/n)*100,'%');SetColor(15);
	gotoxy(5,10);printf("FILIERE PHYSIQUE      : ");SetColor(14);printf("%.2f%c",(phy/n)*100,'%');SetColor(15);
	gotoxy(5,12);printf("FILIERE BIO SCIENCE   : ");SetColor(14);printf("%.2f%c",(bios/n)*100,'%');SetColor(15);
	gotoxy(5,14);printf("FILIERE GEO SCIENCE   : ");SetColor(14);printf("%.2f%c",(geos/n)*100,'%');SetColor(15);
	gotoxy(5,16);printf("FILIERE CHIMIE        : ");SetColor(14);printf("%.2f%c",(chm/n)*100,'%');SetColor(15);
	gotoxy(5,18);printf("FILIERE ICT           : ");SetColor(14);printf("%.2f%c",(ict/n)*100,'%');SetColor(15);
	getch();
}

void selection()
{
	//fonction selection qui permet de cree le different fichier
	RESU st1[Max];
	int i,n;
	recuperer_resultat(st1,&n);
	FILE *fp;
	fp=fopen(FICMATH,"w");
	if(fp!=NULL)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(st1[i].decision,"MATHEMATIQUE")==0)
			{
				fprintf(fp,"%s ; %s ; %s ; %d\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
			}
		}
		fclose(fp);
	}
	fp=fopen(FICPHY,"w");
	if(fp!=NULL)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(st1[i].decision,"PHYSIQUE")==0)
			{
				fprintf(fp,"%s ; %s ; %s ; %d\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
			}
		}
		fclose(fp);
	}
	fp=fopen(FICCHM,"w");
	if(fp!=NULL)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(st1[i].decision,"CHIMIE")==0)
			{
				fprintf(fp,"%s ; %s ; %s ; %d\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
			}
		}
		fclose(fp);
	}
	fp=fopen(FICBIOS,"w");
	if(fp!=NULL)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(st1[i].decision,"BIO_SCIENCE")==0)
			{
				fprintf(fp,"%s ; %s ; %s ; %d\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
			}
		}
		fclose(fp);
	}
	fp=fopen(FICGEOS,"w");
	if(fp!=NULL)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(st1[i].decision,"GEO_SCIENCE")==0)
			{
				fprintf(fp,"%s ; %s ; %s ; %d\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
			}
		}
		fclose(fp);
	}
	fp=fopen(FICICT,"w");
	if(fp!=NULL)
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(st1[i].decision,"ICT")==0)
			{
				fprintf(fp,"%s ; %s ; %s ; %d\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
			}
		}
		fclose(fp);
	}
}

void recuperer_les_candidat_dans_le_fichier(char *filename,Candidat st1[Max],int *n)
{
	FILE *fp;
	Candidat c;
	int i=0;
	fp=fopen(filename,"r");
	if(fp!=NULL)
	{
		while(fscanf(fp,"%s ; %s ; %s ; %d",c.NCIN,c.NOM,c.PRENOM,&c.AGE)!=EOF)
		{
			st1[i]=c;
			i++;
			if(i==Max) break;
		}
		fclose(fp);
		*n=i;
	}
	else
		printf("Erreur Souvenu l'ors del'ouverture du fichier %s!",filename);
}

void affiche_filiere()
{
	//cette fonction appelle la fonction selection et afficher les differante fillier sur l'ecran
	selection();
	Candidat math[Max],bios[Max],chimie[Max],phy[Max],geos[Max],ict[Max],info[Max];
	int m,b,c,p,g,ic,in;
	recuperer_les_candidat_dans_le_fichier(FICMATH,math,&m);
	recuperer_les_candidat_dans_le_fichier(FICBIOS,bios,&b);
	recuperer_les_candidat_dans_le_fichier(FICCHM,chimie,&c);
	recuperer_les_candidat_dans_le_fichier(FICPHY,phy,&p);
	recuperer_les_candidat_dans_le_fichier(FICGEOS,geos,&g);
	recuperer_les_candidat_dans_le_fichier(FICICT,ict,&ic);
	recuperer_les_candidat_dans_le_fichier(FICADMIS,info,&in);
	int i;
	/*
	*	ici je vais mettre une sorte de defilement avec clavier 
	*	pour pouvoir voir les candidat par filier et eviter de
	*	faire que l'ecran devient empeut salle(dirty) 
	*   donc quand l'utilisateur va appuier la direction gauche 
	*	du clavier ons va balance a une autre filier 
	*	et la meme chose pour la direction droit du clavier
	*	et pour pouvoir revenir au clavier il va simplement appuyer 
	*	la touche(bouton) echape 
	*	pour cella je vais definir mes touche
	*	fleche gauche = 75
	*	fleche droit = 77
	*	touche echape =27 quand il va appuyer sur sa sa va sortie de la boucle
	*	donc break
	*	pour pouvoir fait tout cela je vait utiliser un do{}while
	*/
	//la variable dir du type char me permet de detecter un evenement sur le clavier
	char dir;
	//la variable niveau me permet d'afficher une fillier particuliere
	int niveau=1;
	//Exit=1 permetant a la boub=cle de repeter
	int Exit=1;
	do
	{
		system("cls");
		/*ici on va regarder si niveau=1 on affiche mathematique ,niveau=2 on affiche physique
		* niveau =3 on affiche ict ,niveau=4 aff.. chimie ,niveau =5 aff..bios,niveau =6 aff..geos
		*/
		gotoxy(0,0);SetColor(10);printf("FILIERE %d/7",niveau);
		if(niveau==1)//qui correspond a chimie
		{
			clrscr();
			gotoxy(0,0);SetColor(10);printf("FILIERE %d/7",niveau);SetColor(11);
			gotoxy(40,0);printf("FILIERE MATHEMATIQUE");SetColor(15);
			gotoxy(0,2);printf("N");SetColor(10);
			gotoxy(6,2);printf("NCIN");
			gotoxy(34-5,2);printf("NOM");
			gotoxy(64-5,2);printf("PRENOM");SetColor(8);
			gotoxy(94-10,2);printf("AGE");
			for(i=0;i<m;i++)
			{SetColor(14);
				gotoxy(0,4+i);printf("%d",i+1);SetColor(10);
				gotoxy(6,4+i);printf("%s",math[i].NCIN);
				gotoxy(34-5,4+i);printf("%s",math[i].NOM);
				gotoxy(64-5,4+i);printf("%s",math[i].PRENOM);SetColor(8);
				gotoxy(94-10,4+i);printf("%d",math[i].AGE);
			}
		}
		if(niveau==2)//qui correspond a physique
		{
			clrscr();
			gotoxy(0,0);SetColor(10);printf("FILIERE %d/7",niveau);SetColor(11);
			gotoxy(40,0);printf("FILIERE PHYSIQUE");SetColor(15);
			gotoxy(0,2);printf("N");SetColor(10);
			gotoxy(6,2);printf("NCIN");
			gotoxy(34-5,2);printf("NOM");
			gotoxy(64-5,2);printf("PRENOM");SetColor(8);
			gotoxy(94-10,2);printf("AGE");
			for(i=0;i<p;i++)
			{SetColor(14);
				gotoxy(0,4+i);printf("%d",i+1);SetColor(10);
				gotoxy(6,4+i);printf("%s",phy[i].NCIN);
				gotoxy(34-5,4+i);printf("%s",phy[i].NOM);
				gotoxy(64-5,4+i);printf("%s",phy[i].PRENOM);SetColor(8);
				gotoxy(94-10,4+i);printf("%d",phy[i].AGE);
			}
		}
		if(niveau==3)//qui correspond a ict
		{
			clrscr();SetColor(10);gotoxy(0,0);printf("FILIERE %d/7",niveau);SetColor(11);
			gotoxy(40,0);printf("FILIERE ICT");SetColor(15);
			gotoxy(0,2);printf("N");SetColor(10);
			gotoxy(6,2);printf("NCIN");
			gotoxy(34-5,2);printf("NOM");
			gotoxy(64-5,2);printf("PRENOM");SetColor(8);
			gotoxy(94-10,2);printf("AGE");
			for(i=0;i<ic;i++)
			{SetColor(14);
				gotoxy(0,4+i);printf("%d",i+1);SetColor(10);
				gotoxy(6,4+i);printf("%s",ict[i].NCIN);
				gotoxy(34-5,4+i);printf("%s",ict[i].NOM);
				gotoxy(64-5,4+i);printf("%s",ict[i].PRENOM);SetColor(8);
				gotoxy(94-10,4+i);printf("%d",ict[i].AGE);
			}
		}
		if(niveau==4)
		{
			clrscr();gotoxy(0,0);SetColor(10);printf("FILIERE %d/7",niveau);SetColor(11);
			gotoxy(40,0);printf("FILIERE CHIMIE");SetColor(15);
			gotoxy(0,2);printf("N");SetColor(10);
			gotoxy(6,2);printf("NCIN");
			gotoxy(34-5,2);printf("NOM");
			gotoxy(64-5,2);printf("PRENOM");SetColor(8);
			gotoxy(94-10,2);printf("AGE");
			for(i=0;i<c;i++)
			{SetColor(14);
				gotoxy(0,4+i);printf("%d",i+1);
				gotoxy(6,4+i);printf("%s",chimie[i].NCIN);SetColor(10);
				gotoxy(34-5,4+i);printf("%s",chimie[i].NOM);
				gotoxy(64-5,4+i);printf("%s",chimie[i].PRENOM);SetColor(8);
				gotoxy(94-10,4+i);printf("%d",chimie[i].AGE);
			}
		}
		if(niveau==5)
		{
			clrscr();
			gotoxy(0,0);SetColor(10);printf("FILIERE %d/7",niveau);SetColor(11);
			gotoxy(40,0);printf("FILIERE BIO SCIENCE");SetColor(8);
			gotoxy(0,2);printf("N");SetColor(15);
			gotoxy(6,2);printf("NCIN");
			gotoxy(34-5,2);printf("NOM");
			gotoxy(64-5,2);printf("PRENOM");SetColor(8);
			gotoxy(94-10,2);printf("AGE");
			for(i=0;i<b;i++)
			{SetColor(14);
				gotoxy(0,4+i);printf("%d",i+1);SetColor(10);
				gotoxy(6,4+i);printf("%s",bios[i].NCIN);
				gotoxy(34-5,4+i);printf("%s",bios[i].NOM);
				gotoxy(64-5,4+i);printf("%s",bios[i].PRENOM);SetColor(8);
				gotoxy(94-10,4+i);printf("%d",bios[i].AGE);
			}
		}
		if(niveau==6)
		{
			clrscr();gotoxy(0,0);SetColor(10);printf("FILIERE %d/7",niveau);SetColor(11);
			gotoxy(40,0);printf("FILIERE GEO SCIENCE");SetColor(15);
			gotoxy(0,2);printf("N");SetColor(10);
			gotoxy(6,2);printf("NCIN");
			gotoxy(34-5,2);printf("NOM");
			gotoxy(64-5,2);printf("PRENOM");SetColor(8);
			gotoxy(94-10,2);printf("AGE");
			for(i=0;i<g;i++)
			{SetColor(14);
				gotoxy(0,4+i);printf("%d",i+1);SetColor(10);
				gotoxy(6,4+i);printf("%s",geos[i].NCIN);
				gotoxy(34-5,4+i);printf("%s",geos[i].NOM);
				gotoxy(64-5,4+i);printf("%s",geos[i].PRENOM);SetColor(8);
				gotoxy(94-10,4+i);printf("%d",geos[i].AGE);
			}
		}
		if(niveau==7)
		{
			clrscr();gotoxy(0,0);SetColor(10);printf("FILIERE %d/7",niveau);SetColor(11);
			gotoxy(40,0);printf("FILIERE INFORMATIQUE");SetColor(15);
			gotoxy(0,2);printf("N");SetColor(10);
			gotoxy(6,2);printf("NCIN");
			gotoxy(34-5,2);printf("NOM");
			gotoxy(64-5,2);printf("PRENOM");SetColor(8);
			gotoxy(94-10,2);printf("AGE");
			for(i=0;i<in;i++)
			{SetColor(14);
				gotoxy(0,4+i);printf("%d",i+1);SetColor(10);
				gotoxy(6,4+i);printf("%s",info[i].NCIN);
				gotoxy(34-5,4+i);printf("%s",info[i].NOM);
				gotoxy(64-5,4+i);printf("%s",info[i].PRENOM);SetColor(8);
				gotoxy(94-10,4+i);printf("%d",info[i].AGE);
			}
		}
		SetColor(3);printf("\n\n\t\tPour Voir La Filiere Suivante appuyer la fleche ->(%c)\n\t\t  pour la Filiere precedent appuyer la fleche <-(%c)\n\t\t\tPour aller au menu appuyer Echap :",26,27);dir=getch();
		if(LEFT==dir)
		{
			if(niveau==1)
			{
				niveau=1;
			}
			else
			{
				niveau-=1;
			}
		}
		if(RIGHT==dir)
		{
			if(niveau==7)
			{
				niveau=7;
			}
			else
			{
				niveau+=1;
			}
		}
		if(ESCAPE==dir)
		{
			Exit=0;
		}
		
	}while(Exit==1);
	
}

void voir_les_statistique()
{	//cette fonction appelle la fonction statistiques
	RESU Tab[Max];
	statistiques(Tab);
}

void Supprimer()
{
	clrscr();
	//cete fonction supprime tous les candidat agee de plus de 20 ans dans le fichier admis.txt
	//si je veut supprimer les candidat age de plus de 20 ans rapidement j'appelle resultat et amis dans supprimer
	clrscr();
	if((!is_empty(FICRESU)) && is_empty(FICADMIS))
	{
		SetColor(12);
		gotoxy(10,5);printf("Le Fichier %s est vide veilliez selectioner l'option 5 puis resseyer!",FICADMIS);
		getch();return;
	}
	Candidat st1[Max],st2[Max];
	//st2=(Candidat*)malloc(Max*sizeof(Candidat));
	int i,n,c=0;
	recuperer_admis(st1,&n);
	//netoyer(FICADMIS);
	FILE *fp;
	netoyer(FICADMIS);
	Bool active=True;
	fp=fopen(FICADMIS,"a+");
	SetColor(11);gotoxy(35,0);printf("LISTE DEFINITIVE DES ADMIS");
	SetColor(10);gotoxy(0,2);printf("N");
	gotoxy(6,2);printf("NCIN");
	gotoxy(34-5,2);printf("NOM");
	gotoxy(64-5,2);printf("PRENOM");
	gotoxy(94-10,2);printf("AGE");
	SetColor(15);
	if(fp!=NULL)
	{
		for(i=0;i<n;i++)
		{
			/*
			*ici l'inverse de > et <= donc si je veut retirer le candidatat age de plus de 20 ans
			* c'est la même chos comme ecrire dans le fichier les etudiant inferieur ou egale a 20 ans
			*/
			if(st1[i].AGE<=20)
			{
				fprintf(fp,"%s ; %s ; %s ; %d\n",st1[i].NCIN,st1[i].NOM,st1[i].PRENOM,st1[i].AGE);
				strcpy(st2[i].NCIN,st1[i].NCIN);
				strcpy(st2[i].NOM,st1[i].NOM);
				strcpy(st2[i].PRENOM,st1[i].PRENOM);
				st2[i].AGE=st1[i].AGE;
				c++;
				/*gotoxy(0,4+c);printf("%d",i+1);
				gotoxy(6,4+c);printf("%s",st2[i].NCIN);
				gotoxy(34-5,4+c);printf("%s",st2[i].NOM);
				gotoxy(64-5,4+c);printf("%s",st2[i].PRENOM);
				gotoxy(94-10,4+c);printf("%d",st2[i].AGE);*/
			}

		}
		fclose(fp);
		recuperer_les_candidat_dans_le_fichier(FICADMIS,st2,&c);
		for(i=0;i<c;i++)
		{
			gotoxy(0,4+i);printf("%d",i+1);
			gotoxy(6,4+i);printf("%s",st2[i].NCIN);
			gotoxy(34-5,4+i);printf("%s",st2[i].NOM);
			gotoxy(64-5,4+i);printf("%s",st2[i].PRENOM);
			gotoxy(94-10,4+i);printf("%d",st2[i].AGE);
		}
    
    }
    else
	{
		printf("Erreur d'ouverture du fichier %s ",FICADMIS);
	}
	getch();
}

void loading_en_etoil()
{
	int i;
	for(i=0;i<2;i++)
	{
		SetColor(15);
		system("cls");
		gotoxy(45,3);printf("Loading");
		gotoxy(48,7);printf(".");sleep(rand()%2);SetColor(14);
		gotoxy(50,8);printf(".");sleep(rand()%2);SetColor(13);
		gotoxy(50,9);printf(".");sleep(rand()%2);SetColor(12);
		gotoxy(48,10);printf(".");sleep(rand()%2);SetColor(11);
		gotoxy(46,9);printf(".");sleep(rand()%2);SetColor(11);
		gotoxy(46,8);printf(".");sleep(rand()%2);SetColor(9);
		
	}
	SetColor(10);
	gotoxy(26,27);printf("Wait some few seconds we are preparing some modules");
	sleep(3);
	SetColor(14);
	gotoxy(38,29);printf("Appuyer Entrer");getch();
}

void decor()
{
	/*
	* cette fonction me permet de mettre un chargement au demarage du programme
	* dans le chargement je vait implementer un autre comme ceci
						   * *
	--------------->	  *	  *
						   * *
	et l'autre chargement serai comme ceci Loading...

	et un autre comme ca
			|||||||||||||||||||||||||||||||||||
	----->   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> %qui afficherai une progration
			|||||||||||||||||||||||||||||||||||

	*/
	/*
	* here i will randomise number from 1 to 3 
	* if the result is 1 the loading will be loading_en_etoil
	* if the result is 2 the loading will be . . . .
	* if the result is 3 the loading will >>>>>> 
	*/
	srand((unsigned)time(NULL));
	int result=0;
	result=rand()%3+1;
	if(result==2)
	{
		SetColor(11);
		gotoxy(20,30);printf("Loading");
		int i,j;
		for(i=0;i<2;i++)
		{
			SetColor(11);
			gotoxy(20,30);printf("Loading              ");
			for(j=0;j<3;j++)
			{
				SetColor(10);
				gotoxy(27+j,30);printf(".");
				sleep(rand()%2);
			}
		}
		SetColor(10);
		gotoxy(20,32);printf("Wait some few seconds we are preparing some modules");
		sleep(3);
		SetColor(14);
		gotoxy(21,34);printf("Appuyer Entrer");getch();
	}

	if(result==1)
	{
		loading_en_etoil();
	}
	if(result==3)
	{
		gotoxy(30,20);printf("Loading");SetColor(10);
	 	gotoxy(25,22);printf("---------------------");		 
		gotoxy(25,24);printf("---------------------");
	 	int n=25;
	 	int i;
	 	for(i=25;i<45;i++)
	 	{
	 		gotoxy(n,23);SetColorAndBackground(3,11);printf(">");sleep(rand()%2);
	 		n=n+1;
		}
		SetColor(10);
		SetColorAndBackground(10,0);
		gotoxy(20,27);printf("Wait some few seconds we are preparing some modules");
		sleep(3);
		SetColor(14);
		gotoxy(21,29);printf("Appuyer Entrer");getch();
	}
}
void vider_menu()
{
	/*Cette fonction a ete cree pour aider l'utilisateur a netoyer les fichier
	*	candiat ,bacc,choix, resultat et admis
	* et comme je ne veut pas que l'utilsateur netoy le contenu par hazard 
	* je vait ajouter un mot de passe intelligent
	*/
	char mot_de_pass[6],c;//mot_de_pass qui sera admin j'ai mis sa taille 6 parce que le dernier character c'est '\0'
	int i=0,go=1;
	SetColor(15);
	gotoxy(3,5);printf("Entre Le mot de pass Administrateur");SetColor(14);printf("(pour aller au menu principal entre");SetColor(10);printf("->quit) : ");
	SetColor(15);
	do
	{
		
		c=getch();
		mot_de_pass[i]=c;
		//et je vais aussi faire ensort que sa affiche les '*'
		printf("*");
		i+=1;
		if(i>=4 && (strcmp(mot_de_pass,"quit")==0) || (strcmp(mot_de_pass,"exit")==0))
		{
			return;
		}
		else if( i>=4 && strcmp(mot_de_pass,"1031")==0)
		{
			clrscr();			
			char g;
			do
			{
				SetColor(11);
				/*	
				*	218 196 191
				*	179		179
				*	192	196	217
				*/	
				gotoxy(10,2);printf(" ______________________________");
				gotoxy(10,3);printf("|      Vider Fichier           |");
				gotoxy(10,4);printf("|                              |");
				gotoxy(10,5);printf("| 1-Candidat     2-Bacc        |");
				gotoxy(10,6);printf("|                              |");
				gotoxy(10,7);printf("| 3-Choix        4-Resultat    |");
				gotoxy(10,8);printf("|                              |");
				gotoxy(10,9);printf("| 5-Admis        6-Retour      |");
				gotoxy(10,10);printf("|                              |");
				gotoxy(10,11);printf("|Entre votre choix:___         |");
				gotoxy(10,12);printf("|______________________________|");
				gotoxy(30,11);g=getch();
				switch(g)
				{
					case '1':
						netoyer(FICCAN);SetColor(10);gotoxy(10,15);printf("Le Fichier %s a ete renitialiser avec Succes! ",FICCAN);sleep(1);clrscr();
						break;
					case '2':netoyer(FICBACC);SetColor(10);gotoxy(10,15);printf("Le Fichier %s a ete renitialiser avec Succes! ",FICBACC);sleep(1);clrscr();
						break;
					case '3':netoyer(FICCHOIX);SetColor(10);gotoxy(10,15);printf("Le Fichier %s a ete renitialiser avec Succes! ",FICCHOIX);sleep(1);clrscr();
						break;
					case '4':netoyer(FICRESU);SetColor(10);gotoxy(10,15);printf("Le Fichier %s a ete renitialiser avec Succes! ",FICRESU);sleep(1);clrscr();
						break;
					case '5':netoyer(FICADMIS);SetColor(10);gotoxy(10,15);printf("Le Fichier %s a ete renitialiser avec Succes ! ",FICADMIS);sleep(1);clrscr();
						break;
					case '6':return;
				}
			}while(True);
		}
		
		else if(i>=4 )
		{
			SetColor(12);
			gotoxy(10,7);printf("Mot de pass incorrect ");
			sleep(1);
			gotoxy(10,7);printf("                                ");
			SetColor(15);
			clrscr();
			gotoxy(5,5);printf("Entre Le mot de pass Administrateur(pour aller au menu entre ->quit) :        ");
			strcpy(mot_de_pass,"");
			i=0;
			gotoxy(3,5);printf("Entre Le mot de pass Administrateur");SetColor(14);printf("(pour aller au menu principal entre");SetColor(10);printf("->quit1) : ");
			sleep(1);
		}
	}while(go);
	
}
void draw_box()
{
	int i;
	gotoxy(10,2);printf("%c",201);
	gotoxy(10,34);printf("%c",200);
	for(i=11;i<69;i++)
	{
		SetColor(11);
		gotoxy(i,2);printf("%c",205);
		SetColor(14);
		gotoxy(i,34);printf("%c",205);
	}
	gotoxy(68,2);printf("%c",187);
	gotoxy(10,3);printf("%c",186);
	gotoxy(10,34);printf("%c",200);
	gotoxy(68,34);printf("%c",188);
	for(i=3;i<34;i++)
	{
		SetColor(14);
		gotoxy(10,i);printf("%c",186);
		SetColor(11);
		gotoxy(68,i);printf("%c",186);
	}
	


	gotoxy(60,60);
}

#define PASSWORD "TP 1031"//mot de passe pour entre dans le programme


void Tp()//cette fonction permet de mettre TP 1031 sur l'ecran
{
	int i;
		for(i=5;i<35;i++)
		{
			SetColorAndBackground(0,10);gotoxy(i,5);printf(" ");
		}
		for(i=5;i<30;i++)
		{
			SetColorAndBackground(0,11);gotoxy(18,i);printf(" ");
		}
		for(i=30;i>12;i--)
		{
			SetColorAndBackground(0,14);gotoxy(25,i);printf(" ");
		}
		for(i=25;i<38;i++)
		{
			SetColorAndBackground(0,7);gotoxy(i,12);printf(" ");
		}
		for(i=12;i<20;i++)
		{
			SetColorAndBackground(0,7);gotoxy(38,i);printf(" ");
		}
		for(i=38;i>25;i--)
		{
			SetColorAndBackground(0,14);gotoxy(i,20);printf(" ");
		}
		SetColorAndBackground(0,10);gotoxy(40,10);printf(" ");
		for(i=40;i<=50;i++)
		{
			SetColorAndBackground(0,10);gotoxy(i,9);printf(" ");
		}
		for(i=6;i<30;i++)
		{
			SetColorAndBackground(0,14);gotoxy(50,i);printf(" ");
		}
		SetColorAndBackground(0,14);gotoxy(55,29);printf(" ");
		for(i=55;i>=45;i--)
		{
			SetColorAndBackground(0,11);gotoxy(i,30);printf(" ");
		}
		SetColorAndBackground(0,11);gotoxy(45,29);printf(" ");
		//////////////////////////////////////////////////
		for(i=58;i<=70;i++)
		{
			SetColorAndBackground(0,14);gotoxy(i,30);printf(" ");
			SetColorAndBackground(0,10);gotoxy(i,5);printf(" ");
		}
		/////////////////////////////////////////////////
		for(i=6;i<30;i++)
		{
			SetColorAndBackground(0,14);gotoxy(58,i);printf(" ");
			SetColorAndBackground(0,10);gotoxy(70,i);printf(" ");
		}
		//////////////////////////////////////////////////
		for(i=75;i<85;i++)
		{
			SetColorAndBackground(0,12);gotoxy(i,30),printf(" ");
			SetColorAndBackground(0,18);gotoxy(i,5);printf(" ");
			SetColorAndBackground(0,20);gotoxy(i,18);printf(" ");
		}
		///////////////////////////////////////////////////////
		for(i=5;i<=30;i++)
		{
			SetColorAndBackground(0,8);gotoxy(85,i);printf(" ");
		}
		/***************************************************/
		SetColorAndBackground(0,10);gotoxy(90,10);printf(" ");
		for(i=90;i<=100;i++)
		{
			SetColorAndBackground(0,10);gotoxy(i,9);printf(" ");
		}
		for(i=6;i<30;i++)
		{
			SetColorAndBackground(0,14);gotoxy(100,i);printf(" ");
		}
		SetColorAndBackground(0,14);gotoxy(105,29);printf(" ");
		for(i=105;i>=95;i--)
		{
			SetColorAndBackground(0,11);gotoxy(i,30);printf(" ");
		}
		SetColorAndBackground(0,11);gotoxy(95,29);printf(" ");
		for(i=20;i<70;i++)
		{
			SetColorAndBackground(0,14);gotoxy(i,35);printf(" ");
			SetColorAndBackground(0,15);gotoxy(i,40);printf(" ");
		}
		for(i=35;i<=40;i++)
		{
			SetColorAndBackground(0,14);gotoxy(20,i);printf(" ");
			SetColorAndBackground(0,15);gotoxy(70,i);printf(" ");
		}
}
void acceuill()
{
	/*
	*	cette fontion me permetra de faire un acceuilelors de l'ouverture du programme
	*/
	/*201 205 187
	186 205 186
	200 205 188*/
	int i,j=0;
	char r,pass[8];SetColorAndBackground(15,0);
	clrscr();
	Tp();gotoxy(23,38);printf("Entre Le Mot de Passe : ");
	do
	{
		SetColorAndBackground(15,0);
		r=getch();
		pass[j]=r;
		printf("*");
		strupr(pass);
		j++;
		if((strcmp(pass,PASSWORD)==0) && j>=7)
		{
			gotoxy(25,45);SetColor(10);
			break;
		}
		else if(j>=7 && (strcmp(pass,PASSWORD)!=0))
		{
			gotoxy(25,50);SetColor(12);
			printf("Mot de pass InCorrect");sleep(1);
			gotoxy(25,50);
			printf("                         ");
			SetColor(15);
			gotoxy(23,38);printf("Entre Le Mot de Passe :                      ");
			gotoxy(23,38);printf("Entre Le Mot de Passe : ");
			j=0;
			strcpy(pass,"");
		}
	}while(True);

}
/*
*	cette fonction me permet d'afficher l'aide
*	si je fait cette fonction ces parceque j'ai remarquer que dans tous application 
*	il ya toujour une aide 
*/
void aide()
{
	/*201 205 187
	186 205 186
	200 205 188*/
	
	 gotoxy(10,2);printf(" _________________________________________________________");
	 gotoxy(10,3);printf("|                                                         |");
	 gotoxy(10,4);printf("|                         AIDE                            |");	 SetColor(11);
	 gotoxy(10,5);printf("|                                                         |");
	 SetColorAndBackground(10,0);
	 gotoxy(10,6);printf("|   1.Pour Ajouter les Candidat selectioner l'option 1    |");
	 gotoxy(10,7);printf("|                                                         |");SetColorAndBackground(10,0);
	 gotoxy(10,8);printf("|   2.Pour Modifier les information d'un Candidat         |");
	 gotoxy(10,9);printf("|     Selectionner l'option 2                             |");
	gotoxy(10,10);printf("|                                                         |");
	gotoxy(10,11);printf("|   3.Pour Supprimer un Candidat Selectionner l'option 3  |");
	gotoxy(10,12);printf("|                                                         |");
	gotoxy(10,13);printf("|     puis entre le NCIN du Candidat|");
	gotoxy(10,14);printf("|                                                         |");SetColorAndBackground(11,0);
	gotoxy(10,15);printf("|   4.Pour cr%ce le fichier resultat selectioner l'option 4|",130);
	gotoxy(10,16);printf("|                                                         |");//130=é en asci
	gotoxy(10,17);printf("|     puis les resultat s'affichera                       |");//130=é en asci
	gotoxy(10,18);printf("|                                                         |");
	gotoxy(10,19);printf("|   7.Pour Afficher les Candidats admis en INFORMATIQUE   |");
	gotoxy(10,20);printf("|                                                         |");
	gotoxy(10,21);printf("|     Selectionner l'option 5                             |");
	gotoxy(10,22);printf("|                                                         |");
	gotoxy(10,23);printf("|   9.Pour Afficher les statistiques Selectionner         |");
	gotoxy(10,24);printf("|                                                         |");
	gotoxy(10,25);printf("|     l'option 6                                          |");
	gotoxy(10,26);printf("|                                                         |");
	gotoxy(10,27);printf("|   10.Pour Supprimer les Candidats agees de plus de 20ans|");
	gotoxy(10,28);printf("|                                                         |");SetColor(14);
	gotoxy(10,29);printf("|     dans le fichier admis.txt pour la list final        |");
	gotoxy(10,30);printf("|                                                         |");SetColor(14);
	gotoxy(10,31);printf("|   11.Pour afficher les Candidats pas fillier c'est      |");
	gotoxy(10,32);printf("|                                                         |");SetColor(14);
	gotoxy(10,33);printf("|     l'option 8                                     '    |");SetColor(14);
	gotoxy(10,34);printf("|_________________________________________________________|");draw_box();
	gotoxy(12,37);SetColor(10);printf("Appuyer une touche pour appeller au menu principal");
	getch();
	                                 
}


#endif

//version 25.9 (la 25 eme fois que je modifie et augmente le fonction)

/*
*	Pour obtenir ce que tu n'as jamais eu ,
*	Tu dois faire ce que tu n'as jamais fait
*	Navi -->IVAN 
*/
