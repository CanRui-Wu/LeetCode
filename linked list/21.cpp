#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
        	return l2;
        else if(l2 == NULL)
        	return l1;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head_before = new ListNode(-1);
        ListNode *cur = head_before;
        while(p1 != NULL || p2 != NULL) {
        	if(p1 == NULL) {
        		cur->next = p2;
        		p2 = p2->next;
        	} else if(p2 == NULL) {
        		cur->next = p1;
        		p1 = p1->next;
        	} else if(p1->val <= p2->val) {
        		cur->next = p1;
        		p1 = p1->next;
        	} else {
        		cur->next = p2;
        		p2 = p2->next;
        	}
        	cur = cur->next;
        }
        return head_before->next;
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
	p1_1->next = p1_2;
	p1_2->next = p1_3;
	p2_1->next = p2_2;
	p2_2->next = p2_3;
	ListNode *result = solution.mergeTwoLists(p1_1,p2_1);
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
}