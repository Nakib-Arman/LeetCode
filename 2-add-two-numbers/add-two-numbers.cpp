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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *result,*prev;
        int i=0;
        while(l1!=NULL || l2!=NULL){
            int l1_val=0,l2_val=0;
            if(l1!=NULL) l1_val = l1->val;
            if(l2!=NULL) l2_val = l2->val;
            int temp = l1_val + l2_val + carry;
            int value;
            if(temp>=10){
                value = temp%10;
                carry = 1;
            }
            else {
                value = temp;
                carry = 0;
            }
            ListNode* node = new ListNode(value);
            if(i==0){
                result = node;
                i=1;
            }
            else{
                prev->next = node;
            }
            prev = node;
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        if(carry == 1) {
            ListNode* node = new ListNode(1);
            prev->next = node;
        }
        return result;
    }
};