#include <iostream>
#include <vector>


bool binarySearch(const std::vector<int>& arr, int find) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (find < arr[mid]) {
            right = mid - 1;
        }
        else if (find > arr[mid]) {
            left = mid + 1;
        }
        else return true;
    }
    return false;
}

bool binarySearchRecursive(const std::vector<int>& arr, int find, int left, int right) {
    int mid = (left + right) / 2;
    if (left > right) return false;
    else if (find < arr[mid]) return binarySearchRecursive(arr, find, left, mid - 1);
    else if (find > arr[mid]) return binarySearchRecursive(arr, find, mid + 1, right);
    else return true;
}

int main() {
    
}


