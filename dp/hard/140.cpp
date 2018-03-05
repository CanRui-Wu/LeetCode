#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
	void buildResult(const string &s,vector<vector<int> > &dp,int current,stack<int> &space_area,vector<string> &result) {
		if(dp[current].size() == 0)
			return;
		for(int i = 0;i < dp[current].size();i++) {
			if(dp[current][i] == -1) {
				stack<int> temp = space_area;
				string new_s = s;
				int index = 1;
				while(!temp.empty()) {
					new_s.insert(temp.top()+index++," ");
					temp.pop();
				}
				result.push_back(new_s);
			} else {
				space_area.push(dp[current][i]);
				buildResult(s,dp,dp[current][i],space_area,result);
				space_area.pop();
			}
		}
	}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    	vector<vector<int> > dp;
    	unordered_set<string> dict;
    	for(int i = 0;i < wordDict.size();i++) {
    		dict.insert(wordDict[i]);
    	}
    	for(int i = 0;i < s.size();i++) {
    		vector<int> temp;
    		dp.push_back(temp);
    	}

    	for(int i = 0;i < s.size();i++) {
    		for(int j = 0;j <= i;j++) {
    			//cout << "***" << i << " " << j << s.substr(j,i-j+1) << endl;
    			if(dict.find(s.substr(j,i-j+1)) != dict.end()) {
    				if(j == 0 || (dp[j-1].size() != 0)) {
    					dp[i].push_back(j-1);
    				} 
    			}
    		}
    	}
    	vector<string> result;
    	stack<int> mystack;
    	buildResult(s,dp,dp.size()-1,mystack,result);
    	return result;     
    }
};

int main() {
	Solution solution;
	vector<string> dict{"cat", "cats", "and", "sand", "dog"};
	vector<string> result;
	string s = "catsanddog";
	result = solution.wordBreak(s,dict);
	for(int i = 0;i < result.size();i++)
		cout << result[i] << endl;
}