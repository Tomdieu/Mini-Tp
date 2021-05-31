#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#ifndef __TYPE_H_
#define __TYPE_H_
#define N 100
/*
*	si j'ai cree cette fonction c'est pour que le programme ne tourne pas dans une boucle infini
*	quand l'utilisateur entre un character au lieu d'un entier ou un float 
*/
/*
* Et j'ai remarque que cette fonction a un problem 
* m'est l'avantage c'est que ca n'entre pas dans ubne boucle infini  
* si par example j'entre 36d ca vas prendre ca comme un entier et prendre la partie entier 
* qui est 36
* m'est d36 serait un string donc chain de character
*/
char *type_of(char *value)
{
	double temp;
	int n;
	char str[N]="",s[N]="";
	double val=1e-12;//0.0000000000001
	if(sscanf(value,"%lf%s",&temp,s))
	{
		if(strcmp(s,"")==0)
		{
			n=(int)temp;
			/*here , using BODMAS ;
			we can see that the integer part of temp is first divided by temp before removing temm from it */
			if(fabs(temp-n)/temp>val)
			{
				return (char*)"float";
			}
			else
			{
				return (char*)"int";
			}
		}
		else
		{
			return (char*)"string";
		}
	}
	//here , if asssigning value to string is successfull it returns 1 but here all data types can be contain in a string
	else if(sscanf(value, "%s",str)==1)
	{
		return (char*)"string";
	}
	else
	{
		return (char*)"Not_a_type";
	}
}

void sizeofscreen()
{
	//              height=   width=
	//                 v        v
	system("mode con LINES=60 COLS=120");
}
#endif
