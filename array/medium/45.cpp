#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
	if(nums.size() == 1)
		return 0;
	int max = 0;
	int cur_max = 0;
	int distance = 1;
	int i = 0;
	while(i <= max) {
		if(i + nums[i] >= nums.size()-1)
			return distance;
		if(i + nums[i] > cur_max)
			cur_max = i + nums[i];
		if(i == max) {
			max = cur_max;
			distance++;
		}
		i++;
	}
	return -1;
}


int main() {
	vector<int> nums{2,3};
	cout << jump(nums) << endl;
}