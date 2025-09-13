balance = 1000
pin="1234"
def display_menu():
    print("=====ATM Menu=====")
    print("1. View Balance")
    print("2. Deposit Money")
    print("3. Withdraw Money")
    print("4. Change PIN")
    print("5. Exit")
for attempts in range(3):
    entered_pin=input("Enter your PIN: ")
    if entered_pin == pin:
        print("PIN Verified.")
        break
    else:
        print("Invalid PIN!")
else:
    print("Too many wrong attempts. Card Blocked!")
    exit()
while True:
    display_menu()
    choice=input("Enter your choice: ")
    if choice == '1':
        print(f"Your current balance is Rs. {balance}/-")
    elif choice == '2':
        try:
            amount=float(input("Enter the amount to deposit Rs. "))
            if amount > 0:
                balance += amount
                print(f"Rs. {amount}/- is deposited successfully.")
                print(f"Your current balance is Rs. {balance}/-")
            else:
                print("Invalid amount!")
        except ValueError:
            print("Invalid input! Please enter only integers.")
    elif choice == '3':
        try:
            amount=float(input("Enter the amount to withdraw Rs. "))
            if amount > 0 and amount <= balance:
                balance -= amount
                print(f"Rs. {amount} withdrawed successfully.")
                print(f"Your current balance is Rs. {balance}/-")
            else:
                print("Insufficient balance or Invalid amount.")
        except ValueError:
            print("Invalid input! Please enter only integers.")
    elif choice == '4':
        changePIN=input("Enter current PIN: ")
        if changePIN == pin:
            new_PIN=input("Enter new PIN: ")
            confirm_newPIN=input("Re-enter new PIN to confirm: ")
            if new_PIN == confirm_newPIN and new_PIN != "":
                print("PIN changed succcessfully.")
            else:
                print("PINs does not match or empty.")
        else:
            print("Invalid current PIN.")
    elif choice == '5':
        print("Thank You for using ATM. Goodbye!")
        break
    else:
        print("Invalid choice! Please enter 1-5.")