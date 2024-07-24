#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int result = 0;

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    while(!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();
        int curx = cur.first;
        int cury = cur.second;

        for (int i = 0; i < 4; i++)
        {
            int nextx = curx + dir[i][0];
            int nexty = cury + dir[i][1];
            if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;
            if (grid[nextx][nexty] == 1 && !visited[nextx][nexty])
            {
                que.push({nextx, nexty});
                visited[nextx][nexty] = true;
            }
        }
    }

}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> area(N, vector<int>(M, 0));
    for (auto& vec : area)
        for (auto& vi : vec)
            cin >> vi;

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < area.size(); ++i)
    {
        for (int j = 0; j < area[0].size(); ++j)
        {
            if (area[i][j] == 1 && !visited[i][j])
            {
                result++;
                bfs(area, visited, i, j);
            }
        }
    }
    cout << result << endl;
    return 0;
}
