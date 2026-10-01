class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> prev(amount+1, 1e6);
        vector<int> cur(amount+1, 0);

        for(int i=1; i<n+1; i++){
            for(int t=1; t<amount+1; t++){
                cur[t] = prev[t];
                if(t - coins[i-1] >=0) cur[t] = min(cur[t], 1 + cur[t-coins[i-1]]);
            }
            prev = cur;
        }
        if(cur[amount] == 1e6) return -1;
        return cur[amount];
    }
};
