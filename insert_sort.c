#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )


void insert_sort(int list[], int n);

int main()
{
	int my_list[10] = {0, };
	int i;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		my_list[i] = rand() % 100;
	}

	// before sorted
	printf("before\n");

	for (i = 0; i < 10; i++)
	{
		printf("%d\t", my_list[i]);
	}
	printf("\n");

	// after sorted
	insert_sort(my_list, 10);

	printf("after\n");

	for (i = 0; i < 10; i++)
	{
		printf("%d\t", my_list[i]);
	}

	return 0;

}

void insert_sort(int list[], int n)
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		key = list[i];

		for ( j = i-1; j >= 0 && key < list[j]; j--)
		{
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}

}
