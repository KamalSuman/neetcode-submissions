class Solution {
public:
    vector<vector<int>> ans;
    int sum(vector<int>& res){
        int ans = 0;
        for(int i = 0; i < res.size(); i++){
            ans += res[i];
        }
        return ans;
    }
    void help(vector<int>& nums, int j, int target, vector<int>& res){
        if(sum(res) == target) {ans.push_back(res); return;}
        else if(sum(res) > target) return;
        if(j >= nums.size()) return; 
        res.push_back(nums[j]);
        help(nums,j,target,res);
        res.pop_back();
        help(nums,j+1,target,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        help(nums,0,target,res);
        return ans;
    }
};
