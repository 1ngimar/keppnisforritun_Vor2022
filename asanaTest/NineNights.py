def position_is_safe(board, i, j):
    for delta_i in (-2, -1, 1, 2):
        for delta_j in (-2, -1, 1, 2):
            if abs(delta_i) == abs(delta_j):
                continue
            neighbor_i = i + delta_i
            neighbor_j = j + delta_j
            if 0 <= neighbor_i < len(board) and 0 <= neighbor_j < len(board[0]):
                if board[neighbor_i][neighbor_j] == 'k':
                    return False
    return True


def is_valid_solution(board):
    number_of_knights = 0
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 'k':
                if position_is_safe(board, i, j) == False:
                    return False
                number_of_knights += 1

    if number_of_knights != 9:
        return False
    return True

board = []
for i in range(5):
    board.append(list(map(str,input())))

if is_valid_solution(board):
    print("valid")
else:
    print("invalid")