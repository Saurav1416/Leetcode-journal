class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int left =0;
        int right =0;

        queue<char>q;
        string ans="";

        for(auto i :s){

            if( i =='('){
                left++;
                q.push(i);
            }
            else {
                right++ ;
                q.push(i);
            }

            if( left ==right && left!=0){
                q.pop();
                while( !q.empty()){
                    char x = q.front();
                    q.pop();
                    if( !q.empty()){
                        ans+=x;
                    }
                }
                left =0;
                right =0;

            }
        }
        return ans;
    }
};