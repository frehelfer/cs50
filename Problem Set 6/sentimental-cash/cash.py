# Get a number between 1 and 8
while True:
    try:
        n = float(input("Change owed: "))
        if n > 0:
            break
    except ValueError:
        print("That's not an integer!")

# Values
n = round(n * 100)
totalCoins = 0
coins = [25, 10, 5, 1]

# loop througt the coins types. all the logic
for coin in coins:
    totalCoins += n // coin
    n %= coin

# print
print(totalCoins)