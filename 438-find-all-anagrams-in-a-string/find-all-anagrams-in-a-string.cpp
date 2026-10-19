class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();

        if (m > n) return {};

        vector<int> pFreq(26, 0);
        vector<int> winFreq(26, 0);

        for (char c : p)
            pFreq[c - 'a']++;

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            // add current character
            winFreq[s[i] - 'a']++;
           // removecharacter outside window
            if (i >= m)
                winFreq[s[i - m] - 'a']--;

            // check when window size becomes m
            if (i >= m - 1) {
                if (winFreq == pFreq)
                    ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};