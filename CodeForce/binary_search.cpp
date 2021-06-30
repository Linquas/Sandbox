#include <bits/stdc++.h>

using namespace std;

void binarySearch(vector<int>& nums, int target) {
    if (nums.size() == 0) {
        cout << "NO" << endl;
        return;
    }

    int l = 0;
    int r = nums.size();
    bool isFound = false;
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            isFound = true;
            break;
        } else if (nums[mid] > target) {
            r = mid;
        } else {
            l = mid;
        }
    }

    if (nums[l] == target) {
        isFound = true;
    }
    if (isFound) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int length;
    int queries;
    cin >> length;
    cin >> queries;

    vector<int> input = vector<int>(length, -1);
    for (int i = 0; i < length; ++i) {
        int temp;
        cin >> temp;
        input[i] = temp;
    }

    for (int i = 0; i < queries; ++i) {
        int target;
        cin >> target;
        binarySearch(input, target);
    }
    return 0;
}