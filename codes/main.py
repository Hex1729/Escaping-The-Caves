def atod(s):
    val = 16 * (ord(s[0]) - 102) + ord(s[1]) - 102
    return val


def mul(m, n):
    ans = 0
    for i in range(8):
        if n & (1 << i):
            ans ^= (m << i)
    for i in range(13, 6, -1):
        if ans & (1 << i):
            ans ^= (1 << i)
            ans ^= (1 << (i - 6))
            ans ^= (1 << (i - 7))
    return ans


def exp(b, p):
    if p <= 1:
        return b
    return mul(b, exp(b, p - 1))


# *********#

pairs = set()
E = list(range(1, 127))  # 127
A = list(range(0, 128))  # 128
for e in E:
    for a in A:
        pairs.add((e, a))

with open('final.txt', 'r') as reader:

    # read Si,Ti

    for ii in range(128):
        line = reader.readline()
    	#if ii == 
  #  if line=='':
    #    break

        Si = atod(line[0:2])
        Ti = atod(line[16:18])
        #if ii in [3,5,127,1]:
         #   print(Si,Ti)

    # print(Si,Ti)

        temp = set()
        for p in pairs:
            E = p[0]
            A = p[1]
            val1 = exp(A, (E + E**2) % 127)
            val2 = exp(Si, E*((E**2)%127) % 127)
            val = mul(val1, val2)
            if Ti != val:
                temp.add(p)

    # print(len(temp))

        for q in temp:
            for p in pairs:
                if p[0] == q[0] and p[1] == q[1]:
                    pairs.discard(p)
                    break
fo = open('pairs.txt', 'w')
for p in pairs:
    ans = str(p[0]) + ',' + str(p[1]) + '\n'
    fo.write(ans)

