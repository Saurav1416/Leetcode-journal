/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve( Node * root, int ind, Node * parent){
        if( !root) return;

        if( parent && ind ==0){
            root->next = parent->right;
        }
        else if(parent && parent->next && ind == 1){
            root->next = parent->next->left;
        }

        solve( root->left , 0 ,root);
        solve( root->right,1,root);
    }
    Node* connect(Node* root) {

         if( !root) return root;

        // queue<Node* > q;

        // q.push( root);

        // while( !q.empty()){
        //     int size = q.size();

        //     for( int i =0;i< size;i++){

        //         Node * a = q.front();
        //         q.pop();
        //         if( a->left) q.push( a->left);
        //         if(a->right) q.push( a->right);
        //         if( i ==size-1){ continue;}
        //         a->next = q.front ();
                
        //     }

        // }
        // return root;


        solve( root, -1,nullptr);
        return root;
        
    }
};