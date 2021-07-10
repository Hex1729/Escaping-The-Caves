#Code for shifting the deranged ciphertext

s=list(input())
t=[]
for i in range(len(s)):
    if s[i]==' ':
        continue
    t.append(s[i])
j=len(t)-10
for i in range(len(s)):
    if s[i]==' ':
        print(' ',end='')
        continue
    print(t[j%len(t)],end='')
    j+=1