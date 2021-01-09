#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

unsigned long long sum(vector<unsigned long long> v) {
    return accumulate(v.begin(), v.end(), 0);
}

unsigned long long pages(unsigned long long i) {
    return pow(2, i);
}

unsigned long long sol(vector<unsigned long long> afordable, unsigned long long n, unsigned long long x) {

    afordable[0] = 1;
    for(unsigned long long i = n-1; i > n - x; i--) {
        afordable[n-i] = pages(i);
    }
    return sum(afordable);

}

int main() {
    int n, x; cin >> n >> x;

    vector<unsigned long long> afordable(x);

    cout << sol(afordable, n, x);
}
