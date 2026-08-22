class Solution {
public:
    vector<int>p;
    vector<bool>vis;
    // we are using here set
    // we aim to use vector<Vector<int>> res;
    // adjacent elements are  equal so we can skip those
    vector<vector<int>>res;


    vector<vector<int>> permuteUnique(vector<int>& nums) {

        p.clear();
        res.clear();
        vis.assign(nums.size(), false);

        sort(nums.begin(), nums.end());

        
         solve(nums,p,vis, res);

        // vector<vector<int>> finalResult;


        // for(auto it : res){
        //     finalResult.push_back(it);
        // }
        // return finalResult;
        return res;
    }

    

void solve(vector<int>&nums, vector<int>& p, vector<bool>& vis, vector<vector<int>>& res){
    if(p.size() == nums.size()) { res.push_back(p); return;}

    for(int i = 0; i< nums.size(); i++){

        if(vis[i]  || (i > 0 && nums[i] == nums[i-1] && !vis[i-1])) continue;
        // if(!vis[i]){
            vis[i] = true;

            p.push_back(nums[i]);


            solve(nums, p, vis, res);

            // backtracking it

            vis[i] = false;

            p.pop_back();
        // }
    }
}

};


    // base case 
    // if the p.size() == nums.size() 
    // insert the p in the set and return from there
    // 

    //  p => [2,1,1] // nums[ 1,1,2] 

/// sizes are the same
// 


// Backtracking approach
// My approach:
// Generate all the Permutations
// use set to filter the duplicates
// like suppose
// [1,1,2]:
//1.  path = [1] , rem  = [1,2] -> recurse
//2. path =[1,1] rem = [2] -> recurse
// 3. path = [1,1,2] , rem = [] --->> so add it to the set as vector
// 4. Backtracking -> path = [1,2], rem [1] 0> path [1,2,1,] -> add this to the set
// 5.  backtracking -> path = [2] , rem  = [1,1] -> path [ 2, 1,1] -> add this to the set

//SHORTCOMING:
// TC : O(N*N!) 
// SPACE : O(N*N!) 

// OPTIMIMSED
// TC: O(N*N!)
// SC: O(N) ===> RECURSION STACK


// nums= [1,1,2]

// // step 1 : sorting it
// nums = [1,1,2]
// // after sorting 
// nums = [1,1,2]

// // step2 :
// // i = 0 i.e. element = 1 so we will pick it 

// // vis[0] = true;
// // i  = 1  pick 1  vis[1] = true
// // vis[1] = true path =[1,1,2]

// // i = 0  , i = 1 skiping nums[1] == nums[0] & !vis[0]

