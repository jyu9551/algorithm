#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICLES 10
#define INF 100000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICLES][MAX_VERTICLES];

} GraphType;

int A[MAX_VERTICLES][MAX_VERTICLES];

void printA(GraphType* g)
{
	int i, j;
	printf("===================\n");
	for (i = 0; i < g->n; i++)
	{
		for (j = 0; j < g->n; j++)
		{
			if (A[i][j] == INF)
				printf(" * ");
			else
				printf("%3d ", A[i][j]);
		}
		printf("\n");

	}
	printf("===================\n");
}

void floyd(GraphType* g)
{
	int i, j, k;

	for (i = 0; i < g->n; i++)
	{
		for (j = 0; j < g->n; j++)
		{
			A[i][j] = g->weight[i][j];
		}
	}
		printA(g);

	for (k = 0; k < g->n; k++)
	{
		for (i = 0; i < g->n; i++)
		{
			for (j = 0; j < g->n; j++)
			{
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
			}
		}
		printA(g);
	}

}

int main()
{
	GraphType g = { 10,
		{{ 0, 5, 6, INF, INF, INF, INF, INF, 7, 14 },
		{ 5, 0, 5, 4, INF, INF, INF, INF, INF, INF },
		{ 6, 5, 0, 3, 10, 11, INF, INF, INF, 5 },
		{ INF, 4, 3, 0, 6, INF, INF, INF, INF, INF },
		{ INF, INF, 10, 6, 0, 8, INF, INF, INF, INF },
		{ INF, INF, 11, INF, 8, 0, 7, INF, INF, 6 },
		{ INF, INF, INF, INF, INF, 7, 0, 3, INF, 4 },
		{ INF, INF, INF, INF, INF, INF, 3, 0, 8, INF},
		{ 7, INF, INF, INF, INF, INF, INF, 8, INF ,15},
		{ 14, INF, 5, INF, INF, 6, 4, INF, 15, 0}}
	};
	floyd(&g);

	return 0;
}

