/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *temp;
    while (curr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* p2 = reverse(slow);
    struct ListNode* p1 = head;

    while (p2) { 
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}