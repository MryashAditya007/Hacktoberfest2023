import random

def generate_computer_choice():
  """Generates a random choice for the computer."""
  choices = ["rock", "paper", "scissors"]
  return random.choice(choices)

def get_player_choice():
  """Gets the player's choice."""
  player_choice = input("Rock, paper, or scissors? ")
  return player_choice

def determine_winner(player_choice, computer_choice):
  """Determines the winner of the game."""
  if player_choice == computer_choice:
    return "Tie"
  elif player_choice == "rock" and computer_choice == "scissors":
    return "Player wins"
  elif player_choice == "paper" and computer_choice == "rock":
    return "Player wins"
  elif player_choice == "scissors" and computer_choice == "paper":
    return "Player wins"
  else:
    return "Computer wins"

def play_game():
  """Plays a game of rock-paper-scissors."""
  player_choice = get_player_choice()
  computer_choice = generate_computer_choice()

  winner = determine_winner(player_choice, computer_choice)

  print(f"You chose {player_choice} and the computer chose {computer_choice}.")
  print(winner)

if __name__ == "__main__":
  play_game()
