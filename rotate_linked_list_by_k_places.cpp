/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* first = head;
        ListNode* second = head;
        int count = 1;
        while(first -> next != NULL) {
            first = first -> next;
            count++;
        }

        k = k % count;
        while (k > 0) {
            second = second -> next;
            k--;
        }
        
        first = head;
        while(second -> next != NULL) {
            first = first -> next;
            second = second -> next;
        }

        ListNode* temp = first;
        second -> next = head;
        first = first -> next;
        temp -> next = NULL;
        return first;
    }
};
