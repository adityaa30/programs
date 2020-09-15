// adityaa30
#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1000000007;

int random(int a, int b) { return a + rand() % (b - a + 1); }

void GenerateCase(int test) {

}

int32_t main(int32_t argc, char *argv[]) {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(20);

  int t = 10;
  cout << t << '\n';
  for (int test = 1; test <= t; ++test) {
    GenerateCase(test);
  }

  return 0;
}