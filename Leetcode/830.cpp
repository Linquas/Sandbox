class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        if (s.size() == 0) {
            return {};
        }
        vector<vector<int>> result;
        int start = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == s[start]) {
                continue;
            } else {
                if (i - start + 1 > 3) {
                    result.push_back({start, i-1});
                }
                start = i;
            }
        }
        if ((int)s.size() - start >= 3) {
            result.push_back({start, (int)s.size() - 1});
        }
        return result;
    }
};