#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

vector<int> KMPSearch(const string& text, const string& pattern) {
    vector<int> positions;
    int n = text.length();
    int m = pattern.length();
    
    if (m == 0 || n < m) return positions;
    
    vector<int> lps = computeLPS(pattern);
    
    int i = 0;
    int j = 0;
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            positions.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return positions;
}

int main() {
    string text = "ababababc";
    string pattern = "abab";
    
    vector<int> lps = computeLPS(pattern);
    
    cout << "LPS array for pattern \"" << pattern << "\": [";
    for (int i = 0; i < lps.size(); i++) {
        cout << lps[i];
        if (i < lps.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    vector<int> result = KMPSearch(text, pattern);
    
    cout << "Positions found: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}