class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> outdeg;
        for(auto it: tickets){
            adj[it[0]].push_back(it[1]);
            outdeg[it[0]]++;
        }
        for(auto &[x,y] : adj){
            sort(y.rbegin(), y.rend());
        }
        
        vector<string> ans;

        auto dfs = [&](auto self, string node) -> void {
            while(outdeg[node]){
                self(self, adj[node][--outdeg[node]]);
            }
            ans.push_back(node);
        };

        dfs(dfs, "JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
