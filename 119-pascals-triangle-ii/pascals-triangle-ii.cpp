class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> ans( rowIndex+1, 1);

        for( int i =0;i< rowIndex;i++){
            vector<int> helper( i+1, 1);

            for( int j =0;j<=i;j++){

                if( (j-1)>=0){
                    helper[j]=ans[j]+ans[j-1];

                    
                }
                
                
            }
            

            for( int j =0;j<helper.size();j++){

                ans[j]= helper[j];
            }
        }

        return ans;
        
    }
};