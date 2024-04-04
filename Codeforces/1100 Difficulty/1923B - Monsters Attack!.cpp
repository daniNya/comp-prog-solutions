#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        map<int, ll> hp_per_second;
        vector<int> hp;

        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            hp.push_back(a);
        }

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            x = abs(x);

            hp_per_second[x] += hp[j];
        }

        auto it = hp_per_second.begin();
        auto current_key = it -> first;

        ll damage = 0;
        int second = 0;
        int done = 0;

        while (done < hp_per_second.size()) {
            damage += k;
            second++;
            if (current_key == second) {
                damage -= hp_per_second[current_key];
                done++;
                if (damage < 0) break;

                it++;
                current_key = it -> first;
            }
        }

        cout << (damage >= 0 ? "YES" : "NO") << endl;
    }

    return 0;
}

/*
Thought Process:
1. Disregard individual monsters, and group them up by the distance from center
2. Simulate the game by stocking up "damage" every second
3. If the current second matches a distance that has monsters, decrease the damage by the value
4. If the damage drops below 0, that means it's not possible to defeat the monsters at the current distance with the damage

-- Encountered signed integer overflow :/

Status:
ACCEPTED
Time - 827 ms
Memory - 107000 KB
*/
