#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {

    int n;

    scanf("%d", &n);

    printf("%d\n", n);



    vector<int> data(n);

    for(int &i : data) scanf("%d", &i);

    for(int i : data) printf("%d ", i);
}
