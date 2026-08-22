class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> freq;  //stores elt and its freq

        for( auto i: answers){

            freq[i]++;
        }
        int ans=0;
        for( auto i:freq){

            int a = i.first;
            int b = i.second;   // b represent freq

            if( a<b-1){

                int q = (b/(a+1))*(a+1);
                if( b%(a+1)!=0){
                    q+=a+1;
                }
                ans+=q;
            }else{
                ans+=a+1;
            }
        }
        return ans;
    }
};