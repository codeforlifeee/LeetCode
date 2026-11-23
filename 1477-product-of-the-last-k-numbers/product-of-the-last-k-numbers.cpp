class ProductOfNumbers {
public:
    vector<int> streamNumbers;
    ProductOfNumbers() {
        streamNumbers.clear();
        
    }
    
    void add(int num) {
        streamNumbers.push_back(num);
        
    }
    
    int getProduct(int k) {
        int runningProduct = 1;
        int totalSize = streamNumbers.size();

        int startIndex = totalSize -1;
        int endIndex = totalSize - k;


        for(int currentIndex = startIndex; currentIndex >= endIndex; currentIndex--){
            runningProduct  *=streamNumbers[currentIndex];
        }
        return runningProduct;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */