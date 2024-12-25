#include <iostream>
using namespace std;
#define pb push_back
using ll = long long;
#define mod 1000000007
#define loop(i, start, end) for (ll i = ll(start); i < ll(end); i++)

// How to calculate 2 ka power very large

ll power_mod(ll n)
{
  ll ans = 1;
  loop(i, 0, n) { ans = (ans * 2) % mod; }
  return ans;
}
int main()
{
  ll n;
  cin >> n;
  cout << power_mod(n) << endl;
}