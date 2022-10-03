t=int(input())
while t>0:
    a=list(map(int,input().split()))
    a.sort()
    ans=0
    for i in range(3):
        if a[i]!=0:
            ans+=1 
            a[i]-=1 
    a.sort()
    if a[0]>=2:
        print(ans+3)
    elif a[0]==1:
        if a[2]>=2:
            print(ans+2)
        else:
            print(ans+1)
    else:
        if a[1]==0:
            print(ans)
        else:
            print(ans+1)
    t-=1
