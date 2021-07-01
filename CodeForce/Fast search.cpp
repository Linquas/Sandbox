#include <bits/stdc++.h>

using namespace std;

int fastSearch(vector<int>& nums, int l_num, int r_num) {
    //find l_num  -> lowerBound
    //  xxvv
    //   lr
    //    ^ 
    int l = -1;
    int r = nums.size();
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == l_num) {
            r = mid;
        } else if (nums[mid] < l_num) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int indexOfL = r;

    //find r_num  -> upperBound - 1

    // xxvvyy
    //    lr  
    //    ^ 
    l = -1;
    r = nums.size();
    while(r - l > 1) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == r_num) {
            l = mid;
        } else if (nums[mid] < r_num) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return l - indexOfL + 1;
}

int main() {
    int length;
    cin >> length;
    
    vector<int> nums = vector<int>(length, -1);
    for (int i = 0; i < length; ++i) {
        int num;
        cin >> num;
        nums[i] = num;
    }
    sort(nums.begin(), nums.end());

    int queries;
    cin >> queries;

    for (int i = 0; i < queries; ++i) {
        int l;
        int r;
        cin >> l;
        cin >> r;
        cout << fastSearch(nums, l, r) << " ";
    }
   
    return 0;
}