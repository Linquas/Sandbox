class Solution {
private:
    int dp(vector<int>& coins, int amount) {
        if (amount == 0) { return 0; }
        if (amount < 0) { return -1; }
        int res = INT_MAX;
        
        for (auto coin : coins) {
            int result = dp(coins, amount - coin);
            
            if (result == -1) { continue; }
            res = min(res, result + 1);
        }
        return res == INT_MAX ? -1 : res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins, amount);
    }
};

class Solution {
private:
    unordered_map<int, int> record;
    int dp(vector<int>& coins, int amount) {
        if (amount == 0) { return 0; }
        if (amount < 0) { return -1; }
        
        if (record.find(amount) != record.end()) {
            return record[amount];
        }
        
        int res = INT_MAX;
        
        for (auto coin : coins) {
            int result = dp(coins, amount - coin);
            
            if (result == -1) { continue; }
            res = min(res, result + 1);
        }
        record[amount] = res == INT_MAX ? -1 : res;
        return record[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins, amount);
    }
};