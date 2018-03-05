#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for(auto num:nums) {
        	if(num_set.find(num) != num_set.end()) {
        		return true;
        	}
        	num_set.insert(num);
        }
        return false;
    }
};

int main() {
	Solution solution;
	vector<int> nums{1,2,3,1};
	cout << solution.containsDuplicate(nums) << endl;
}