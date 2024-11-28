struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode *return_list    = NULL;

    struct ListNode *next_headA     = NULL;
    struct ListNode *next_headB     = NULL;

	if(headA == NULL || headB == NULL)
	{
		return_list == NULL;
		goto end_of_function;
	}

	next_headA = headA;
	next_headB = headB;

    while (next_headA != next_headB)
    {
        next_headA = (next_headA == NULL) ? headB : next_headA->next;
        next_headB = (next_headB == NULL) ? headA : next_headB->next;
    }

	return_list = next_headA;

end_of_function:
    return return_list;
}
