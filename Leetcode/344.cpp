class Solution {
public:
    void reverseString(vector<char>& s) {
        int count = (int)s.size();
        int index = count / 2;
        for (int i = 0; i < index; i++) {
            char temp = s[i];
            s[i] = s[count - 1 - i];
            s[count - 1 - i] = temp;
        }
    }
};