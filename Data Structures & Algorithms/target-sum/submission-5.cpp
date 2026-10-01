class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tar = accumulate(nums.begin(), nums.end(), 0) + target;
        if(tar & 1 || tar < 0) return 0;
        tar /= 2;

        vector<int> prev(tar+1, 0);
        vector<int> cur(tar+1, 1);
        prev[0] = 1;

        for(int i=1; i<n+1; i++){
            for(int t=0; t<tar+1; t++){
                cur[t] = prev[t];
                if(t - nums[i-1] >= 0) cur[t] += prev[t - nums[i-1]];
            }
            prev = cur;
        }
        return cur[tar];
    }
};
