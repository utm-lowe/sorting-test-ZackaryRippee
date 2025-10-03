#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>

void mergesort(std::vector<int> &ar);
void mergeHelper(std::vector<int> &ar, int p, int r);
void merge(std::vector<int> &arr, int p, int q, int r);

#endif // MERGESORT_H
