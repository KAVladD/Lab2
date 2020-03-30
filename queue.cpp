#include "stdafx.h"
#include <conio.h>
#include <clocale>
#include <string>
#pragma warning (disable:4996)

struct sp{char fam[20];int gr;sp *p;};

//������� �����
void input(sp *first)
{
	puts("������� �������� � ��� ������");
	scanf("%s%d",first->fam,&first->gr);
	int k;sp *f, *ff; ff=first;
	while(1)
	{
		puts("����� ������ ������ �������� ������� 1, ����� 0");
		scanf("%d",&k);
		if(k==0) break;
		f=new sp;
		puts("������� �������� � ��� ������");
		scanf("%s %d",f->fam,&f->gr);
		ff->p=f;
		ff=f;
	}
	ff->p=NULL;
}
//������� ������
void output(sp *f)
{
	int k = 0;
	while(f)
	{
		k++;
		printf("%d->%d\n",f,f->p);
		printf("������� %s ������ %d\n",f->fam,f->gr);
		f=f->p;
	}
	if (k == 0)puts("������ ����");
}

//������� ���-�� �� ������
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

//������� ������ �� ������� 
int fa(sp *f, char s[20])
{
	while(f)
	{
		if(strcmp(f->fam,s)==0) return f->gr;
		f=f->p;
	}
	puts("�������� � ����� �������� ���");
}

//������� �������� �� ������
void del(sp *f,int n)
{
	for(int i=1;i<n-1;i++) f=f->p;
	sp *ff;
	ff=f->p;
	f->p=ff->p;
	delete ff;
}

//������� ���������� ����� ������
void in(sp *f, int n)
{
	for(int i=1;i<n;i++) f=f->p;
	sp *ff;
	ff=new sp;
	puts("������� �������� � ��� ������");
	scanf("%s%d",ff->fam,&ff->gr);
	ff->p=f->p;
	f->p=ff;
}

//������� �������� �� ������
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

//������� ���������� �� ������
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

	//����
	while(1)
	{
		puts("\n0.�����\n1.���-�� ��������� � ������\n2.����� ������ �������� �� �������\n3.������� �� ������ � ������\n4.�������� �������� ����� ������� �� ������\n5.������� ���� ��������� �� ������ ������");
		int x;
		scanf("%d",&x);
		if(x==0) break;
		else if(x==1)
		{
			puts("������� ����� ������");
			int g;
			scanf("%d",&g);
			printf("���-�� ��������� � ������ %d ����� %d",g,gr(first,g));
		}
		else if(x==2)
		{
			puts("\n������� ������� ��������");
			char s[20];
			scanf("%s",s);
			printf("����� ������ %d �������� %s",fa(first,s),s);
		}
		else if(x==3)
		{
			puts("\n������� ����� �������� �� ������, �������� ���������� �������");
			scanf("%d",&n);
			del(first,n);
			output(first);
		}
		else if(x==4)
		{
			puts("\n������� ����� ��������, ����� �������� ����� �������� ������");
			scanf("%d",&n);
			in(first,n);
			output(first);
		}
		else if(x==5)
		{
			puts("������� ����� ������ ��� �������� ��������");
			scanf("%d",&n);
			first=dell(first,n);
			output(first);
		}
		else if (x == 6)
		{
			puts("������� ����� ������");
			scanf("%d", &n);
			ingr(first, n);
			output(first);
		}
	}

	getch();
	return 0;
}

