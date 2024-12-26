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

int solve() {
  ll n, m;
  cin >> n >> m;
  string x, s;
  cin >> x >> s;

  for (int i = 0; i <= 5; i++) {
    if (x.find(s) != -1) {
      return i;
    }
    x.append(x);
  }
  return -1;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
}
