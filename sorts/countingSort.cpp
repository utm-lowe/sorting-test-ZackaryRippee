#include "countingSort.h"
#include <vector>
#include <algorithm>

// Counting Sort: assumes non-negative integers
void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    int maxVal = *std::max_element(arr.begin(), arr.end());
    std::vector<int> count(maxVal + 1, 0);
    for (int x : arr) ++count[x];
    int idx = 0;
    for (int i = 0; i <= maxVal; ++i) {
        while (count[i]-- > 0) arr[idx++] = i;
    }
}
