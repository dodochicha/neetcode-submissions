class Twitter {
public:
    int timer = 0;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, deque<pair<int, int>>> tweets; // [time, tweetId]

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
        if (tweets[userId].size() > 10) tweets[userId].pop_front();
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        auto addTweet = [&](int uid) {
            for (auto& tweet: tweets[uid]) {
                if (pq.size() == 10) {
                    if (pq.top().first < tweet.first) {
                        pq.pop();
                        pq.push(tweet);
                    }
                }
                else {
                    pq.push(tweet);
                }
            }
        };
        addTweet(userId);
        for (auto& uid: following[userId]) {
            addTweet(uid);
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
