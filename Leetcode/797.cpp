class Solution {
private:
    void traverse(vector<vector<int>>& graph, vector<int> path, int s, vector<vector<int>>& ans) {
        path.push_back(s);
        
        if (s == (graph.size() - 1)) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        for(int i = 0; i < graph[s].size(); ++i) {
            traverse(graph, path, graph[s][i], ans);
        }
        
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        traverse(graph, path, 0, ans);
        return ans;
    }
};