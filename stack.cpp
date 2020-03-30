// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <clocale>
#include <conio.h>
#pragma warning(disable:4996)

struct st{double v; st *p;};

//функция ввода
st *input()
{
	st *f,*ff;
	f=new st;
	f->p=NULL;
	puts("Введите элемент,что бы закончить-букву");
	while(scanf("%lf",&f->v))
	{
		ff=new st;
		ff->p=f;
		f=ff;
		puts("Введите элемент,что бы закончить-букву");
	}
	getchar();
	return f->p;
}
//функция вывода
void output(st *l)
{
	int k = 0;
	while(l)
	{
		k++;
		puts("");
		printf("%d->%d",l,l->p);
		printf("\n%d.%4.2lf",k,l->v);
		l=l->p;
	}
	if (k == 0) puts("Список пуст");
}

//функция кол-ва эл-тов больше введ.
int kol(st *l,double x)
{
	int k=0;
	while(l)
	{
		if(l->v>x)k++;
		l=l->p;
	}
	return k;
}

//функция добавления по номеру
void app(st *l, int x)
{
	for(int i=1;i<x;i++)l=l->p;
	st *f;
	f=new st;
	puts("Введите элемент");
	scanf("%lf",&f->v);
	f->p=l->p;
	l->p=f;
}
//функция добавления по значению
void ap(st *l, double x)
{
	while(l)
	{
		if(l->v==x)
		{ 
			app(l,1);
			l=l->p;
		}
		l=l->p;
	}
}

//функция удаления по номеру
st *dell(st *l, int x)
{
	st*ff=l;
	if(x==1)
	{
		ff=l->p;
		delete l;
		return ff;
	}
	for(int i=1;i<x-1;i++)l=l->p;
	st *f;
	f=l->p;
	l->p=f->p;
	delete f;
	return ff;
}
//функция удаления по значению 
st *del(st *l, double x)
{
	st*f=l,*ff;
	while (l)
	{
		if (l->v == x)
		{
			if (l == f)
			{
				l = dell(l, 1);
				f = l;
			}
		}
		else if (l->p!=NULL&&l->p->v == x)
		{
			ff = l;
			while (ff->p!=NULL&&ff->p->v==x)
			{
				l = l->p;
				ff->p = l->p;
				delete l;
				l = ff;
			}
		}
		else l = l->p;
	}
	return f;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE,"");

	st *last=NULL;

	last=input();
	output(last);

	int x;
	double y;

	//меню
	while (1)
	{
		puts("");
		puts("\n1.Кол-во эл-тов больше введённого \n2.Удаление по номеру \n3.Добавление после номера \n4.Удаление всех по значению \n5.Добавление после всех по значению \n0.Конец работы");
		scanf("%d", &x);
		if (x == 0)break;
		else if (x == 1)
		{
			puts("\nВведите число, больше которого должны быть элементы");
			scanf("%lf", &y);
			printf("Кол-во эл-тов больше %4.2lf равно %d", y, kol(last,y));
		}
		else if (x == 2)
		{
			puts("\nВведите номер эл-та, который нужно удалить");
			scanf("%d", &x);
			last=dell(last, x);
			output(last);
		}
		else if (x == 3)
		{
			puts("\nВведите номер эл-та, после которого нужно вставить эл-нт");
			scanf("%d", &x);
			app(last, x);
			output(last);
		}
		else if (x == 4)
		{
			puts("\nВведите значение эл-тов, которые нужно удалить");
			scanf("%lf", &y);
			last=del(last, y);
			output(last);
		}
		else if (x == 5)
		{
			puts("Введите значение эл-тов, после которых нужно вставить новые эл-ты");
			scanf("%lf", &y);
			ap(last, y);
			output(last);
		}
	}

	getch();
	return 0;
}
