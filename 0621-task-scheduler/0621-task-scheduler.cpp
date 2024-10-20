class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    
        vector<int> mp(26, 0);  // Frequency of each task (A-Z)

        // Count the frequency of each task
        for (char &ch : tasks) {
            mp[ch - 'A']++;
        }

        // Max-heap (priority queue) to store frequencies of tasks
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (mp[i] > 0) {
                pq.push(mp[i]);  // Push only non-zero frequencies
            }
        }

        int time = 0;  // Total time required to complete all tasks

        // Execute the tasks with a cooling period
        while (!pq.empty()) {
            vector<int> temp;  // Store tasks to be re-added with decreased frequency
            int cycle = n + 1; // A cycle consists of n + 1 time units

            // Try to execute as many tasks as possible within the cycle
            int tasksProcessed = 0;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();  // Get the most frequent task
                    pq.pop();
                    freq--;  // Decrease its frequency as it's executed
                    if (freq > 0) {
                        temp.push_back(freq);  // Store it to re-add later
                    }
                    tasksProcessed++;
                }
            }

            // Re-add the remaining tasks with decreased frequencies to the queue
            for (int &f : temp) {
                pq.push(f);
            }

            // If the queue is empty, we just add the tasks processed time.
            if (pq.empty()) {
                time += tasksProcessed;  // No idle time required
            } else {
                time += cycle;  // Add full cycle time
            }
        }

        return time;
    
    }
};