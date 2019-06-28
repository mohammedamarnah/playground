#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define TAKE_INPUT(v, n) for(int i = 0; i < n; ++i) scanf("%d", &v[i])
#define OUTPUT(v, n) for(int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;

ll n;
ll dp[10000];

ll calc(ll sum) {
  if (sum > n) return 1e9;
  if (sum == n) return 0;
  if (dp[sum] != -1) return dp[sum];
  ll one = 1 + calc(sum + 1);
  ll three = 1 + calc(sum + 3);
  ll four = 1 + calc(sum + 4);

  return dp[sum] = min(one, min(three, four));
}

int main() {
    scanf("%lld", &n);
    memset(dp, -1, sizeof(dp));
    cout << calc(0) << endl;
}
