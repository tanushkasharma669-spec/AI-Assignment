print("----- Simple Turing Test -----")
print("Chat with the machine. Type 'exit' to stop.\n")

responses = {
    "hello": "Hi there!",
    "how are you": "I'm doing well, thanks for asking!",
    "what is your name": "I am an AI program.",
    "bye": "Goodbye! Have a nice day."
}

while True:
    user = input("You: ").lower()

    if user == "exit":
        print("Test ended.")
        break

    if user in responses:
        print("Machine:", responses[user])
    else:
        print("Machine: That's interesting! Tell me more.")