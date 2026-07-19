class Solution {
public:
    string largestOddNumber(string num) {
        
       string ans ="";
       int max =-1;
       bool counter=false;

     for( int i =num.size()-1;i>=0;i--){

        if(num[i]%2 !=0){
            counter= true;
        }
        if(counter){
            ans+=num[i];
        }
     }
     reverse(ans.begin(),ans.end());
     return ans;

    }
};