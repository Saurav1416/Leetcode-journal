class Solution {
public:
    string reverseParentheses(string s) {

        vector<int>st;

        for( int i =0;i< s.size();i++){

            if( s[i]=='(') st.push_back( i);
            else if( s[i]==')'){
                int x = st.back();
                st.pop_back();
                int len = i-x+1;
                reverse(s.begin()+ x,s.begin()+x+len );
            }
        }
        string ans = "";
        for( int i =0;i<s.size();i++){
            if( s[i] >= 'a' && s[i] <= 'z'){
                ans+=s[i];
            }
        }
        return ans;
        
    }
};