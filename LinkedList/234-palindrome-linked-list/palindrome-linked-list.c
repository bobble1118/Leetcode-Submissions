/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev;
    struct ListNode* temp;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    prev = slow, slow = slow->next, prev->next = NULL;
    while (slow != NULL){
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    fast = head, slow = prev;
    while(slow != NULL){
        if (slow->val != fast->val) return false;
        else{
            slow = slow->next;
            fast = fast->next;
        }
    }
    return true;
}