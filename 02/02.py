import os

char_to_int = {"A": 1, "B": 2, "C": 3, "X": 1, "Y": 2, "Z": 3}

with open(os.path.join(os.path.dirname(__file__), "02-input.txt")) as f:
    strategy_guide = f.read().split("\n")

# Part 1

score = 0

for round in strategy_guide:
    if round in ["A X", "B Y", "C Z"]:
        score += char_to_int[round[2]] + 3
    elif round in ["C X", "A Y", "B Z"]:
        score += char_to_int[round[2]] + 6
    elif round in ["A Z", "C Y", "B X"]:
        score += char_to_int[round[2]]
print("Part 1: " + str(score))

# Part 2

score = 0


def get_losing_shape(counter_shape):
    return {"A": "Z", "B": "X", "C": "Y"}.get(counter_shape)


def get_winning_shape(counter_shape):
    return {"A": "Y", "B": "Z", "C": "X"}.get(counter_shape)


for round in strategy_guide:
    if round[2] == "X":
        score += char_to_int[get_losing_shape(round[0])]
    elif round[2] == "Y":
        score += char_to_int[round[0]] + 3
    elif round[2] == "Z":
        score += char_to_int[get_winning_shape(round[0])] + 6

print("Part 2: " + str(score))
