import datetime

today = datetime.date.today()

while True:
    dob_input = input("Enter your Date Of Birth (DD/MM/YYYY): ")
    try:
        dob = datetime.datetime.strptime(dob_input, "%d/%m/%Y").date()
        break
    except ValueError:
        print("Invalid date! Please try again.")

try:
    eighteenth_birthday = dob.replace(year=dob.year + 18)
except ValueError:
    eighteenth_birthday = dob.replace(year=dob.year + 18, day=28)

if today >= eighteenth_birthday:
    print("Allowed.")
else:
    print("Not allowed because you are a minor.")
    days_left = (eighteenth_birthday - today).days
    print(f"You need to wait {days_left} more days.")

    years = days_left // 365
    remaining_days = days_left % 365
    months = remaining_days // 30
    days = remaining_days % 30

    if years == 0:
        if months == 0:
            print(f"Which is approximately {days} days left.")
        else:
            print(f"Which is approximately {months} months, {days} days left.")
    else:
        print(f"Which is approximately {years} years, {months} months, {days} days left.")