#include <iostream>
using namespace std;

int main() {
	int arr[10];

	cout << "Unsorted: " << endl;
	for (int i = 0; i <10;i++) {   //initialisation
		arr[i] = 10 - i;
		cout << arr[i]<<" " ;
	}cout << endl;

	for (int i = 0; i < 10;i++) {   //10 times, we will have 10 rounds of checking adjacent pairs. 1 round for each number
		for (int j = 0; j < 9 - i;j++) { //9-i, we can check 9 total adjacent pairs and i because largest number sorts and goes to right afer every round
			if (arr[j]>arr[j+1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << "Sorted:	" << endl;
	for (int i = 0; i < 10;i++) {
		cout << arr[i]<<" ";
	}cout << endl;
	return 0;
}