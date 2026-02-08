
#include <iostream>
#include <time.h>
using namespace std;

template<typename T>
void selectSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(arr[minIndex], arr[i]);
		}
	}
}

int main() {
	time_t start, end;
	int arr[] = { 5, 2, 9, 1, 8, 3 };
	start = clock();
	selectSort(arr, 6);
	end = clock();
	cout << (double)difftime(end, start) / CLOCKS_PER_SEC << endl;
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}
}


