#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICLES 10
#define INF 100000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICLES][MAX_VERTICLES];
		
} GraphType;

int distance[MAX_VERTICLES];
int found[MAX_VERTICLES];

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;		
		}
	}
	return minpos;
}

void print_status(GraphType* g)
{
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++)
	{
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%3d", distance[i]);
	}
	printf("\n");
	printf("found: ");
	for (int i = 0; i < g->n; i++)
	{
		printf("%2d ", found[i]);
	}
	printf("\n\n");
}

void shortest_path(GraphType* g, int start)
{
	int i, u, w;

	for (i = 0; i < g->n; i++)
	{
		distance[i] = g->weight[start][i];
		found[i] = 0;
	}
	found[start] = 1;
	distance[start] = 0;

	for (i = 0; i < g->n; i++)
	{
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = 1;
		for (w = 0; w < g->n; w++)
		{
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
		}
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
	shortest_path(&g, 0);
	return 0;
}

