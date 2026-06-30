class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        op = set(['+', '-', '/', '*'])
        st = []
        for x in (tokens):
            if x in op:
                y = st.pop()
                z = st.pop()
                p = 0
                if x == '+':
                    p = z + y
                if x == '-':
                    p = (z-y) 
                if x == '*':
                    p = (z*y)
                if x == '/':
                    p = int(z/y)
                # print(p)
                st.append(p)
            else:
                st.append(int(x))
        return st[0]
