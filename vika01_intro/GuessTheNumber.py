# �etta virkar ekki n�gu vel, ef a� guess byrjar sem 500 �� n�um vi� 
# aldrei a� giska upp a� 1000
# og ef a� guess byrjar � 501 �� n�um vi� aldrei a� giska ni�ur � 1

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
