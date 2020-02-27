#include <vector>
#include <iostream>
using namespace std;

bool isHuiWen(int Num) {
    if(Num<0) return false;

	vector<int> nums; //  每一位数字

    int tmp = Num;
    while( tmp>0) {
        nums.push_back(tmp % 10);
        tmp /= 10;
    }

    // 判断回文数
    for(int i=0, j=nums.size()-1; i<=j; ++i,--j) {
        if(nums[i] != nums[j]) 
            return false;
    }
    return true;
}

int main() {
	int a;
	while(cin>>a) {
		if(isHuiWen(a))
			cout<<"Is a Huiwen Number."<<endl;
		else
			cout<< "Not a HuiWen Number."<<endl;
	}
	return 0;
}