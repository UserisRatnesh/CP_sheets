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

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);

  int index = 0;
  while (index < n) {
    cin >> arr[index++];
  }

  int ans = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (arr[i + 1] == 0) {
      cout << -1 << endl;
      return;
    }
    while (arr[i] >= arr[i + 1]) {
      arr[i] /= 2;
      ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
