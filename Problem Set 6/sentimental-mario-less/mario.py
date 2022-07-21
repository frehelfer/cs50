import math

# Get a number between 1 and 8
while True:
    try:
        n = int(input("Height: "))
        if n > 0 and n < 9:
            break
    except ValueError:
        print("That's not an integer!")

# For loop
for i in range(n):
    for j in range(n):
        if i + j >= n - 1:
            print("#", end="")
        else:
            print(" ", end="")
    print()

