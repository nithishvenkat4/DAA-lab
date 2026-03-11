N = 4

board = [-1]*N

used_cols = set()
diag1 = set()
diag2 = set()

def solve(row):

    if row == N:
        print(board)
        return

    for col in range(N):

        if col in used_cols:
            continue

        if (row-col) in diag1:
            continue

        if (row+col) in diag2:
            continue

        board[row] = col

        used_cols.add(col)
        diag1.add(row-col)
        diag2.add(row+col)

        solve(row+1)

        used_cols.remove(col)
        diag1.remove(row-col)
        diag2.remove(row+col)

solve(0)