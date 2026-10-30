
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // dist[node][count]
        const int INF = INT_MAX;

        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // Min heap: {cost, node, consecutive count}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // Starting node
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [cost, u, cnt] = pq.top();
            pq.pop();

            // Skip outdated state
            if (cost != dist[u][cnt])
                continue;

            // Destination reached
            if (u == n - 1)
                return cost;

            // Visit neighbours
            for (auto [v, w] : adj[u]) {

                int newCnt;

                if (labels[u] == labels[v]) {
                    newCnt = cnt + 1;
                }
                else {
                    newCnt = 1;
                }

                // Check consecutive character limit
                if (newCnt > k)
                    continue;

                int newCost = cost + w;

                if (newCost < dist[v][newCnt]) {

                    dist[v][newCnt] = newCost;

                    pq.push({
                        newCost,
                        v,
                        newCnt
                    });
                }
            }
        }

        return -1;
    }
};
