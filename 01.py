import os

summed_groups = []
with open(os.path.join(os.path.dirname(__file__), "01-input.txt")) as f:
    raw_groups = f.read().split("\n\n")
cleaned_groups = [group.split("\n") for group in raw_groups]
num_groups = [[int(i) for i in group] for group in cleaned_groups]
for num_group in num_groups:
    summed_groups.append(sum(int(i) for i in num_group))
summed_groups.sort(reverse=True)
print(summed_groups[0])
print(sum(summed_groups[:3]))
