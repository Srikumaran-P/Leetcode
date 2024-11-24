/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head==NULL || head->next==NULL)
        return true;
    struct ListNode *fast=head, *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode *next=NULL, *prev=NULL, *current=slow;
    while (current!=NULL)
    {
        next = current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    struct ListNode *frontH=head, *midH=prev;
    while(midH!=NULL)
    {
        if ((frontH->val) != (midH->val))
            return false;
        frontH=frontH->next;
        midH=midH->next;
    }
    return true;
}
