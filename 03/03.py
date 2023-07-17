import os


def get_priority(item):
    if item.lower() == item:
        return ord(item) - 96
    else:
        return ord(item) - 38


total = 0
with open(os.path.join(os.path.dirname(__file__), "03-input.txt")) as f:
    rucksacks = f.read().split("\n")
for rucksack in rucksacks:
    first_compartment = rucksack[0 : len(rucksack) // 2]
    second_compartment = rucksack[len(rucksack) // 2 :]
    for item in first_compartment:
        if item in second_compartment:
            total += get_priority(item)
            break

print("Part 1: " + str(total))

total = 0
counter = 0
while counter < len(rucksacks) - 1:
    for item in rucksacks[counter]:
        if item in rucksacks[counter + 1] and item in rucksacks[counter + 2]:
            total += get_priority(item)
            counter += 3
            break

print("Part 2: " + str(total))
