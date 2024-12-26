#include <iostream>
#include <vector>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(null);                                                               \
  cout.tie(null)
#define mod 1000000007
#define mod1 998244353
#define inf 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define pi 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void solve() {
  ll n;
  cin >> n;

  vector<ll> b;
  for (int i = 0; i < n; ++i) {
    ll input;
    cin >> input;
    b.pb(input);
  }
  vector<ll> a;
  a.pb(b[0]);
  for (int i = 1; i < n; ++i) {
    if (b[i] >= b[i - 1]) {
      a.pb(b[i]);
    } else {
      a.pb(1);
      a.pb(b[i]);
    }
  }

  cout << a.size() << endl;
  for (int val : a) {
    cout << val << " ";
  }
  cout << endl;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
