class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        for (int i = 0; i < goal.size(); i++) {
            if (goal[i] == s[0]) {
                
                string temp = goal;
                reverse(temp.begin(), temp.begin() + i);
                reverse(temp.begin() + i, temp.end());
                reverse(temp.begin(), temp.end());

                if (temp == s) return true;
            }
        }
        return false;
    }
};
