class Solution {
public:
    int romanToInt(string s) {
        
        int ans =0;
     unordered_map<char,int>um;
     um['V']=5;
     um['X']=10;
     um['L']=50;
     um['C']=100;
     um['D']=500;
     um['M']=1000;
     um['I']=1;

     for (int i =0;i<s.size();i++){

         if( um[s[i]]<um[s[i+1]]){
            ans+= um[s[i+1]]-um[s[i]];
            i++;
         }
         else{
            ans+=um[s[i]];
         }


     }
     return ans;
    }
};