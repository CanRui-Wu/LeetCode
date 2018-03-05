#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

 struct TreeNode {
	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void inorder(TreeNode* root,vector<int> &result) {
		if(root == NULL)
			return;
		inorder(root->left,result);
		result.push_back(root->val);
		inorder(root->right,result);
	}
    int getMinimumDifference(TreeNode* root) {
    	vector<int> result;
    	inorder(root,result);
    	int min_dist = INT_MAX;
    	for(int i = 1;i < result.size();i++) {
    		if(abs(result[i]-result[i-1]) < min_dist)
    			min_dist = abs(result[i]-result[i-1]);
    	}
    	return min_dist;
    }
};

int main() {
	Solution solution;
	TreeNode* t1 = new TreeNode(2);
	TreeNode* t2 = new TreeNode(6);
	TreeNode* t3 = new TreeNode(4);
	t1->left = t2;
	t1->right = t3;
	cout << solution.getMinimumDifference(t1);
}