class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0') return 0;

        vector<int> dp(n+1, 0);
        dp[n] = 1;
        dp[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            if(s[i] == '0') continue;
            if(stoi(s.substr(i,2)) <= 26) dp[i] = dp[i+2];
            if(s[i+1] != '0') dp[i] += dp[i+1];
        }

        return dp[0];
    }
};
