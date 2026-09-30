class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e4);
        vector<int> temp(n, 1e4);
        vector<int> is_changed(n, 0);
        
        dist[src] = 0;
        temp[src] = 0;

        for(int i=0; i<k+1; i++){
            for(auto it: flights){
                if(is_changed[it[1]]){
                    if(dist[it[0]] + it[2] < temp[it[1]]){
                        temp[it[1]] = dist[it[0]] + it[2];
                    }
                }

                else if(dist[it[0]] + it[2] < dist[it[1]]){
                    temp[it[1]] = dist[it[0]] + it[2];
                    is_changed[it[1]] = 1;
                }
            }
            
            fill(is_changed.begin(), is_changed.end(), 0);
            dist = temp;
        }

        if(dist[dst] == 1e4) return -1;
        return dist[dst];
    }
};
