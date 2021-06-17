class Solution {
private:
    vector<int> temp;
    void dfs(vector<int> &nums, vector<int> &used, vector<vector<int>> &ans, int depth) {
        if (depth == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            if(used[i] == 0) {
                used[i] = 1;
                temp.push_back(nums[i]);
                dfs(nums, used, ans, depth + 1);
                used[i] = 0;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        vector<vector<int>> ans;
        
        dfs(nums, used, ans, 0);
        return ans;
    }
};