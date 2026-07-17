class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int l =prices[0];
        // int profit = INT_MIN;
        // for(int i =1;i< prices.size();i++){
        //     profit= max(prices[i]-l,profit);
        //     l = min( l,prices[i]);
        // }
        // if( profit <0) return 0;
        // return profit;




















        int min = INT_MAX;
        int maxx = 0;
        int profit =0;

        for(int i =0 ;i< prices.size();i++){

            if( prices[i]<min){
                min=prices[i];
                maxx=0;

            }else if( prices[i]>maxx){
                maxx = prices[i];
                profit = max(profit,maxx-min);
            }
        }
        return profit ;
    }
    
};