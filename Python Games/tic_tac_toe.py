# Tic-Tac-Toe Game

# Initialize the board
board = [" " for _ in range(9)]

# Function to print the board
def print_board():
    for i in range(0, 9, 3):
        print("|".join(board[i:i+3]))
        if i < 6:
            print("-----")

# Function to check for a win
def check_win(player):
    win_conditions = [(0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6), (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6)]
    for condition in win_conditions:
        if all(board[i] == player for i in condition):
            return True
    return False

# Function to play the game
def play_game():
    player = "X"
    while True:
        print_board()
        print(f"Player {player}'s turn. Enter a position (0-8): ", end="")
        move = int(input())
        
        if move < 0 or move > 8 or board[move] != " ":
            print("Invalid move. Try again.")
            continue
        
        board[move] = player
        
        if check_win(player):
            print_board()
            print(f"Player {player} wins!")
            break
        
        if " " not in board:
            print_board()
            print("It's a tie!")
            break
        
        player = "O" if player == "X" else "X"

# Start the game
if __name__ == "__main__":
    play_game()
