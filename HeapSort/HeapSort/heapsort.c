#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define NUM_ARRAY 20
int array[NUM_ARRAY];

void print_tree(int A[], int n){
	int i, j;
	int root=0;
	int depth = 0;
	int count = 0;

	/*caculate depth*/
	for (i = 0; i < NUM_ARRAY; i++)
	{
		//printf("%d ", array[i]);
		count++;

		if (count == (root>=1 ? 2<<(root-1):1)){
			//printf("\n");
			count = 0;
			root++;
		}
	}	
	depth = root;

	root = 0;
	count = 0;
	for (i = 0; i < NUM_ARRAY; i++)
	{
		for (j = 0; j < ((depth - root)+3)*2; j++)
			printf(".");
		printf("%3d", array[i]);
		//for (j = 0; j < (depth - root)+1; j++)
		//	printf("...");
		count++;

		if (count == (root >= 1 ? 2 << (root - 1) : 1)){
			printf("\n");
			count = 0;
			root++;
		}
	}
	printf("\n");
	printf("\n");
}

void swap(int *dest, int *src)
{
	int temp;
	temp = *src;
	*src = *dest;
	*dest = temp;
}
void rebuildHeap(int A[],int root,int n)
{
	int child = 2 * root + 1;
	if (child <= n){
		int rightchild = child + 1;

		/*Right child가 있고, Right Child보다 Left Child보다
		 코다면, child를 rightchild로 setting!*/
		if (rightchild <= n && A[rightchild] > A[child])
			child = rightchild;

		/*Root가 left_child(이미 걸러짐) 보다 작으면 교환 */
		if (A[root] < A[child]){
			swap(&A[root], &A[child]);
			/*교환후 child를 기준으로 다시 rebuild!*/
			rebuildHeap(A, child, n);//
		}
	}
}

void heapsort(int A[], int n)
{
	int root,last;
	for (root = (n - 1 - 1) / 2; root >= 0; root--)
		rebuildHeap(A, root, n);
	//print_tree(A, n);
	
	for (last = n - 1; last > 0; last--){
		swap(&A[last], &A[0]);
	
		rebuildHeap(A, 0, last -1);
		//print_tree(A, n);
	}
}

int main()
{
	int i;

	srand(time(NULL));

	for (i = 0; i < NUM_ARRAY; i++)
	{
		array[i] = rand() % 1000;
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");

	//print_tree(array, NUM_ARRAY);

	
	heapsort(array, NUM_ARRAY);


	for (i = 0; i < NUM_ARRAY; i++)
	{
		
		printf("%d ", array[i]);
	}

	printf("\n");



}