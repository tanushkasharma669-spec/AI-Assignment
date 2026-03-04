# AI Assignment

This repository contains implementations for:

1. BFS and DFS search algorithms
2. Missionaries and Cannibals problem
3. Turing Test simulation
4. CAPTCHA verification

---

# Turing Test Architecture

The Turing Test is designed to evaluate whether a machine can exhibit intelligent behavior indistinguishable from a human.

Architecture:

User → Interface → AI Program → Response Generator → Output

Steps:
1. User sends a message.
2. The AI program checks predefined responses.
3. The system generates a reply.
4. If the user cannot distinguish the machine from a human, the test is considered successful.

<img width="863" height="193" alt="image" src="https://github.com/user-attachments/assets/9835c417-691e-469a-a867-dcd8bba5dcd6" />

Decision: If the judge cannot distinguish the AI from a human,
The AI is considered to have passed the Turing Test.

---

# CAPTCHA Architecture

CAPTCHA (Completely Automated Public Turing test to tell Computers and Humans Apart) is used to distinguish humans from bots.

Architecture:

User → CAPTCHA Generator → Challenge → User Input → Verification → Result

Steps:
1. System generates a random challenge (e.g., math problem).
2. User enters the answer.
3. System verifies the answer.
4. If correct → Human verified.


User ---> CAPTCHA Generator ---> Challenge Displayed
             |
             v
      Verification Engine <--- User Response
             |
             v
          Decision
     (Human / Bot Detection)

