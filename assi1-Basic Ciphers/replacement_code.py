#Code for replacing letters for hit and trial

dic={}
for i in range(26):
    dic[chr(97+i)]='_'

#replacements
#dic['y']='e'
#dic['m']='t'
#dic['e']='h'
#dic['a']='s'
#dic['w']='i'
#dic['h']='n'
#...

s=list(input())
for i in range(len(s)):
    if s[i] in {' ','.',',','!'}:
        print(s[i],end='')
    elif ord(s[i])<97:
        x=ord(s[i])-65+97
        if x<=122 and x>=97:
            y=chr(ord(dic[chr(x)])-97+65)
        print(y,end='')
    else:
        print(dic[s[i]],end='')
        