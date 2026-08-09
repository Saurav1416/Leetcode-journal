class Solution {
public:

//    void setnext(vector<int>& next,vector<int>& heights ){

//     stack<int>st;
//     st.push(-1);
//     for(int i =heights.size()-1;i>=0;i--){

       

//            while (st.top() != -1 &&
//            heights[st.top()] >= heights[i]) {

//                  st.pop();
//              }
//             next[i]= st.top();
//             st.push(i);
        
//     }
//    }
//    void setprev(vector<int>& prev,vector<int>& heights ){

//     stack<int>st;
//     st.push(-1);
//     for (int i = 0; i < heights.size(); i++) {

//     while (st.top() != -1 &&
//            heights[st.top()] >= heights[i]) {

//         st.pop();
//     }

//     prev[i] = st.top();

//     st.push(i);
// }
 //  }
    int largestRectangleArea(vector<int>& heights) {

        // vector<int> prev(heights.size(),-1);   //find the  prev smaller elt than i
        //  vector<int> next(heights.size(),-1);   //find then next smaller elt than i 

        // setprev( prev,heights);
        // setnext(next, heights);
        // int ans = -1;

        // for( int i =0 ;i<heights.size();i++){
        //     if( next[i]==-1){
        //         next[i]=heights.size();
        //     }
        //     int breadth = next[i]-prev[i]-1;
        //     ans = max( ans, breadth* heights[i]);
        // }

        // return ans;


        vector<pair<int,int>> stack;
        pair<int,int>p;
        int index;
        int ans =-1;
        int n = heights.size();

        for( int i =0;i<heights.size();i++){
             index =i;

            while( !stack.empty() && stack.back().second>=heights[i]){

                p = stack.back();
                stack.pop_back();
                index =p.first;

                ans = max(ans, (i-p.first)*p.second);
            }

            stack.push_back({index,heights[i]});
        }

        while(! stack.empty()){
            p = stack.back();
            stack.pop_back();
            ans = max(ans,( n-p.first)*p.second);
        }

        return ans;
        
    }
};