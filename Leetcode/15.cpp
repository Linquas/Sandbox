class Solution {
public:
    //[-1,0,1,2,-1,-4]
    
    //[-4,-1,-1,0,1,2]
    //  i  l        r        
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size()-2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                //check next num is duplicated or not
                int l = i + 1;
                int r = nums.size()-1;
                int target = -nums[i];
                while(r > l) {
                    if (target == nums[l] + nums[r]) {
                        result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                        //move l and r to next num that is not as same as current value;

                        while(nums[l+1] == nums[l] && r > l) { l++; }
                        l++;

                        while(nums[r-1] == nums[r] && r > l) { r--; }
                        r--;
                    } else if (nums[l] + nums[r] < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }

        return result;
    }
};