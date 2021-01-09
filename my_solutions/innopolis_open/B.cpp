#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct element {
  int data;
  bool moved;
};

vector<pair<int, int>> swaps;

int min(vector<element> v, int begin, int end) {
  int min = v[begin].data;
  int min_index = begin;

  for(int i = begin + 1; i <= end; i++) {
    if(v[i].data < min) {
      min = v[i].data;
      min_index = i;
    }
  }

  return min_index;

}

bool selection_sort(vector<element>& children) {
  bool is_possible = true;

  for(int i = 0; i < children.size() && is_possible; i++) {
    int current_min = min(children, i, children.size()-1);
    if(i != current_min) {
      if(children[i].moved || children[current_min].moved) is_possible = false;
      else {
        swap(children[i], children[current_min]);

        children[i].moved = true;
        children[current_min].moved = true;

        swaps.push_back(make_pair(i + 1, current_min + 1));
      }
    }
    
  }

  return is_possible;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  vector<element> v(n);

  for(int i = 0; i < n; i++) cin >> v[i].data;

  if(selection_sort(v)) {
    cout << "Yes\n";
    cout << swaps.size() << '\n';

    for(int i = 0; i < swaps.size(); i++) {
      cout << swaps[i].first << ' ' << swaps[i].second << '\n';
    }
  }
  else cout << "No";
}
