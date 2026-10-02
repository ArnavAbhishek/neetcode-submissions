class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> prev(m+1, 0);
        vector<int> cur(m+1, 0);
        prev[0] = 1; cur[0] = 1;

        for(int i=1; i<n+1; i++){
            for(int j=1; j<min(m+1, i+1); j++){
                if(s[i-1] == t[j-1]) cur[j] = prev[j-1] + prev[j];
                else cur[j] = prev[j];
            }
            prev = cur;
        }

        return cur[m];
    }
};
