class Solution {
public:
    string reverseWords(string s) {
        
         int i =0;
         bool anotherspace =false;
        string ans ="";
        while( s[i]==' ' ){
            i++;
        }
        int e = s.size()-1;
        while( s[e]==' '){
            e--;
        }
        stack<char>st;
        for( int j =e ; j>=i ;j--){

                if( (s[j]!=' ' && j!=i) ){
                    st.push(s[j]);
                    anotherspace = false;
                    
                }else if (s[j]==' '  ){

                    while( !st.empty()){
                        char a =st.top();
                        st.pop();
                        ans+=a;
                        

                    }
                    if( anotherspace==false)
                    {ans+=s[j];
                    anotherspace=true;}
                }else if( j==i){

                    st.push(s[j]);
                    while( !st.empty()){
                        char a =st.top();
                        st.pop();
                        ans+=a;
                    }

                }
        }
        return ans;
    }
};