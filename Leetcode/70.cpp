class Solution {
public:
    int climbStairs(int n) {
        vector<int> record = vector(n+1, 0);
        
        if (n==1) {
            return 1;
        }
        if (n==2) {
            return 2;
        }
        
        record[0] = 1;
        record[1] = 1;
        record[2] = 2;
        
        for(int i = 3; i <= n; ++i) {
            record[i] = record[i-1] + record[i-2];
        }
        return record[n];
    }
};