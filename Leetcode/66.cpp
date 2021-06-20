class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0) {
            return digits;
        }
        
        int index = digits.size() - 1;
        int carry = 0;
        for (int i = index; 0 <= i; --i) {
            int num = digits[i];
            
            //add one
            if (i == digits.size() - 1 || carry == 1) {
                num++;
                if (num >= 10) {
                    carry = 1;
                    num = num % 10;
                } else {
                    carry = 0;
                }
                digits[i] = num;
            }
            
            if (carry == 1 && i == 0) {
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};