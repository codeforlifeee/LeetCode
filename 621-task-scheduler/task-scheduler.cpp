class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
            unordered_map<char, int> freq;
    for (char task : tasks) {
        freq[task]++;
    }

    priority_queue<int> pq;
    for (auto& p : freq) {
        pq.push(p.second);
    }

    int time = 0;
    while (!pq.empty()) {
        vector<int> temp;
        int cycle = n + 1;
        for (int i = 0; i < cycle && !pq.empty(); ++i) {
            temp.push_back(pq.top() - 1);
            pq.pop();
        }

        for (int t : temp) {
            if (t > 0) pq.push(t);
        }

        time += pq.empty() ? temp.size() : cycle;
    }

    return time;

        
    }
};