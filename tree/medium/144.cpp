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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     stack<TreeNode *> mystack;
    //     TreeNode *current = root;
    //     while(current != NULL || !mystack.empty()) {
    //     	while(current != NULL) {
    //     		result.push_back(current->val);
    //     		mystack.push(current);
    //     		current = current->left;
    //     	}
    //     	current = mystack.top();
    //     	mystack.pop();
    //     	current = current->right;
    //     }
    //     return result;
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> mystack;
        mystack.push(root);
        TreeNode *current;
        while(!mystack.empty()) {
        	current = mystack.top();
        	mystack.pop();
        	if(current == NULL)
        		continue;
        	result.push_back(current->val);
        	mystack.push(current->right);
        	mystack.push(current->left);
        }
        return result;	        
    }
};

int main() {
	Solution solution;
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	t1->left = t2;
	t2->left = t3;
	vector<int> result = solution.preorderTraversal(t1);
	for(int i = 0;i < result.size();i++) {
		cout << result[i] << endl;
	}
}