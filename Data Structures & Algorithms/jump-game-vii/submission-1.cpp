class Solution {
public:
    bool canJump(int u, int v, string s, int minJump, int maxJump, vector<int>& cache) {
        if(u > v || s[u] == '1') return false;
        
        if(cache[u] != -1) return cache[u];
        // if(u + minJump <= v && u + maxJump >= v) return true;
        for(int i = minJump; i <= maxJump; i++) {
            if(s[u+i] == '0' && canJump(u+i, v, s, minJump, maxJump, cache) == 1){
                return cache[u] = 1;
            }
        }
        return cache[u] = 0;
    }
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size() - 1;
        vector<int> cache(n+1, -1);
        cache[n] = 1;
        return canJump(0, n, s, minJump, maxJump, cache);
    }
};