class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& grid) {
        
        vector<vector<int>> adj(n);

        vector<int> indegree(n);
        for(auto it: grid){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for(auto it: adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        
        if(topo.size() == n){
            return topo;
        }
        else return {};
    }
};
