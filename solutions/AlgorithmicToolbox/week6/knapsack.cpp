#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define oo 1e9

int w, n;
vector<int> v;
int dp[400][10000+100];

int main() {
    scanf("%d%d", &w, &n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= n; i++) {
      for (int wt = 0; wt <= w; wt++) {
        if (i == 0 || wt == 0) {
          dp[i][wt] = 0;
        } else if (v[i-1] <= wt) {
          dp[i][wt] = max(v[i-1] + dp[i-1][wt-v[i-1]], dp[i-1][wt]);
        } else {
          dp[i][wt] = dp[i-1][wt];
        }
      }
    }

    cout << dp[n][w] << endl;
}
