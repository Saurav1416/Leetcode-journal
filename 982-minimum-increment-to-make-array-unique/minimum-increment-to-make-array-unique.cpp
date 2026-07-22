class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        
        int x =0;       //x remembers the last seen elt 
        int count =0;

        unordered_map<int,int>um;
        sort( arr.begin(),arr.end());

        for(int i =0;i<arr.size();i++){

            if( um[arr[i]]!=0){
                 count+= x+1-arr[i];
                arr[i]= x+1;
                
               
               
            }
                um[arr[i]]++;
                 x=arr[i];
            
        }
        return count;
    }
};