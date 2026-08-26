class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        

        int carry = 1;
        vector<int>ans( digits.size()+1,0);
        // for( int i =1;i<ans.size();i++){
        //     ans[i]= digits[i-1];
        // }
        int i = digits.size()-1;
        while( i>=0 && carry==1){

            if( digits[i]==9 && i==0){
                ans[0]=1;
                carry =2;
                break;
            }else if( digits[i]==9){
                digits[i]=0;
                carry =1;
                i--;
            }
            else {
                digits[i]++;
                carry =0;
            }
            
        }
        if( carry==2) return ans;
        return digits;
    }
};