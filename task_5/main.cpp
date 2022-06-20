#include <iostream>
#include <vector>

void FindWaysDown(const std::vector<std::vector<int>>& child_tree, std::vector<int>& answer, std::vector<int>& count, int n = 0) {
  for (auto c : child_tree[n]) {
    FindWaysDown(child_tree, answer, count, c);
    count[n] += count[c];
    answer[n] += count[c] + answer[c];
  }
  count[n]++;
}

void FindWays(const std::vector<std::vector<int>>& child_tree, std::vector<int>& answer, std::vector<int>& count, int p = -1, int n = 0) {
  if (p != -1) {
    answer[n] = answer[p] + child_tree.size() - 2 * count[n];
  }
  for (auto c : child_tree[n]) {
    FindWays(child_tree, answer, count, n, c);
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> child_tree(n);
  for(int parent, child; std::cin >> parent >> child;){
    child_tree[parent].push_back(child);
  }
  std::vector<int> answer(n), count(n);
  FindWaysDown(child_tree, answer, count);
  FindWays(child_tree, answer, count);
  for (auto c : answer) {
    std::cout << c << std::endl;
  }
}