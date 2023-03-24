#include <vector>
using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<bool> isVisited, vector<int>& path, vector<vector<int>>& allPaths) {
        int sz = isVisited.size();

        if (isVisited[node]) return;
        isVisited[node] = true;
        path.push_back(node);
        if (node == sz - 1) allPaths.push_back(path);
        else for (auto next: graph[node]) {dfs(graph, next, isVisited, path, allPaths);}
        isVisited[node] = false;
        path.pop_back();
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<vector<int>> allPaths;
        vector<bool> isVisited(sz, false);
        vector<int> path;
        dfs(graph, 0, isVisited, path, allPaths);
        return allPaths;
    }
};