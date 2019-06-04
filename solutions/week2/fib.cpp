#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> fib;

long long solve_fib(int n) {
  fib.resize(n);
  fib[0] = fib[1] = 1;
  for (int i = 2; i < n; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }

  return fib[n-1];
}

int main() {
  int n;
  scanf("%d", &n);
  cout << solve_fib(n) << endl;
  return 0;
}
