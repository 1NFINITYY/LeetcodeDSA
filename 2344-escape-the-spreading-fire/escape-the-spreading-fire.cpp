class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        const int INF = 1e9;

        vector<vector<int>> fireTime(n, vector<int>(m, INF));
        queue<pair<int,int>> qfire;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    qfire.push({i, j});
                    fireTime[i][j] = 0;
                }
            }
        }

        while(!qfire.empty()) {
            auto [x, y] = qfire.front();
            qfire.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                if(grid[nx][ny] == 2)
                    continue;

                if(fireTime[nx][ny] != INF)
                    continue;

                fireTime[nx][ny] = fireTime[x][y] + 1;
                qfire.push({nx, ny});
            }
        }

        auto canEscape = [&](int wait) {
            if(grid[0][0] == 2)
                return false;

            if(fireTime[0][0] <= wait)
                return false;

            queue<pair<int,int>> q;
            vector<vector<int>> dist(n, vector<int>(m, -1));

            q.push({0, 0});
            dist[0][0] = 0;

            while(!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;

                    if(grid[nx][ny] == 2)
                        continue;

                    if(dist[nx][ny] != -1)
                        continue;

                    int arrive = wait + dist[x][y] + 1;

                    if(nx == n - 1 && ny == m - 1) {
                        if(arrive <= fireTime[nx][ny])
                            return true;
                    }
                    else {
                        if(arrive < fireTime[nx][ny]) {
                            dist[nx][ny] = dist[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }

            return false;
        };

        if(!canEscape(0))
            return -1;

        if(fireTime[n - 1][m - 1] == INF)
            return 1000000000;

        int low = 0;
        int high = 1000000000;

        while(low < high) {
            int mid = low + (high - low + 1) / 2;

            if(canEscape(mid))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};