import random

def choose_word():
    word_list = ['python', 'java', 'ruby', 'javascript', 'html', 'css']
    return random.choice(word_list)

def display_word(word, guessed_letters):
    display = ''
    for letter in word:
        if letter in guessed_letters:
            display += letter
        else:
            display += '_'
    return display

def hangman():
    print("Welcome to Hangman!")
    secret_word = choose_word()
    guessed_letters = []
    attempts = 6

    while attempts > 0:
        print("\nAttempts left:", attempts)
        current_display = display_word(secret_word, guessed_letters)
        print("Current word:", current_display)

        guess = input("Guess a letter: ").lower()

        if len(guess) != 1 or not guess.isalpha():
            print("Invalid input. Please enter a single letter.")
            continue

        if guess in guessed_letters:
            print("You've already guessed that letter. Try again.")
            continue

        guessed_letters.append(guess)

        if guess not in secret_word:
            attempts -= 1
            print("Incorrect guess! Try again.")
        else:
            print("Good guess!")

        if set(guessed_letters) == set(secret_word):
            print("Congratulations! You guessed the word:", secret_word)
            break

    if attempts == 0:
        print("Sorry, you're out of attempts. The word was:", secret_word)

if __name__ == "__main__":
    hangman()
