#ifndef ONLINE_JUDGE
#include "/usr/local/include/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

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

#ifndef ONLINE_JUDGE
#define debug(x)                                                               \
  cerr << #x << " ";                                                           \
  _print(x);                                                                   \
  cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

int dirX[] = {0, 1, 0, -1};
int dirY[] = {1, 0, -1, 0};

void dfs(int i, int j, vector<string> &matrix) {
  int n = matrix.size();
  int m = sz(matrix[0]);
  if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] != '.') {
    return;
  }

  matrix[i][j] = '#';
  for (int k = 0; k < 4; k++) {
    int newI = i + dirX[k];
    int newJ = j + dirY[k];
    dfs(newI, newJ, matrix);
  }
}

void rooms(vector<string> &matrix) {
  int n = matrix.size();
  int m = sz(matrix[0]);

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] == '.') {
        ans++;
        dfs(i, j, matrix);
      }
    }
  }

  cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
  ll n, m;
  cin >> n >> m;
  vector<string> matrix(n);
  for (int i = 0; i < n; i++) {
    cin >> matrix[i];
  }
  rooms(matrix);
}
