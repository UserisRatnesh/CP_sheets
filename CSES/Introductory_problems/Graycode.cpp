#include <algorithm>
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

vector<string> solve(ll n) {
  if (n == 1) {
    return {"0", "1"};
  }
  vector<string> ans = solve(n - 1);

  vector<string> revAns = ans;
  reverse(ans.begin(), ans.end());

  int index = 0;
  int prevSize = ans.size();
  while (index < prevSize) {
    ans[index] = "0" + ans[index];
    ans.pb("1" + revAns[index]);

    index++;
  }
  return ans;
}

int main() {
  ll n;
  cin >> n;
  vector<string> ans = solve(n);
  for (string str : ans) {
    cout << str << endl;
  }
}
