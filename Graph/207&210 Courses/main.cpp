#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> order;
    bool valid = true;

public:
    // use different mark to represent its status
    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]){
            if (visited[v] == 0) dfs(v);
            else if (visited[v] == 1) {valid = false; return;}
        }
        visited[u] = 2;
        order.emplace_back(u);
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        order.reserve(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].emplace_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (visited[i] == 0) dfs(i);
        }
        if (valid) for (int vertice : order) cout << vertice << " ";
        cout << "\n";
        return valid;
    }

    bool bfs(int numCourses, vector<vector<int>>& prerequisites){
        vector<int> indegree, ans;
        indegree.resize(numCourses);
        ans.reserve(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].emplace_back(info[0]);
            ++indegree[info[0]];
        }
        deque<int> q;
        int cnt;
        for (int i = 0; i < numCourses; ++i) if (indegree[i] == 0) q.push_back(i);
        while (!q.empty()){
            cnt = q.front();
            q.pop_front();
            for (int next : edges[cnt]){
                if (--indegree[next] == 0) q.push_back(next);
            }
            ans.push_back(cnt);
        }
        return (numCourses == ans.size());
        // return (numCourses == ans.size())? ans : vector<int>{};
    }

};
