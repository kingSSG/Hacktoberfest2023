#include <iostream>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

int x;

void dfsUtil(int node, int count, bool visited[], int& maxCount, list<int>* adj) {
    visited[node] = true;
    count++;
    for (auto i = adj[node].begin(); i != adj[node].end(); ++i) {
        if (!visited[*i]) {
            if (count >= maxCount) {
                maxCount = count;
                x = *i;
            }
            dfsUtil(*i, count, visited, maxCount, adj);
        }
    }
}

void dfs(int node, int n, list<int>* adj, int& maxCount) {
    bool visited[n + 1];
    int count = 0;
    for (int i = 1; i <= n; ++i)
        visited[i] = false;

    dfsUtil(node, count + 1, visited, maxCount, adj);
}

int diameter(list<int>* adj, int n) {
    int maxCount = INT_MIN;
    dfs(1, n, adj, maxCount);
    dfs(x, n, adj, maxCount);
    return maxCount;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    list<int>* adj = new list<int>[n + 1];

    cout << "Enter the edges (node pairs, e.g., 1 2):" << endl;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Diameter of the given tree is " << diameter(adj, n) << endl;
    return 0;
}
