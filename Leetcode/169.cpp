class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> records;
        map<int, int>::iterator iter;
        
        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        for(int i = 0; i < nums.size(); i++) {
            iter = records.find(nums[i]);
            if (iter != records.end()) {
                if (iter->second + 1 > nums.size() / 2) {
                    return nums[i];
                } else {
                    records[nums[i]] = iter->second + 1;
                }
            } else {
                records[nums[i]] = 1;
            }
        }
        return 0;
    }
};