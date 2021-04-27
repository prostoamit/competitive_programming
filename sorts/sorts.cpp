#include "sorts.h"
#include <vector>


int min(std::vector<int> v, int begin, int end) {
    int min = v[begin];
    int min_index = begin;

    for (int i = begin + 1; i <= end; i++) {
        if (v[i] < min) {
            min = v[i];
            min_index = i;
        }
    }
    return min_index;
}

std::pair<int, int> min_max(std::vector<int> v, int begin, int end) {
    std::pair<int, int> min_max(v[begin], v[end]);
    std::pair<int, int> min_max_indexes(begin, end);

    for (int i = begin + 1; i <= end; i++) {
        if (v[i] < min_max.first) {
            min_max.first = v[i];
            min_max_indexes.first = i;
        }
        if (v[i] > min_max.second) {
            min_max.second = v[i];
            min_max_indexes.second = i;
        }
    }
    return min_max_indexes;
}


void Sorts::selection_sort(std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        int current_min = min(v, i, v.size() - 1);
        if (i != current_min) std::swap(v[i], v[current_min]);
    }
}

void Sorts::double_selection_sort(std::vector<int>& v) {
    for (int i = 0; i < v.size() / 2; i++) {
        std::pair<int, int> current_min_max = min_max(v, i, v.size()-1);
        if(i != current_min_max.first) std::swap(v[i], v[current_min_max.first]);
        if(v.size() - 1 - i != current_min_max.second) std::swap(v[v.size() - 1 - i], v[current_min_max.second]);
    }
}
