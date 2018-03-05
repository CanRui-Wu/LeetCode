#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int *pre;
    int *size;
    map<int,int> my_map;

    int find(int index) {
        if(pre[index] == -1)
            return index;
        pre[index] = find(pre[index]);
        return pre[index];
    }

    void union_set(int index1,int index2) {
        int root1 = find(index1);
        int root2 = find(index2);
        if(root1 != root2) {
            pre[root1] = root2;
            size[root2] += size[root1];
        }
    }

    int longestConsecutive(vector<int>& nums) {
        pre = new int[nums.size()];
        size = new int[nums.size()];
        memset(pre,-1,sizeof(int)*nums.size());
        for(int i = 0;i < nums.size();i++) {
            size[i] = 1;
        }
        for(int i = 0;i < nums.size();i++) {
            my_map[nums[i]] = i;
        }
        map<int,int>::iterator it,it2;
        for(it2 = my_map.begin();it2 != my_map.end();it2++) {
        	//cout << it2->first << " " << it2->second << endl;
            int cur = find(it2->second);
            it = my_map.find((it2->first)+1);
            if(it != my_map.end()) {
            	//cout << it->first << "there" << endl;
                int temp = find(it->second);
                union_set(cur,temp);
            }
        }
        int max = 0;
        for(it2 = my_map.begin();it2 != my_map.end();it2++) {
            if(size[it2->second] > max)
                max = size[it2->second];
        }
        return max;
    }
};

int main() {
	vector<int> nums{103,102,-1,100,101, 4, 200, 1,102, 3,99,100,98,97, 2,0};
	Solution solution;
	cout << solution.longestConsecutive(nums) << endl;
}
