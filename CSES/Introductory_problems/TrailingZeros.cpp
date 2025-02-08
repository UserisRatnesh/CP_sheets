#include <iostream>
using namespace std;

#define pb push_back
#define MAX 100000

using ll = long long;

// This solution is very naive and gives overflow for even slight large value of
// n

int fact(int num, int res[], int res_size) {
  int carry = 0;
  for (int i = 0; i < res_size; i++) {
    int prod = res[i] * num + carry;
    res[i] = prod % 10;
    carry = prod / 10;
  }

  while (carry > 0) {
    res[res_size++] = carry % 10;
    carry = carry / 10;
  }
  return res_size;
}

void solve() {
  ll n;
  cin >> n;
  if (n == 0 || n == 1) {
    cout << 0;
    return;
  }

  int res[MAX];
  int res_size = 0;
  res[res_size++] = 1;
  for (int i = 2; i <= n; i++) {
    res_size = fact(i, res, res_size);
  }

  int i = 0;
  while (res[i] == 0 && i < res_size) {
    i++;
  }
  cout << i;
}

// Efficient way
void solveBetter() {
  ll n;
  cin >> n;

  ll ans = 0;
  for (ll i = 5; i <= n; i *= 5) {
    ans += (n / i);
  }
  cout << ans;
}

int main() {
  solveBetter();
  return 0;
}
