#include <iostream>
#include <vector>

using namespace std;

void Adjust(vector<int>& arr, int len, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    int max_idx = index;
    // min_heap
    if (left < len && arr[left] < arr[max_idx]) {
        max_idx = left;
    }
    if (right < len && arr[right] < arr[max_idx]) {
        max_idx = right;
    }

    // max_heap
    // if (left < len && arr[left] > arr[max_idx]) {
    //     max_idx = left;
    // }
    // if (right < len && arr[right] > arr[max_idx]) {
    //     max_idx = right;
    // }

    if (max_idx != index) {
        swap(arr[max_idx], arr[index]);
        Adjust(arr, len, max_idx);
    }

}

void HeapSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; --i) {
        Adjust(arr, size, i);
    }

    for (int i = size - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        Adjust(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
    HeapSort(arr);
    for (int& ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}