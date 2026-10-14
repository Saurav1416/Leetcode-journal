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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if( lists.size()==0) return nullptr;

        ListNode * dummy  = new ListNode( 0);
        ListNode * temp = dummy;

        ListNode * minnnode = lists[0];
        int j =0;
        int b =1;
        
        while( b){

            b =0;
           for( int i =0;i<lists.size();i++ ){

             if( lists[i]){
                b =1;
                if( !minnnode || lists[i]->val< minnnode->val){
                    minnnode = lists[i];
                    j =i;
                }
            }


           }
           if( b ==1)
           {dummy->next = minnnode ;
           dummy= dummy->next;
           minnnode = nullptr;
           lists[j] = lists[j]->next;}
        }
        return temp->next;

        
    }
};