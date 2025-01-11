def print_board(board):
    print("\nTic Tac Toe Board:")
    for row in board:
        print(" ".join(row))

def check_win(board, player):
    # Check rows, columns, and diagonals for a win
    for i in range(3):
        if board[i][0] == player and board[i][1] == player and board[i][2] == player:  # Row check
            return True
        if board[0][i] == player and board[1][i] == player and board[2][i] == player:  # Column check
            return True
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:  # Diagonal check
        return True
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:  # Diagonal check
        return True
    return False

def check_draw(board):
    for row in board:
        if ' ' in row:
            return False  # If any cell is empty, no draw yet
    return True  # No empty cells, it's a draw

def play_game():
    play_again = 'y'
    while play_again.lower() == 'y':
        board = [[' ' for _ in range(3)] for _ in range(3)]
        player = 'X'
        game_won = False

        while not game_won:
            print_board(board)
            print(f"Player {player}'s turn.")
            row, col = map(int, input("Enter row and column (0-2): ").split())

            if row < 0 or row > 2 or col < 0 or col > 2 or board[row][col] != ' ':
                print("Invalid move, try again.")
                continue

            board[row][col] = player

            if check_win(board, player):
                print_board(board)
                print(f"Player {player} wins!")
                game_won = True
            elif check_draw(board):
                print_board(board)
                print("It's a draw!")
                game_won = True

            player = 'O' if player == 'X' else 'X'  # Switch player

        play_again = input("Do you want to play again? (y/n): ")

    print("Thanks for playing!")

# Start the game
play_game()
