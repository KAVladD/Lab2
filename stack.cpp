// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <clocale>
#include <conio.h>
#pragma warning(disable:4996)

struct st{double v; st *p;};

//������� �����
st *input()
{
	st *f,*ff;
	f=new st;
	f->p=NULL;
	puts("������� �������,��� �� ���������-�����");
	while(scanf("%lf",&f->v))
	{
		ff=new st;
		ff->p=f;
		f=ff;
		puts("������� �������,��� �� ���������-�����");
	}
	getchar();
	return f->p;
}
//������� ������
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
	if (k == 0) puts("������ ����");
}

//������� ���-�� ��-��� ������ ����.
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

//������� ���������� �� ������
void app(st *l, int x)
{
	for(int i=1;i<x;i++)l=l->p;
	st *f;
	f=new st;
	puts("������� �������");
	scanf("%lf",&f->v);
	f->p=l->p;
	l->p=f;
}
//������� ���������� �� ��������
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

//������� �������� �� ������
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
//������� �������� �� �������� 
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

	//����
	while (1)
	{
		puts("");
		puts("\n1.���-�� ��-��� ������ ��������� \n2.�������� �� ������ \n3.���������� ����� ������ \n4.�������� ���� �� �������� \n5.���������� ����� ���� �� �������� \n0.����� ������");
		scanf("%d", &x);
		if (x == 0)break;
		else if (x == 1)
		{
			puts("\n������� �����, ������ �������� ������ ���� ��������");
			scanf("%lf", &y);
			printf("���-�� ��-��� ������ %4.2lf ����� %d", y, kol(last,y));
		}
		else if (x == 2)
		{
			puts("\n������� ����� ��-��, ������� ����� �������");
			scanf("%d", &x);
			last=dell(last, x);
			output(last);
		}
		else if (x == 3)
		{
			puts("\n������� ����� ��-��, ����� �������� ����� �������� ��-��");
			scanf("%d", &x);
			app(last, x);
			output(last);
		}
		else if (x == 4)
		{
			puts("\n������� �������� ��-���, ������� ����� �������");
			scanf("%lf", &y);
			last=del(last, y);
			output(last);
		}
		else if (x == 5)
		{
			puts("������� �������� ��-���, ����� ������� ����� �������� ����� ��-��");
			scanf("%lf", &y);
			ap(last, y);
			output(last);
		}
	}

	getch();
	return 0;
}
