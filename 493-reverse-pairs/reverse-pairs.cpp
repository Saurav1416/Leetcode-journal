class Solution {
public:
    int ans =0;

    void merge( int l , int m ,int r, vector<int > & nums){

        int n1 = m-l+1;
        int n2 = r-m;

        vector<int>l1 ( n1,0);
        vector<int>r1( n2,0);

        for( int i =0;i<n1;i++){
            l1[i]= nums[l+i];
        }
        for( int i =0;i<n2;i++){
            r1[i]= nums[m+1+i];
        }

        int x = n1-1;
        int y = n2-1;
        while( x>=0 && y>=0){

            if ((long long)l1[x] > 2LL * r1[y]) {
                ans+= y+1;
                x--;
            }
            else{
                y--;
            }
        }

        int k = l;
        int i =0;
        int j =0;

        while( i<n1 && j<n2){
            if( l1[i]<r1[j]){
                nums[k] = l1[i];
                i++;
            }
            else{
                nums[k]=r1[j];
                j++;
            }
            k++;
        }

        while( i<n1){
            nums[k]=l1[i];
            i++;
            k++;
        }
        while( j<n2){
            nums[k]=r1[j];
            j++;
            k++;
        }
    }
    void mergesort( int l,int r, vector<int>&nums){

        if( l>=r) return;
        int mid = l + (r-l)/2;
        mergesort(l,mid,nums);
        mergesort( mid+1,r,nums);
        merge( l,mid,r,nums);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size()-1;

        
        mergesort( 0,n,nums);
        return ans;

    }
};