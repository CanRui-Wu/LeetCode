#include <iostream>
using namespace std;

struct ListNode {
	int val;	
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
//Quick Sort Version
// class Solution {
// public:
//     void sortListMain(ListNode *pre_head,ListNode *tail) {
//         if(pre_head->next == tail)
//             return;
//         ListNode *current = pre_head->next;
//         ListNode *pivot = current;
//         ListNode *pre = pre_head;
//         while(current->next && current->next != tail) {
//             if(current->next->val < pivot->val) {
//                 ListNode *temp = pre->next;
//                 pre->next = current->next;
//                 current->next = current->next->next;
//                 pre->next->next = temp;
//             } else {
//                 current = current->next;
//             }
//         }
//         sortListMain(pre_head,pivot);
//         while(pivot->next != tail && pivot->next->val == pivot->val)
//             pivot = pivot->next;
//         sortListMain(pivot,tail);
//     }

//     ListNode* sortList(ListNode* head) {
//     	if(head == NULL || head->next == NULL)
//     		return head;
//     	ListNode *temp = new ListNode(0);
//         temp->next = head;
//         sortListMain(temp,NULL);
//         ListNode *result = temp->next;
//         delete temp;
//         return result;
//     }
// };

//Merge Sort Version,From UP to Bottom
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if(head == NULL || head->next == NULL)
//             return head;
//         ListNode *mid = head,*current = head;
//         while(true) {
//             current = current->next;
//             if(current == NULL)
//                 break;
//             current = current->next;
//             if(current == NULL)
//                 break;
//             mid = mid->next;
//         }
//         ListNode *temp = mid->next;
//         mid->next = NULL;
//         ListNode *head1 = sortList(head);
//         ListNode *head2 = sortList(temp);
//         ListNode *result;
//         if(head1->val <= head2->val) {
//             result = head1;
//             head1 = head1->next;
//         } else {
//             result = head2;
//             head2 = head2->next;
//         }
//         current = result;
//         int one_or_two = 1;
//         while(head1 != NULL || head2 != NULL) {
//             if(head1 == NULL)
//                 one_or_two = 2;
//             else if(head2 == NULL)
//                 one_or_two = 1;
//             else if(head2->val < head1->val)
//                 one_or_two = 2;
//             else
//                 one_or_two = 1;
//             if(one_or_two == 1) {
//                 current->next = head1;
//                 head1 = head1->next;
//             } else {
//                 current->next = head2;
//                 head2 = head2->next;
//             }
//             current = current->next;
//         } 
//         return result;
//     }
// };


int main() {
	ListNode *t1 = new ListNode(6);
	ListNode *t2 = new ListNode(3);
	// ListNode *t3 = new ListNode(5);
	// ListNode *t4 = new ListNode(7);
	// ListNode *t5 = new ListNode(4);
	t1->next = t2;
	// t2->next = t3;
	// t3->next = t4;
	// t4->next = t5;
	ListNode *current = t1;
	Solution solution;
	current = solution.sortList(t1);
	while(current != NULL) {
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
    delete t1;
    delete t2;
    // delete t3;
    // delete t4;
    // delete t5;
}