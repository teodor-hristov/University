#pragma once

#include <vector>
#include "../Headers/Utils.h"

void merge(std::vector<ClientWrapper *> &inputArr, int start, int mid, int end,
           bool (*predicate)(const ClientWrapper *const &a, const ClientWrapper *const &b)) {
    ClientWrapper *temp[end - start + 1];

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (predicate(inputArr[i], inputArr[j])) {
            temp[k] = inputArr[i];
            k += 1;
            i += 1;
        } else {
            temp[k] = inputArr[j];
            k += 1;
            j += 1;
        }
    }

    while (i <= mid) {
        temp[k] = inputArr[i];
        k += 1;
        i += 1;
    }

    while (j <= end) {
        temp[k] = inputArr[j];
        k += 1;
        j += 1;
    }

    for (i = start; i <= end; i += 1) {
        inputArr[i] = temp[i - start];
    }
}

void topToBottomMergeSort(std::vector<ClientWrapper *> &Arr, int start, int end,
               bool (*predicate)(const ClientWrapper *const &a, const ClientWrapper *const &b)) {
    if (start < end) {
        int mid = (start + end) / 2;
        topToBottomMergeSort(Arr, start, mid, predicate);
        topToBottomMergeSort(Arr, mid + 1, end, predicate);
        merge(Arr, start, mid, end, predicate);
    }
}