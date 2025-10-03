#include "radixSort.h"
#include <vector>
#include <algorithm>

// Radix Sort: binary radix, bitwise counting (LSD first, stable)
void radixSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int bits = 0;
    while ((1 << bits) <= maxVal) ++bits;
    for (int b = 0; b < bits; ++b) {
        std::vector<int> zero, one;
        for (int x : arr) {
            if ((x >> b) & 1) one.push_back(x);
            else zero.push_back(x);
        }
        arr.clear();
        arr.insert(arr.end(), zero.begin(), zero.end());
        arr.insert(arr.end(), one.begin(), one.end());
    }
}
