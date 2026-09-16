class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string,int>mp;   // count 
        if( s.size()<10) return {};

        string a = s.substr( 0, 10);
        mp[a]++;
        vector<string> ans;
        int l =1;
        for( int i =10;i<s.size();i++){
           
            string x = s.substr(l,10);
            if(mp.count(x) && mp[x]==1){
                ans.push_back(x);
            }
           mp[x]++;
            l++;
        }
        return ans;
    }
};