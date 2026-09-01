class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<pair<int, int>> litter;
        int sr = -1, sc = -1;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    id[r][c] = litter.size();
                    litter.push_back({r, c});
                }
            }
        }

        int k = litter.size();

        if (k == 0)
            return 0;

        int fullMask = (1 << k) - 1;

        /*
            best[r][c][mask] =
                maximum amount of energy with which we have
                reached (r,c) having collected 'mask'.

            If we later reach the same state with <= best energy,
            that state is useless because BFS guarantees that
            the current path is not shorter.
        */
        int states = m * n * (1 << k);

        vector<int> best(states, -1);

        auto getId = [&](int r, int c, int mask) {
            return (r * n + c) * (1 << k) + mask;
        };

        struct State {
            int r, c, mask, energy;
        };

        queue<State> q;

        best[getId(sr, sc, 0)] = energy;
        q.push({sr, sc, 0, energy});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            // Process one BFS level.
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Cannot make a move without energy.
                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter.
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset energy.
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int idx = getId(nr, nc, nmask);

                    /*
                        If we've already reached this (position, mask)
                        with at least as much energy, this state is
                        completely dominated.
                    */
                    if (best[idx] >= ne)
                        continue;

                    best[idx] = ne;
                    q.push({nr, nc, nmask, ne});
                }
            }

            moves++;
        }

        return -1;
    }
};