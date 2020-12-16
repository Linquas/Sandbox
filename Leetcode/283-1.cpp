class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPosition = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (zeroPosition == -1) {
                    zeroPosition = i;    
                }
            } else {
                if (zeroPosition != -1) {
                    swap(nums[zeroPosition], nums[i]);
                    i = zeroPosition;
                    zeroPosition = -1;
                }
            }
        }
    }
};