#include "bubbleSortA.h"
#include <vector>

// Bubble Sort A: no swap detection
void bubbleSortA(std::vector<int>& arr) {
    int n = (int)arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
