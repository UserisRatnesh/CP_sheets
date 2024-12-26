
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

void solve() {
  ll a, b;
  cin >> a >> b;
  if ((2 * a - b) < 0 || (2 * a - b) % 3 || (2 * b - a) < 0 ||
      (2 * b - a) % 3) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
