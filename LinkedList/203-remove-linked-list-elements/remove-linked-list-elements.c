/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) return NULL;
    
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* curr = dummy;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next; 
            curr->next = curr->next->next;      
            free(temp);                         
           
        } else {
            curr = curr->next;
        }
    }
    
    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}