class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> target;
        unordered_map<char, int> record;
        int valid = 0;
        
        for(auto &chara: s1) {
            target[chara] += 1;
        }
        
        // eidboaooo
        // lllll
        //    rr
        
        int left = 0;
        int right = 0;
        
        while(right < s2.size()) {
            char temp = s2[right];
            right++;
            
            if (target.count(temp)) {
                record[temp]++;
                if (record[temp] == target[temp]) {
                    valid++;
                }
            } 
            
            while(right - left >=  s1.size()) {
                if (valid == target.size()) {
                    return true;
                } else {
                    char temp = s2[left];
                    left++;
                    
                    if (record.count(temp)) {
                        if (record[temp] == target[temp]) {
                            valid--;
                        }
                        record[temp]--;
                    }
                }
                
            }
        }
        
        return false;
    }
};