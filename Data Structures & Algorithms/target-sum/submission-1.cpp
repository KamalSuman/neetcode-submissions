class Solution {
public:
    vector<vector<int>> dp;
    int k;
    int help(int i, int t, vector<int> &nums, int target){
        if(i >= nums.size()){
            if(t == k + target) return 1;
            return 0;
        }
        if(dp[i][t] != -1) return dp[i][t];
        int ans = 0;
        ans += help(i+1, t - nums[i], nums, target) + help(i+1, t + nums[i], nums, target);
        return dp[i][t] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum) return 0;
        k = sum;
        dp.resize(nums.size(),vector<int>(2*sum+5,-1));
        return help(0,k,nums,target);
    }
};
