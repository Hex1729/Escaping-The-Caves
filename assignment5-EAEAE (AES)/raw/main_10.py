#for i in range(8):
   # file=str("inputs"+str(i+1)+".txt")
i=7
f=open("inputs7.txt","a")
for j in range(128):
    s=['f']*16
    s[2*i]=chr(102+j//16)
    s[2*i+1]=chr(102+j%16)
    s.append("\n")
    val=''.join(str(e) for e in s)
    f.write(val)
    
    
