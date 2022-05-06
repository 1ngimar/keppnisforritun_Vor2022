# Þetta virkar ekki nógu vel, ef að guess byrjar sem 500 þá náum við 
# aldrei að giska upp að 1000
# og ef að guess byrjar í 501 þá náum við aldrei að giska niður í 1

import sys

def guessAgain(oldGuess, higher, oldDiff):
    diff = round(oldDiff / 2)
    if higher:
        guess = oldGuess + diff
    else:
        guess = oldGuess - diff

    print(guess)
    sys.stdout.flush()
    
    answer = input()
    if answer == "higher":
        guessAgain(guess, True, diff)
    elif answer == "lower":
        guessAgain(guess, False, diff)
    elif answer == "correct":
        sys.exit()
    
guess = 500
print(guess)
sys.stdout.flush()

answer = input()
if answer == "higher":
    guessAgain(guess, True, guess)
elif answer == "lower":
    guessAgain(guess, False, guess)
elif answer == "correct":
    sys.exit()
