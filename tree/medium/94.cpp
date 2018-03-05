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
 
//Not Recurisive solution using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> mystack;
        TreeNode *current = root;
        while(current != NULL || !mystack.empty()) {
        	while(current != NULL) { //不断寻找其左子树，直到为空
        		mystack.push(current); //栈正确存储了每个结点的顺序
        		current = current->left;
        	}
        	current = mystack.top(); //当前左子树访问完毕的结点会出现在栈顶
        	mystack.pop(); 
        	result.push_back(current->val);
        	current = current->right;
        }
        return result;
    }
};

int main() {
	Solution solution;
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	t1->right = t2;
	t2->left = t3;
	vector<int> result = solution.inorderTraversal(t1);
	for(int i = 0;i < result.size();i++) {
		cout << result[i] << endl;
	}
}