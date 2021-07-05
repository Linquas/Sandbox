class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> targets;
        
        for (auto& chara: p) {
            targets[chara]++;
        }
        
        unordered_map<char, int> window;
        vector<int> result;
        int right = 0;
        int left = 0;
        int valid = 0;
        
        while(right < s.size()) {
            char temp = s[right];
            right++;
            
            if (targets.count(temp)) {
                window[temp]++;
                if (window[temp] == targets[temp]) {
                    valid++;
                }
            }
            
            while(right - left >= p.size()) {
                if (valid == targets.size()) {
                    result.push_back(left);
                }
                
                char temp = s[left];
                left++;
                
                if (targets.count(temp)) {
                    if (window[temp] == targets[temp]) {
                        valid--;
                    }
                    window[temp]--;
                }
            }
        }
        
        return result;
    }
};