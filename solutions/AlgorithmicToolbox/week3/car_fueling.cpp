#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define TAKE_INPUT(v, n) for(int i = 0; i < n; ++i) scanf("%d", &v[i])
#define OUTPUT(v, n) for(int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;

int d, m, n;
vector<int> gas;

int main() {
    cin >> d >> m >> n;
    gas.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> gas[i];
    }
    gas.push_back(d);
    int numRefills = 0, currentRefill = 0;
    while (currentRefill <= n) {
        int lastRefill = currentRefill;
        while (currentRefill <= n &&
               gas[currentRefill + 1] - gas[lastRefill] <= m) {
            currentRefill++;
        }
        if (currentRefill == lastRefill) {
            numRefills = -1;
            break;
        }
        if (currentRefill <= n) {
            numRefills++;
        }
    }
    cout << numRefills << endl;
    return 0;
}
