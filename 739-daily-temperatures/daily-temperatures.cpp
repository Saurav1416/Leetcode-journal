class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<pair<int,int>> stack;    //we store temp,index 
        vector<int>ans(temperatures.size(),0);
        int index;
        for(int i =0;i<temperatures.size();i++){

            while( !stack.empty() && temperatures[i]> stack.back().first){
                    index = stack.back().second;
                    ans[index]=i-index;
                    stack.pop_back();
            }

            stack.push_back({temperatures[i],i});
        }
        return ans;
        
    }
};