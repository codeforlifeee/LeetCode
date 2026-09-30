class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
     vector<int>result;
     int currentDepth = 0;

     for(char character : seq){
        if(character == '('){
            currentDepth++;

            result.push_back(currentDepth%2);
        }else{
            result.push_back(currentDepth%2);
            currentDepth--;
        }
     }   
    return result;
    }
};