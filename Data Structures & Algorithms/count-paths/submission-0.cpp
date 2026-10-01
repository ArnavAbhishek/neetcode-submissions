class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        vector<int> cur(n, 1);

        for(int i=1; i<m; i++){
            for(int t=1; t<n; t++){
                cur[t] = prev[t] + cur[t-1];
            }
            prev = cur;
        }

        return cur[n-1];
    }
};
