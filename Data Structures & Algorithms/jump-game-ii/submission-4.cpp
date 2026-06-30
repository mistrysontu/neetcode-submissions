class Solution {
public:
    int getJumps(int src, int dest, vector<int>& nums, vector<int>& cache) {
        if(cache[src] != INT_MAX-1000) return cache[src];
        if(src == dest || src + nums[src] >= dest) return cache[dest] + 1;
        for(int i = 1; i < nums[src]+1; i++) {
            cache[src] = min(cache[src], getJumps(src+i, dest, nums, cache)+1);
        }
        return cache[src];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, INT_MAX-1000);
        cache[n-1] = 0;
        return getJumps(0, n-1, nums, cache);
    }
};
