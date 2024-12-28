#include <csetjmp>
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

void solve(int n, int from, int to, int aux, vector<pair<int, int>> &ans) {
  if (n == 0) {
    return;
  }

  solve(n - 1, from, aux, to, ans);
  ans.pb({from, to});
  solve(n - 1, aux, to, from, ans);
  return;
}

int main() {
  fastio(); // Call here to enable fast IO.

  int n;
  cin >> n;
  vector<pair<int, int>> ans;
  solve(n, 1, 3, 2, ans);
  cout << ans.size() << endl;
  for (pair<int, int> p : ans) {
    cout << p.first << " " << p.second << endl;
  }
}
