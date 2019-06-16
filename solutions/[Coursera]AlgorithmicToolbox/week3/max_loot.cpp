#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> a, pair<int, int> b) {
  return (a.first/a.second) > (b.first/b.second);
}

double max_loot(vector<pair<int, int> > v, int total) {
  sort(v.begin(), v.end(), compare);
  double w = 0.0;
  double ans = 0.0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].second + w <= total) {
      w += v[i].second;
      ans += v[i].first;
    } else if (w < total) {
      w = total;
      ans += v[i].first / (v[i].second / w);
    }
  }

  return ans;
}

int main() {
  int n, w;
  scanf("%d%d", &n, &w);

  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[i].first = a;
    v[i].second = b;
  }

  cout << setprecision(10) << max_loot(v, w) << endl;

  return 0;
}
