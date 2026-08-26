class Solution {
public:
    string convert(string s, int n) {

        if ( n==1 || n>=s.size()) return s;

        int strsize = s.size();

        vector<string>arr( n,"");

        int i =0;
        int k =0;

        while( i< s.size() ){

            for( int j =0;j<n && i <s.size(); j++){

               arr[j]+=s[i];
                i++;
            }
            
           int t =n-2;

           while( i<strsize && t>0){
            arr[t]+=s[i];
            i++;
            t--;
           }
        }
        string ans = "";
        for( int i =0;i<arr.size();i++){

           ans+= arr[i];
        }
        return ans;


       
        
    }
};