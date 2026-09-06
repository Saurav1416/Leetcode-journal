class Solution {
    int findp(int x, vector<int>& parent) {
        if (parent[x] != x) {
            return parent[x] = findp(parent[x], parent);
        }
        return x;
    }

    void unionn(int a, int b, vector<int>& parent, vector<long long>& size) {
        int x = findp(a, parent);
        int y = findp(b, parent);
        if (x == y) return;

        // Union by size
        if (size[x] < size[y]) swap(x, y);
        size[x] += size[y];
        parent[y] = x;
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<long long> size(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (const auto& edge : edges) {
            unionn(edge[0], edge[1], parent, size);
        }

        long long ans = 0;
        long long remainingNodes = n;

        for (int i = 0; i < n; i++) {
            // Only process component roots  
            if (parent[i] == i) {
                long long componentSize = size[i];
                remainingNodes -= componentSize;
                ans += componentSize * remainingNodes;
            }
        }

        return ans;
    }
};