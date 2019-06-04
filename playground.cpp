#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long GCD(long long a, long long b) {
  return b ? GCD(b, a % b) : a;
}

int main() {
  long long a, b;
  scanf("%lld%lld", &a, &b);
  cout << (a * b) / GCD(a,b) << endl;
  return 0;
}
