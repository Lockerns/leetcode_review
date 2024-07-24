#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void dfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int x, int y)
{
    graph[x][y] = 0;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nexty < 0 || nextx > graph.size() - 1 || nexty > graph[0].size() - 1) continue;
        if (!visited[nextx][nexty] && graph[nextx][nexty] == 1)
        {
            dfs(graph, visited, nextx, nexty);
        }

    }
}
int main()
{
    int N = 0, M = 0, result = 0;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M, 0));
    for (auto& vec : graph)
        for (auto& ele : vec)
            cin >> ele;

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (graph[i][j] == 1)
            {
                result++;
                dfs(graph, visited, i, j);
            }
        }
    cout << result << endl;
    return 0;
}
