#include <iostream>
using namespace std;

void solve() {
  long n;
  cin >> n;
  // for each index of grid k x k
  for (long k = 1; k <= n; ++k) {
    long ans = (k * k * (k * k - 1) / 2);
    ans -= 4 * (k - 1) * (k - 2);
    cout << ans << endl;
  }
}

int main() {

  solve();

  return 0;
}
