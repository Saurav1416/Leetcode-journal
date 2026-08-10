class Solution {
public:
    void bar(vector<vector<char>>& matrix,vector<int>&area,int node ){
        int count;
        for( int i =0;i<matrix[0].size();i++){

             count =0;
            for( int j =node ;j>=0;j--){
                if( matrix[j][i]=='0'){
                   break;
                }
                 count++;
            }
            area[i]= count;
        }
    }
    int solve( vector<vector<char>>& matrix,vector<int>& area ){

        vector<pair<int,int>> st;
        pair<int,int> p;
        int ans=-1;
        int m = matrix[0].size();

        for( int i =0;i< area.size();i++){
            int index=i;
            
            while( !st.empty() && st.back().second>=area[i]){

                p = st.back();
                index = p.first;
                st.pop_back();
                ans = max( ans, (i-p.first)*p.second);
            }
            if( area[i]!=0){
                st.push_back( {index,area[i]});
            }
        }
        while( !st.empty()){
            ans = max( ans, (m-st.back().first) * st.back().second);
            st.pop_back();
        }
        return ans;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int ans =-1;

        for( int i =0;i<matrix.size();i++){
            vector<int>area(matrix[0].size(),0);
            bar( matrix,area,i);

            ans = max( ans,solve(matrix,area));
        }
        return ans==-1?0:ans;

        
    }
};