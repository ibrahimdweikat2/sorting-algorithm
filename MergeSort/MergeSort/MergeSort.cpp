#include <iostream>
using namespace std;

void merge(int arr[], int const left, int const mid, int const right) {
	//declare size of each subarray
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTow = right - mid;

	//declare temp array
	int* leftArray = new int[subArrayOne];
	int* rightArray = new int[subArrayTow];

	//fill temp array 
	for (int i = 0;i < subArrayOne;i++) {
		leftArray[i] = arr[left + i];
	}
	for (int i = 0;i < subArrayTow;i++) {
		rightArray[i] = arr[mid+1+i];
	}

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergeArray = left;
	//sort and merge of array
	while (indexOfSubArrayOne< subArrayOne && indexOfSubArrayTwo<subArrayTow)
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			arr[indexOfMergeArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			arr[indexOfMergeArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergeArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		arr[indexOfMergeArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergeArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTow) {
		arr[indexOfMergeArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergeArray++;
	}

	delete[] leftArray;
	delete[] rightArray;

}

void MergeSort(int arr[], int begin, int end) {
	if (begin >= end)
		return;

	auto mid = begin + (end - begin) / 2;
	MergeSort(arr, begin, mid);
	MergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}

void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

void main() {
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	MergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);

}