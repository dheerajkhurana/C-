#include <iostream>
using namespace std;
													//MERGE SORT
void mergesort(int arr[],int l,int r) {
	if (l<r) {
		int m = (l+r) / 2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		//------------------MERGING STARTS FROM HERE------------------
		int i = l, j = m + 1, k = l; int b[10];
		while (i<=m && j<=r) {
			if (arr[i]<arr[j]) {
				b[k++] = arr[i++];
			}
			else {
				b[k++] = arr[j++];
			}
		}
		while (i<=m) {
			b[k++] = arr[i++];
		}
		while (j <= r) {
			b[k++] = arr[j++];
		}
		for (int i = l; i <= r;i++) {
			arr[i] = b[i];
		}
	}
}

int main() {
	int arr[10];
	cout << "Numbers given:" << endl;
	for (int i = 0; i < 10;i++) {
		arr[i] = 10 - i;
		cout << arr[i] << " ";
	}cout << endl;
	mergesort(arr,0,9);
	cout << "After Merge sort: " << endl;
	for (int i = 0; i < 10;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}