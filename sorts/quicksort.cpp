#include "quicksort.h"
#include <iostream>
#include <vector>
#include <random>



// Lomuto partition: partitions ar[low..high] around pivot ar[high]
static int partition(std::vector<int> &ar, int low, int high) {
    int pivot = ar[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (ar[j] < pivot) {
            ++i;
            std::swap(ar[i], ar[j]);
        }
    }
    std::swap(ar[i + 1], ar[high]);
    return i + 1;
}

void quicksortHelper(std::vector<int> &ar, int low, int high){
    if (low < high){
        // Randomized pivot: pick a random index in [low, high] and swap with high
        static thread_local std::mt19937_64 rng((std::random_device())());
        std::uniform_int_distribution<int> dist(low, high);
        int pivotIndex = dist(rng);
        std::swap(ar[pivotIndex], ar[high]);

        int pi = partition(ar, low, high);
        quicksortHelper(ar, low, pi - 1);
        quicksortHelper(ar, pi + 1, high);
    }
}

void quicksort(std::vector<int> &ar){
    if (ar.empty()) return;
    int low = 0; // left index
    int high = (int)ar.size() - 1; // right index
    if (low >= high) return;
    quicksortHelper(ar, low, high);
}
