#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Selection
// Find the smallest element and swap it with the first element. Repeat for the rest of the array.
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Bubble
// Repeatedly swap adjacent elements if they are in the wrong order.
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion
// Insert each element into its correct position in the sorted part of the array.
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge
// Divide the array into halves, sort each half, and merge them.
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick
// Choose a pivot, partition the array around the pivot, and sort the partitions.
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Radix
// Sort elements digit by digit, starting from the least significant digit.
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n), count(10, 0);

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

// Count
// Count the occurrences of each element and reconstruct the sorted array.
void countingSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());
    int minElement = *min_element(arr.begin(), arr.end());
    int range = maxElement - minElement + 1;

    vector<int> count(range, 0), output(arr.size());
    for (int num : arr) 
        count[num - minElement]++;
    for (int i = 1; i < range; i++) 
        count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--)
        output[--count[arr[i] - minElement]] = arr[i];
    arr = output;
}

// Bucket
// Divide the range into buckets, sort each bucket, and concatenate them.
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> buckets(n);

    int maxElement = *max_element(arr.begin(), arr.end());
    for (int num : arr) {
        int bucketIndex = (num * n) / (maxElement + 1);
        buckets[bucketIndex].push_back(num);
    }

    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    arr.clear();
    for (auto& bucket : buckets) {
        for (int num : bucket) arr.push_back(num);
    }
}
