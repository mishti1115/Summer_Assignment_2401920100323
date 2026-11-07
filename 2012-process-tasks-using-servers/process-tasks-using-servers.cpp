class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ll = long long;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> free;
        
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> busy;

        int n = servers.size();
        int m = tasks.size();

        for(int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        vector<int> ans(m);
        ll time = 0;

        for(int i = 0; i < m; i++) {
            time = max(time, (ll)i);

            while(!busy.empty() && busy.top().first <= time) {
                int idx = busy.top().second;
                busy.pop();
                free.push({servers[idx], idx});
            }

            if(free.empty()) {
                time = busy.top().first;

                while(!busy.empty() && busy.top().first <= time) {
                    int idx = busy.top().second;
                    busy.pop();
                    free.push({servers[idx], idx});
                }
            }

            auto [weight, idx] = free.top();
            free.pop();

            ans[i] = idx;

            busy.push({time + tasks[i], idx});
        }

        return ans;
    }
};