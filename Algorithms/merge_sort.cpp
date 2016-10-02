//Implementation of Merge-sort

#include <iostream>
 
using namespace std;

void merge (int*, int, int, int);	//Prototype of function used to merge two sorted array

void mergesort (int *A, int l, int r)
{
	if (l < r)						//Check if we need to split the array more
	{
		int mid = l + (r-l)/2;		//using l + (r-l)/2 instead of (l+r)/2 because this ensures that the sum l+r never goes beyond the capacity of int
		/*
			*recursively splitting the array into two arrays, 
			*each of the length half of the original and then 
			*merging two sorted arrays such that the merged 
			*array remains sorted.
			*Array splitting happens till the array left is of unit length
			*Array containing only one element is always sorted
		*/
		mergesort (A, l, mid);
		mergesort (A, mid+1, r);
		merge (A, l, mid, r);
	}
}

void merge (int* A, int l, int m, int r)		//Merges two sorted arrays into a single array
{
	int *C = new int [r-l+1], i = 0, j = l, k = m+1;
	//Ensuring that we don't continue checking once the index of any particular array goes out of bound
	while (j <= m && k <= r)
		C[i++] = (A[j] < A[k] ? A[j++] : A[k++]);
	while (j <= m)
		C[i++] = A[j++];
	while (k <= r)
		C[i++] = A[k++];
	for (int i = 0, j = l; j <= r; i++, j++)
		A[j] = C[i];
	delete [] C;
}

int main ()
{
	int N;
	cin >> N;
	int *A = new int [N];				//Creates a test case and checks
	for (int i = 0; i < N; i++)			//and verifies if the program
		cin >> A[i];
	mergesort (A, 0, N-1);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	delete []A;
	return 0;
}