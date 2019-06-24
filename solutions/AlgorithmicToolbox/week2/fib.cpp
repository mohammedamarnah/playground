#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> fib;

long long solve_fib(int n) {
  if (!n) return 0;
  if (n < 3) return 1;
  fib.resize(n+1);
  fib[0] = fib[1] = fib[2] = 1;
  for (int i = 3; i <= n; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  return fib[n];
}

int main() {
  int n;
  scanf("%d", &n);
  cout << solve_fib(n) << endl;
  return 0;
}
