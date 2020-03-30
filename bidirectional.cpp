// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include <conio.h>
#pragma warning(disable:4996)

struct sp {
	char fam[30];
	int n;
	sp* next;
	sp* prev;
};

//функция ввода
sp* input(sp* first)
{
	sp* f,*ff;
	ff = first;
	int n;
	puts("Чтобы добавить элемент введите 1,чтобы закончить ввод введите 0");
	scanf("%d", &n);
	while (n)
	{
		f = new sp;
		puts("Введите элемент списка");
		scanf("%s%d", f->fam, &f->n);
		f->next = NULL;
		f->prev = ff;
		ff->next = f;
		ff = f;
		puts("Чтобы добавить элемент введите 1,чтобы закончить ввод введите 0");
		scanf("%d", &n);
	}
	return ff;
}
//функция вывода
void output(sp* f)
{
	int k = 0;
	while (f)
	{
		k++;
		printf("\n%d<-%d->%d", f->prev, f, f->next);
		printf("\n%s %d", f->fam, f->n);
		f = f->next;
	}
	if (k == 0) puts("Список пуст");
}

//функция номер по фамилии
void nu(sp* l,char f[30])
{
	int n = 0;
	puts("Номера студентов с введённой фамилией");
	while (l)
	{
		if (strcmp(l->fam, f) == 0)
		{
			printf("%4d", l->n);
			n++;
		}
		l = l->prev;
	}
	if (n == 0) puts("Студентов с такой фамилией нет");
}

//функция фамилии с "А"
int kol(sp* f)
{
	int k = 0;
	
	while (f)
	{
		if (f->fam[0] == 'A')k++;
		f = f->next;
	}
	return k;
}

//функция удаления чётных по стеку
sp* del(sp* l,sp*first)
{
	sp* f;
	while (l && l->prev != NULL)
	{
		f = l;
		f = f->prev;
		l->prev = f->prev;
		delete f;
		f = l->prev;
		if (f)
		{
			f->next = l;
			l = f;
		}
		first = l;
	}
	return first;
}


int main()
{
	setlocale(LC_CTYPE, "");

	sp* first,*last;
	first = new sp;
	first->next = NULL;
	first->prev = NULL;
	
	puts("Введите первый элемент списка");
	scanf("%s%d", first->fam, &first->n);
	
	last = input(first);
	output(first);

	int x;

	//меню
	while (1)
	{
		puts("\n1.Номер по введ. фамилии \n2.Кол-во студентов с фамилией на А \n3.Удаление чётных с конца \n0.Конец работы");
		scanf("%d", &x);
		if (x == 0) break;
		else if (x == 1)
		{
			puts("Введите фамилию");
			char s[30];
			scanf("%s", s);
			nu(last, s);
		}
		else if (x == 2)
		{
			printf("Кол-во студентов с фамилией на А равно %d", kol(first));
		}
		else if (x == 3)
		{
			first = del(last, first);
			output(first);
		}
	}

	getch();
	return 0;
}
