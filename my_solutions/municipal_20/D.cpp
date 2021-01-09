#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

long long array_sum(vector<long long> v, int begin, int end) {
    long long sum = 0;

    for(int i = begin; i < end; i++) sum += v[i];

    return sum;
}

long long l_sum(vector<long long> comp_time, int l) {
    long long sum = 0;

    for(int i = 0; i < comp_time.size() - l + 1; i++) {
        sum += array_sum(comp_time, i, i + l);
    }

    return sum;
}


void sol(vector<long long> com_time) {
    int n = com_time.size();

    for(int i = 0; i < n; i++) {
        cout << l_sum(com_time, i+1) << ' ';
    }
}

int main() {
    int n; cin >> n;
    vector<long long> v(n);

    for(int i = 0;i < n; i++) cin >> v[i];

    sol(v);
}