class Solution {
public:
    string largestOddNumber(string num) {
        
        int index=-1;

        for(int i = 0;i<num.size();i++){
            if ( num[i]%2!=0)
                index = i;
        }
        if ( index==-1)
            return "";

        return  num.substr(0,index+1);
    }   

};