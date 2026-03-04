import random

print("----- CAPTCHA Verification -----")

a = random.randint(1, 10)
b = random.randint(1, 10)

print(f"Solve this to prove you are human: {a} + {b}")

user = int(input("Enter your answer: "))

if user == a + b:
    print("CAPTCHA Passed! You are human.")
else:
    print("CAPTCHA Failed! Try again.")
