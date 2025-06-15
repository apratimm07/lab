N = 8  # Size of the chessboard

# Function to print the board
def print_board(board):
    for row in board:
        for cell in row:
            print("Q" if cell else "-", end=" ")
        print()
    print()

def is_safe(board, row, col):
    for i in range(col):
        if board[row][i]:  # Check same row
            return False
        if row - i - 1 >= 0 and board[row - i - 1][col - i - 1]:  # Upper diagonal
            return False
        if row + i + 1 < N and board[row + i + 1][col - i - 1]:  # Lower diagonal
            return False
    return True

def solve(board, col):
    if col == N:                             # Base case
        print_board(board)
        return True
    found = False
    for row in range(N):
        if is_safe(board, row, col):
            board[row][col] = 1
            found = solve(board, col + 1) or found
            board[row][col] = 0  # Backtrack
    return found

def solve_n_queens():
    board = [[0]*N for _ in range(N)]
    if not solve(board, 0):
        print("No solution exists.")

solve_n_queens()