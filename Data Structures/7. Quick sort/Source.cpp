#include <iostream>
using namespace std;
												// QUICK SORT
void swap(int* a,int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[],int l,int r) {        //used for making a partition where all the numbers that are left of pivot are smaller than pivot and right numbers are larger
	int i = l - 1;
	
	for (int j = l; j <= r - 1;j++) {
		if (arr[r]>arr[j]) {
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return i + 1;                              //returning the pivots final position after partitioning, pivot is the partitioner
}

void quicksort(int arr[],int l,int r) {
	if (l<r) {
		int pi = partition(arr,l,r);
		quicksort(arr,l,pi-1);
		quicksort(arr, pi + 1, r);
	}
}

int main() {
	int arr[10];
	for (int i = 0; i < 10;i++) {
		arr[i] = 10 - i;
		cout << arr[i] << " ";
	}cout << endl;
	quicksort(arr,0,9);
	for (int i = 0; i < 10;i++) {
		cout << arr[i] << " ";
	}cout << endl;
	return 0;
}