#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        int **dp = new int*[n+1];
        for(int i = 0;i <= n;i++) {
        	dp[i] = new int[n+1];
        }
        for(int i = 0;i <= n;i++) {
        	for(int j = 0;j <= n;j++) {
        		dp[i][j] = 0;
        		if(i <= 1 || i+j > n)
        			continue;
        		int min_pay = INT_MAX;
        		for(int k = 0;k < i;k++) {
        			int current = j+k+1+max(dp[k][j],dp[i-k-1][j+k+1]);
        			if(current < min_pay)
        				min_pay = current;
        		}
        		dp[i][j] = min_pay;
        	}
        }
        return dp[n][0];
    }
};

int main() {
	Solution solution;
	cout << solution.getMoneyAmount(6) << endl;
}