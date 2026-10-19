class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int>reqfreq(26,0);
        vector<int>currfreq(26,0);

        for( int i =0;i< p.size();i++){
            reqfreq[p[i]-'a']++;
        }
        int l=0; vector<int>ans;
        for( int i =0;i< s.size();i++){

            if( reqfreq[s[i]-'a']==0){ l=i+1;
            currfreq= vector<int>( 26,0);}

            else{
                currfreq[s[i]-'a']++;
                
                while( reqfreq[s[i]-'a']<currfreq[s[i]-'a'] ){
                    currfreq[s[l]-'a']--;
                    l++;
                }
                if ( reqfreq==currfreq) ans.push_back( l);

            }
        }
        return ans;
        
    }
};