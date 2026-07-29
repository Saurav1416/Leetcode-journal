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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = head;
        ListNode * prev =nullptr;
        while( dummy  && dummy->next){

            if(dummy->val !=dummy->next->val){
                prev = dummy;
                
                dummy=dummy->next;
            }
            else  {
                ListNode * a = dummy;
                 while ( a && a->next && a->val ==a->next->val){
                    a= a->next ;
                 }
                 if( !prev) head = a->next;
                 else prev->next = a->next;
                 dummy =a->next;
            }
        }

        return head;
        
    }
};