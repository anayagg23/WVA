#include <bits/stdc++.h>

using namespace std;

vector<int> movex = {1, 1, -1, -1, 2, 2, -2, -2};
vector<int> movey = {2, -2, 2, -2, 1, -1, 1, -1};

bool in_board(int x, int y) {
  if (x >= 1 && x <= 8 && y >= 1 && y <= 8) {
    return true;
  }
  return false;
}

int knight_tour(vector<vector<bool>>& visited, pair<int, int> start,
                pair<int, int> target) {
  queue<pair<pair<int, int>, int>> holder;
  int x1 = start.first;
  int y1 = start.second;
  int x2 = target.first;
  int y2 = target.second;
  holder.push(make_pair(make_pair(x1, y1), 0));
  while (!holder.empty()) {
    pair<pair<int, int>, int> curr = holder.front();
    int x = curr.first.first;
    int y = curr.first.second;
    int lvl = curr.second;
    holder.pop();
    if (x == x2 && y == y2) {
      return lvl;
    }
    for (int move = 0; move < 8; move++) {
      int xprime = x + movex[move];
      int yprime = y + movey[move];
      if (in_board(xprime, yprime) && !visited[xprime][yprime]) {
        holder.push(make_pair(make_pair(xprime, yprime), lvl + 1));
        visited[xprime][yprime] = true;
      }
    }
  }
  return 69;
}

int main() {
  vector<vector<bool>> visited(8, vector<bool>(8, false));
  pair<int, int> start(1, 1);
  pair<int, int> target(5, 1);
  int k = knight_tour(visited, start, target);
  cout << k << endl;
}
