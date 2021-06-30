#include <bits/stdc++.h>

using namespace std;

int closestToRight(vector<int>& nums, int target) {
    //lower bound
    if (nums.size() == 0) {
        return 0;
    }

    int l = -1;
    int r = nums.size();

    // 2 , 3 , 5, 5 , 7 , 8  target = 7
    //                ^    
    //            l   r 
    // l = -1, r = 6, mid = 2
    // l = 2, r = 6. mid = 3
    // l = 3, r = 6 mid = 4
    // l = 3, r = 4 mid = 3
    while(r - l > 1) { // end at r = l + 1
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            r = mid;
        } else if (nums[mid] < target) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    return r;
}

int main() {
    int length;
    int queries;
    cin >> length;
    cin >> queries;

    vector<int> input = vector<int>(length, -1);
    for (int i = 0; i < length; ++i) {
        int num;
        cin >> num;
        input[i] = num;
    }

    for (int i = 0; i < queries; ++i) {
        int target;
        cin >> target;
        cout << closestToRight(input, target) + 1 << endl;
    }

    return 0;
}