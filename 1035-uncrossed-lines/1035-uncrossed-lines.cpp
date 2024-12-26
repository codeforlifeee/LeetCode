class Solution {
public:
    int t[2001][2001];
    int solve(vector<int>&nums1, vector<int>&nums2,int i, int j){
        int n = nums1.size(); 
        int m = nums2.size();
        
        if(i == n || j == m) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        int take = 0;
        
        if(nums1[i] == nums2[j])
            take =  1 + solve(nums1,nums2,i+1,j+1);
            
        int skip = max(solve(nums1, nums2, i+1,j), solve(nums1,nums2, i, j+1));
            
        return t[i][j] = max(take, skip);
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        memset(t,-1,sizeof(t));
        return solve(nums1,nums2,0,0);
    }
};