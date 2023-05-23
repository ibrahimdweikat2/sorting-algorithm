#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    int i, temp, j;
    for (i = 1;i < n;i++) {
        temp = arr[i];
        j = i - 1;
        for (;j >= 0 && arr[j] > temp;j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int x[8] = { 5,1,6,2,8,7,4,3 };
    InsertionSort(x, 8);
    for (int i = 0;i < 8;i++) {
        cout << x[i] << " ";
    }
}
