#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int binaryFind(vector<int>& nums,int start,int end) {
		int mid = (start+end)/2;
		int left = 0,right = 0;
		if(mid == start || nums[mid] > nums[mid-1])
			left = 1;
		if(mid == end || nums[mid] > nums[mid+1])
			right = 1;
		if(left*right == 1)
			return mid;
		else if(left == 0)
			return binaryFind(nums,start,mid-1);
		else
			return binaryFind(nums,mid+1,end);
		
	}
    int findPeakElement(vector<int>& nums) {
        return binaryFind(nums,0,nums.size()-1);
    }
};

int main() {
	Solution solution;
	vector<int> nums{1,2};
	cout << solution.findPeakElement(nums) << endl;
}