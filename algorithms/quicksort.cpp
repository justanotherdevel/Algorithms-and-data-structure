/*
	*Generic implementation of quicksort.
	*Avoid using this in favour of STLs sort().
	*Which is the implementation of quicksort in 
	*algorithnm library.
*/

//Check how templates work in function
//Also check if we can call a modular function from a modular function
#include <iostream>

using namespace std;

template <typename F>
void swap (F &l, F &r){
	F temp = l;
	l = r;
	r = temp;
}

template <typename T>
void quicksort (T* A, int l, int r){
	//Replacing first element with random element to avoid
	//worst case time complexity in case of already sorted array
	void swap (T &l, T &r){
	T temp = l;
	l = r;
	r = temp;
	}
	int replace = rand () % (r-l) + l;
	swap (A[l], A[replace]);
	int i = l, j = l+1;				//Initiating two pointers, one for keeping
	//a track of currenct check and another the last place where we swapped an element smaller than A[l]
	for (; j < r; j++){
		if (A[j] < A[l])
			swap (A[++i], A[j]);		//Swapping if element is smaller than left most element
	}
	swap (A[l], A[i]);			//Swapping to assure that the left array contains elementes smaller than former A[l]
	//And right array contains of elementes that's greater than it.
	quicksort (A, l, i);
	quicksort (A, i+1, r);
}

//Main function simply shows that the program is working.
//Remove main and incroporate the above program can be used anywhere
int main (){
	int N;
	cin >> N;
	int *A = new int [N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	quicksort<int>(A, 0, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << "\t";
	delete []A;
	return 0;
}