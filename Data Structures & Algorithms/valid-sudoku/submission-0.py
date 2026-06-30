class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        cube = [[-1]*len(board)]*len(board[0])
        for i in range(len(board)):
            row = [-1 for i in range(11)]
            for j in range(len(board[0])):
                val = board[i][j]
                if val == ".":
                    continue
                val = int(val)
                if (row[val-1] == -1):
                    row[val-1] = 1
                else:
                    return False

        for j in range(len(board[0])):
            col = [-1 for i in range(11)]
            for i in range(len(board)):
                val = board[i][j]
                if val == ".":
                    continue
                val = int(val)
                if col[val] == -1:
                    col[val] = 1
                else:
                    return False

        corner = [[-1 for j in range(11)] for i in range(10)]
        for i in range(len(board)):
            for j in range(len(board[0])):
                val = board[i][j]
                if val == ".":
                    continue
                val = int(val)
                row, col = (i//3), (j//3)
                idx1 = (row*3) + col
                if corner[idx1][val] == -1:
                    corner[idx1][val] = 1
                else:
                    for x in corner:
                        print(x)
                    print(val, i, j)
                    return False
        return True


        '''
        0,0 0,1 0,2
        1,0 1,1 1,2
        2,0 2,1 2,2
        '''
