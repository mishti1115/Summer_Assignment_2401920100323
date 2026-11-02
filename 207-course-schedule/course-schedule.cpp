class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for(auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        // Find courses with indegree 0
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        // BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for(int x : adj[node]) {
                indegree[x]--;

                if(indegree[x] == 0)
                    q.push(x);
            }
        }

        return count == numCourses;
    }
};