import random
def playRound():
    while True:
        try:
            player=int(input("Choose 1.rock 2.paper 3.scissors: "))
            if player<1 or player>3:
                print("Invalid input! Please enter 1, 2, or 3 only.\n")
                continue
            break
        except ValueError:
            print("Invalid input! Please enter 1, 2, or 3 only.\n")
    comp=random.randint(1,3)
    match player:
        case 1:
            match comp:
                case 1:
                    print("It's a draw!")
                case 2:
                    print("Sorry, you lost!")
                case 3:
                    print("Congratulations! You have won.")
        case 2:
            match comp:
                case 1:
                       print("Congratulations! You have won.")
                case 2:
                    print("It's a draw!")
                case 3:
                    print("Sorry, you lost!") 
        case 3:
            match comp:
                case 1:
                       print("Sorry, you lost!")
                case 2:
                    print("Congratulations! You have won.")
                case 3:
                    print("It's a draw!")
playRound()
while True:
    try:
        choice=input("\nDo you want to play again? (y/n): ")
        print()
    except:
        print("Invalid input! Please enter 1, 2, or 3 only.\n")
    if choice=='y' or choice == 'Y':
        playRound()
    else:
        print("Thanks for playing!")
        exit()