class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> record;
        unordered_map<char, int> targetRecord;

        int valid = 0;

        for (auto &c: t) {
            targetRecord[c]++;
        }

        int start = 0;
        int len = INT_MAX;

        while(l < s.size()) {
            if (targetRecord.count(s[l])) {
                //found in record
                record[s[l]]++;
                if (record[s[l]] == targetRecord[s[l]]) {
                    valid++;
                }
            }
            l++;

            while (valid == (int)targetRecord.size()) {
                // update answer
                if (len > l - r) {
                    start = r;
                    len = l - r;
                }

                if (targetRecord.count(s[r])) {
                    if (record[s[r]] == targetRecord[s[r]]) {
                        valid--;
                    }
                    record[s[r]]--;
                }
                r++;
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};