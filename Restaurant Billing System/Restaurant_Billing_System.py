valid_username='admin'
valid_password="hi123"
print("Welcome to Hi Restaurant.")
for i in range(3):
    username=input("Enter username: ")
    password=input("Enter password: ")
    if username == valid_username and password == valid_password:
        print("Login successful!\nAccess granted.")
        break
    else:
        print("Invalid username or password.\nPlease try again.")
        if i == 2:
            print("Too many wrong attempts. \nAcess denied.")
            exit()
breakfast_menu={
    "Idly": 50,
    "Dosa": 60,
    "Woda": 70,
    "Bonda":60,
    "Puri": 70,
    "Tea/Coffee": 30
}
lunch_menu={
    "Veg Thali": 280,
    "Non-Veg Thali": 150,
    "Chocken Biryani": 230,
    "Mutton Biryani": 300,
    "Veg Biryani": 250,
    "Salad/Papad":45,
    "Cold Drink": 90
}
dinner_menu={
    "Chicken Biryani": 230,
    "Mutton Biryani": 300,
    "Chicken Curry": 300,
    "Panner Curry": 250,
    "Roti/Chapati": 20,
    "soup": 120
}
order_quantity,i =[],1
print("Enter your meal plan: ")
print("1. Breakfast\n2. Lunch\n3. Dinner")
while True:
    choice=input("Enter your choice (1/2/3): ")
    if not choice.isdigit():
        print("Invalid input! Please enter a number.")
        continue
    meal_plan=int(choice)
    if meal_plan == 1:
        menu=breakfast_menu
        print("\nBreakfast Menu:")
        break
    elif meal_plan == 2:
        menu=lunch_menu
        print("\nLunch menu: ")
        break
    elif meal_plan == 3:
        menu=dinner_menu
        print("\nDinner menu: ")
        break
    else:
        print("Invalid choice! Please enter (1/2/3). for meal plan.")
menu_items=list(menu.items())
menu_size=len(menu_items)
orders=[]
while True:
    print("/nAvailable Menu:")
    for idx, (item, price) in enumerate(menu_items, start=1):
        print(f"{idx}. {item} - Rs. {price}/-")
    order_input=input("Enter item number to order: ")
    if not order_input.isdigit():
        print("Invalid input! Please enter a number.")
        continue
    order_no=int(order_input)
    if order_no < 1 or order_no > menu_size:
        print("Invalid item number!")
        continue
    qty_input=input(f"Enter the quantity for {menu_items[order_no-1][0]}: ")
    if not qty_input.isdigit():
        print("Invalid input! Please enter a number.")
        continue
    qty=int(qty_input)
    orders.append((menu_items[order_no-1][0], qty, menu_items[order_no-1][1]))
    while True:
        more=input("Do you want to order more items? (y/n): ").lower()
        if more == 'y':
            break
        elif more == 'n':
            break
        else:
            print("Invalid input! Please enter only 'y or 'n'.")
    if more == 'n':
        break
import time
print("Generating your BILL........")
time.sleep(2)
print("BILL generated.")
print("="*40)
print(f"{'Item':<20}{'Quantity':<10}{'Price'}")
print("-"*40)
for item, qty, price in orders:
    print(f"{item:<20}{qty:<10}{qty*price}/-")
    print("-"*40)
subtotal=sum(qty*price for _, qty, price in orders)
cgst=round(subtotal*0.05,2)
sgst=round(subtotal*0.05, 2)
total=round(subtotal+cgst+sgst,2)
print(f"{'Sum Total':<30}: {subtotal}/-")
print(f"{'CGST':<30}: {cgst}/-")
print(f"{'SGST':<30}: {sgst}/-")
print(f"{'Total Bill':<30}: {total}/-")
print("="*40)