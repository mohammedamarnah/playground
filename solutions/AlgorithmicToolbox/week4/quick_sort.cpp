#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define TAKE_INPUT(v, n) for(int i = 0; i < n; ++i) scanf("%d", &v[i])
#define OUTPUT(v, n) for(int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;

pair<int, int> partition(vector<int> &v, int l, int r) {
  int lt = l, i = l, gt = r, pivot = v[l];
  while (i <= gt) {
    if (v[i] < pivot) {
      swap(v[i], v[lt]);
      lt++;
      i++;
    } else if (v[i] > pivot) {
      swap(v[i], v[gt]);
      gt--;
    } else {
      i++;
    }
  }

  return make_pair(lt, gt);
}

void quick_sort(vector<int> &v, int l, int r) {
  if (l >= r) {
    return;
  }
  int pivot = l + rand() % (r - l + 1);
  swap(v[l], v[pivot]);
  pair<int, int> m = partition(v, l, r);

  quick_sort(v, l, m.first - 1);
  quick_sort(v, m.second + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }
    quick_sort(v, 0, n - 1);
    for (int i = 0; i < n; i++) {
      cout << v[i] << " ";
    } cout << endl;
}
