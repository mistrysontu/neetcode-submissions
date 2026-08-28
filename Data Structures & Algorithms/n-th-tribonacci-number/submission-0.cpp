class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        for(int i = 3; i <= n; i++) {
            int d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        if(n <= 1) return n;
        return c;
    }
};

/*
a = a;
b = b;
c = c;
d = 

*/