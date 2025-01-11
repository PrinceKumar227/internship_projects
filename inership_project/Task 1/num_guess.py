import random

def guess_number():
    secret_number = random.randint(1, 100)

    print("Guess the number between 1 and 100: ")

    guess = None
    while guess != secret_number:
        guess = int(input("Enter your guess: "))

        if guess < secret_number:
            print("Too low! Try again.")
        elif guess > secret_number:
            print("Too high! Try again.")
        else:
            print("Congratulations! You've guessed the correct number!")

guess_number()
