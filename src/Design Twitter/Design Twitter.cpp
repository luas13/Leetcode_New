// Beautiful Design Question
// Time Complexity: n is number of user
//      postTweet: O(1)
//      getNewsFeed: O(n log n)
//      follow: O(1)
//      unfollow: O(1)

// U need to define data structures to be used inside private

// We need 2 DS
// a. unordered_map<int, unordered_set<int>> follower_map
//      bcz for a particular user there may be millions of
//      followers & we dont need a sorted order of followers
//
// b. unordered_map<int, list<tweet>> feed_map
//      bcz for a particular user there may be millions of 
//      tweets & we need tweets sorted based on latest time.
//      We took list so that we can easily add in a tweet
//      in front and it works in O(1).

//  We need a structure of tweet which contain userId, tweetId & timestamp

class Twitter {
    struct tweet{
        int tweetId;
        int userId;
        int timestamp;
        tweet(int x, int y, int z):tweetId(x), userId(y), timestamp(z){}
    };
    
    // Can't define a class mycomp{} here because the it will become private
    // In that case u will have to define outside this class. So defined a struct
    // Comparetor func: It compares 2 pair<list<tweet>::iterator, list<tweet>::iterator>
    // This represents all tweets of a particular user, 
    // here ( feed_map[userId].begin(), feed_map[userId].end() )
    struct mycomp{
        bool operator()(pair<list<tweet>::iterator, list<tweet>::iterator> p1, pair<list<tweet>::iterator, list<tweet>::iterator> p2)
        {
            return p1.first->timestamp < p2.first->timestamp;
        }
    };
    
    int gtime = 0;
    // Which all users a particular userId is following
    unordered_map<int, unordered_set<int>> follower_map;
    // List of all tweets for a userId
    unordered_map<int, list<tweet>> feed_map;
public:
    
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    // Should be O(1)
    // Imp point: Add userId to the follower_map of userId itself
    // And keep adding all tweets to feed_map for a particular userId
    void postTweet(int userId, int tweetId) {
        follower_map[userId].insert(userId);
        feed_map[userId].push_front(tweet(tweetId, userId, gtime));
        gtime++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    // Create a Priority Queue to keep track of all feeds based on latest time
    // Here pq of pair<list<tweet>::iterator, list<tweet>::iterator> which is 
    // nothing but ( feed_map[userId].begin(), feed_map[userId].end() )
    // *** We just make pq based on feed_map[userId].begin()'s timestamp
    // bcz we intent to use just it and after incrementing it we again 
    // push the remaining to pq i.e. ++[ feed_map[userId].begin() ], feed_map[userId].end()
    // See code
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (!follower_map[userId].size()) return res;
        priority_queue<pair<list<tweet>::iterator, list<tweet>::iterator>, vector<pair<list<tweet>::iterator, list<tweet>::iterator>>, mycomp> pq;
        for (auto it = follower_map[userId].begin(); it != follower_map[userId].end(); it++)
            if (feed_map[*it].begin() != feed_map[*it].end())
                pq.push(make_pair(feed_map[*it].begin(), feed_map[*it].end()));
        
        int n=0;
        while(!pq.empty() && n<10)
        {
            auto tmp= pq.top();
            pq.pop();
            res.push_back(tmp.first->tweetId);
            // After using we increment feed_map[userId].begin()
            // and push again to pq
            if (++tmp.first != tmp.second)
                pq.push(tmp);
            n++;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    // Just add to follower_map
    void follow(int followerId, int followeeId) {
        follower_map[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    // Just delete a particular followee from a userId's follower_map
    void unfollow(int followerId, int followeeId) {
        if (follower_map[followerId].find(followeeId) != follower_map[followerId].end() && followerId != followeeId)
            follower_map[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */