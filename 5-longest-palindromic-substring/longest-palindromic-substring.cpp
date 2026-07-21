class Solution {
public:
    string longestPalindrome(string s) {

        int st =-1;
        int end =-1;
        int ans = -1;

        for( int i =0;i< s.size();i++){

            int l = i ; int r = i+1;   // for even palindrome;

            while( (l>=0 && r<s.size()) && s[l]==s[r]){

                if( r-l+1 >ans){
                    ans = r-l+1;
                    st = l;  end = r;
                }
                l--; r++;
            }

              l = i;  r =i ;  //for odd palindrome 
            
            while( (l>=0 && r<s.size()) && s[l]==s[r]){

                if( r-l+1 >ans){
                    ans = r-l+1;
                    st = l;  end = r;
                }
                l--; r++;
            }

        }
        return  s.substr(st, end-st+1);   //substr(starting index,length of string);

        
    }
};