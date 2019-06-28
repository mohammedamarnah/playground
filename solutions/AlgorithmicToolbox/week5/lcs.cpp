#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define oo 1e9

ll n, m;
vector<ll> v, e;
ll dp[200][200];

ll calc(int a, int b) {
  if (a == 0 || b == 0) {
    return 0;
  }
  if (dp[a][b] != -1) return dp[a][b];

  if (v[a-1] == e[b-1]) {
    return dp[a][b] = 1 + calc(a-1, b-1);
  }
  return dp[a][b] = max(calc(a, b-1), calc(a-1, b));
}

int main() {
    scanf("%lld", &n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%lld", &v[i]);
    }
    scanf("%lld", &m);
    e.resize(m);
    for (int i = 0; i < m; i++) {
      scanf("%lld", &e[i]);
    }
    memset(dp, -1, sizeof(dp));

    cout << calc(n, m) << endl;
}
