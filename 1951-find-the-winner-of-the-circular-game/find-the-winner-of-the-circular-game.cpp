
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vis(n, 0);
        int curr = 0;

        for (int i = 0; i < n - 1; i++) {
            int x = k;

            while (x > 0) {
                if (vis[curr] == 1) {
                    curr = (curr + 1) % n;
                } else {
                    x--;

                    if (x > 0) {
                        curr = (curr + 1) % n;
                    }
                }
            }

            vis[curr] = 1;
            curr = (curr + 1) % n;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                return i + 1;
            }
        }

        return 0;
    }
};
