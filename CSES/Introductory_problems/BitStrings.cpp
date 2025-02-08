#include <iostream>
using namespace std;
#define pb push_back
using ll = long long;
#define MOD 1000000007
#define loop(i, start, end) for (ll i = ll(start); i < ll(end); i++)

// How to calculate 2 ka power very large

ll power_mod(ll n) {
  ll ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans = (ans * 2) % MOD;
  }
  return ans;
}
int main() {
  ll n;
  cin >> n;
  cout << power_mod(n) << endl;
}
