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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==n){
            ListNode* nextHead = head->next;
            delete head;
            return nextHead;
        }
        temp=head;
        int result = count - n;
        while(temp!=NULL){
            result--;
            if(result==0) break;
            temp=temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next= temp->next->next;
        delete delNode;
        return head;
    }
};