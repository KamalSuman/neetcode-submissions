class Solution {
public:
    vector<vector<int>> ans;
    void help(vector<int>& nums, int j, vector<int>& res){
        for(int i = j; i<nums.size(); i++){
            res.push_back(nums[i]);
            help(nums,i+1,res);
            res.pop_back();
        }
        ans.push_back(res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        help(nums,0,res);
        return ans;
    }
};
