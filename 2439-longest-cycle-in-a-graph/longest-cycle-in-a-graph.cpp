class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int time = 0, ans = -1, n = edges.size();
        vector<int> vis(n, 0);

        for(int i=0; i<n; i++) {
            if(vis[i]) continue;

            int next = i;
            int start = time;
            while(next != -1 && vis[next] == 0) {
                vis[next] = time++;
                next = edges[next];
            }

            // if we find a cycle (vis[next] != 0)
            if(next != -1 && vis[next] >= start) {
                ans = max(ans, time - vis[next]);
            }
        }

        return ans;
    }
};