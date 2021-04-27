#include <vector>
using namespace std;

class PrefixSum {
public:
    static vector<int> generate(vector<int> data);

    static int interval_sum(vector<int> prefix_sum, int begin, int end);
};
