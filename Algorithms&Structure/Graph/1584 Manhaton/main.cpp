#include <vector>
#include <queue>
using namespace std;

class Solution {
    struct Point{
        int point;
        int dist;

        bool operator<(const Point& a){
            return (dist < a.dist || (dist == a.dist && point < a.point));
        }
    };

    int abs(const int& a, const int& b){return (a < b)? (b-a):(a-b);}
    int distance(const vector<int> a, const vector<int> b){
        return abs(a[0], b[0]) + abs(a[1], b[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int sz = points.size();
        vector<int> q;
        q.reserve(sz);
        int dist = 0, a = 0;
        vector<int> visited(sz, false);
        visited[0] = true;
        q.emplace_back(10000);
        for (int i = 1; i < sz; ++i){
            dist = distance(points[i], points[a.point]); 
            q.push_back(dist);
        }
        int ans = 0;
        while (!q.empty()){
            a = 0;
            for (int i = 0; i < sz; ++i){
                if (!visited[i] && q[i] < q[a]){
                    a = i;
                }
            }
            visited[a] = true;
            ans += q[a];
            for (int i = 0; i < sz; ++i){
                if (!visited[i] && q[i] > distance(points[i], points[a])){
                    q[i] = distance(points[i], points[a]);
                }
            }
        }
        return ans;
    }
};