#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;

// My version
// bool canJump(vector<int>& nums) {
// 	stack<int> mystack;
// 	mystack.push(0);
// 	int *visit = new int[nums.size()];
// 	memset(visit,0,sizeof(int)*nums.size());
// 	visit[0] = 1;
// 	while(!mystack.empty())	{
// 		int temp = mystack.top();
// 		mystack.pop();
// 		if (temp+nums[temp] >= nums.size()-1) {
// 			return true;
// 		}
// 		for(int i = 1;i <= nums[temp];i++) {
// 			if(visit[temp+i] == 0) {
// 				mystack.push(temp+i);
// 				visit[temp+i] = 1;
// 			}
// 		} 	
// 	}
// 	return false;        
// }


//Correct Version
bool canJump(vector<int>& nums) {
	int max = 0;
	for(int i = 0;i <= max;i++) {
		if(i+nums[i] >= nums.size()-1)
			return true;
		if(i+nums[i] > max)
			max = i+nums[i];
	}
	return false;
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(0);
	// = {1,1,1,0};
	if(canJump(nums)) {
		cout << "ok" << endl;
	}
}