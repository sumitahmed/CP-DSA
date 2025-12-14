#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Rectangle {
    int x, y, w, h;
    Rectangle(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {}
};

int M, N, C;
vector<Rectangle> rectangles;

bool isOutOfBounds(int x, int y, int w, int h) {
    // Grid spans from (0,0) to (N, M) inclusive
    return x < 0 || y < 0 || x + w > N || y + h > M;
}

bool isOverlapping(int x, int y, int w, int h, int skipIndex = -1) {
    for (int i = 0; i < rectangles.size(); i++) {
        if (i == skipIndex) continue;
        
        Rectangle& r = rectangles[i];
        
        // Rectangles touch or overlap if they're NOT completely separated
        // They are separated if one is completely to the left/right/above/below
        bool separated = (x + w <= r.x) || (r.x + r.w <= x) || 
                        (y + h <= r.y) || (r.y + r.h <= y);
        
        if (!separated) {
            return true;
        }
    }
    return false;
}

int findRectangle(int x, int y, int w, int h) {
    for (int i = 0; i < rectangles.size(); i++) {
        if (rectangles[i].x == x && rectangles[i].y == y && 
            rectangles[i].w == w && rectangles[i].h == h) {
            return i;
        }
    }
    return -1;
}

int findRectangleAtPosition(int x, int y) {
    for (int i = 0; i < rectangles.size(); i++) {
        if (rectangles[i].x == x && rectangles[i].y == y) {
            return i;
        }
    }
    return -1;
}

int main() {
    cin >> M >> N >> C;
    cin.ignore();
    
    vector<string> invalidCommands;
    
    for (int i = 0; i < C; i++) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string command;
        int x, y, w, h;
        
        ss >> command >> x >> y >> w >> h;
        
        if (command == "draw") {
            if (isOutOfBounds(x, y, w, h) || isOverlapping(x, y, w, h)) {
                invalidCommands.push_back(line);
            } else {
                rectangles.push_back(Rectangle(x, y, w, h));
            }
        } 
        else if (command == "remove") {
            int idx = findRectangle(x, y, w, h);
            if (idx == -1) {
                invalidCommands.push_back(line);
            } else {
                rectangles.erase(rectangles.begin() + idx);
            }
        } 
        else if (command == "extend") {
            int idx = findRectangleAtPosition(x, y);
            if (idx == -1) {
                invalidCommands.push_back(line);
            } else {
                Rectangle& current = rectangles[idx];
                
                // Check if dimensions are valid for extension
                if (w < current.w || h < current.h) {
                    invalidCommands.push_back(line);
                } else if (isOutOfBounds(x, y, w, h) || isOverlapping(x, y, w, h, idx)) {
                    invalidCommands.push_back(line);
                } else {
                    current.w = w;
                    current.h = h;
                }
            }
        } 
        else if (command == "shrink") {
            int idx = findRectangleAtPosition(x, y);
            if (idx == -1) {
                invalidCommands.push_back(line);
            } else {
                Rectangle& current = rectangles[idx];
                
                // Check if dimensions are valid for shrinking
                if (w > current.w || h > current.h) {
                    invalidCommands.push_back(line);
                } else {
                    current.w = w;
                    current.h = h;
                }
            }
        }
    }
    
    for (const string& cmd : invalidCommands) {
        cout << cmd << endl;
    }
    
    cout << rectangles.size() << endl;
    
    return 0;
}
