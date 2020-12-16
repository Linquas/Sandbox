class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> records;
        for (auto &chara: s) {
            if (records.find(chara) != records.end()) {
                records[chara] = records[chara] + 1;
            } else {
                records[chara] = 1;
            }
        }
        for (auto &chara: t) {
            if (records.find(chara) != records.end()) {
                if (records[chara] == 0) {
                    return false;
                }
                records[chara] = records[chara] - 1;
            } else {
                return false;
            }
        }
        for (auto &record: records) {
            if (record.second != 0) {
                return false;
            }
        }
        return true;
    }
};