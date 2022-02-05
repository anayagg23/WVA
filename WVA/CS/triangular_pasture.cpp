#include <bits/stdc++.h>

using namespace std;

int solution(int N, vector<vector<int>> points) {
  int run_max = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        int area = 0;
        vector<int> p1 = points[i];
        vector<int> p2 = points[j];
        vector<int> p3 = points[k];
        if (p1[0] == p2[0] && p1[1] == p3[1]) {
          area = (abs(p1[1] - p2[1])) * (abs(p1[0] - p3[0]));
        }
        if (area > run_max) {
          run_max = area;
        }
      }
    }
  }
  return run_max;
}

int main() {
  int N;
  vector<vector<int>> points;
  cin >> N;
  vector<int> filler = {0, 0};
  for (int i = 0; i < N; i++) {
    points.push_back(filler);
  }
  for (int i = 0; i < N; i++) {
    cin >> points[i][0] >> points[i][1];
  }
  cout << solution(N, points);
}

