#include <climits>
#include <iostream>
#include <vector>
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

void solve(int index, vector<ll> &wt, vector<ll> &ff, vector<ll> &ss, ll &ans) {
  if (index == wt.size()) {
    ll sumF = 0, sumS = 0;
    for (ll val : ff) {
      sumF += val;
    }
    for (ll val : ss)
      sumS += val;

    ans = min(ans, abs(sumF - sumS));
    return;
  }

  ff.pb(wt[index]);
  solve(index + 1, wt, ff, ss, ans);
  ff.ppb();

  ss.pb(wt[index]);
  solve(index + 1, wt, ff, ss, ans);
  ss.ppb();
}

int main() {
  fastio(); // Call here to enable fast IO.

  int n;
  cin >> n;
  vector<ll> wt(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> wt[i];
  }

  vector<ll> ff, ss;
  ll ans = LLONG_MAX;
  solve(0, wt, ff, ss, ans);
  cout << ans << endl;
}
