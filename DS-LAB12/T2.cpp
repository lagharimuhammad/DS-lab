#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int PRIME = 101;

vector<int> rabinKarpSearch(const string& text, const string& pattern, vector<pair<int, string>>& falsePositives) {
    vector<int> positions;
    falsePositives.clear();
    
    int n = text.length();
    int m = pattern.length();
    if (m == 0 || n < m) return positions;
    
    int patternHash = 0;
    int textHash = 0;
    int h = 1;
    
    for (int i = 0; i < m - 1; i++) {
        h = (h * 256) % PRIME;
    }
    
    for (int i = 0; i < m; i++) {
        patternHash = (256 * patternHash + pattern[i]) % PRIME;
        textHash = (256 * textHash + text[i]) % PRIME;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    string falseMatch = "";
                    for (int k = 0; k < m; k++) {
                        falseMatch += text[i + k];
                    }
                    falsePositives.push_back({i, falseMatch});
                    break;
                }
            }
            if (match) {
                positions.push_back(i);
            }
        }
        
        if (i < n - m) {
            textHash = (256 * (textHash - text[i] * h) + text[i + m]) % PRIME;
            if (textHash < 0) {
                textHash += PRIME;
            }
        }
    }
    
    return positions;
}

int main() {
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";
    
    vector<pair<int, string>> falsePositives;
    vector<int> result = rabinKarpSearch(text, pattern, falsePositives);
    
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    if (!falsePositives.empty()) {
        cout << "\nFalse-positive hash matches discarded:" << endl;
        for (const auto& fp : falsePositives) {
            cout << "Position " << fp.first << ": \"" << fp.second << "\"" << endl;
        }
    }
    
    return 0;
}