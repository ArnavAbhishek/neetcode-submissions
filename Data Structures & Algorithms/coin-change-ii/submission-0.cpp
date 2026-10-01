class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int> prev(amount+1, 0);
        vector<int> cur(amount+1, 1);

        for(int i=1; i<n+1; i++){
            for(int t=1; t<amount+1; t++){
                cur[t] = prev[t];
                if(t - coins[i-1] >= 0) cur[t] += cur[t - coins[i-1]];
            }
            prev = cur;
        }
        return cur[amount];
    }
};
