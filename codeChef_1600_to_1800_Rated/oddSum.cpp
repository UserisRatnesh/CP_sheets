#include <iostream>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

int main() {

  ll t;
  cin >> t;
  vector<ll> results;
  while (t--) {
    ll n;
    cin >> n;
    results.push_back(1 + (n - 1) * (n - 2));
  }
  for (const auto &res : results) {
    cout << res << '\n';
  }
  return 0;
}
