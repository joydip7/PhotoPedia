/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int>mpp;
        ListNode* temp = headA;
        if(headA==NULL || headB==NULL) return NULL;
        while(temp!=NULL){
            mpp[temp] = 1;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL){
            if(mpp[temp]) return temp;

            temp=temp->next;
        }
        return NULL;
    }
};