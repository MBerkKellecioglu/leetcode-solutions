class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
    
        if(!q.empty()){
            while(!q.empty() && (q.front() < t - 3000 || q.front() > t) ){
                q.pop();
            }
            q.push(t);
        }
        else q.push(t);

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */