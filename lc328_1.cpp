/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// 奇数下标组合在一起, 偶数下标组合在一起.
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *odd = head, *even = head->next;

        ListNode *ehead = even, *ohead = odd;

        while (odd && even) {
        	odd->next = even->next;
        	if (!odd->next) break;
        	odd = odd->next;

        	even->next = odd->next;
        	even = even->next;
        }

        odd->next = ehead;

        return ohead;
    }
};