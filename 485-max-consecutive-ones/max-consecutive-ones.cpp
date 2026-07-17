class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, maxx = 0;
    for (int x : nums) {
        if (x == 1) {
            count++;
            maxx = max(maxx, count);
        } else {
            count = 0;
        }
    }
    return maxx;
}
};