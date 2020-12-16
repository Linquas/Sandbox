class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> records;
        for (auto &num: nums) {
            if (records.find(num) != records.end()) {
                return true;
            } else {
                records[num] = 1;
            }
        }
        return false;
    }
};