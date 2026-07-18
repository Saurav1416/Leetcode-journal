class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         vector<pair<int,int>>a;
        for(int i =0;i<matrix.size();i++){
            for (int j =0;j<matrix[0].size();j++){

                if( matrix[i][j]==0){
                    a.push_back({i,j});
                }
            }
        }
        for(auto i: a){
            auto row=i.first;
            auto col =i.second ;
            setrowzero(row,matrix);
            setcolzero(col,matrix);
        }
    }
    void setrowzero(int i , vector<vector<int>>& matrix){
        vector<int> a ( matrix[0].size(),0);
        matrix[i]=a;
    }
    void setcolzero(int j , vector<vector<int>>& matrix){
        for(int i =0;i<matrix.size();i++){
            matrix[i][j]=0;
        }
    }
};