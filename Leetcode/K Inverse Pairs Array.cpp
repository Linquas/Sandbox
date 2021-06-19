class Solution {
    /*
    123
    
    132
    213
    
    231
    321
    312
    */
    
private:
    int result = 0;
    vector<int> current;
    void helper(vector<int>& used, int n, int k, int depth, vector<int> current) {
        if (depth == n) {
            //check reverse
            int countReverse = 0;
            for (int i = 0; i < current.size(); ++i) {
                int currentValue = current[i];
                for(int j = 0; j < current.size(); ++j) {
                    if (i != j) {
                        if (j < i && current[j] > currentValue) {
                            countReverse++;
                        }
                    }   
                }
            }
            if (countReverse == k) {
                result++;
            }
            return;
        }
        
        for(int i = 0; i < n; ++i) {
            if(used[i] == 0) {
                used[i] = 1;
                current.push_back(i+1);
                helper(used, n, k, depth+1, current);
                current.pop_back();
                used[i] = 0;
            }
        }
    }
public:
    int kInversePairs(int n, int k) {
        vector<int> used(n, 0);
        helper(used, n, k, 0, current);
        return result;
    }
};