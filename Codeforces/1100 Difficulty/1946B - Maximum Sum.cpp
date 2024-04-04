#include <bits/stdc++.h>
#define ll long long

const ll MOD = pow(10, 9) + 7;

using namespace std;

ll find_max(vector<ll> nums, ll trailing_sum_max, int total_count) {
    ll last_num = LONG_MIN;
    ll temp = 0;
    ll total_sum = 0;

    for (auto& num : nums) {
        total_sum += num % MOD;
        total_sum %= MOD;
        if (total_sum < 0) total_sum = MOD + total_sum;
        temp += num;
        if (temp < 0) temp = 0;
        last_num = max(temp, last_num);
    }

    if (last_num == 0) return total_sum;

    total_sum += last_num % MOD;
    total_sum %= MOD;
    if (total_sum < 0) total_sum = MOD + total_sum;
    last_num += trailing_sum_max;
    total_count--;
    if (total_count > 0) {
        total_sum += last_num % MOD;
        total_sum %= MOD;
        if (total_sum < 0) total_sum = MOD + total_sum;
    }

    for (int i = 1; i < total_count; i++) {
        last_num *= 2;
        last_num %= MOD;
        total_sum += last_num;
        total_sum %= MOD;
        if (total_sum < 0) total_sum = MOD + total_sum;
    }

    return total_sum;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int res = 0;

        int n, k;
        cin >> n >> k;

        vector<ll> nums;

        for (int j = 0; j < n; j++) {
            ll a;
            cin >> a;

            nums.push_back(a);
        }

        vector<ll> rev = nums;
        reverse(rev.begin(), rev.end());
        ll max_sum = 0;
        ll temp = 0;
        for (auto& num : rev) {
            temp += num;
            if (temp < 0) temp = 0;
            max_sum = max(temp, max_sum);
        }

        res = find_max(nums, max_sum, k);

        cout << res << endl;
    }

    return 0;
}

/*
Thought Process:
1. Find the maximum sum of sub-array in the array
2. If the maximum sum is less than or equal to 0, return the sum of the array
3. Every operation, the maximum sum gets added to the array
4. Any subsequent number that gets added to the array is simply double the previous last number of the array

Status:
ACCEPTED
Time - 328 ms
Memory - 2100 KB
*/
