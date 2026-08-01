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
    Node* connect(Node* root) {
        if( !root) return root;

        queue<Node * > st;

        st.push(root);
        st.push(nullptr);

        while( !st.empty()){
            Node * a = st.front();
            st.pop();
            if( a ==nullptr && !st.empty()){
                st.push(nullptr);
                continue;
            }else if( a ==nullptr && st.empty()){
               continue;
            }
            
            else {a->next = st.front();
            if( a->left){
                st.push(a->left);
            }
            
            if( a->right){
                st.push(a->right);
            }}
        }

        return root;
        
    }
};