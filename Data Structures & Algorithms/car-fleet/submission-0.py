class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [(p, s) for p, s in zip(position, speed)]
        pair.sort(reverse=True)
        stack = [0]
        for p, s in pair:
            time = (target - p) / s
            if time > stack[-1]:
                stack.append(time)

        return len(stack) - 1