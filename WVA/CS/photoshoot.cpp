#include <bits/stdc++.h>

using namespace std;

vector<int> generate(int i, vector<int> b, int N) {
  vector<int> a;
  a.push_back(i);
  // then push back b[0]-i, b[1]-i, ...
  int run_el = i;
  for (int j = 0; j < N - 1; j++) {
    a.push_back(b[j] - run_el);
    run_el = b[j] - run_el;
  }
  return a;
}

bool isperm(vector<int> a, int N) {
  // Set to check the count
  // of non-repeating elements
  set<int> hash;

  int maxEle = 0;

  for (int i = 0; i < N; i++) {
    // Insert all elements in the set
    hash.insert(a[i]);

    // Calculating the max element
    maxEle = max(maxEle, a[i]);
  }

  if (maxEle != N)
    return false;

  // Check if set size is equal to n
  if (hash.size() == N)
    return true;

  return false;
}

int main() {
  int N;
  cin >> N;
  vector<int> b;
  for (int i = 0; i < N - 1; i++) {
    int el;
    cin >> el;
    b.push_back(el);
  }
  // now we have b filled
  vector<int> h = generate(1, b, N);

  for (int i = 1; i <= N; i++) {
    // generate a for this
    vector<int> a = generate(i, b, N);
    // test if a is a permutation of {1,2,...,N} if yes return this and die
    if (isperm(a, N)) {
      for (auto& entry : a) {
        cout << entry << " ";
      }
      cout << endl;
      return 0;
    }
  }
}
