class Solution {
public:
    vector<vector<int>> ans;
    void help(vector<int>& nums, int j, int target,  int sum , vector<int>& res){
        if(sum == target) {ans.push_back(res); return;}
        else if(sum> target) return;
        if(j >= nums.size()) return; 
        res.push_back(nums[j]);
        help(nums,j+1,target,sum + nums[j],res);
        res.pop_back();
        int next = j + 1;
        while(next < nums.size() && nums[next] == nums[j]) {
            next++;
        }
        help(nums,next,target,sum,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> res;
        help(nums,0,target,0,res);
        return ans;
    }
};
