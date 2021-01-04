class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        vector<int>lastRow;
        for (int i = 1 ; i <= numRows; i++) {
            //count of Level
            
            vector<int> row;
            for (int j = 1; j <= i; j++) {
                //loop of each row
                if (j == 1 || j == i) {
                    row.push_back(1);
                } else {
                    int num = lastRow[j] + lastRow[j-1];
                    row.push_back(num);
                }
            }
            
            lastRow = row;
            result.push_back(row);
        }
        return result;
    }
};