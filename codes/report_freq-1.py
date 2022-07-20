import re

pattern = re.compile("Slowly, a new text starts appearing on the screen. It reads ...")
flagged = False

f = open("freq_outputs.txt", "w")

for line in open("ssh_outputs.log"):
    if flagged:
        flagged = False
        f.write("{}\n".format(line.strip()))
    else:
        for match in re.finditer(pattern, line):
            if match:
                flagged = True

f.close()
# chars = set()

# for line in open("text/freq_outputs.txt", "r+"):
#     chars.update(list(line.strip()))

# c = list(chars)
# c.sort()
# print(c, len(chars))
