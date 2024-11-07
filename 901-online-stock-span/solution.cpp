class StockSpanner {
private:
    stack<pair<int,int>> cache; // monotonic decrasing stack
public:
    StockSpanner() {
        
    }
    
    int next(int price) {

        int ans = 1;

        while(!cache.empty() && price >= cache.top().first){
            ans += cache.top().second;
            cache.pop();
        }

        cache.push({price, ans});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */