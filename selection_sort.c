#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
#define size 9

void selectionsort(int list[], int n);


void selectionsort(int list[], int n)
{
	int i, j, tmp;
	int least;

	for (i = 0; i <= n - 2; i++)
	{
		least = i;

		for (j = i+1; j <= n-1; j++)
		{
			if (list[least] > list[j])
			{
				least = j;	
			}
		}
		SWAP(list[least], list[i], tmp);
	}

}


int main()
{
	int list[size] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };

	
	// before sorted
	printf("before sorted:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	// after selection sort
	selectionsort(list, size);

	printf("after sorting:\n");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", list[i]);
	}





	return 0;
}