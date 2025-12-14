#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
using namespace std;

map<string, set<string>> graph;
map<string, set<string>> restrictions; // source -> restricted stations

bool canReach(string source, string dest) {
    if (source == dest) return true;
    
    set<string> visited;
    queue<string> q;
    q.push(source);
    visited.insert(source);
    
    // Get restrictions for this source
    set<string> restricted;
    if (restrictions.count(source)) {
        restricted = restrictions[source];
    }
    
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        
        if (current == dest) return true;
        
        // Explore neighbors
        if (graph.count(current)) {
            for (const string& neighbor : graph[current]) {
                // Skip if already visited or restricted
                if (visited.count(neighbor) || restricted.count(neighbor)) {
                    continue;
                }
                
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    // Read initial connections
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string source, station;
        ss >> source;
        
        // Remove comma if present
        if (source.back() == ',') {
            source.pop_back();
        }
        
        while (ss >> station) {
            if (station.back() == ',') {
                station.pop_back();
            }
            
            graph[source].insert(station);
            graph[station].insert(source); // Bidirectional
        }
    }
    
    int q;
    cin >> q;
    cin.ignore();
    
    // Process queries
    for (int i = 0; i < q; i++) {
        string line;
        getline(cin, line);
        
        if (line.find(" to ") != string::npos) {
            // Travel query
            size_t pos = line.find(" to ");
            string source = line.substr(0, pos);
            string dest = line.substr(pos + 4);
            
            if (canReach(source, dest)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        else if (line.find(" connects ") != string::npos) {
            // Connect query
            size_t pos = line.find(" connects ");
            string station1 = line.substr(0, pos);
            string station2 = line.substr(pos + 10);
            
            graph[station1].insert(station2);
            graph[station2].insert(station1);
        }
        else if (line.find(" disconnects ") != string::npos) {
            // Disconnect query
            size_t pos = line.find(" disconnects ");
            string station1 = line.substr(0, pos);
            string station2 = line.substr(pos + 13);
            
            graph[station1].erase(station2);
            graph[station2].erase(station1);
        }
    }
    
    int r;
    cin >> r;
    cin.ignore();
    
    // Read restrictions
    for (int i = 0; i < r; i++) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string source, station;
        ss >> source;
        
        if (source.back() == ',') {
            source.pop_back();
        }
        
        while (ss >> station) {
            if (station.back() == ',') {
                station.pop_back();
            }
            restrictions[source].insert(station);
        }
    }
    
    return 0;
}
