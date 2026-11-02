class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis;

        queue<string> q;

        if(dead.count("0000"))
            return -1;

        q.push("0000");
        vis.insert("0000");

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                string s = q.front();
                q.pop();

                if(s == target)
                    return steps;

                for(int i = 0; i < 4; i++) {
                    string t = s;

                    t[i] = (s[i] - '0' + 1) % 10 + '0';

                    if(!dead.count(t) && !vis.count(t)) {
                        q.push(t);
                        vis.insert(t);
                    }

                    t = s;

                    t[i] = (s[i] - '0' + 9) % 10 + '0';

                    if(!dead.count(t) && !vis.count(t)) {
                        q.push(t);
                        vis.insert(t);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};