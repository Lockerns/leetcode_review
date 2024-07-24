#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(const vector<vector<int>>& graph, int depth)
{
    if(depth == graph.size() - 1)
    {
        result.push_back(path);
        return;
    }
    for (int i = 1; i < graph.size(); i++)
    {
        if(graph[depth][i])
        {
            path.push_back(i);
            dfs(graph, i);
            path.pop_back();
        }
    }

}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N+1, vector<int>(N+1, 0));
    int i = 0, j = 0;
    while(M--)
    {
        cin >> i >> j;
        graph[i][j] = 1;
    }
    path.push_back(1);
    dfs(graph, 1);
    if (result.empty()) cout << -1;
    for (auto vec : result)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
            if (i != vec.size() - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
