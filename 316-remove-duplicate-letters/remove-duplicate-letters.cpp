class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int>freq(26,0);
        vector<bool>used(26,false);

        for( auto i:s){
            freq[i-'a']++;
        }
        string st;

        for( int i =0;i<s.size();i++){

            freq[s[i]-'a']--;

            if( used[s[i]-'a']){
                continue;
            }

            while( !st.empty() && st.back()>s[i]
            && freq[st.back()-'a']){

                used[st.back()-'a'] =false;
                st.pop_back();

            }
            st.push_back(s[i]);
            used[s[i]-'a']= true;
        }
        return st;
    }
};