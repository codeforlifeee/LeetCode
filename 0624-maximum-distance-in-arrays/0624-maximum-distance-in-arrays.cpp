class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int min_num = arrays[0].front();//smallest element from the front of an array
        int max_num = arrays[0].back();
        int max_dis = 0;
        
        for(int i = 1; i<n; i++){
            max_dis = max({max_dis,abs(arrays[i].back()-min_num),abs(arrays[i].front()-max_num)});
            
        //update smallest and largest value 
        min_num = min(min_num, arrays[i].front());
        max_num = max(max_num, arrays[i].back());
        }
        return max_dis;
        
        
    }
}; 
//Brute giving TLE
//   int n = arrays.size();
//         int max_dis = 0;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 for (int x : arrays[i]) {
//                     for (int y : arrays[j]) {
//                         max_dis = std::max(max_dis, std::abs(x - y));
//                     }
//                 }
//             }
//         }
        
//         return max_dis;