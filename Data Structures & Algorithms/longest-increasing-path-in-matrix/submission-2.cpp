class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxi = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                maxi = max(maxi, matrix[i][j]);
            }
        }

        queue<pair<int,int>> q;
        vector<vector<int>> dist(rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                    dist[i][j] = 1;
                    q.push({i,j});
            }
        }

        auto valid =[&](int i, int j) -> bool {
            return (i >=0 && i < rows && j >=0 && j < cols);
        };

        vector<int> delx = {1,-1,0,0};
        vector<int> dely = {0,0,1,-1};

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;

            for(int t=0; t<4; t++){
                int i = delx[t];
                int j = dely[t];
                if(valid(x+i, y+j)){
                    if(matrix[x+i][y+j] >= matrix[x][y]) continue;
                    if(dist[x+i][y+j] < 1 + dist[x][y]){
                        dist[x+i][y+j] = 1 + dist[x][y];
                        q.push({x+i, y+j});
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                ans = max(ans, dist[i][j]);
                cout << dist[i][j] << ' ';
            }
            cout << endl;
        }

        return ans;
    }
};
