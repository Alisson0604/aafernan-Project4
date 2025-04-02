#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "printVec.h"

template<typename Comparable>
vector<Comparable> bubbleSort(vector<Comparable> vec, unsigned long& reads, unsigned long& allocations) {
    reads = allocations = 0;
    int numPasses = 0, i;
    allocations += sizeof(int) * 2;
    Comparable temp;
    allocations += sizeof(Comparable);

    bool haveSwapped = true;
    allocations += sizeof(bool);

    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            reads++;
            reads++;
            // Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i+1]) {
                temp = vec[i];
                reads++;
                vec[i] = vec[i+1];
                reads++;
                vec[i+1] = temp;
                reads++;
                // Update haveSwapped
                haveSwapped = true;
            }
        }
        // Update numPasses
        ++numPasses;

        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    cout << reads << endl;
    cout << allocations << endl;
    return vec;
}

#endif
