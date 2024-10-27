N = 8  # You can change this value to set the size of the board (e.g., N = 4 for a 4x4 board)

def print_solution(board):
    for row in board:
        for cell in row:
            if cell:
                print("Q", end=" ")
            else:
                print(".", end=" ")
        print()

def is_safe(board, row, col):
    # Check this row on the left side
    for i in range(col):
        if board[row][i]:
            return False

    # Check upper diagonal on the left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False

    # Check lower diagonal on the left side
    for i, j in zip(range(row, N), range(col, -1, -1)):
        if board[i][j]:
            return False

    return True

def solve_nq_util(board, col):
    # Base case: If all queens are placed, return true
    if col >= N:
        return True

    # Consider this column and try placing this queen in all rows one by one
    for i in range(N):
        # Check if the queen can be placed on board[i][col]
        if is_safe(board, i, col):
            # Place this queen in board[i][col]
            board[i][col] = 1

            # Recur to place the rest of the queens
            if solve_nq_util(board, col + 1):
                return True

            # If placing queen in board[i][col] doesn't lead to a solution,
            # then remove the queen from board[i][col] (BACKTRACK)
            board[i][col] = 0

    # If the queen cannot be placed in any row in this column, return false
    return False

def solve_nq():
    # Initialize the board
    board = [[0 for _ in range(N)] for _ in range(N)]

    # Solve the N-Queens problem using backtracking
    if not solve_nq_util(board, 0):
        print("Solution does not exist")
        return False

    print_solution(board)
    return True

# Driver program to test the above function
if __name__ == "__main__":
    solve_nq()