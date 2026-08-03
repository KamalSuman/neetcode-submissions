class Solution {
public:
    vector<vector<int>> ans;
    void help(vector<int>& nums, int j,vector<int>& res){
        for(int i = j; i<nums.size();){
            res.push_back(nums[i]);
            help(nums,i+1,res);
            res.pop_back();
            int next = i + 1;
            while(next < nums.size() && nums[next] == nums[i]) {
                next++;
            }
            i = next;
        }
        ans.push_back(res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        help(nums,0,res);
        return ans;
    }
};
