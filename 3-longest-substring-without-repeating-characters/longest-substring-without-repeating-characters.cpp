class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int l =0;
        
        // unordered_map<char,int > a; 
        // int maxx = 0;
        // for(int r =0;r< s.size();r++){

        //     if( a.find(s[r])!= a.end()){

        //         l = max ( l, a[s[r]]+1);
        //     }

        //     a[s[r]]=r;
        //     maxx = max( maxx, r-l+1);
        // }
         

        //  return maxx;


        
    unordered_map<char,int>um ;            //stores char and index
    int maxlen=0;
    int st = 0;
    for( int i =0; i<s.size();i++){

        if( um.find(s[i])!= um.end()){
            if( st<=um[s[i]])
            st= um[s[i]]+1;
            
        }
        maxlen= max(maxlen, i-st+1);

        um[s[i]]=i;
    }
    return maxlen;
    }
};