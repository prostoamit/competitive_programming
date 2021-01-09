class PrefixSum {
public:
    vector<int> generate(vector<int> data) {
        vector<int> prefix_sum(data.size());
        prefix_sum[0] = data[0];

        for(int i = 1; i < data.size(); i++) prefix_sum[i] = prefix_sum[i-1] + data[i];

        return prefix_sum;
    }

    int interval_sum(vector<int> prefix_sum, int begin, int end) {
        return prefix_sum[end] - prefix_sum[begin-1];
    }
}
