#include "selectionSortA.h"
#include <iostream>
#include <vector>
#include <algorithm>

//Selection sort algorithm that swaps whenever a smaller element is found
void selectionSortA(std::vector<int> &ar) {
    int n = ar.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ar[j] < ar[i]) {
                std::swap(ar[i], ar[j]);
            }
        }
        }
    }