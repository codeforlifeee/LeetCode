class Solution {
public:
    /*
    traverse the array and store the count of each element
    and if count>2 then remove that element
    and then return the remaining elements
    we can use unordered_set here 
    coz it stores frequency and also in the order in which we push_back in it
    without sorting it
    
    
*/
    int removeDuplicates(vector<int>& nums) {
        
  int i =0;
        // int ele= nums[0];
        for(auto ele : nums)
        {
            if(i==0 || i==1 || nums[i-2] != ele)
            {
                nums[i] = ele;
                i++;
            }
        }
    return i ;
       
    }
};

// int n=v.size(),i,a=min(n,2);
//         for(i=2;i<n;i++){
//             if(v[i]!=v[a-2]){
//                 v[a]=v[i];
//                 a++;
//             }
//         }
//         return a;



//   int i =0;
//         // int ele= nums[0];
//       for(auto ele : nums)
//         {
//             if(i==0 || i==1 || nums[i-2] != ele)
//             {
//                 nums[i] = ele;
//                 i++;
//             }
//         }
//     return i ;