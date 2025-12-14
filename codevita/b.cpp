#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m, start1, start2, outpost;
vector<int> adj[20];
int minTowns = INT_MAX;

void dfs2(int node, int mask, int count) {
    if (node == outpost) {
        // Both scouts reached outpost
        int totalTowns = __builtin_popcount(mask);
        minTowns = min(minTowns, totalTowns);
        return;
    }
    
    for (int next : adj[node]) {
        // Allow visiting if: not visited OR it's the outpost
        if (!(mask & (1 << next)) || next == outpost) {
            dfs2(next, mask | (1 << next), count + 1);
        }
    }
}

void dfs1(int node, int mask, int count) {
    if (node == outpost) {
        // Path 1 reached outpost, now find path 2
        dfs2(start2, mask | (1 << start2), 1);
        return;
    }
    
    for (int next : adj[node]) {
        // Don't visit already visited nodes
        if (!(mask & (1 << next))) {
            dfs1(next, mask | (1 << next), count + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    cin >> start1 >> start2;
    cin >> outpost;
    
    // Start DFS from first scout
    dfs1(start1, (1 << start1), 1);
    
    if (minTowns == INT_MAX) {
        cout << "Impossible" << endl;
    } else {
        cout << minTowns << endl;
    }
    
    return 0;
}
