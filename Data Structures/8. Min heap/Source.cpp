#include <iostream>
using namespace std;
										// MIN HEAP , Definition of min heap, root is the smallest number and parent is equal or smaller than the child node
void pushdown(int i,int n,int arr[]) {  //push parent down to find the correct value 
	int parent=arr[i];
	int parentindex = i;
	int child = 2 * i;

	while (child<=n) {
		if (child<n && arr[child]>arr[child+1]) {
			child++;    //because we are interested in the smaller value 
		}
		if (parent<=arr[child]) {
			break;
		}
		arr[parentindex] = arr[child];
		parentindex = child;
		child = 2 * parentindex;
	}
	arr[parentindex] = parent;
}

void buildheap(int arr[],int n) {
	for (int i = n / 2; i >= 1;i--) {
		pushdown(i,n,arr);
	}
}

int main() {
	int arr[11];
	for (int i = 1; i < 11;i++) {
		arr[i] = 11 - i;
	}
	buildheap(arr,10);
	for (int i = 1; i < 11;i++) {
		cout << arr[i] << " ";
	}cout << endl;
	return 0;
}