class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int tar = accumulate(nums.begin(), nums.end(), 0);
        if(tar & 1) return false;
        tar /= 2;

        vector<bool> prev(tar+1, 0);
        vector<bool> cur(tar+1, 1);
        prev[0] = 1;

        for(int i=1; i<n+1; i++){
            for(int t=1; t<tar+1; t++){
                cur[t] = prev[t];
                if(t - nums[i-1] >= 0) cur[t] = cur[t] || prev[t - nums[i-1]];
            }
            prev = cur;
        }

        return cur[tar];
    }
};
