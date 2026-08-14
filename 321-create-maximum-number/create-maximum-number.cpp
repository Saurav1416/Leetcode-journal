class Solution {
public:
    vector<int> maxlex(vector<int> nums, int k ){

        if( k>nums.size()) return {};
        if( k == nums.size()) return nums;

        vector<int > a ;
        int n = nums.size();
        int t =k;
        
        for( int i =0;i<n;i++){

            while(!a.empty()&& a.back()<nums[i] && n-i-t>=1 ){
                a.pop_back();
                t++;
            }

            a.push_back( nums[i]);
            t--;
        }
        a.resize(k);
        return a;
    }

    vector<int> merge( vector<int>a , vector<int>b){

        vector<int >ans;

        int x =0;int y =0;

        while( x<a.size() && y <b.size()){

            if( a[x]>b[y]){
                ans.push_back(a[x]);
                x++;
            }
            else if( a[x]<b[y]){
                ans.push_back( b[y]);
                y++;
            }
            else {
            // Current elements are equal.
            // Compare remaining suffixes.
            int i = x;
            int j = y;

            while (i < a.size() && j < b.size() && a[i] == b[j]) {
                i++;
                j++;
            }

            // If b is exhausted, a is lexicographically larger/equal.
            if (j == b.size() || 
                (i < a.size() && a[i] > b[j])) {

                ans.push_back(a[x]);
                x++;
            }
            else {
                ans.push_back(b[y]);
                y++;
            }
        }
        }
        while( x<a.size()){
            ans.push_back( a[x]);
            x++;
        }

        while( y<b.size()){
            ans.push_back( b[y]);
            y++;
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {


        vector<int>ans;

        for( int i =0;i<=k;i++){
            int j =k-i;
            vector<int>a = maxlex(nums1,i );
            vector<int>b = maxlex(nums2,j);

            if( a.size() + b.size() == k){
                vector<int> mergedarr = merge(a,b);

                ans = max(ans,mergedarr);
            }
        }
        return ans;
        
    }
};