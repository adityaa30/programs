#include <bits/stdc++.h>
#define int long long int
using namespace std;

class RollingMedian {
  multiset<int> mn; // Right Half
  multiset<int, greater<int>> mx; // Left Half

public:
  void insert(int x) {
    mx.insert(x);
    mn.insert(*mx.begin());
    mx.erase(mx.begin());

    if (mx.size() < mn.size()) {
      mx.insert(*mn.begin());
      mn.erase(mn.begin());
    }
  }

 bool erase(int x) {
    if (mx.find(x) != mx.end()) {
      mx.erase(mx.find(x));
      if (mx.size() < mn.size()) {
        mx.insert(*mn.begin());
        mn.erase(mn.begin());
      }

      return true;
    } else if (mn.find(x) != mn.end()) {
      mn.erase(mn.find(x));
      if (mx.size() - mn.size() == 2) {
        mn.insert(*mx.begin());
        mx.erase(mx.begin()); 
      }
      
      return true;
    }
    return false;
  }

  // Here if (mx.size() == mn.size()) => Even length
  // We right now take the minimum element
  int GetMedian() { return *mx.begin(); }
};

int32_t main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  RollingMedian rm;

  for (int i = 0; i < k; ++i) {
    cin >> A[i];
    rm.insert(A[i]);
  }

  int ans = 0, median = rm.GetMedian();
  for (int i = 0; i < k; ++i) {
    ans += abs(A[i] - median);
  }

  cout << ans << ' ';
  for (int i = k; i < n; ++i) {
    ans -= abs(A[i - k] - median);

    cin >> A[i];
    rm.insert(A[i]);
    rm.erase(A[i - k]);
    int prevMedian = median;
    median = rm.GetMedian();

    ans += abs(A[i] - median);
    if (!(k & 1)) ans -= median - prevMedian;

    cout << ans << ' ';
  } 
  return 0;
}