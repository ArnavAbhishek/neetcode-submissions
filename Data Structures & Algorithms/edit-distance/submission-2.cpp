class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if(n == 0){
            if(m == 0) return 0;
            else return m;
        }

        vector<int> prev(m+1, 0);
        for(int i=0; i<m+1; i++) prev[i] = i;
        vector<int> cur(m+1, 0);
        cur[0] = 1;

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(word1[i-1] == word2[j-1]) cur[j] = prev[j-1];
                else{
                    cur[j] = 1 + min(min(prev[j-1], prev[j]), cur[j-1]);
                }
            }
            prev = cur;
        }
        // cout << cur[m];
        return cur[m];
    }
};
