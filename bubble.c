// 알고리즘 과제1 problem 7
// 0부터 1000 사이의 랜덤 값을 20개 받아 버블정렬하라.


#include<stdio.h>
#include<stdlib.h>
#include<time.h>		// random값 위해 <time.h> 헤더파일 작성 -> 시간을 random값으로 

#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )	// swap 함수를 define
#define list_size 20	

void bubble_sort(int list[], int n);	// size n인 list 받아 bubble sort

int main()
{
	int my_list[list_size] = { 0, };
	int i;

	srand(time(NULL));		// time을 seed로 하는 랜덤값 부르기

	for (i = 0; i < list_size; i++)
	{
		my_list[i] = rand() % 1001;		// rand() % 1001 => 0~1000 사이 랜덤값 
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
