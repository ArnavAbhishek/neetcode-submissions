class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxprodhere = nums[0];
        int minprodhere = nums[0];
        int maxprod = nums[0];

        for(int i=1; i<n; i++){
            int temp = maxprodhere;
            maxprodhere = max(minprodhere*nums[i], max(maxprodhere*nums[i], nums[i]));
            minprodhere = min(temp*nums[i], min(minprodhere*nums[i], nums[i]));
            maxprod = max(maxprod, maxprodhere);
        }

        return maxprod;
    }
};
