#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k, x;
        cin >> n >> k >> x;

        deque<int> nums;

        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;

            nums.push_back(num);
        }

        sort(nums.begin(), nums.end(), greater<int>());
        deque<int> negatives = nums;
        for (auto& num : negatives) {num *= -1;};

        int ans = 0;
        for (int j = x; j < nums.size(); j++) {
            ans += nums[j];
        }
        for (int j = 0; j < x; j++) {
            ans += negatives.front();
            negatives.pop_front();
        }

        int res = ans;

        for (int j = 0; j < k; j++) {
            if (nums.size() > 0) {
                ans += nums.front();
                nums.pop_front();
            }
            if (negatives.size() > 0) {
                ans += negatives.front() * 2;
                negatives.pop_front();
            }
            res = max(res, ans);
        }

        cout << res << endl;
    }

    return 0;
}

/*
Thought Process:
1. For Bob to play optimally, he will ALWAYS use up all his operations on the largest numbers
2. For Alice to play optimally, she can try to remove the largest numbers one by one until she gets the maximum value
3. Sort the numbers descending
4. Take the sum of Bob's negative numbers and the remaining numbers
5. Every element Alice removes corresponds to :
    - Adding back the largest number to the sum (negating Bob's previous negative number)
    - Subtracting the next largest number twice (once to negate positive, twice to actually subtract)
6. Compare and return the max sum

Status:
ACCEPTED
Time - 202 ms
Memory - 100 KB
*/
