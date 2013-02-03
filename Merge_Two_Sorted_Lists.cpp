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

    /* Iterative */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    ListNode *temp_head = NULL;
    ListNode *to_attach = NULL;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    
    if (l1->val > l2->val)
    {
        temp_head = l2;
        l2 = l2->next;
    }
    else
    {
        temp_head = l1;
        l1 = l1->next;
    }
    
    to_attach = temp_head;
    
    ListNode *rest = NULL;
    
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val > l2->val)
        {
            rest = l2->next;
            l2->next = l1;
            to_attach->next = l2;
            to_attach = to_attach->next;
            l2 = rest;
        }
        else
        {
            rest = l1->next;
            l1->next = l2;
            to_attach->next = l1;
            to_attach = to_attach->next;
            l1 = rest;
        }
    }
    
    if (l1 == NULL)
        to_attach->next = l2;
    if (l2 == NULL)
        to_attach->next = l1;
    
    return temp_head;
    }
};
