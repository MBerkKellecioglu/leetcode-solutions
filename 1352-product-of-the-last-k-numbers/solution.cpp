class ProductOfNumbers {
private:
    vector<int> multpl;
    vector<int> zeros;

    int sz;

public:
    ProductOfNumbers() {

        sz = 0;
    }
    
    void add(int num){

        sz++;

        if(num == 0){
            zeros.push_back(sz - 1);
            multpl.clear();
        }
        else if(!multpl.empty()){
            multpl.push_back(multpl.back() * num);
        }
        else multpl.push_back(num);
        
    }
    
    int getProduct(int k) {

        int ind = sz - k;

        int multpl_size = multpl.size();

        for(auto z : zeros){
            if(z >= ind) return 0;
        }

        if(multpl_size - k - 1 < 0) return multpl.back();

        return multpl.back() / multpl[multpl_size - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */