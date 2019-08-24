// Final Build

// To compile: g++ main.cpp -> ./a.out
// OR
// make main -> make run -> make clean(to clear the files)

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void sortRandomIntegers(int size);
void fillRandomArray(int *items, int size);
void printArray(int *items, int size);
void copyTheArray(int *sour, int sstart, int size, int *dest, int dstart, int n);
void insertionSort(int *items, int size);
void mergeSort(int *items, int size);
void merge(int *temp1, int *temp2, int *items, int p, int q, int size);
void quickSort(int *items, int size);
void quickSort(int *items, int l, int r);
int partition(int *items, int l, int r);
void heapSort(int *items, int size);
void constructTheHeap(int *items, int size);
void deleteMax(int *items, int size);

void sortRandomIntegers(int size) {
  cout << "\nElapsed time in clicks for " << size << " random integers: " << endl;

  clock_t start, end, elapsed;
  int *t1 = new int[size];
  int *t2 = new int[size];
  int *t3 = new int[size];
  int *t4 = new int[size];

  int *arr = new int[size];
  fillRandomArray(arr, size);

  copyTheArray(arr, 0, size, t1, 0, size);
  copyTheArray(arr, 0, size, t2, 0, size);
  copyTheArray(arr, 0, size, t3, 0, size);
  copyTheArray(arr, 0, size, t4, 0, size);

  start = 0;
  end = 0;
  elapsed = 0;
  start = clock();
  insertionSort(t1, size); // Insertion sort
  end = clock();
  elapsed = end - start;
  cout << "Insertion Sort: " << elapsed << endl;

  start = 0;
  end = 0;
  elapsed = 0;
  start = clock();
  quickSort(t3, size); // Quick sort
  end = clock();
  elapsed = end - start;
  cout << "Quick Sort: " << elapsed << endl;

  start = 0;
  end = 0;
  elapsed = 0;
  start = clock();
  heapSort(t4, size); // Heap sort
  end = clock();
  elapsed = end - start;
  cout << "Heap Sort: " << elapsed << endl;

  start = 0;
  end = 0;
  elapsed = 0;
  start = clock();
  mergeSort(t2, size); // Merge sort
  end = clock();
  elapsed = end - start;
  cout << "Merge Sort: " << elapsed << endl;
} // end sortRandomIntegers

void fillRandomArray(int *items, int size) {
  // random numbers between 1-20000
  for (int i = 0; i < size; i++) {
    items[i] = 1 + rand() % 10;
  } // end for
} // end fillRandomArray

void printArray(int *items, int size) {
  for (int i = 0; i < size; i++) {
    cout << items[i] << " ";
  } // end for
  cout << endl;
} // end printArray

void copyTheArray(int *sour, int sstart, int size, int *dest, int dstart, int n) {
  for (int i = sstart, j = dstart; i < size; i++, j++) {
    dest[j] = sour[i];
  } // end for
} // copyTheArray

void insertionSort(int *items, int size) {
  for (int i = 1; i < size; i++) {
    int temp = items[i];
    int j = i;

    while (j > 0 && temp < items[j - 1]) {
      items[j] = items[j - 1];
      j--;
    } // end while

    items[j] = temp;
  } // end for
} // end insertionSort

void mergeSort(int *items, int size) {
  int s1 = size / 2;
  int s2 = size - s1;
  int *temp1 = new int[s1];
  int *temp2 = new int[s2];

  if (size > 1) {
    copyTheArray(items, 0, size, temp1, 0, s1);
    copyTheArray(items, s1, size, temp2, 0, s2);

    mergeSort(temp1, s1);
    mergeSort(temp2, s2);
    merge(temp1, temp2, items, s1, s2, size);
  } // end if
} // end mergeSort

void merge(int *temp1, int *temp2, int *items, int p, int q, int size) {
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < p && j < q) {
    if (temp1[i] <= temp2[j]) {
      items[k] = temp1[i];
      i = i + 1;
    } // end if
    else {
      items[k] = temp2[j];
      j = j + 1;
    } // end else

    k = k + 1;
  } // end while

  if (i == p)
    copyTheArray(temp2, j, size, items, k, q - j);
  else
    copyTheArray(temp1, i, size, items, k, p - i);
} // end merge

void quickSort(int *items, int size) {
  quickSort(items, 0, size - 1);
} // end quickSort

void quickSort(int *items, int l, int r) {
  int s = partition(items, l, r);

  if (l < s - 1)
    quickSort(items, l, s - 1);
  if (s < r)
    quickSort(items, s, r);
} // end quickSort

int partition(int *items, int l, int r) {
  int p = l;
  int q = r;
  int temp;
  int pivot;
  pivot = items[(l + r) / 2];

  while (p <= q) {
    while (items[p] < pivot)
    p++;
    while (items[q] > pivot)
    q--;

    if (p <= q) {
      temp = items[p];
      items[p] = items[q];
      items[q] = temp;
      p++;
      q--;
    } // end if
  } // end while
  return p;
} // end partition

void heapSort(int *items, int size) {
  constructTheHeap(items, size);
  deleteMax(items, size);
} // end heapSort

void constructTheHeap(int *items, int size) {
  int j, k, temp;
  for (int i = 1; i < size; i++) {
    j = i;

    do {
      k = (j - 1) / 2;
      if (items[k] < items[j]) {
        temp = items[k];
        items[k] = items[j];
        items[j] = temp;
      } // end if

      j = k;

    } while (k != 0);
  } // end for
} // end constructTheHeap

void deleteMax(int *items, int size) {
  for (int i = size - 1; i > 0; i--) {
    int temp = items[0];
    items[0] = items[i];
    items[i] = temp;

    constructTheHeap(items, i);
  } // end for
} // end deleteMax

// Driver code
int main() {
  srand(time(NULL));

  sortRandomIntegers(100);
  sortRandomIntegers(500);
  sortRandomIntegers(1000);
  sortRandomIntegers(2000);
  sortRandomIntegers(5000);
  sortRandomIntegers(8000);
  sortRandomIntegers(10000);

  system("pause");
  return 0;
} // end main
