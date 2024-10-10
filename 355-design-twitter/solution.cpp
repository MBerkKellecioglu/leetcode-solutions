class Twitter {
private:
    vector<pair<int, int>> tweets;
    map<int, vector<int>> follower_list; 
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId){
        if(follower_list.find(userId) == follower_list.end()){
            follower_list[userId].push_back(userId);
        }
        tweets.insert(tweets.begin(), {userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> sol;
        vector<int> * pt = &follower_list[userId];

        for(auto tweet : tweets){
            if(sol.size() == 10) break;
            if(find(pt->begin(), pt->end(), tweet.first) != pt->end()){
                sol.push_back(tweet.second);
            }
        }
        
        return sol;
    }
    
    void follow(int followerId, int followedId) {
        if(follower_list.find(followerId) == follower_list.end()){
            follower_list[followerId].push_back(followerId);
        }
        follower_list[followerId].push_back(followedId);
    }
    
    void unfollow(int followerId, int followedId) {
        vector<int> * pt = &follower_list[followerId];

        auto pos = find(pt->begin(), pt->end(), followedId);

        if(pos != pt->end()) pt->erase(pos);
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