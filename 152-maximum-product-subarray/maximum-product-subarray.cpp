class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
      
    int a = nums[0]; // current minimum
    int b = nums[0]; // current maximum
    int ans = nums[0];

    for(int i = 1; i < nums.size(); i++) {

        int oldA = a;
        int oldB = b;

        a = min({nums[i], oldA * nums[i], oldB * nums[i]});
        b = max({nums[i], oldA * nums[i], oldB * nums[i]});

        ans = max(ans, b);
    }

    return ans;

    }
};