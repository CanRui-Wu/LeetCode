#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> mystack;
        stack<TreeNode *> mystack2;
        TreeNode *current = root;
       	mystack.push(root);
       	while(!mystack.empty()) {
       		current = mystack.top();
       		mystack.pop();
       		if(current == NULL)
       			continue;
       		mystack2.push(current);
       		mystack.push(current->left);
       		mystack.push(current->right);
       	}
       	while(!mystack2.empty()) {
       		current = mystack2.top();
       		mystack2.pop();
       		result.push_back(current->val);
       	}
       	return result;
    }
};

int main() {
	Solution solution;
	vector<int> result;
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	t1->left = t2;
	t2->right = t3;
	result = solution.postorderTraversal(t1);
	for(int i = 0;i < result.size();i++) {
		cout << result[i] << endl;
	}
}