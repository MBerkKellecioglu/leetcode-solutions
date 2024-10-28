class SmallestInfiniteSet {
private:
    int inf = 1;
    priority_queue <int, vector<int>, greater<int> > pq;
    vector<int> dup = vector<int>(1001,0);

public:
    SmallestInfiniteSet() {
    }
    
    int popSmallest(){

        int ans = 0;

        if(!pq.empty()){
            ans = pq.top();
            pq.pop();
            dup[ans] = 0;
        }
        else{
            ans = inf;
            inf++;
        }

        return ans;
    }
    
    void addBack(int num) {
        if(!dup[num] && num < inf){
            dup[num] = 1;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */