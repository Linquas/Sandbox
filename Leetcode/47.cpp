class Solution {
    
private:
    vector<int> temp;
    
    void dfs(vector<int>& nums, vector<vector<int>>& ans, int depth, vector<int> used) {
        if (depth == nums.size()) {
            ans.push_back(temp);
        }
        set<int> usedNumber;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] == 0 && usedNumber.find(nums[i]) == usedNumber.end()) {
                usedNumber.insert(nums[i]);
                
                used[i] = 1;
                temp.push_back(nums[i]);
                dfs(nums, ans, depth + 1, used);
                temp.pop_back();
                used[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> used(nums.size(), 0);
        dfs(nums, ans, 0, used);
        return ans;
    }
};


// Version 2 without using set
class Solution {
private: 
    vector<int> tmp;
    vector<bool> seen;
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<vector<int>>& ans) {
        if(tmp.size() == nums.size()) {
            ans.push_back(vector<int>(tmp));
            
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(seen[i] == false) {
                seen[i] = true;
                tmp.push_back(nums[i]);
                dfs(nums, ans);
                tmp.pop_back();
                seen[i] = false;
                
                while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                    i++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        seen = vector<bool>(nums.size(), false);
        
        dfs(nums, ans);
        
        return ans;
    }
};