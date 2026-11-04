
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        // Two multisets for maintaining sliding window median
        multiset<int> low, high;

        long long lowSum = 0, highSum = 0;

        // Rebalance the two multisets
        auto balance = [&]() {
            int target = (low.size() + high.size() + 1) / 2;

            while (low.size() > target) {
                auto it = prev(low.end());
                int val = *it;

                low.erase(it);
                lowSum -= val;

                high.insert(val);
                highSum += val;
            }

            while (low.size() < target) {
                auto it = high.begin();
                int val = *it;

                high.erase(it);
                highSum -= val;

                low.insert(val);
                lowSum += val;
            }
        };

        // Insert an element
        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                lowSum += val;
            } else {
                high.insert(val);
                highSum += val;
            }

            balance();
        };

        // Remove an element
        auto remove = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                lowSum -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                highSum -= val;
            }

            balance();
        };

        // Calculate cost of current window
        auto getCost = [&]() -> long long {
            long long median = *low.rbegin();

            long long left =
                median * (long long)low.size() - lowSum;

            long long right =
                highSum - median * (long long)high.size();

            return left + right;
        };

        // Step 1: Calculate cost of every window
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {

            remove(nums[i - x]);

            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // Step 2: DP
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        // Base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= k; j++) {

                // Choice 1: Skip current element
                dp[i][j] = dp[i - 1][j];

                // Choice 2: Take a window of size x
                if (i >= x && dp[i - x][j - 1] != INF) {

                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
