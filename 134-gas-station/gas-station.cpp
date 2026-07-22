class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int sum =0;
        for ( int i =0; i< gas.size( );i++){

            gas[i]= gas[i]-cost[i];
            sum+= gas[i];
        }
        if( sum<0){
            return -1;
        }
        int index = 0;
        int currgas=0;
        for( int i =0;i< gas.size();i++){
            currgas+=gas[i];
            if(currgas<0){
                currgas=0;
                index = i+1;
            }
        }

        return index;
    }
};