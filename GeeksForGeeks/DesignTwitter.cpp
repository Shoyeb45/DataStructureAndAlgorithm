#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Twitter {
  public:
    // Initialize your data structure here
    set<int> followers[(int)1e5 + 1];
    
    vector<pair<int, int>> tweets;
    Twitter() {}

    // Compose a new tweet
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    // Retrieve the 10 most recent tweet ids as mentioned in question
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        
        for (int i = tweets.size() - 1; i >= 0; i--) {
            if (ans.size() == 10) {
                break;
            }
            if (tweets[i].first == userId || followers[userId].find(tweets[i].first) != followers[userId].end()) {
                ans.push_back(tweets[i].second);
            }
        }
        return ans;
    }

    // Follower follows a followee. If the operation is invalid, it should be a
    // no-op.
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    // Follower unfollows a followee. If the operation is invalid, it should be
    // a no-op.
    void unfollow(int followerId, int followeeId) {
        set<int> &st = followers[followerId];
        if (st.find(followeeId) != st.end()) {
            st.erase(followeeId);
        }
    }
};
