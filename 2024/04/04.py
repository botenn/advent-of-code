import os


with open(os.path.join(os.path.dirname(__file__), "04-input.txt")) as input_file:
    words = [line.strip() for line in input_file]

DIRECTIONS = [
    (-1, 0),
    (-1, 1),
    (0, 1),
    (1, 1),
    (1, 0),
    (1, -1),
    (0, -1),
    (-1, -1),
]


def room_for_pattern(x, y, dx, dy):
    return 0 <= x + 3 * dx < len(words[y]) and 0 <= y + 3 * dy < len(words)


def count_xmas_patterns(x, y):
    results = 0
    for dx, dy in DIRECTIONS:
        if room_for_pattern(x, y, dx, dy):
            try:
                if (
                    words[y + dy][x + dx] == "M"
                    and words[y + 2 * dy][x + 2 * dx] == "A"
                    and words[y + 3 * dy][x + 3 * dx] == "S"
                ):
                    results += 1
            except IndexError:
                pass
    return results


results = 0

for y in range(len(words)):
    for x in range(len(words[y])):
        if words[y][x] == "X":
            results += count_xmas_patterns(x, y)

print(f"part1: {results}")
