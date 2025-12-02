#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, pair<int, int>> sumPairs;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if (sumPairs.find(sum) == sumPairs.end()) {
                sumPairs[sum] = {arr[i], arr[j]};
            } else {
                pair<int, int> p = sumPairs[sum];
                if (p.first != arr[i] && p.first != arr[j] &&
                    p.second != arr[i] && p.second != arr[j]) {
                    cout << "(" << p.first << ", " << p.second << ") and ("
                         << arr[i] << ", " << arr[j] << ")" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No pairs found" << endl;
    return 0;
}
