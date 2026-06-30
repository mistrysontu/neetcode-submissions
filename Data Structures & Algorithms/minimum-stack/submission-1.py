class MinStack:

    def __init__(self):
        self.stk = []
        self.min = None

    def push(self, val: int) -> None:
        self.stk.append(val)
        if self.min is None:
            self.min = val
        if self.min > val:
            self.min = val        

    def pop(self) -> None:
        if len(self.stk):
            self.stk.pop()
            self.min = min(self.stk) if len(self.stk) else None

    def top(self) -> int:
        if len(self.stk):
            return self.stk[-1]

    def getMin(self) -> int:
        return self.min
        
