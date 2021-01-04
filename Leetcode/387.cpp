class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> map;
        
        for (int i = 0; i < s.length(); i ++) {
            if (map.find(s[i]) != map.end()) {
              map[s[i]] = map[s[i]] + 1;  
            } else {
                map[s[i]] = 1;
            }
        }
        
        for (int i = 0; i < s.length(); i ++) {
            if (map.find(s[i]) != map.end()) {
                if (map[s[i]] == 1) {
                    return i;
                }
            }
        }
        return -1;
    }
};