#define fr(i,n) for(int i=0; i<n; i++)

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);

        fr(i,n-1){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n);

        auto dfs = [&](auto self, int node) -> void {
            vis[node] = 1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    self(self, it);
                }
            }
        };

        int comp = 0;
        fr(i,n){
            if(!vis[i]){
                dfs(dfs, i);
                comp++;
            }
        }

        return comp == 1;
    }
};
