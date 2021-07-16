s=list(input())
ans=[]
for i in range(0,len(s),2):
    x=ord(s[i])-102
    y=ord(s[i+1])-102
    z=16*x+y
    ans.append(z)
print(ans)