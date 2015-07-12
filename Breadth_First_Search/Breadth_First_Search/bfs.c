#include<stdio.h>
#include<conio.h>

char que[20];
int front = 0, rear = 0, n;
char arr[20];
int bfs(int);
char ajMat[20][20];
char b[20];
void display();
int p = 0;

#define false 0
#define true 1

void display()
{
	printf("BFS of Graph : ");
	for (int i = 0; i<n; i++)
		printf("%c ", arr[i]);
}

void insert(char val)
{
	que[front] = val;
	front++;
}

char del()
{
	rear = rear + 1;
	return que[rear - 1];
}

char unVisit(char val)
{
	for (int i = 0; i<front; i++)
	{
		if (val == que[i])
			return false;
	}
	return true;
}

int bfs(int i)
{
	char m;
	if (front == 0)
	{
		insert(b[i]);
	}
	for (int j = 0; j<n; j++)
	{
		if (ajMat[i][j] == '1')
		{
			if (unVisit(b[j]))
			{
				insert(b[j]);
			}
		}
	}
	m = del();
	arr[p] = m;
	p++;
	return 0;
}


int main()
{
	char v;
	freopen("sample_input.txt", "r", stdin);
	printf("Enter the number of nodes in a graph");
	scanf("%d ", &n);
	printf("Enter the value of node of graph");
	for (int i = 0; i<n; i++)
	{
		scanf("%c ", &b[i]);
	}

	//printf("Enter the value in adjancency matrix in from of 'y' or 'n'\n");
	//printf("If there exits an edge between two vertices than 'y' otherwise 'n'\n");
	for (int i = 0; i<n; i++)
		printf("%c ", b[i]);
	for (int i = 0; i<n; i++)
	{
		printf("\n%c ", b[i]);
		for (int j = 0; j<n; j++)
		{
			//printf("%c ", v = getch());
			scanf("%c ", &ajMat[i][j]);			
		}
		printf("\n\n");
	}
	for (int i = 0; i<n; i++)
		bfs(i);

	display();
	getch();
}
