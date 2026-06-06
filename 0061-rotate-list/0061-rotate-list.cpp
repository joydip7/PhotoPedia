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
    ListNode* findNewLastNode(ListNode* temp, int k){
        k--;
        while(k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
    return head;
        ListNode* tail = head;
        int length=1;
        while(tail->next!=NULL){
            length++;
            tail=tail->next;
        }
        if(k%length==0) return head;
        k = k%length;
        tail->next = head;
        ListNode* newlastNode = findNewLastNode(head,length-k);
        head = newlastNode ->next;
        newlastNode->next = NULL;

        return head;
    }
    
};