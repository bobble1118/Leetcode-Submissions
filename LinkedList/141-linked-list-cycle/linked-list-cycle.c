/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head) return false;
    
    struct ListNode * ptr1 = head;
    struct ListNode * ptr2 = head;

    while (ptr2 != NULL){
        if (ptr2->next == NULL){
            break;
        }
        else{
            ptr2 = ptr2->next;
        } 
        if (ptr1 == ptr2) return true;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return false;
}