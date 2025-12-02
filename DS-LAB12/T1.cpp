#include <iostream>
#include <vector>
using namespace std;

vector<int> bruteForceSearch(const string& text, const string& pattern, int& comparisons) {
    vector<int> positions;
    comparisons = 0;
    
    int n = text.length();
    int m = pattern.length();
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            comparisons++;
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            positions.push_back(i);
        }
    }
    
    return positions;
}

int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    
    int comparisons;
    vector<int> result = bruteForceSearch(text, pattern, comparisons);
    
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    cout << "Total comparisons: " << comparisons << endl;
    
    return 0;
}