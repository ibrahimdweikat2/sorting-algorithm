#include <iostream>
using namespace std;
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low;j < high;j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	//Swap pivot
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void QuickSort(int arr[], int low, int high) {
	if (low < high) {

		int pi = partition(arr, low, high);

		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

void main() {
	int arr[] = { 10,20,5,1,40,6 };
	int high = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, high-1);
	for (int i = 0;i < high;i++) {
		cout << arr[i] << " ";
	}
}
