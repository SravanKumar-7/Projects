import random
def oneGame():
    player_count=comp_count=draw=0
    print("\n\n--- New Game: 10 Rounds ---")
    for i in range(10):
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
        if player == comp:
            print("It's a draw!")
            draw+=1
        elif (player == 1 and comp == 3) or (player == 2 and comp == 1) or (player == 3 and comp == 2):
            print("+1 for you.")
            player_count+=1
        else:
            print("+1 for computer.")
            comp_count+=1
    print("\n--- Final Results ---")
    print("You: ",player_count)
    print("Computer: ",comp_count)
    print("Total draws: ",draw)
    if player_count > comp_count:
        print("Congratulations! You have won.\n")
    elif player_count < comp_count:
        print("Sorry, you lost!\nBetter luck next time!")
    else :
        print("It's a draw!\nBetter luck next time!")
while True:
    oneGame()
    while True:
        choice=input("\nDo you want to play again? (y/n): ").lower()
        print()
        if choice=='y':
            break
        elif choice == 'n':
            print("Thanks for playing!\n")
            exit()
        else:
            print("Invalid input! Please enter (y/n) only.")