#include <iostream>
using namespace std;

void BubbleSort(int a[], int n) {
	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j < n - i - 1;j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int main() {
	int x[] = { 2,4,1,6,5,3,7,8 };
	int n = sizeof(x) / sizeof(x[0]);
	BubbleSort(x,n);
	for (int i = 0;i < 8;i++) {
		cout << x[i] << " ";
	}
	return 0;
}