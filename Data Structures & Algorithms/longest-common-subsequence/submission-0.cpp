class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.size();
        int cols = text2.size();

        vector<int> prev(cols+1, 0);
        vector<int> cur(cols+1, 0);
        
        for(int i=1; i<rows+1; i++){
            for(int t=1; t<cols+1; t++){
                if(text1[i-1] == text2[t-1]) cur[t] = prev[t-1]+1;
                else cur[t] = max(prev[t], cur[t-1]);
            }
            prev = cur;
        }

        return cur[cols];
    }
};
