import random

# Stone Paper Scissor
def gameWin(comp, you):
    # If two values are equal, declare a tie!
    if comp == you:
        return None

    # Check for all possibilities when computer chose st
    elif comp == 'st':
        if you=='sc':
            return False
        elif you=='p':
            return True
    
    # Check for all possibilities when computer chose p
    elif comp == 'p':
        if you=='st':
            return False
        elif you=='sc':
            return True
    
    # Check for all possibilities when computer chose sc
    elif comp == 'sc':
        if you=='p':
            return False
        elif you=='st':
            return True
print("Rule: \n 1. Stone wins over Scissor \n 2. Paper wins over Stone \n 3. Scissor wins over Paper")
print("Comp Turn: Stone(st) Paper(p) or Scissior(sc)?")
randNo = random.randint(1, 3) 
if randNo == 1:
    comp = 'st'
elif randNo == 2:
    comp = 'p'
elif randNo == 3:
    comp = 'sc'

you = input("Your Turn: Stone(st) Paper(p) or Scissor(sc)?")
a = gameWin(comp, you)

print(f"Computer chose {comp}")
print(f"You chose {you}")

if a == None:
    print("The game is a tie!")
elif a:
    print("You Win!")
else:
    print("You Lose!")
