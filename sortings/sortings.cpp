#include <vector>
using namespace std;

int min(std::vector<int> v, int begin, int end) {
  int min = v[begin];
  int min_index = begin;

  for(int i = begin + 1; i <= end; i++) {
    if(v[i] < min) {
      min = v[i];
      min_index = i;
    }
  }

  return min_index;

}

class Sortings {
public:
    bool selection_sort(std::vector<int>& v) {

        for(int i = 0; i < v.size(); i++) {
            int current_min = min(v, i, v.size()-1);
            if(i != current_min) std::swap(v[i], v[current_min]);
        }

    }
};
