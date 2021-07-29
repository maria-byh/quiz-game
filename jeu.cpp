#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	char joueur1[20], joueur2[20];
	char t1[100],mot1[10],mot2[10];
	char t3[100], t2[100];
	int temp[100], solu1, solu2;
	int a,n,i,j,j1=0,j2=0;
	int x=100,y=100,z=100;
	FILE *f;
	FILE *g;
	FILE *s;
	f= fopen("premièrepartie.txt","r");
	g= fopen("deuxièmepartie.txt","r");
	s= fopen("solutions.txt","r");
	printf("************bienvenue chers joueurs************\n");
	printf("==>donnez le nom du premier joueur:");
	scanf(" %s",&joueur1);
	printf("==>donnez le nom du deuxieme joueur:");
	scanf(" %s",&joueur2);
	printf("==>choisissez le niveau du jeu:\n--1 Simple--\n--2 Moyen--\n--3 Difficile--\n");
	scanf("%d",&a);
	if(a==1){
		n=10;
	}
	else if (a==2){
		n=20;
	}
	else {
		n=40;
	}
	for (i=1;i<=n;i++){
		printf("\nround %d:\n",i);
		printf("\n*********partie une (lettres)*********\n");
		fgets(t1,x,f);
		printf(t1);
		printf("donnez les mots:\n");
		scanf("%s",&mot1);
		scanf("%s",&mot2);
		if (strlen(mot1)>strlen(mot2)) {
			j1=j1+1;
		}
		else if (strlen(mot1)<strlen(mot2)) {
			j2=j2+1;
		}
		printf("\n******partie deux (formules mathematiques)******\n");
		fgets(t2,y,g);
		printf(t2);
		printf("donnez la solution:\n");
		scanf("%d",&solu1);
		scanf("%d",&solu2);
		fgets(t3,z,s);
		temp[i] = atoi(t3);
		if (solu1==temp[i]) {
			j1=j1+1;
		}
		else if (solu2==temp[i]) {
			j2=j2+1;
		}
	}
	printf("*********le jeu est termine*********\n");
	printf("votre score finale est:\n==>%s :%d points\n==>%s :%d points\n",&joueur1,j1,&joueur2,j2);

	if (j1>j2){
		printf("alors le gagnant est: %s felicitation",&joueur1);
	}
	else if (j1<j2){
		printf("alors le gagnant est: %s felicitation",&joueur2);
	}
	else {
		printf("vous avez eu le meme score");
	}
	fclose(f);
	fclose(g);
	fclose(s);
	return 0;
} 
