struct ItemNew {
    int time;
    int id;
    int news;
};

class Twitter {
private:
    unordered_map<int, vector<ItemNew>> map;
    unordered_map<int, unordered_set<int>> myfollows;
    int timecount;
public:
    /** Initialize your data structure here. */
    Twitter() {
        timecount = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        ItemNew itemnew = ItemNew{timecount++, userId, tweetId};

        map[userId].push_back(itemnew);
        for (int id : myfollows[userId]) {
            map[id].push_back(itemnew);
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        sort(map[userId].begin(), map[userId].end(), [](const ItemNew &a, const ItemNew &b){
            return a.time > b.time;
        });
        vector<int> retvec;
        for (auto item : map[userId]) {
            retvec.push_back(item.news);
            if (retvec.size() == 10) break;
        }

        return retvec;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId && myfollows[followeeId].count(followerId) == 0) {
            for (auto item : map[followeeId]) {
                if (item.id == followeeId) {
                    map[followerId].push_back(item);
                }
            }
            myfollows[followeeId].insert(followerId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId && myfollows[followeeId].count(followerId) != 0) {
            myfollows[followeeId].erase(followerId);
            int i = 0;
            vector<ItemNew> vec;
            for (auto item : map[followerId]) {
                if (item.id != followeeId) {
                    vec.push_back(item);
                }
            }
            map[followerId] = vec;
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */