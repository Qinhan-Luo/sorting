#include "util.h"
#include "sort.h"

using namespace sorting;
using namespace sorting::util;

int main(int argc, char** argv) {
	int nums[] = {2,8,7,1,3,5,6,4};
	QuickSort(nums, 0, 7);
	PrintNums(nums, 5);
	
	return 0;
}