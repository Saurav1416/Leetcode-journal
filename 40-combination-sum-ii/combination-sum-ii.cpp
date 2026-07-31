class Solution {
public:

    void solve( int sum ,int node ,int target,vector<int> &ans, vector<vector<int>> & anss ,
    vector<int>& candidates
    ){

        if( sum > target) return ;

        if( sum == target){
            anss.push_back( ans);
            return;
        }

        for( int i =node ;i<candidates.size();i++){

            if ( i>node && candidates[i]==candidates[i-1]){
                continue;
            }

            if( sum+ candidates[i]<=target){
                ans.push_back(candidates[i]);
                solve(sum+candidates[i], i+1,target,ans,anss,candidates);
                ans.pop_back();
            }


        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int>ans;
        vector<vector<int>>anss;
        sort( candidates.begin(),candidates.end());

        solve( 0,0, target,ans,anss,candidates);

        return anss;
        
    }
};