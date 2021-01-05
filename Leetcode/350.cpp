class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> numCount1;
        map<int,int> numCount2;
        
        for (auto &num: nums1) {
            if (numCount1.find(num) != numCount1.end()) {
                numCount1[num] = numCount1[num] + 1;
            } else {
                numCount1[num] = 1;
            }
        }
        
        for (auto &num: nums2) {
            if (numCount2.find(num) != numCount2.end()) {
                numCount2[num] = numCount2[num] + 1;
            } else {
                numCount2[num] = 1;
            }
        }
        
        vector<int> result;
        
        for (auto &count: numCount1) {
            if (numCount2.find(count.first) != numCount2.end()) {
                
                int countOfNumber = min(count.second, numCount2[count.first]);
                for (int i = 0; i < countOfNumber; i++) {
                    result.push_back(count.first);
                }
            }
        }
        
        return result;
    }
};