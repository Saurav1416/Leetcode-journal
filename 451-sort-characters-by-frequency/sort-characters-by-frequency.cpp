class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> a;

        for( int j=0;j<s.size();j++){
            a[s[j]]++;
        }
        vector<vector<char>> b(s.size()+1) ;
        for(auto i: a){
            b[i.second].push_back(i.first);
        }
        string ans ="";
        for( int i = b.size()-1;i>0;i--){
            for( char v: b[i]){
                ans.append(i,v);
            }
        }
        return ans;


    }
};