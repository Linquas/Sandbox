class Solution {
public:
    int titleToNumber(string s) {
        int length = s.size() - 1;
        int result = 0;
        int numberOfPower = pow(26, length);
        for (auto &chara: s) {
            int num = chara - 'A' + 1;
            result = result + num * numberOfPower;
            numberOfPower = numberOfPower / 26;
        }
        return result;
    }
};