#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define oo 1e9

int n;
vector<int> v;
unordered_map<string, bool> dp;

bool calc(int idx, int a, int b, int c) {
  if (a == 0 && b == 0 && c == 0) {
    return true;
  }

  if (idx < 0 || a < 0 || b < 0 || c < 0) {
    return false;
  }

  string key = to_string(a) + "|" + to_string(b) + "|" + to_string(c) + "|" + to_string(idx);
  if (dp.find(key) == dp.end()) {
    bool one = calc(idx - 1, a - v[idx], b, c);
    bool two = calc(idx - 1, a, b - v[idx], c);
    bool three = calc(idx - 1, a, b, c - v[idx]);
    dp[key] = one || two || three;
  }

  return dp[key];
}

int main() {
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    if (n < 3) {  cout << 0 << endl; return 0; }
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << (!(sum % 3) && calc(n-1, sum/3, sum/3, sum/3)) << endl;
}
