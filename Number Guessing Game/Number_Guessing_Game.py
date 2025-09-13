import random
min,max=1,100
roll=random.randint(min,max)
n=None
attempts=1
while n!=roll:
    n=int(input("Enter your guess: "))
    if n==roll:
        print("Correct guess!")
        print(f"You guessed in {attempts} attempts.")
    elif n<roll:
        print("Too low!")
    elif n>roll:
        print("Too high!")
    attempts+=1