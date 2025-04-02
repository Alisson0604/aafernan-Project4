#include "Fernandez.h"

#include "sorting-algorithms/bubbleSort.h"
#include "sorting-algorithms/heapSort.h"
#include "sorting-algorithms/insertionSort.h"
#include "sorting-algorithms/mergeSort.h"
#include "sorting-algorithms/quickSort.h"
#include "sorting-algorithms/radixSort.h"
#include "sorting-algorithms/selectionSort.h"
#include "stability-test/contactsList.h"

#include <iomanip>
#include <algorithm>
#include <random>

using std::string, std::vector, std::ifstream;
using namespace std;

void stabilityTest();

int main() {

    unsigned long reads, allocations;

    // Load data
    std::vector<Fernandez> pokemons;
    std::string file = "../Fernandez_pokemon.csv";
    loadFromFile(file, pokemons);

    // Create and open ofstream objects to save results
    ofstream outFileBubbleSort, outFileMergeSort, outFileHeapSort, outFileSelectionSort;
    outFileBubbleSort.open("../bubbleSort.csv");
    outFileMergeSort.open("../mergeSort.csv");
    outFileHeapSort.open("../heapSort.csv");
    outFileSelectionSort.open("../selectionSort.csv");

    // loop through vector sizes from 1000 to 100 in decrements of 100
    for (int i = 1000; i >= 100; i-=100) {
        pokemons.resize(i);
        cout << "* Pokemons vector size: " << i << endl;
        // sort the vector in four different ways (bubble, merge, heap, selection)
        // record the number of reads and allocations for each sort
        // Bubble Sort
        reads = 0, allocations = 0;
        bubbleSort(pokemons, reads, allocations);
        cout << "Bubble Sort reads: " << reads << endl;
        cout << "Bubble Sort allocations: " << allocations << endl;
        outFileBubbleSort << i << "," << reads << "," << allocations << endl;
        cout << " " << endl;

        // Merge Sort
        reads = 0, allocations = 0;
        mergeSort(pokemons, reads, allocations);
        cout << "Merge Sort reads: " << reads << endl;
        cout << "Merge Sort allocations: " << allocations << endl;
        outFileMergeSort << i << "," << reads << "," << allocations << endl;
        cout << " " << endl;

        // Heap Sort
        reads = 0, allocations = 0;
        heapSort(pokemons, reads, allocations);
        cout << "Heap Sort reads: " << reads << endl;
        cout << "Heap Sort allocations: " << allocations << endl;
        outFileHeapSort << i << "," << reads << "," << allocations << endl;
        cout << " " << endl;

        // Selection Sort
        reads = 0, allocations = 0;
        selectionSort(pokemons, reads, allocations);
        cout << "Selection Sort reads: " << reads << endl;
        cout << "Selection Sort allocations: " << allocations << endl;
        outFileSelectionSort << i << "," << reads << "," << allocations << endl;
        cout << " " << endl;
    }
    // Close CSV files with results stored
    outFileBubbleSort.close();
    outFileMergeSort.close();
    outFileHeapSort.close();
    outFileSelectionSort.close();

    stabilityTest();
    return 0;
}

void stabilityTest() {
    ContactsList people;
    people.readContactsFromFile("../stability-test/names.csv");
    cout << "People (Default ordering)" << endl;
    people.printList();

    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort<contact>);

    cout << endl << "Merge Sort" << endl;
    people.sortAndPrint(mergeSort<contact>);

    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort<contact>);

    cout << endl << "Selection Sort" << endl;
    people.sortAndPrint(selectionSort<contact>);
}