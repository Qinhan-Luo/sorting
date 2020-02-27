#include <iostream>

using namespace std;

int getMiddleIndex(int num[], int n) {
    int sum = 0;
    if(n<=0) return -1;
     
    for(int i=0; i<n; ++i) {
        sum += num[i];
    }

    // assert the middle
    int now_sum = 0, need_sum = 0;
    for(int j=0; j<n-1; ++j) {
        now_sum += num[j];
        need_sum = sum - num[j+1] - now_sum;
        if(now_sum == need_sum){
            return j+1;
        }
    }

    return -1;
}

int main() {
    
    return 0;
}