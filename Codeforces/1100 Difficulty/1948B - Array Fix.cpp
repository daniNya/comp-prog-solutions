#include <bits/stdc++.h>

using namespace std;

bool fix(vector<int> nums, int curr, int next_idx) {
    if (next_idx >= nums.size()) return true;

    bool res = false;

    int num = nums[next_idx];

    if (num >= curr) res |= fix(nums, num, next_idx + 1);

    if (num >= 10) {
        if ((num / 10) >= curr && (num / 10 <= num % 10)) res |= fix(nums, (num % 10), next_idx + 1);
    }

    return res;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> nums;

        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;

            nums.push_back(a);
        }

        string res = (fix(nums, 0, 0) ? "YES" : "NO");

        cout << res << endl;
    }

    return 0;
}

/*
Thought Process:
1. Every number in the vector must be more than or equal to the previous number (we assume the number before index 0 is 0 as numbers can only be non-negative)
2. To see if its possible for the vector, all combinations of the operation may be tried out
3. Can be done using recursion
    - For the first branch, check if the number itself is more than or equal to the previous number, then proceed with next number with the current number as checking
    - If the number is 2 digits, create the second branch where it checks if the ones is more than or equal to the tens, if yes, proceed with next number with the ones as checking
4. If any of the branches returns a true, that means that the vector it "created" is non-descending, and therefore possible to be made

Status:
ACCEPTED
Time - 233 ms
Memory - 0 KB
*/
