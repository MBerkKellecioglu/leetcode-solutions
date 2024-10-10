class MedianFinder{
private:
    priority_queue<int> small;
    priority_queue <int, vector<int>, greater<int> > big;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int k = small.size(), p = big.size();

        if(abs(k - p) >= 1){
            if(small.size() < big.size()){
                if(num < big.top()) small.push(num);
                else{
                    int tmp = big.top();
                    big.pop();
                    small.push(tmp);
                    big.push(num);
                }
            }
            else{
                if(num > small.top()) big.push(num);
                else{
                    int tmp = small.top();
                    small.pop();
                    big.push(tmp);
                    small.push(num);
                }
            }
        }
        else{
            if(small.empty()) small.push(num);
            else if(big.empty()) big.push(num);
            else{
                if(num < big.top()) small.push(num);
                else big.push(num);
            }
        } 
    }
    
    double findMedian(){
        if((small.size() + big.size()) % 2 == 0 ){
            return (double(small.top()) + double(big.top())) / 2;
        }
        else{
            if(big.size() > small.size()) return big.top();
            else return small.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */