/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode * pointA = headA;
    struct ListNode * pointB = headB;

    while (pointA != pointB){
        pointA = (pointA != NULL) ? pointA->next : headB;
        pointB = (pointB != NULL) ? pointB->next : headA;
    }
    return pointA;
}