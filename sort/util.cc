#include "util.h"
#include <iostream>
#include <cassert>

namespace sorting{
namespace util{

void PrintNums(int nums[], int n) {
	assert(n>0);
	for(int i=0; i<n; ++i) {
			std::cout<<nums[i]<<",";
		if(i>0 && i%10==0)
			std::cout<<std::endl;
	}
}




}
}