#include <iostream>
using namespace std;
											//Insertion sort(divide the numbers into sorted and unsorted portion, taking 1st element in the sorted region)
int main() {

	int arr[10];

	for (int i = 0; i < 10;i++) {       // Initialisation
		arr[i] = 10 - i;
		cout << arr[i] << " ";
	}cout << endl;

	for (int i = 1; i < 10;i++) {		   // we are starting from the 1 because 0 is already in the sorted portion
		int temp = arr[i];
		int j = i;								//after every iteration the value of j will change so securing the orignal j taken
		while (j > 0 && arr[j-1]>arr[j]) {   //we ha ve already gone through j-1 so at j=1 j-1=0 0 has been already considered
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;             
			j = j - 1;							// now our j is at j-1 position so taking the same element and checking through the while loop again
		}
	}

	for (int i = 0; i < 10;i++) {					//Printing
		cout << arr[i] << " ";
	}cout << endl;

	return 0;
}