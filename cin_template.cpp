#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {

//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n; cin >> n;

    cout << '\n';

    cout << n << '\n';


    vector<int> data(n);

    for(int &i : data) cin >> i;

    for(int i : data) cout << i << ' ';
}
