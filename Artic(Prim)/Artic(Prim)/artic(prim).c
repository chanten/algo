#include <stdio.h>
#include <math.h>
#define MAX_SPOT 1000
double cost[MAX_SPOT][MAX_SPOT];
#define LONGEST_DISTANCE 9999999999
int visited[MAX_SPOT];

struct spot{
	double x;
	double y;
}spots[MAX_SPOT];

int test_case;
int n;

int a, b, u, v;
double min;
double mincost;
double maxcost = 0;

int prim()
{
	int ne;
	int i, j;
	double tmp;

	ne = 0;
	a = b = u = v = 0;
	min = LONGEST_DISTANCE;
	mincost = 0;
	
	visited[0] = 1;
	maxcost = 0;
	while (ne < n-1){
		for (i = 0,min=LONGEST_DISTANCE; i < n; i++)
			for (j = 0; j < n; j++){
				if (cost[i][j] < min && visited[i] != 0){
					min = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}

			if (visited[u] == 0 || visited[v] == 0){
				//printf("\n Edge %d:(%d %d) cost:%lf", ne++, a, b, min);
				ne++;
				mincost += min;
				visited[b] = 1;
				if (min > maxcost)
					maxcost = min;
			}
			cost[a][b] = cost[b][a] = LONGEST_DISTANCE;
					
	}
	//printf("\n Minimun cost=%lf", mincost);

	//maxcost = 10.184;
	maxcost = sqrt(maxcost);
	tmp = maxcost + 0.005f;	
	printf("%.2lf\n", maxcost);	

}

int cacluate_cost()
{
	int i, j;
	float x_diff, y_diff;
	for (i = 0; i < n;i++)
		for (j = 0; j < n; j++){			
			x_diff = spots[i].x - spots[j].x;
			y_diff = spots[i].y - spots[j].y;
			cost[i][j] = pow(x_diff, 2)+ pow(y_diff, 2);
			
			if (cost[i][j] == 0)
				cost[i][j] = LONGEST_DISTANCE;
		}
}

int main()
{
	int i, j;
#ifdef WIN32
	freopen("gul.txt", "r", stdin);
#endif

	scanf("%d", &test_case);	

	for (i = 0; i < test_case; i++)
	{
		scanf("%d", &n);
		for (j = 0; j < n; j++){
			scanf("%lf %lf", &spots[j].x, &spots[j].y);
			visited[j] = 0;
		}
		cacluate_cost();
		prim();

	}

	
}