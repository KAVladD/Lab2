// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <clocale>
#include <conio.h>
#include <string>
#pragma warning(disable:4996)

struct sp{char fam[20];int gr;int mark[3];};

void input(FILE *f,sp a[],int k,int *s)
{
	for(int i=0;i<k;i++)
	{
		fscanf(f,"%s",a[i].fam);
		fscanf(f,"%d",&a[i].gr);
		for(int j=0;j<3;j++)
		{
			fscanf(f,"%d",&a[i].mark[j]);
			s[i]+=a[i].mark[j];
		}
			
	}
}
void output(sp *a, int k)
{
	for(int i=0;i<k;i++)
	{
		printf("%s %d ",a[i].fam,a[i].gr);
		for(int j=0;j<3;j++)
			printf("%d ",a[i].mark[j]);
		puts("");
	}
}
int g(int *s, int k)
{
	int m=s[0];
	for(int i=0;i<k;i++)
		if(s[i]>m) m=s[i];
	return m;
}



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE,"");

	FILE *f;
	f=fopen("f.txt","r");

	if(f==NULL){puts("Файл отсутствует");getch();return 1;}

	int k=0;char s[1000];

	while(fgets(s,1000,f))k++;
	//printf("%d",k);


	sp *a;
	a = new sp [k];
	

	rewind(f);

	int *su;
	su=new int [k];
	for(int i=0;i<k;i++)su[i]=0;

	input(f,a,k,su);
	output(a,k);

	puts("Введите фамилию");
	scanf("%s",s);

	for(int i=0;i<k;i++)
	{
		if(strcmp(s,a[i].fam)==0)
		{
			printf("%d",a[i].gr);
			for(int j=0;j<3;j++)
				printf(" %d",a[i].mark[j]);
		}
	}

	//for(int i=0;i<k;i++) printf("%d ",su[i]);
	int max;
	max=g(su,k);

	puts("\nСтуденты с максимальной оценкой");
	for (int i = 0; i < k; i++)
	{
		if (su[i] == max)
			printf("%s ", a[i].fam);
	}
	

	getch();
	return 0;
}

