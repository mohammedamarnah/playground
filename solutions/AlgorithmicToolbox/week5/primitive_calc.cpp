#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define oo 1e9

ll n;
ll dp[1000000+20];
vector<ll> ops;

ll calc(ll x) {
  if (x > n) return oo;
  if (x == n) return 0;
  if (dp[x] != -1) return dp[x];

  ll one = 1 + calc(x + 1);
  ll two = 1 + calc(x * 2);
  ll three = 1 + calc(x * 3);
  dp[x] = min(one, min(two, three));

  return dp[x];
}

void construct_list() {
  for (int i = 0; i < 1000000; i++) {
    if (dp[i] != -1) {
      cout << i << ", " << dp[i] << endl;
    }
  }
}

int main() {
    scanf("%lld", &n);
    memset(dp, -1, sizeof(dp));
    cout << calc(1) << endl;
    construct_list();
}
