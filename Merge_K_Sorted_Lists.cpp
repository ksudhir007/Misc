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

    /* Recursive */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *temp_head = NULL;
        if(l1 == NULL)
          return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val < l2->val)
        {
            temp_head = l1;
            temp_head->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            temp_head = l2;
            temp_head->next = mergeTwoLists(l1, l2->next);
        }
        return temp_head;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head_to_return = NULL;
        int size = lists.size();
        int c;
        for (c = 0; c < size; c++)
        {
            if (lists[c] != NULL)
            {
                head_to_return = lists[c];
                break;
            }
        }
        for (int i=0; i < size; i++)
        {
            if ((i+1) < size && (i+1 != c))
                head_to_return = mergeTwoLists(head_to_return, lists[i+1]);
                
        }
        return head_to_return;
    }
};
