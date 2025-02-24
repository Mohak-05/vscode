import random

n = int(input("Enter the total number of random numbers to generate: "))

ascending_file = "DAA Codes/ascending_numbers.txt"
descending_file = "DAA Codes/descending_numbers.txt"
random_file = "DAA Codes/random_numbers.txt"

with open(ascending_file, "w") as file:
    for i in range(1, n + 1):
        file.write(str(i) + "\n")

with open(descending_file, "w") as file:
    for i in range(n, 0, -1):
        file.write(str(i) + "\n")

with open(random_file, "w") as file:
    for i in range(n):
        file.write(str(random.randint(1, n)) + "\n")

print("Files have been generated: ascending_numbers.txt, descending_numbers.txt, random_numbers.txt")
