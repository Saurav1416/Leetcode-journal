class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> um ; //stores last index ;

        int prevelt=-1;
        int currelt=fruits[0];
        um[-1] = -1;
        um[fruits[0]]=0;
        int cnt =0;
        int ans =0;

        for( int i =0;i<fruits.size();i++){

                if( fruits[i]!= currelt && fruits[i]!= prevelt){
                    cnt = i -um[prevelt];
                    prevelt= currelt;
                    currelt= fruits[i];
                }
                else{
                    if( currelt!=fruits[i]){
                        prevelt= currelt;
                        currelt= fruits[i];
                    }
                    cnt++;
                }
                 um [fruits[i]] =i;
                 ans = max( ans, cnt);

                
        }
        return ans;

        
    }
};