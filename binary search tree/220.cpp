#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> num_set;
        for(int i = 0;i < nums.size();i++) {
        	auto it1 = num_set.lower_bound((long long)nums[i]-t);
        	if(it1 != num_set.end() && *it1 <= (long long) nums[i]+t)
        		return true;
        	num_set.insert(nums[i]);
        	if(i >= k) {
        		auto it = num_set.find(nums[i-k]);
        		num_set.erase(it);
        	}
        }
        return false;
    }
};

int main() {
	Solution solution;
	vector<int> nums{0,2147483647};
	cout << solution.containsNearbyAlmostDuplicate(nums,1,2147483647) << endl;
}