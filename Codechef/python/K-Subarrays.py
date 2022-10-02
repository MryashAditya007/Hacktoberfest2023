from math import gcd
t=int(input())
while t>0:
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    g=a[0]
    for i in range(1,n):
        g=gcd(g,a[i])
    count=0
    x=0
    for i in range(n):
        x=gcd(x,a[i])
        if x==g:
            count+=1
            x=0
    if count>=k:
        print("YES")
    else:
        print("NO")
    
    t-=1
