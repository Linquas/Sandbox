class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        unordered_map<char, int> record;
        int length = 0;
        int maxLength = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (record.find(s[j]) == record.end()) {
                    record[s[j]] = 1;
                    length++;
                } else {
                    if (length > maxLength) {
                        maxLength = length;
                    }
                    record.clear();
                    length = 0;
                    break;
                }
            }
        }
        
        if (length > maxLength) {
            maxLength = length;
        }
        
        return maxLength;
    }
};