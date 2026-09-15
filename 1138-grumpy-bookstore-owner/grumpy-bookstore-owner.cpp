class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0)
                base += customers[i];
        }

        int extra = 0;
        int best = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 1)
                extra += customers[i];

            if (i >= minutes && grumpy[i - minutes] == 1)
                extra -= customers[i - minutes];

            best = max(best, extra);
        }

        return base + best;
    }
};