#include <bits/stdc++.h>
using namespace std;

struct Box {
  int h, w, d;

  int area() { return w * d; }
};

bool CompareArea(Box &A, Box &B) { return A.area() > B.area(); }

int MinStackHeight(vector<Box> &boxes) {
  const int N = boxes.size();
  vector<Box> repeatedBoxes;
  for (Box box : boxes) {
    repeatedBoxes.push_back({box.h, max(box.w, box.d), min(box.w, box.d)});
    repeatedBoxes.push_back({box.w, max(box.h, box.d), min(box.h, box.d)});
    repeatedBoxes.push_back({box.d, max(box.w, box.h), min(box.w, box.h)});
  }

  // Sort the boxes based on decreasing order of base area
  // As we keep the box with maximum area at the bottom
  sort(repeatedBoxes.begin(), repeatedBoxes.end(), CompareArea);

  // Same as Maximum Increase Subsequence Sum Problem
  vector<int> height(3 * N);
  for (int i = 0; i < 3 * N; ++i) {
    Box A = repeatedBoxes[i];

    // Consider only this box at this place (for now - Base Condition)
    height[i] = A.h;

    for (int j = 0; j < i; ++j) {
      Box B = repeatedBoxes[j];
      // Keep B below A --> base area of B should be more than A
      if (B.w > A.w && B.d > A.d) {
        height[i] = max(height[i], height[j] + A.h);
      }
    }
  }

  // Answer is the maximum possible heigh
  return *max_element(height.begin(), height.end());
}

int main() {
  vector<Box> boxes = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
  int ans = MinStackHeight(boxes);
  cout << "MinStackHeight=" << ans << '\n';
  return 0;
}