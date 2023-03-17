#include<stdlib.h>
#include<stdio.h>

#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(int list[], int n);


int main(void)
{
	int list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };

	int i;

	// before sorted
	printf("before\n");

	for (i = 0; i < 9; i++)
	{
		printf("%d\t", list[i]);
	}
	printf("\n");

	// after sorted
	selection_sort(list, 9);

	printf("after\n");

	for (i = 0; i < 9; i++)
	{
		printf("%d\t", list[i]);
	}

	return 0;

}


void selection_sort(int list[], int n)
{
	int i, j, least, tmp;

	for (i = 0; i <= n - 2; i++) 
	{
		least = i;
		for (j = i + 1; j <= n-1; j++)
		{
			if (list[j] < list[least])
				least = j;
		}
		SWAP(list[i], list[least], tmp);
	}
}
