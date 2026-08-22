class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char,int> um;   //stores char and last index;

        for(int i =0;i< s.size();i++){

            um[s[i]]=i;

        }
        int lastind = -1;
        int prev=-1;
        vector<int>ans;
        for( int i =0;i<s.size();i++){

            lastind = max( lastind, um[s[i]]);

            if( lastind==i){
                ans.push_back(lastind-prev);
                prev= lastind;
                lastind=-1;
            }
        }

        return ans;

        
    }
};