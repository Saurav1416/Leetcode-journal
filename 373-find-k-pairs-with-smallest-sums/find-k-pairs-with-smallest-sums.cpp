class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
         vector<vector<int>>ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;

        for(int i =0;i<nums2.size();i++){
            pq.push({ nums1[0]+nums2[i],0,i});
        }

        while(k-- && !pq.empty()){
           vector<int> curr = pq.top();
            pq.pop();
            
            int i = curr[1];
            int j =curr[2];
            ans.push_back({nums1[i],nums2[j]});
            if (i + 1 < nums1.size()) {
                pq.push({nums1[i+1] + nums2[j], i+1, j});
            }


            
        }
        return ans;
    }
};