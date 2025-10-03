#include "bubbleSortB.h"
#include <vector>

// Bubble Sort B: swap detection, left-to-right
void bubbleSortB(std::vector<int>& arr) {
    int n = (int)arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
