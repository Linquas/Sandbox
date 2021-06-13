class Solution {
public:
    int islandCount = 0;
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> record;
        for(int i = 0; i < m; ++i) {
            record.push_back(vector<int>(n, 0));
        }
        
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (traverse(i, j, m, n, grid, record)) {
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
    
private:
    bool traverse(int x, int y, int m, int n, vector<vector<char>>& grid, vector<vector<int>>& record) {
        if (x < 0 || x >= m) {
            return false;
        }
        
        if (y < 0 || y >= n) {
            return false;
        }
        
        if (record[x][y] == 1) {
            return false;
        }
        
        if (grid[x][y] == '1') {
            record[x][y] = 1;
            
            //find four direction
            bool up = traverse(x, y-1, m, n, grid, record);
            bool left = traverse(x-1, y, m, n, grid, record);
            bool right = traverse(x+1, y, m, n, grid, record);
            bool buttom = traverse(x, y+1, m, n ,grid, record);
            return true;
        }
        return false;
    }
};