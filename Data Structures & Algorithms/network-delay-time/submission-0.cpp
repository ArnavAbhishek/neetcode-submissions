#define fr(i,n) for(int i=0; i<n; i++)
#define vi vector<int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vi dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto node = pq.top();
            int dd = node.first;
            int val = node.second;
            pq.pop();

            for(auto it: adj[val]){
                if(dist[it.first] > it.second + dd){
                    dist[it.first] = it.second + dd;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        int ans = *max_element(dist.begin()+1, dist.end());
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
