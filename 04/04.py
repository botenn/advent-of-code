import os

assignments = []
overlaps = 0
subset = 0


def parse_line(line):
    return [int(item) for item in line.replace(",", "-").split("-")]


def range_overlaps(set_of_pairs):
    start = max(int(pair_of_ranges[0]), int(pair_of_ranges[2]))
    end = min(int(pair_of_ranges[1]), int(pair_of_ranges[3]))
    return start <= end


def range_is_subset(set_of_pairs):
    if set_of_pairs[0] <= set_of_pairs[2] and set_of_pairs[1] >= set_of_pairs[3]:
        return True
    elif set_of_pairs[0] >= set_of_pairs[2] and set_of_pairs[1] <= set_of_pairs[3]:
        return True
    else:
        return False


with open(os.path.join(os.path.dirname(__file__), "04-input.txt")) as f:
    lines = f.read().split("\n")
for line in lines:
    assignments.append(parse_line(line))
for pair_of_ranges in assignments:
    if range_overlaps(pair_of_ranges):
        overlaps += 1
    subset += range_is_subset(pair_of_ranges)


print("Part 1: " + str(subset))
print("Part 2: " + str(overlaps))
