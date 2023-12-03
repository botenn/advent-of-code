import os

summed_calories = []
with open(os.path.join(os.path.dirname(__file__), "01-input.txt")) as f:
    raw_input = f.read().split("\n\n")
cleaned_input = [group.split("\n") for group in raw_input]
elves_calories = [[int(i) for i in group] for group in cleaned_input]
for elf_calories in elves_calories:
    summed_calories.append(sum(int(calories) for calories in elf_calories))
summed_calories.sort(reverse=True)
print(summed_calories[0])
print(sum(summed_calories[:3]))
