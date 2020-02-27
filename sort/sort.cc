// some operations for sorting...
#include "sort.h"

#include <stdlib.h>
#include <limits.h>
#include <iostream>

namespace sorting {

void BubbleSort(int nums[], int size) {
	int tmp;	
	for(int i=0; i<size; ++i) {
		for(int j=0; j<size-i-1; ++j) {
			if(nums[j]<nums[j+1]) {
				tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
			}
		}
	}
}

void SelectionSort(int num[], int size) {
	int tmp;
	for(int i=0; i<size; ++i) {
		for(int j=i+1; j<size; ++j) {
			if(num[j]>num[i]) {
					tmp = num[j];
					num[j] = num[i];
					num[i] = tmp;
			}
		}
	}	
}	

void InsertionSort(int num[], int size) {
	int key; int j;
	for(int i=1; i<size; ++i) {
		key = num[i];
		j=i-1;
		while(j>=0 && num[j]<key) {
			num[j+1] = num[j];
			j--;
		}			
		num[j+1] = key;	
	}	
}

void Merge(int num[],int p, int q, int r)  {
	int left = q-p+1;
	int right = r-q;
	int L[left+1], R[right+1];

	for(int i=0; i<left; ++i) {
		L[i] = num[p+i];
	}

	for(int j=0; j<right; ++j) {
		R[j] = num[q+j+1];
	}

	L[left] = INT_MAX;
	R[right] = INT_MAX; // 无穷大的示意替换

	int iCount=p, i=0, j=0;
	while(iCount<=r) {
          if (L[i] > R[j]) {
            num[iCount] = R[j];
            j++;
          } else {
            num[iCount] = L[i];
            i++;
          }

    	iCount++;
	}
}

void MergeSort(int num[], int p, int r) {
	if(p>=r) return;
	int q = (r+p)/2;
	MergeSort(num, p, q);
	MergeSort(num, q+1, r);
	Merge(num, p, q, r);
}

void MaxHeapfy(int num[], int size, int index) {
	int left = 2*index+1;
	int right = 2*index+2;

	int largest;

	if(left<size && num[left]>num[index]) {
		largest = left;
	} else
		largest = index;

	if(right<size && num[right]>num[largest])
		largest=right;
	
	if(largest!=index) {
		int tmp = num[index];
		num[index] = num[largest];
		num[largest] = tmp;
		MaxHeapfy(num, size, largest);
	}
	return;
}

void HeapSort(int *num, int size) {
	// Build Heap
	int index = size / 2;
	for(int i=index-1; i>=0; --i) {
		MaxHeapfy(num, size, i);
	}
	
	// extract the max-num at the top of heap 
	int tmp;
	int heap_tail = size-1; // for c 0-size-1;
	while(heap_tail>=1){
		tmp = num[0];
		num[0] = num[heap_tail];
		num[heap_tail] = tmp;
		heap_tail--;

		MaxHeapfy(num, heap_tail+1, 0);
	}


}

int PartionArray(int* num, int p, int r) {
	int pivot = num[r];
	int i=p-1;
	int tmp;
	for(int j=p; j<=r-1; j++) {
		if(num[j]<=pivot) {
			i++;
			tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
		}
	}
	num[r] = num[i+1];
	num[i+1] = pivot;
	return i+1;
}


void QuickSort(int* num, int p, int r) {
	if(p<=r) {
		int q = PartionArray(num,p,r);
		QuickSort(num, p, q-1);
		QuickSort(num, q+1, r);
	}


}


}