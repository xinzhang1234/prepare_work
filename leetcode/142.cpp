/*142. Linked List Cycle II
 *Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *first, *second;
        first = head;
        second = head;
        while(second && second->next)
        {
            first = first->next;
            second = second->next ? second->next->next : NULL;
            if (first == second)
            {
                second = head;
                while(first!=second)
                {
                    first = first->next;
                    second = second->next;
                }
                return second;
            }
        }
        return NULL;
        
    }
};
