class Solution {
public:
    string simplifyPath(string path) {

        int i =0;
        stack<string>st;
        int eleminstack=0;
        string ans="";
        
        while( i<path.size()){

            while( i< path.size() && path[i]=='/'){
                i++;
            }

            string s="/";
            int count =0;
            
            while( i<path.size( ) && path[i]!='/' ){
                 s+=path[i];
                 count++;
                 i++;
            }
            if (s == "/.") {
                continue;
            }
            else if( s=="/.."){
                if( !st.empty()) st.pop();
            }else if( count){
                st.push(s);
            }



        }

        while( !st.empty()){
           string a = st.top()+ ans;
           st.pop();
           ans = a;
           

        }
        return ans.size()==0?"/":ans;
        
        
    }
};