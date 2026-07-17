class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0;i<matrix.size();i++){
            for(int j=i;j<matrix[i].size();j++){
                int temp = matrix[i][j];
                matrix[i][j]= matrix[j][i];
                matrix[j][i]=temp;
            }
        }
       
        for (int i =0;i<matrix.size();i++){
             int n = matrix.size()-1;
             int l =0;
             while( l<n){
                int temp = matrix[i][l];
                matrix[i][l]=matrix[i][n];
                matrix[i][n]=temp;
                l++;n--;
             }
             
        }
       
        

    }
};