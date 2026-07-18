class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> um;
        int maxLen = 0;

        for (int x : nums) {
            if (um[x] == 0) { 
                int left = um[x-1];
                int right = um[x+1];
                int length = left + right + 1;

                um[x] = length;
                um[x-left] = length;   // update left boundary not left elt
                um[x+right] = length;  // update right boundary

                maxLen = max(maxLen, length);
            }
        }
        return maxLen;
    }
};
