#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define oo 1e9

ll dp[200][200];

ll min(ll x, ll y, ll z) {
  return min(x, min(y, z));
}

ll edit_distance(string a, string b, int n, int m) {
  if (m == 0) return n;
  if (n == 0) return m;
  if (dp[n][m] != -1) return dp[n][m];

  if (a[n-1] == b[m-1]) {
    return dp[n][m] = edit_distance(a, b, n-1, m-1);
  }

  return dp[n][m] = 1 + min(edit_distance(a, b, n, m-1),
                            edit_distance(a, b, n-1, m),
                            edit_distance(a, b, n-1, m-1));
}

int main() {
    string a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << edit_distance(a, b, a.size(), b.size()) << endl;
}
