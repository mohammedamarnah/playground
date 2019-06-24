#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define TAKE_INPUT(v, n) for(int i = 0; i < n; ++i) scanf("%d", &v[i])
#define OUTPUT(v, n) for(int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    bool state = false;
    for (int i = 0; i < n; i++) {
        auto lb = lower_bound(v.begin(), v.end(), v[i]);
        auto ub = upper_bound(v.begin(), v.end(), v[i]);
        auto dist1 = distance(v.begin(), lb);
        auto dist2 = distance(v.begin(), ub);
        if (dist2 - dist1 > n / 2) {
            state = true;
            break;
        }
    }
    cout << state << endl;
}
