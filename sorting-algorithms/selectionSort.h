#ifndef SORTING_SELECTIONSORT_H
#define SORTING_SELECTIONSORT_H

#include "printVec.h"

template<typename Comparable>
vector<Comparable> selectionSort(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    int swapIndex, i, minIndex;
    allocations += sizeof(int) * 3;
    Comparable temp;
    allocations += sizeof(Comparable);
    for (swapIndex = 0; swapIndex < vec.size()-1; ++swapIndex) {
        // Loop through vector starting at swapIndex and keep track of min
        minIndex = swapIndex;
        for (i = swapIndex+1; i < vec.size(); ++i) {
            ++reads;
            ++reads;
            if (vec[i] < vec[minIndex]) {
                // We have a new minimum
                minIndex = i;
            }
        }
        // Swap min value into swapIndex spot in vector
        if (minIndex != swapIndex) {
            temp = vec[swapIndex];
            ++reads;
            vec[swapIndex] = vec[minIndex];
            ++reads;
            vec[minIndex] = temp;
            ++reads;
        }

        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    cout << reads << endl;
    cout << allocations << endl;
    return vec;
}

#endif
