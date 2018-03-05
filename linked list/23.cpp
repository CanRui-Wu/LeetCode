#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> temp_lists = lists;
        ListNode* result = new ListNode(-1);
        ListNode* current = result;
        while(true) {
    		int ok = 0;    	
        	for(const auto &p:temp_lists) {
        		if(p != NULL) {
        			ok = 1;
        			break;
        		}
        	}
        	if(ok == 0) {
        		break;
        	}
        	int min = INT_MAX,min_index;
        	for(int i = 0;i < temp_lists.size();i++) {
        		if(temp_lists[i] == NULL)
        			continue;
        		if(temp_lists[i]->val < min) {
        			min = temp_lists[i]->val;
        			min_index = i;
        		}
        	}
        	current->next = temp_lists[min_index];
        	current = current->next;
        	temp_lists[min_index] = temp_lists[min_index]->next;
        }
        return result->next;
    }
};

int main() {
	Solution solution;
	ListNode *p1_1 = new ListNode(1);
	ListNode *p1_2 = new ListNode(2);
	ListNode *p1_3 = new ListNode(4);
	ListNode *p2_1 = new ListNode(1);
	ListNode *p2_2 = new ListNode(3);
	ListNode *p2_3 = new ListNode(4);
	ListNode *p3_1 = new ListNode(2);
	ListNode *p3_2 = new ListNode(3);
	ListNode *p3_3 = new ListNode(5);
	p1_1->next = p1_2;
	p1_2->next = p1_3;
	p2_1->next = p2_2;
	p2_2->next = p2_3;
	p3_1->next = p3_2;
	p3_2->next = p3_3;
	vector<ListNode*> lists;
	ListNode *result = solution.mergeKLists(lists);
	while(result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	while(p1_1 != NULL) {
		cout << p1_1->val << " ";
		p1_1 = p1_1->next;
	}
	cout << endl;
	while(p2_1 != NULL) {
		cout << p2_1->val << " ";
		p2_1 = p2_1->next;
	}
	cout << endl;
	while(p3_1 != NULL) {
		cout << p3_1->val << " ";
		p3_1 = p3_1->next;
	}
	cout << endl;
}