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

// Two pointer
class Solution {
public:
    
    // pwwkew
    //   L       
    // R      
    
    // count = L-R
    // R move to R + 1
    // L move to R
    // repeat
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int l = 0;
        int r = 0;
        int longest = -1;
        unordered_set<int> record;
        while (l < s.size()) {
            if (record.find(s[l]) != record.end()) {
                // found repeating char
                int count = l - r;
                longest = max(count, longest);
                r++;
                l = r;
                record.clear();
            } else {
                record.insert(s[l]);
                l++;
            }
        }
        
        //For last
        longest = max((int)s.size()-r, longest);
        
        return longest;
    }
};