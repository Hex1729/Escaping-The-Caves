import re
sentence=re.compile("Slowly, a new text starts appearing on the screen. It reads ...")
on=False
f=open("f4_outputs.txt", "w")
for line in open("f3_crude_outputs.log"):
    if on:
        on=False
        f.write("{}\n".format(line.strip()))
    else:
        for state in re.finditer(sentence, line):
            if state:
                on=True
f.close()