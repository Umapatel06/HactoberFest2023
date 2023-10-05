#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(vector<int>& stalls, int k, int minDistance) {
    int cowsPlaced = 1;
    int lastPlaced = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPlaced >= minDistance) {
            cowsPlaced++;
            lastPlaced = stalls[i];
        }
    }

    return cowsPlaced >= k;
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int left = 1;
    int right = stalls.back() - stalls.front();

    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(stalls, k, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}
