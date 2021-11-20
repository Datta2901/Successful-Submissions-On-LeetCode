class Solution {
public:
    int rob(vector<int>& nums) {
   int l = nums.size();
   if (l == 0) return 0;
   if (l == 1) return nums[0];
   if (l == 2) return max(nums[0], nums[1]);
  
   vector<int> arr(l);
   arr[0] = nums[0]; 
   arr[1] = max(nums[1], arr[0]);
   for (int i = 2; i < l-1; i++) { 
       arr[i] = max(nums[i] + arr[i - 2], arr[i - 1]);        
   }

 
   vector<int> arr2(l);
   arr2[0] = 0;
   arr2[1] = nums[1];
   arr2[2] = max(nums[2], arr2[1]);
   for (int i = 3; i < l; i++) { 
       arr2[i] = max(nums[i] + arr2[i - 2], arr2[i - 1]);
   }
   
   
   return max(arr[l-2] , arr2[l-1]) ;
}
};