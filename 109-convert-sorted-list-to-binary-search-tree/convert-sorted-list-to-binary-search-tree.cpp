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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* findmid( ListNode * start, ListNode * end){

        if( !start  || start ==end){
            return nullptr;
        }

        
        ListNode * slow = start;
       ListNode *  fast = start;

        while( fast!=end  && fast->next !=end){
            slow = slow->next;
            fast = fast->next->next;
        }
       
        return slow;

    }
    TreeNode * solve( ListNode * start, ListNode * end){

        if ( !start  || start ==end){
            return nullptr;
        }
        

        ListNode* a = findmid( start,end);
        
         TreeNode * b = new TreeNode ( a->val);
        b->left = solve( start, a);
        b->right = solve( a->next , end);

        return b;
    }
    TreeNode* sortedListToBST(ListNode* head) {

        return solve( head, nullptr);

        
    }
};