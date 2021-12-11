#pragma once
#ifndef HOMEWORK1_UTILS_H
#include "ClientWrapper.h"

void topToBottomMergeSort(std::vector<ClientWrapper*> &Arr, int start, int end, bool (*predicate)(const ClientWrapper * const & a, const ClientWrapper * const & b));

#define HOMEWORK1_UTILS_H
#endif //HOMEWORK1_UTILS_H
