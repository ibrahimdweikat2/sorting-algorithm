#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
	int i, j, minindex,x,y;
	for (i = 0;i < n - 1;i++) {
		minindex = i;
		for (j = i + 1;j < n;j++) {
			x = arr[j];y = arr[minindex];
			if (arr[j] < arr[minindex]) {
				minindex = j;
			}
		}
				swap(arr[i], arr[minindex]);
	}
}

int main()
{
	int x[6] = { 23,78,45,8,32,56 };
	SelectionSort(x, 6);
	int y;
	for (int i = 0;i < 6;i++) {
		y = x[i];
		cout << x[i] << " ";
	}
}

