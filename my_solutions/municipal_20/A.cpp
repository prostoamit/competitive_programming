#include <iostream>
using namespace std;

int sol(int n, int k, int x, int y) {
    // n - all the days
    // k - first weekend
    // x - problems on weekDAYS
    // y - problems on weekENDS

    int weekends_count = n / k;
    int weekdays_count = n - weekends_count;

    int problems = weekdays_count * x + weekends_count * y;

    return problems;

}

int main() {

    int n, k, x, y; cin >> n >> k >> x >> y;

    cout << sol(n, k, x, y);

}
