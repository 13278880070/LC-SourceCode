/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// 两两交换相邻结点.
public:
    ListNode* swapPairs(ListNode* head) {	// 个人解法, 画图, 奇偶, 规律
       	if(head->next == NULL) return head;
       	ListNode* head1 = head;
       	ListNode* head2 = head->next;
       	ListNode* node1 = head1;
       	ListNode* node2 = head2;
       	head = node2;
       	while (head1 != NULL && head2 != NULL) {
       		head1->next = head1->next->next;
       		head1 = head1->next;
       		if(head1 == NULL) break;
       		head2->next = head2->next->next;
       		head2 = head2->next;
       	}
       	head1 = node1;
       	head2 = node2;

       	// 处理完成
       	while (node1 != NULL) {
       		node1 = head2->next;
       		head2->next = head1;
       		head2 = node1;

       		if(node1 == NULL) return head;

       		node1 = head1->next;
       		head1->next = head2;
       		head1 = node1;
       	}
       	return head;
    }
};