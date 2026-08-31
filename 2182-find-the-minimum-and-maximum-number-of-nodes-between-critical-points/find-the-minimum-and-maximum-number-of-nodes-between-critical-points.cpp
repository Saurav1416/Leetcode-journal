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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if( !head->next->next){
            return {-1,-1};
        }

        int first=-1;
        
        int curr;
        int ans=INT_MAX;

        ListNode * a = head->next;
        ListNode * prev= head;
       int  t = 1;

        while(a && a->next){

            if( a->val > prev->val && a->val > a->next->val){
                if( first ==-1){
                    first = t;
                    curr =t;
                }
                else {
                    ans = min(ans , t-curr);
                }
                curr =t;


                
            }

            else if( a->val < prev->val && a->val < a->next->val){
                if( first ==-1){
                    first = t;
                    curr =t;
                }
                 else {
                    ans = min(ans , t-curr);
                }
                curr =t;
                
            }

            prev=a; 
            a=a->next;
            t++;

           


        }
        if( first ==-1 || curr == first) return {-1,-1};
         return { ans, curr-first};
        



        
        
    }
};