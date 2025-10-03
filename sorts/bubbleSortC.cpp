#include "bubbleSortC.h"
#include <vector>

// Bubble Sort C: swap detection, right-to-left
void bubbleSortC(std::vector<int>& arr) {
    int n = (int)arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = n - 1; j > i; --j) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
