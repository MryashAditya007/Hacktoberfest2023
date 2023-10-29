#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform bucket sort
void bucketSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    int max_val = *std::max_element(arr.begin(), arr.end());
    int min_val = *std::min_element(arr.begin(), arr.end());

    // Create buckets
    int num_buckets = max_val - min_val + 1;
    std::vector<std::vector<int>> buckets(num_buckets);

    // Distribute elements into buckets
    for (int i = 0; i < arr.size(); i++) {
        int index = arr[i] - min_val;
        buckets[index].push_back(arr[i]);
    }

    // Sort individual buckets (you can use any sorting algorithm here)
    for (int i = 0; i < num_buckets; i++) {
        if (!buckets[i].empty()) {
            std::sort(buckets[i].begin(), buckets[i].end());
        }
    }

    // Concatenate sorted buckets to get the final sorted array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    std::vector<int> arr = {45, 12, 36, 78, 53, 98, 65, 42, 21, 7};
    
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    bucketSort(arr);
    
    std::cout << "\nSorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
