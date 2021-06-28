class Solution { // need improve
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) {
            return "";
        }
        if (s.size() == 1) {
            return s;
        }
        
        int longest = 0;
        int lIndex = -1;
        int rIndex = -1;
        for (int i = 1; i < s.size(); ++i) {
            int l = i - 1;
            int r = i + 1;
            int count = 1;
            
            if (s[l] == s[i]) {
                // XYYX
                l--;
                count = 2;
                while (l >= 0 && r < s.size()) {
                    if (s[l] == s[r]) {
                        count += 2;
                        l--;
                        r++;
                    } else {
                        break;
                    }
                }
            }
            if (count > longest) {
                longest = count;
                lIndex = l+1;
                rIndex = r-1;
            }
            
            l = i - 1;
            r = i + 1;
            count = 1;
                
            if (s[l] == s[r]) {
                //XYX
                while (l >= 0 && r < s.size()) {
                    if (s[l] == s[r]) {
                        count += 2;
                        l--;
                        r++;
                    } else {
                        break;
                    }
                }
            }
            if (count > longest) {
                longest = count;
                lIndex = l+1;
                rIndex = r-1;
            }
        }
        return s.substr(lIndex, longest);
    }
};