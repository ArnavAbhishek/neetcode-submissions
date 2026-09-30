class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int n = rows;
        
        auto is_valid = [&](int i, int j) -> bool {
            return (i < rows && i >=0 && j < cols && j >= 0);
        };

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        vector<vector<pair<int,int>>> par(rows, vector<pair<int,int>>(cols));

        vector<int> delx = {1,-1,0,0};
        vector<int> dely = {0,0,1,-1};

        pq.push({grid[0][0], {0,0}});
        dist[0][0] = grid[0][0];
        while(!pq.empty()){
            auto node = pq.top();
            int dd = node.first;
            int x = node.second.first;
            int y = node.second.second;
            pq.pop();

            for(int i=0; i<4; i++){
                int xnew = x + delx[i];
                int ynew = y + dely[i];

                if(is_valid(xnew, ynew)){
                    if(dist[xnew][ynew] > max(dd, grid[xnew][ynew])){
                        dist[xnew][ynew] = max(dd, grid[xnew][ynew]);
                        pq.push({dist[xnew][ynew], {xnew, ynew}});
                    }
                }
            }
        }

        return dist[n-1][n-1];
    }
};
