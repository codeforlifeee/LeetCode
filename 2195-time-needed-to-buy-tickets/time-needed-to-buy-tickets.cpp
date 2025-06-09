class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<int>q;
        for (int i = 0; i < tickets.size(); ++i) {
            q.push(i);
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            tickets[front]--;
            time++;

            if(front == k && tickets[front] == 0) return time;

            if (tickets[front] > 0) q.push(front);
        }
        return time;
    }
};