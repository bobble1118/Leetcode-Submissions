/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n = 1;
        int res = 0;
        ListNode* curr = head;

        while(curr){
            n <<= 1;
            curr = curr->next;
        }

        while(head){
            n >>= 1;
            res += n * head->val;
            head = head->next;
        }
        return res;
    }
};