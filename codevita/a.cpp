#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Cell {
    int row, col, count;
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    vector<string> rows(n);
    for (int i = 0; i < n; i++) {
        getline(cin, rows[i]);
    }
    
    // Parse grid
    vector<vector<char>> grid;
    vector<pair<int, int>> sources;
    
    for (int i = 0; i < n; i++) {
        vector<char> gridRow;
        string row = rows[i];
        int j = 0;
        
        while (j < (int)row.length()) {
            string num = "";
            while (j < (int)row.length() && isdigit(row[j])) {
                num += row[j];
                j++;
            }
            
            char brick = row[j];
            j++;
            
            int count = stoi(num);
            for (int k = 0; k < count; k++) {
                gridRow.push_back(brick);
                if (brick == 'S') {
                    sources.push_back({i, (int)gridRow.size() - 1});
                }
            }
        }
        grid.push_back(gridRow);
    }
    
    // BFS
    queue<Cell> q;
    vector<vector<int>> dist(n);
    for (int i = 0; i < n; i++) {
        dist[i].resize(grid[i].size(), -1);
    }
    
    // Add ALL source positions to queue
    for (int i = 0; i < (int)sources.size(); i++) {
        q.push({sources[i].first, sources[i].second, 0});
        dist[sources[i].first][sources[i].second] = 0;
    }
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = curr.row + dx[i];
            int nc = curr.col + dy[i];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < (int)grid[nr].size() && dist[nr][nc] == -1) {
                char cell = grid[nr][nc];
                
                if (cell == 'D') {
                    cout << curr.count << endl;
                    return 0;
                }
                
                if (cell == 'G') {
                    dist[nr][nc] = curr.count + 1;
                    q.push({nr, nc, curr.count + 1});
                }
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}
