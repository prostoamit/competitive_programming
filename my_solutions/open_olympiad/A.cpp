#include <bits/stdc++.h>
using namespace std;


long long solve(long long n, long long a, long long x, long long m) {
  long long water = n * a;

  if(water - x < 0) {
    return 0;
  }

  else {
    water -= x;
    return water / m;
  }
}

int main() {
  long long m, n, x, a; cin >> n >> a >> x >> m;

  cout << solve(n, a, x, m);
  return 0;
}
