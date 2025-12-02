#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ALPHABET_SIZE = 4;

int getIndex(char c) {
    switch(c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default: return 0;
    }
}

vector<int> buildBadCharTable(const string& pattern) {
    vector<int> badChar(ALPHABET_SIZE, -1);
    
    for (int i = 0; i < pattern.length(); i++) {
        badChar[getIndex(pattern[i])] = i;
    }
    
    return badChar;
}

vector<int> buildGoodSuffixTable(const string& pattern) {
    int m = pattern.length();
    vector<int> goodSuffix(m, 0);
    vector<int> suffixes(m + 1, 0);
    
    suffixes[m] = m + 1;
    int f = 0;
    
    for (int i = m - 1; i >= 0; i--) {
        if (i > f && suffixes[i + m - 1 - f] < i - f) {
            suffixes[i] = suffixes[i + m - 1 - f];
        } else {
            if (i < f) f = i;
            int j = f - i;
            while (j < m && pattern[f - j] == pattern[m - 1 - j]) {
                j++;
            }
            suffixes[i] = j;
            f = i;
        }
    }
    
    for (int i = 0; i < m; i++) {
        goodSuffix[i] = m;
    }
    
    for (int i = m - 1; i >= 0; i--) {
        if (suffixes[i] == i + 1) {
            for (int j = 0; j < m - 1 - i; j++) {
                if (goodSuffix[j] == m) {
                    goodSuffix[j] = m - 1 - i;
                }
            }
        }
    }
    
    for (int i = 0; i <= m - 2; i++) {
        goodSuffix[m - 1 - suffixes[i]] = m - 1 - i;
    }
    
    return goodSuffix;
}

vector<int> boyerMooreSearch(const string& text, const string& pattern) {
    vector<int> positions;
    int n = text.length();
    int m = pattern.length();
    
    if (m == 0 || n < m) return positions;
    
    vector<int> badChar = buildBadCharTable(pattern);
    vector<int> goodSuffix = buildGoodSuffixTable(pattern);
    
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }
        
        if (j < 0) {
            positions.push_back(s);
            s += goodSuffix[0];
        } else {
            int bcShift = j - badChar[getIndex(text[s + j])];
            int gsShift = goodSuffix[j];
            s += max(1, max(bcShift, gsShift));
        }
    }
    
    return positions;
}

int main() {
    string dna = "ACGTACGTGACG";
    string pattern = "ACG";
    
    vector<int> result = boyerMooreSearch(dna, pattern);
    
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}