import os


left = []
right = []
diff = 0
sim = 0

with open(os.path.join(os.path.dirname(__file__), "01-input.txt")) as input_file:
    lines = input_file.read().splitlines()
    for line in lines:
        left.append(line.split("   ")[0])
        right.append(line.split("   ")[1])

left = sorted([int(i) for i in left])
right = sorted([int(i) for i in right])

for count in range(len(left)):
    diff += abs(left[count] - right[count])

for left_cord in left:
    modifier = 0
    for right_cord in right:
        if left_cord == right_cord:
            modifier += 1
    sim += left_cord * modifier

print(f"part 1: {diff}")
print(f"part 2: {sim}")
