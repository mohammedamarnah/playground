#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> fib;

long long last_digit(int n) {
  if (n < 2) return 1;
  fib.resize(n);
  fib[0] = fib[1] = 1;
  for (int i = 2; i < n; i++) {
    fib[i] = fib[i-1] + fib[i-2];
    fib[i] %= 10;
  }

  return fib[n-1];
}

int main() {
  int n;
  scanf("%d", &n);
  cout << last_digit(n) << endl;
  return 0;
}
