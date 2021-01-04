class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (1 + nums.size()) * nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum - nums[i];
        }
        return sum;
    }
};