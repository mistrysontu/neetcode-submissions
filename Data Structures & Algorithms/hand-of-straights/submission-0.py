class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand.sort()
        '''
            1 2 2 3 3 4 4 5
            1 2 4 3 1 2 5 6
            -1 1 -1 -1 -1 4 5 6,   3

            1 [2] [3]
            1 2
        '''
        n = len(hand)
        
        for i, e in enumerate(hand):
            print(hand)
            cnt = 1
            elem = e
            if e == -1:
                continue
            # print(i, e)
            hand[i] = -1
            print('x ', hand[i+1:])
            for j, f in enumerate(hand[i+1:]):
                print(i, j+i+1, elem)
                if f == elem + 1:
                    cnt += 1
                    hand[j+i+1] = -1
                    elem = f

                if cnt == groupSize:
                    break
            if cnt < groupSize:
                return False
        return True

