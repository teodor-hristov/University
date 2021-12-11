#include <vector>
#include "../Headers/Utils.h"

void merge(std::vector<ClientWrapper *> &inputArr, int start, int mid, int end,
           bool (*predicate)(const ClientWrapper *const &a, const ClientWrapper *const &b)) {
    ClientWrapper *tempArr[end - start + 1];

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (predicate(inputArr[i], inputArr[j])) {
            tempArr[k] = inputArr[i];
            k += 1;
            i += 1;
        } else {
            tempArr[k] = inputArr[j];
            k += 1;
            j += 1;
        }
    }

    while (i <= mid) {
        tempArr[k] = inputArr[i];
        k += 1;
        i += 1;
    }

    while (j <= end) {
        tempArr[k] = inputArr[j];
        k += 1;
        j += 1;
    }

    for (i = start; i <= end; i += 1) {
        inputArr[i] = tempArr[i - start];
    }
}

/*Merge sort implementation*/
void topToBottomMergeSort(std::vector<ClientWrapper *> &Arr, int start, int end,
               bool (*predicate)(const ClientWrapper *const &a, const ClientWrapper *const &b)) {
    int midIndex;

    if (start >= end) {
        return;
    }

    midIndex = (start + end) / 2;
    topToBottomMergeSort(Arr, start, midIndex, predicate);
    topToBottomMergeSort(Arr, midIndex + 1, end, predicate);
    merge(Arr, start, midIndex, end, predicate);
}