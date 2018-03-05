#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	unordered_map<string,bool> checked_map;
	unordered_set<string> my_set;
	bool check(const string &s) {
		//cout << s << endl;
		unordered_map<string,bool>::iterator it;
		it = checked_map.find(s);
		if(it != checked_map.end())
			return it->second;
		checked_map[s] = false;
		if(my_set.find(s) != my_set.end()) {
			checked_map[s] = true;
		} else {
			for(int i = 1;i < s.size();i++) {
				if(check(s.substr(i)) && check(s.substr(0,i)))
					checked_map[s] = true;
			}
		}
		return checked_map[s];
	}
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it = wordDict.begin();it != wordDict.end();it++) {
        	my_set.insert(*it);
        }
        return check(s);
    }
};

int main() {
	Solution solution;
	vector<string> a{"leet","code","0","1"};
	string s = "0leetcode010";
	cout << solution.wordBreak(s,a) << endl;
}