#include "stdafx.h"
#include <conio.h>
#include <clocale>
#include <string>
#pragma warning (disable:4996)

struct sp{char fam[20];int gr;sp *p;};

//ôóíêöèÿ ââîäà1
void input(sp *first)
{
	puts("Ââåäèòå ñòóäåíòà è åãî ãðóïïó");
	scanf("%s%d",first->fam,&first->gr);
	int k;sp *f, *ff; ff=first;
	while(1)
	{
		puts("×òîáû ââåñòè íîâîãî ñòóäåíòà ââåäèòå 1, èíà÷å 0");
		scanf("%d",&k);
		if(k==0) break;
		f=new sp;
		puts("Ââåäèòå ñòóäåíòà è åãî ãðóïïó");
		scanf("%s %d",f->fam,&f->gr);
		ff->p=f;
		ff=f;
	}
	ff->p=NULL;
}
//ôóíêöèÿ âûâîäà
void output(sp *f)
{
	int k = 0;
	while(f)
	{
		k++;
		printf("%d->%d\n",f,f->p);
		printf("Ñòóäåíò %s ãðóïïà %d\n",f->fam,f->gr);
		f=f->p;
	}
	if (k == 0)puts("Ñïèñîê ïóñò");
}

//ôóíêöèÿ êîë-âî ïî ãðóïïå
int gr(sp *f,int n)
{
	int k=0;
	while(f)
	{
		if(f->gr==n) k++;
		f=f->p;
	}
	return k;
}

//ôóíêöèÿ ãðóïïû ïî ôàìèëèè 
int fa(sp *f, char s[20])
{
	while(f)
	{
		if(strcmp(f->fam,s)==0) return f->gr;
		f=f->p;
	}
	puts("Ñòóäåíòà ñ òàêîé ôàìèëèåé íåò");
}

//ôóíêöèÿ óäàëåíèÿ ïî íîìåðó
void del(sp *f,int n)
{
	for(int i=1;i<n-1;i++) f=f->p;
	sp *ff;
	ff=f->p;
	f->p=ff->p;
	delete ff;
}

//ôóíêöèÿ äîáàâëåíèÿ ïîñëå íîìåðà
void in(sp *f, int n)
{
	for(int i=1;i<n;i++) f=f->p;
	sp *ff;
	ff=new sp;
	puts("Ââåäèòå ñòóäåíòà è åãî ãðóïïó");
	scanf("%s%d",ff->fam,&ff->gr);
	ff->p=f->p;
	f->p=ff;
}

//ôóíêöèÿ óäàëåíèÿ ïî ãðóïïå
sp * dell(sp *f,int n)
{
	sp *st,*ff=f;
	st=f;
	while(f)
	{
		if(f->gr != n) {st=f;f=f->p;}
		else
		{
			if(st==f)
			{
				f=f->p;
				ff=f;
				delete st;
				st=f;
			}
			else
			{
				st->p=f->p;
				delete f;
				f=st->p;
			}
		}
	}
	return ff;
}

//ôóíêöèÿ äîáàâëåíèÿ ïî ãðóïïå
void ingr(sp* f, int n)
{
	while(f)
	{
		if (n == f->gr) in(f, 1);
		f = f->p;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE,"");

	sp *first;
	first=new sp;
	input(first);
	output(first);

	int n;

	//ìåíþ
	while(1)
	{
		puts("\n0.Âûõîä\n1.Êîë-âî ñòóäåíòîâ â ãðóïïå\n2.Íîìåð ãðóïïû ñòóäåíòà ïî ôàìèëèè\n3.Óäàëèòü ïî íîìåðó â ñïèñêå\n4.Âñòàâèòü ñòóäåíòà ïîñëå íóæíîãî ïî íîìåðó\n5.Óäàëèòü âñåõ ñòóäåíòîâ ïî íîìåðó ãðóïïû");
		int x;
		scanf("%d",&x);
		if(x==0) break;
		else if(x==1)
		{
			puts("Ââåäèòå íîìåð ãðóïïû");
			int g;
			scanf("%d",&g);
			printf("Êîë-âî ñòóäåíòîâ â ãðóïïå %d ðàâíî %d",g,gr(first,g));
		}
		else if(x==2)
		{
			puts("\nÂâåäèòå ôàìèëèþ ñòóäåíòà");
			char s[20];
			scanf("%s",s);
			printf("Íîìåð ãðóïïû %d ñòóäåíòà %s",fa(first,s),s);
		}
		else if(x==3)
		{
			puts("\nÂâåäèòå íîìåð ñòóäåíòà ïî ñïèñêó, êîòîðîãî íåîáõîäèìî óäàëèòü");
			scanf("%d",&n);
			del(first,n);
			output(first);
		}
		else if(x==4)
		{
			puts("\nÂâåäèòå íîìåð ñòóäåíòà, ïîñëå êîòîðîãî íóæíî äîáàâèòü íîâîãî");
			scanf("%d",&n);
			in(first,n);
			output(first);
		}
		else if(x==5)
		{
			puts("Ââåäèòå íîìåð ãðóïïû äëÿ óäàëåíèÿ ñòóäåíòà");
			scanf("%d",&n);
			first=dell(first,n);
			output(first);
		}
		else if (x == 6)
		{
			puts("Ââåäèòå íîìåð ãðóïïû");
			scanf("%d", &n);
			ingr(first, n);
			output(first);
		}
	}

	getch();
	return 0;
}

