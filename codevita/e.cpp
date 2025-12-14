#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

// Count operations in expanded form
int countOps(map<string, int>& terms) {
    int ops = 0;
    bool first = true;
    
    for (auto& p : terms) {
        if (p.second == 0) continue;
        
        if (!first) ops++; // addition between terms
        first = false;
        
        string term = p.first;
        if (abs(p.second) != 1 || term.empty()) {
            if (!term.empty()) ops++; // multiplication
        }
        
        // Count multiplications within term
        int varCount = 0;
        for (char c : term) {
            if (c == 'x' || c == 'y') varCount++;
        }
        if (varCount > 1) ops += varCount - 1;
    }
    
    return ops;
}

// Try to match factorization patterns
int tryFactorization(map<string, int>& terms) {
    int xx = terms["xx"], xy = terms["xy"], yy = terms["yy"];
    int x = terms["x"], y = terms["y"];
    int c = terms[""];
    
    // Form 1: a1*a2*xx + (a1*b2+a2*b1)*x + b1*b2
    // Try to factor into (a1*x + b1)(a2*x + b2)
    if (xx != 0 && yy == 0 && xy == 0) {
        // Try to find a1, a2, b1, b2 such that:
        // a1*a2 = xx, a1*b2 + a2*b1 = x, b1*b2 = c
        for (int a1 = -10; a1 <= 10; a1++) {
            if (a1 == 0 || xx % a1 != 0) continue;
            int a2 = xx / a1;
            
            for (int b1 = -10; b1 <= 10; b1++) {
                if (c != 0 && b1 == 0) continue;
                if (c != 0 && c % b1 != 0) continue;
                if (c == 0 && b1 != 0) continue;
                
                int b2 = (c == 0) ? 0 : c / b1;
                
                if (a1 * b2 + a2 * b1 == x) {
                    // Found factorization: (a1*x + b1)(a2*x + b2)
                    int ops = 2; // one mult, one add in each bracket
                    if (a1 != 1 && a1 != -1) ops++;
                    if (a2 != 1 && a2 != -1) ops++;
                    ops++; // multiply the two brackets
                    return ops;
                }
            }
        }
    }
    
    // Form 2: a1*a2*xy + a1*b2*x + a2*b1*y + b1*b2
    // Try to factor into (a1*x + b1)(a2*y + b2)
    if (xx == 0 && yy == 0 && xy != 0) {
        for (int a1 = -10; a1 <= 10; a1++) {
            if (a1 == 0 || xy % a1 != 0) continue;
            int a2 = xy / a1;
            
            for (int b1 = -10; b1 <= 10; b1++) {
                if (c != 0 && b1 == 0) continue;
                if (c != 0 && c % b1 != 0) continue;
                if (c == 0 && b1 != 0) continue;
                
                int b2 = (c == 0) ? 0 : c / b1;
                
                if (a1 * b2 == x && a2 * b1 == y) {
                    int ops = 2;
                    if (a1 != 1 && a1 != -1) ops++;
                    if (a2 != 1 && a2 != -1) ops++;
                    ops++;
                    return ops;
                }
            }
        }
    }
    
    // Form 3: a1*a2*xx + a1*b2*x + a2*b1*xy + b1*b2*y
    // Try to factor into (a1*x + b1*y)(a2*x + b2)
    if (yy == 0 && xx != 0 && xy != 0) {
        for (int a1 = -10; a1 <= 10; a1++) {
            if (a1 == 0 || xx % a1 != 0) continue;
            int a2 = xx / a1;
            
            for (int b1 = -10; b1 <= 10; b1++) {
                if (b1 == 0) continue;
                if (xy % a2 != 0) continue;
                int b1_test = xy / a2;
                if (b1 != b1_test) continue;
                
                for (int b2 = -10; b2 <= 10; b2++) {
                    if (y != 0 && b1 * b2 == y && a1 * b2 == x) {
                        int ops = 3; // (a1*x + b1*y) has 3 ops
                        if (a2 != 1 && a2 != -1) ops++;
                        ops++; // multiply brackets
                        return ops;
                    }
                }
            }
        }
    }
    
    return INT_MAX;
}

int main() {
    string input;
    getline(cin, input);
    
    // Remove spaces
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    
    // Parse and expand to get coefficients
    // This is a simplified version - full implementation needs proper parser
    map<string, int> terms;
    terms["xx"] = 0; terms["xy"] = 0; terms["yy"] = 0;
    terms["x"] = 0; terms["y"] = 0; terms[""] = 0;
    
    // Count operations in original
    int originalOps = 0;
    for (char c : input) {
        if (c == '+' || c == '*') originalOps++;
    }
    
    int expandedOps = countOps(terms);
    int factoredOps = tryFactorization(terms);
    
    int minOps = min({originalOps, expandedOps, factoredOps});
    cout << minOps << endl;
    
    return 0;
}
