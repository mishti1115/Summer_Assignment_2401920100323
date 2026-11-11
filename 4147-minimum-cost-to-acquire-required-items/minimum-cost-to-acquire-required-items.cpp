class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        auto calc = [&](long long x) {
            return x * costBoth
                 + max(0LL, (long long)need1 - x) * cost1
                 + max(0LL, (long long)need2 - x) * cost2;
        };

        long long mn = min(need1, need2);
        long long mx = max(need1, need2);

        return min({calc(0), calc(mn), calc(mx)});
    }
};