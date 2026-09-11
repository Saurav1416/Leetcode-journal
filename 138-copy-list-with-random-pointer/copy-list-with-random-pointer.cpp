/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( !head ) return nullptr;
        Node * dummy = new Node ( head->val);
        Node * t = dummy;
        unordered_map<Node* ,Node *> news;
        news[head] = t;
        news[nullptr] = nullptr;

        while( head){
                // creating next 
            if( news.find( head->next)!=news.end()){
                t->next = news[head->next];

            } 
            else{
                t->next = new Node ( head->next->val);
                news[head->next] = t->next;
            }


             if( news.find( head->random)!=news.end()){
                t->random = news[head->random];

            } 
            else{
                t->random= new Node ( head->random->val);
                news[head->random] = t->random;
            }

            head= head->next;
            t = t->next;

        }
        return dummy;
        
    }
};