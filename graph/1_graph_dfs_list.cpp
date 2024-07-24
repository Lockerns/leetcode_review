#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(const vector<list<int>>& graph, int depth)
{
    if(depth == graph.size() - 1)
    {
        result.push_back(path);
        return;
    }

    for (list<int>::const_iterator it = graph[depth].begin(); it != graph[depth].end(); ++it)
    {
        path.push_back(*it);
        dfs(graph, *it);
        path.pop_back();
    }
}
int main()
{
    int N = 0, M = 0;
    cin >> N >> M;
    vector<list<int>> graph(N + 1);
    int s = 0, t = 0;
    while(M--)
    {
        cin >> s >> t;
        graph[s].push_back(t);
    }
    path.push_back(1);
    dfs(graph, 1);
    if (result.empty()) cout << -1 << endl;
    for (auto vec : result)
    {
        for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        {
            cout << *it;
            if (it != vec.end() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
