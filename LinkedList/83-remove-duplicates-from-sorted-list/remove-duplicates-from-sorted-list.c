/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;

    struct ListNode* dummy = head;
    struct ListNode* prev = head;

    while (head != NULL){
        if (head->val != prev->val){
            prev->next = head;
            prev = prev->next;
            head = head->next;
        }
        else{
            head = head->next;
        }
    }
    prev->next = NULL;
    return dummy;
}