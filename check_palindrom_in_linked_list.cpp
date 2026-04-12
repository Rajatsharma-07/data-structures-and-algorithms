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

    ListNode* reverseLinkedList(ListNode* node) {
        ListNode* prev = NULL;
        ListNode* nex = NULL;
        while(node) {
            nex = node -> next;
            node -> next = prev;
            prev = node;
            node = nex;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        slow -> next = reverseLinkedList(slow -> next);
        slow = slow -> next;

        while (slow) {
            if (slow -> val != head -> val) {
                return false;
            }
            slow = slow -> next;
            head = head -> next;
        }
        return true;
    }
};
