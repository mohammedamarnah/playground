#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<double, double> a, pair<double, double> b) {
  return (a.first/a.second) > (b.first/b.second);
}

double max_loot(vector<pair<double, double> > v, double total) {
  sort(v.begin(), v.end(), compare);
  double w = 0.0;
  double ans = 0.0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].second + w <= total) {
      w += v[i].second;
      ans += v[i].first;
    } else if (w < total) {
      ans += (v[i].first / v[i].second) * (total - w);
      w = total;
    }
  }

  return ans;
}

int main() {
  double n, w;
  cin >> n >> w;

  vector<pair<double, double> > v(n);
  for (int i = 0; i < n; i++) {
    double a, b;
    cin >> a >> b;
    v[i].first = a;
    v[i].second = b;
  }

  cout << setprecision(10) << max_loot(v, w) << endl;

  return 0;
}
