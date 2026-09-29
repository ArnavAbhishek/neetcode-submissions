#define fr(i,n) for(int i=0; i<n; i++)
#define fra(i,a,n) for(int i=a; i<n; i++)

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1) return 0;
        vector<int> par(n);
        vector<int> size(n,1);
        fr(i,n) par[i]=i;

        auto getpar = [&](auto self, int i) -> int {
            if(i == par[i]) return i;
            return par[i] = self(self, par[i]);
        };

        auto unionsize = [&](int i, int j) -> void {
            int pi = getpar(getpar, i);
            int pj = getpar(getpar, j);
            
            if(size[pi] < size[pj]){
                par[pi] = pj;
                size[pj] += size[pi];
            }
            else{
                par[pj] = pi;
                size[pi] += size[pj];
            }
        };

        vector<vector<int>> dist;
        fr(i,n){
            fra(j,i+1,n){
                int x = abs(points[i][0] - points[j][0]);
                int y = abs(points[i][1] - points[j][1]);
                dist.push_back({x+y, i, j}); 
            }
        }

        sort(dist.begin(), dist.end());

        int ans = 0;
        fr(i,dist.size()){
            if(getpar(getpar, dist[i][1]) != getpar(getpar, dist[i][2])){
                unionsize(dist[i][1], dist[i][2]);
                ans += dist[i][0];
            }
        }

        return ans;
    }
};
