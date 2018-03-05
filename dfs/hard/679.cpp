#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	double caculate(double num1,double num2,int mode) {
		double result = -1;
		switch(mode) {
			case 0:
				result = num1+num2;
				break;
			case 1:
				result = num1*num2;
				break;
			case 2:
				result = num1-num2;
				break;
			case 3:
				result = num2-num1;
				break;
			case 4:
				result = num1/num2;
				break;
			case 5:
				result = num2/num1;
				break;
		}
		return result;
	}
	bool dfs(vector<double> &temp) {
		// for(int i = 0;i < temp.size();i++)
		// 	cout << temp[i] << " ";
		// cout << endl;
		if(temp.size() == 1) {
			if(abs(temp[0] - 24.0) < 1e-10)
				return true;
			return false;
		}

		for(int i = 0;i < temp.size();i++) {
			for(int j = i + 1;j < temp.size();j++) {
				for(int k = 0;k < 6;k++) {
					if(k == 4 && temp[j] == 0 || k == 5 && temp[i] == 0)
						continue;
					double result = caculate(temp[i],temp[j],k);
					double temp1 = temp[i];
					double temp2 = temp[j];
					temp.erase(temp.begin()+j);
					temp.erase(temp.begin()+i);
					temp.insert(temp.begin(),result);
					if(dfs(temp))
						return true;
					temp.erase(temp.begin());
					temp.insert(temp.begin()+i,temp1);
					temp.insert(temp.begin()+j,temp2);
				}
			}
		}
		return false;
	}
    bool judgePoint24(vector<int>& nums) {
    	vector<double> temp(nums.begin(),nums.end());
    	return dfs(temp);    
    }
};

int main() {
	vector<int> a{3,3,8,8};
	Solution solution;
	cout << solution.judgePoint24(a) << endl;
	cout << (24-8/(3-8.0/3)) << endl;
}