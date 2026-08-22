class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;  //stores element and freq

        for( auto i: hand){
            mp[i]++;
        }

        for( auto i: mp){

            if( i.second==0)
                continue;
            int x =i.second;


            for( int j =0;j<groupSize;j++){
                 if( mp.find(i.first+j)==mp.end() || mp[i.first+j]<x){
                    return false;
                 }
                 mp[i.first+j]-=x;

            }
            
        }
        return true;
        
    }
};