#include "mergesort.h"
#include <iostream>
#include <vector>



void merge(std::vector<int> &arr, int p, int q, int r){
    int nL = q - p + 1; //length of A[p:q]
    int nR = r - q; //length of A[q+1:r]
    std::vector<int> L(nL); //create left array
    std::vector<int> R(nR); //create right array
    for (int i = 0; i < nL; i++){
        L[i] = arr[p + i]; //copy A[p:q] to L
    }
    for (int j = 0; j < nR; j++){
        R[j] = arr[q + 1 + j]; //copy A[q+1:r] to R
    }
    int i = 0; //i indexes the smallest remaining element in L
    int j = 0; //j indexes the smallest remaining element in R
    int k = p; //k indexes the location in A to fill
    while (i < nL && j < nR){
        if (L[i] <= R[j]){
            arr[k] = L[i]; //copy L[i] to A[k]
            i = i + 1; //increment i
        }
        else{
            arr[k] = R[j]; //copy R[j] to A[k]
            j = j + 1; //increment j
        }
        k = k + 1; //increment k
    }
    while (i < nL){
        arr[k] = L[i]; //copy remaining elements of L to A
        i = i + 1; //increment i
        k = k + 1; //increment k
    }
    while (j < nR){
        arr[k] = R[j]; //copy remaining elements of R to A
        j = j + 1; //increment j
        k = k + 1; //increment k
    }

}

void mergeHelper(std::vector<int> &ar, int p, int r){
    if (p >= r){
        return;
    }

    int q = (p + r) / 2; //q is the middle element between p and r
    mergeHelper(ar, p, q);
    mergeHelper(ar, q + 1, r);
    merge(ar, p, q, r);
}

void mergesort(std::vector<int> &arr){
    if (arr.empty()) return;
    int p = 0; // left index
    int r = (int)arr.size() - 1; // right index
    if (p >= r) return;
    mergeHelper(arr, p, r);
}

