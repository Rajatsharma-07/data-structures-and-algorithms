class Solution{
    public:
        ListNode* merge(ListNode* list1, ListNode* list2) {
            ListNode* dummy = new ListNode(0);
            ListNode* res = dummy;

            while(list1 != NULL || list2 != NULL) {
                if (list1 -> val < list2 -> val) {
                    res -> child = list1;
                    list1 = list1 -> next;
                    res = res -> child;
                } else {
                    res -> chile = list2;
                    list2 = list2 -> next;
                    res = res -> child;
                }
            }

            if (list1) {
                res -> child = list1;
            }

            if (list2) {
                res -> child = list2;
            }

            if (dummy -> child) {
                dummy -> child -> next = NULL;
            }
            return dummy -> child;
        }

        ListNode* flattenLinkedList(ListNode* head) {
            if (head == NULL || head -> next == NULL) {
                return NULL;
            }

            ListNode* mergedNode = flattenLinkedList(head -> next);

            head = merge(head, mergedNode);
            return head;
        }
}