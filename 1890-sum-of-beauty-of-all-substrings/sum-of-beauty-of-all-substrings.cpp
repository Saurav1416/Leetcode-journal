class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int freq[26] = {0};

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int cmax = 0;
                int cmin = INT_MAX;

                // Scan 26 frequencies to find true max and min non-zero frequencies
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        cmax = max(cmax, freq[k]);
                        cmin = min(cmin, freq[k]);
                    }
                }

                ans += (cmax - cmin);
            }
        }
        return ans;
    }
};
