class Solution {
public:
    string simplifyPath(string path) {

        vector<string> st;
        int i = 0;
        int n = path.size();

        while (i < n) {

            // Skip '/'
            while (i < n && path[i] == '/')
                i++;

            string dir;

            // Extract one directory name
            while (i < n && path[i] != '/') {
                dir += path[i];
                i++;
            }

            if (dir.empty() || dir == ".")
                continue;

            if (dir == "..") {
                if (!st.empty())
                    st.pop_back();
            } else {
                st.push_back(dir);
            }
        }

        if (st.empty())
            return "/";

        string ans;

        for (string &dir : st)
            ans += "/" + dir;

        return ans;
    }
};