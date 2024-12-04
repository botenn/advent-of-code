import os


with open(os.path.join(os.path.dirname(__file__), "03-input.txt")) as input_file:
    mem_dump = input_file.read()

results = 0
i = 0

for i in range(len(mem_dump)):
    if mem_dump[i : i + 4] == "mul(":
        if ")" in mem_dump[i + 4 : i + 12]:
            p = mem_dump[i + 4 : i + 12].index(")")
            f = mem_dump[i + 4 : i + 4 + p]
            if len(f.split(",")) == 2:
                factors = f.split(",")
                if factors[0].isdigit() and factors[1].isdigit():
                    results += int(factors[0]) * int(factors[1])
    i += 1

print(f"part 1: {results}")
