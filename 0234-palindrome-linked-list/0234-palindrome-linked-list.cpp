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
    ListNode* ReverseLinkedList(ListNode* head){
        ListNode* temp=head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* newHead = temp->next;
            temp->next = prev;
            prev=temp;
            temp=newHead;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead = slow->next;
        newHead = ReverseLinkedList(newHead);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second!=NULL){
            if(first->val!=second->val){
                newHead = ReverseLinkedList(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        ReverseLinkedList(newHead);
        return true;
    }
};