class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());  //  sorted word as key
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &p : mp) {
            ans.push_back(move(p.second));
        }
        return ans;
    }
};






















        


