#include "code.h"
#include <string.h>
#include <stdio.h>

void init(char * tab, int taille, char value) {
	int i=0;
	for (i=0;i<taille;i++){
		tab[i]=value;
	}
	tab[i]='\0';
}

void inverser(char * tab){
	int taille=0;
	while (tab[taille]!='\0'){
		taille++;
	}
	int i=0;
	char tabinv[50];
	for (i=0;i<taille;i++){
		tabinv[i]=tab[taille-i-1];
	}
	tabinv[i]='\0';
	strcpy(tab,tabinv);
}

int conversionb2d(const char * tab){
	int dec=0;
	if (tab[0]!='\0'){
		int i=1;
		int bit;
		if (tab[0]=='0'){bit=0;}else{bit=1;}
		dec = bit;
		while (tab[i]!='\0'){
			if (tab[i]=='0'){bit=0;}else{bit=1;}
			dec=dec*2+bit;
			i++;
		}
	}

	return dec;
}

void conversiond2b(int nb, char * tab){
	if (nb!=0){
		int i=0;
		char bit;
		while (nb!=0){
			if (nb%2==0){bit='0';}else{bit='1';}
			tab[i]=bit;
			i++;
			nb=nb/2;
		}
		tab[i]='\0';
	}
	else{
		tab[0]='0';
		tab[1]='\0';
	}
	inverser(tab);
}


char * addition(char *r, char *a, char * b) {
	int add=conversionb2d(a)+conversionb2d(b);
	conversiond2b(add,r);
    return r;
}	

