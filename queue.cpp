#include "stdafx.h"
#include <conio.h>
#include <clocale>
#include <string>
#pragma warning (disable:4996)

struct sp{char fam[20];int gr;sp *p;};

//функция ввода
void input(sp *first)
{
	puts("Введите студента и его группу");
	scanf("%s%d",first->fam,&first->gr);
	int k;sp *f, *ff; ff=first;
	while(1)
	{
		puts("Чтобы ввести нового студента введите 1, иначе 0");
		scanf("%d",&k);
		if(k==0) break;
		f=new sp;
		puts("Введите студента и его группу");
		scanf("%s %d",f->fam,&f->gr);
		ff->p=f;
		ff=f;
	}
	ff->p=NULL;
}
//функция вывода
void output(sp *f)
{
	int k = 0;
	while(f)
	{
		k++;
		printf("%d->%d\n",f,f->p);
		printf("Студент %s группа %d\n",f->fam,f->gr);
		f=f->p;
	}
	if (k == 0)puts("Список пуст");
}

//функция кол-во по группе
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

//функция группы по фамилии 
int fa(sp *f, char s[20])
{
	while(f)
	{
		if(strcmp(f->fam,s)==0) return f->gr;
		f=f->p;
	}
	puts("Студента с такой фамилией нет");
}

//функция удаления по номеру
void del(sp *f,int n)
{
	for(int i=1;i<n-1;i++) f=f->p;
	sp *ff;
	ff=f->p;
	f->p=ff->p;
	delete ff;
}

//функция добавления после номера
void in(sp *f, int n)
{
	for(int i=1;i<n;i++) f=f->p;
	sp *ff;
	ff=new sp;
	puts("Введите студента и его группу");
	scanf("%s%d",ff->fam,&ff->gr);
	ff->p=f->p;
	f->p=ff;
}

//функция удаления по группе
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

//функция добавления по группе
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

	//меню
	while(1)
	{
		puts("\n0.Выход\n1.Кол-во студентов в группе\n2.Номер группы студента по фамилии\n3.Удалить по номеру в списке\n4.Вставить студента после нужного по номеру\n5.Удалить всех студентов по номеру группы");
		int x;
		scanf("%d",&x);
		if(x==0) break;
		else if(x==1)
		{
			puts("Введите номер группы");
			int g;
			scanf("%d",&g);
			printf("Кол-во студентов в группе %d равно %d",g,gr(first,g));
		}
		else if(x==2)
		{
			puts("\nВведите фамилию студента");
			char s[20];
			scanf("%s",s);
			printf("Номер группы %d студента %s",fa(first,s),s);
		}
		else if(x==3)
		{
			puts("\nВведите номер студента по списку, которого необходимо удалить");
			scanf("%d",&n);
			del(first,n);
			output(first);
		}
		else if(x==4)
		{
			puts("\nВведите номер студента, после которого нужно добавить нового");
			scanf("%d",&n);
			in(first,n);
			output(first);
		}
		else if(x==5)
		{
			puts("Введите номер группы для удаления студента");
			scanf("%d",&n);
			first=dell(first,n);
			output(first);
		}
		else if (x == 6)
		{
			puts("Введите номер группы");
			scanf("%d", &n);
			ingr(first, n);
			output(first);
		}
	}

	getch();
	return 0;
}

