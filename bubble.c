// �˰��� ����1 problem 7
// 0���� 1000 ������ ���� ���� 20�� �޾� ���������϶�.


#include<stdio.h>
#include<stdlib.h>
#include<time.h>		// random�� ���� <time.h> ������� �ۼ� -> �ð��� random������ 

#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )	// swap �Լ��� define
#define list_size 20	

void bubble_sort(int list[], int n);	// size n�� list �޾� bubble sort

int main()
{
	int my_list[list_size] = { 0, };
	int i;

	srand(time(NULL));		// time�� seed�� �ϴ� ������ �θ���

	for (i = 0; i < list_size; i++)
	{
		my_list[i] = rand() % 1001;		// rand() % 1001 => 0~1000 ���� ������ 
	}

	// before sorted
	printf("before\n");

	for (i = 0; i < list_size; i++)
	{
		printf("%d ", my_list[i]);
	}
	printf("\n");

	// after sorted
	bubble_sort(my_list, list_size);

	printf("after\n");

	for (i = 0; i < list_size; i++)
	{
		printf("%d ", my_list[i]);
	}

	return 0;
}

void bubble_sort(int list[], int n)
{
	int i, j, tmp;

	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], tmp);
		}
	}
}
