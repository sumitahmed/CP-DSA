#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

struct Box {
    int x1, y1, x2, y2;
    int area;
    
    Box(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {
        area = (x2 - x1) * (y2 - y1);
    }
};

int N, M;
set<pair<pair<int,int>, pair<int,int>>> lines;

void addLine(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || (x1 == x2 && y1 > y2)) {
        swap(x1, x2);
        swap(y1, y2);
    }
    lines.insert({{x1, y1}, {x2, y2}});
}

bool hasVerticalLine(int x, int y1, int y2) {
    if (y1 > y2) swap(y1, y2);
    for (auto& line : lines) {
        int lx1 = line.first.first, ly1 = line.first.second;
        int lx2 = line.second.first, ly2 = line.second.second;
        
        if (lx1 == lx2 && lx1 == x) {
            if (ly1 <= y1 && ly2 >= y2) return true;
        }
    }
    return false;
}

bool hasHorizontalLine(int y, int x1, int x2) {
    if (x1 > x2) swap(x1, x2);
    for (auto& line : lines) {
        int lx1 = line.first.first, ly1 = line.first.second;
        int lx2 = line.second.first, ly2 = line.second.second;
        
        if (ly1 == ly2 && ly1 == y) {
            if (lx1 <= x1 && lx2 >= x2) return true;
        }
    }
    return false;
}

vector<Box> findBoxes() {
    vector<Box> boxes;
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
    
    // Use flood fill to find connected regions
    for (int startY = 0; startY < M; startY++) {
        for (int startX = 0; startX < N; startX++) {
            if (visited[startX][startY]) continue;
            
            // Find the box boundaries using flood fill
            int minX = startX, minY = startY;
            int maxX = startX, maxY = startY;
            
            // Simple approach: try to expand from this point
            for (int x2 = startX + 1; x2 <= N; x2++) {
                for (int y2 = startY + 1; y2 <= M; y2++) {
                    bool isBox = true;
                    
                    // Check if this forms a valid box
                    // Check all four edges
                    if (!hasHorizontalLine(startY, startX, x2)) isBox = false;
                    if (!hasHorizontalLine(y2, startX, x2)) isBox = false;
                    if (!hasVerticalLine(startX, startY, y2)) isBox = false;
                    if (!hasVerticalLine(x2, startY, y2)) isBox = false;
                    
                    if (isBox) {
                        boxes.push_back(Box(startX, startY, x2, y2));
                        for (int x = startX; x < x2; x++) {
                            for (int y = startY; y < y2; y++) {
                                visited[x][y] = true;
                            }
                        }
                        goto next_start;
                    }
                }
            }
            next_start:;
        }
    }
    
    return boxes;
}

int main() {
    cin >> N >> M;
    
    // Add boundary lines
    addLine(0, 0, N, 0);
    addLine(0, M, N, M);
    addLine(0, 0, 0, M);
    addLine(N, 0, N, M);
    
    int L;
    cin >> L;
    for (int i = 0; i < L; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        addLine(x1, y1, x2, y2);
    }
    
    vector<Box> boxes = findBoxes();
    
    // Sort boxes by area (desc), then by x (asc), then by y (asc)
    sort(boxes.begin(), boxes.end(), [](const Box& a, const Box& b) {
        if (a.area != b.area) return a.area > b.area;
        if (a.x1 != b.x1) return a.x1 < b.x1;
        return a.y1 < b.y1;
    });
    
    int R;
    cin >> R;
    cin.ignore();
    
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> strings;
    string s;
    while (ss >> s) {
        strings.push_back(s);
    }
    
    // Assign strings to boxes (left-to-right, bottom-to-top)
    vector<Box> originalOrder = findBoxes();
    sort(originalOrder.begin(), originalOrder.end(), [](const Box& a, const Box& b) {
        if (a.y1 != b.y1) return a.y1 < b.y1;
        return a.x1 < b.x1;
    });
    
    map<pair<int,int>, string> boxToString;
    for (int i = 0; i < originalOrder.size(); i++) {
        boxToString[{originalOrder[i].x1, originalOrder[i].y1}] = strings[i];
    }
    
    // Get the string for rank R
    Box targetBox = boxes[R - 1];
    string targetString = boxToString[{targetBox.x1, targetBox.y1}];
    
    int value = 0;
    for (char c : targetString) {
        value += (int)c;
    }
    
    cout << value << endl;
    
    return 0;
}
