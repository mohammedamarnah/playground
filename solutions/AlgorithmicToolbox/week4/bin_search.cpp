#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define TAKE_INPUT(v, n) for(int i = 0; i < n; ++i) scanf("%d", &v[i])
#define OUTPUT(v, n) for(int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;

int binary_search(vector<int> v, int x) {
    int l = 0, h = (int)v.size() - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (v[mid] == x) {
            return mid;
        } else if (v[mid] > x) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n; scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    int k; scanf("%d", &k);
    for (int i = 0, x; i < k; i++) {
        scanf("%d", &x);
        cout << binary_search(v, x) << " ";
    } cout << endl;
}

