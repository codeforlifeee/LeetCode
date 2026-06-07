
class Twitter {
private:
    unordered_map<int, unordered_set<int>> userFollows;
    unordered_map<int, vector<pair<int, int>>> userTweets;
    int timestamp;
    
public:
    /** Initialize your data structure here. **/
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({tweetId, timestamp++});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. 
        Each item in the news feed must be posted by users who
        the user followed or by the user herself. 
        Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second; // min-heap based on timestamp
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> maxHeap(cmp);
        
        // Add user's own tweets to maxHeap
        for (auto& tweet : userTweets[userId]) {
            maxHeap.push(tweet);
        }
        
        // Add followed users' tweets to maxHeap
        for (int followee : userFollows[userId]) {
            for (auto& tweet : userTweets[followee]) {
                maxHeap.push(tweet);
            }
        }
        
        // Retrieve up to 10 most recent tweets
        vector<int> result;
        while (!maxHeap.empty() && result.size() < 10) {
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            userFollows[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        userFollows[followerId].erase(followeeId);
    }
}; // TC: post/follow/unfollow O(1), feed O(T log T), SC: O(T)

