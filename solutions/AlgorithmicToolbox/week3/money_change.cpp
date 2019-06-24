#include <bits/stdc++.h>
using namespace std;

int get_change(int n) {
 vector<int> coins(3);
 coins[0] = 1, coins[1] = 5, coins[2] = 10;
 int sum = 0, sol = 0;
 while (sum < n) {
   sum += coins[coins.size() - 1];
   if (sum > n) {
     sum -= coins[coins.size() - 1];
     coins.pop_back();
   } else {
     sol++;
   }
 }

 return sol;
}

int main() {
  int n;
  scanf("%d", &n);
  cout << get_change(n) << endl;
  return 0;
}
