t=int(input())
while t>0:
    p,q,r=map(int,input().split())
    res=p|q|r   
    x=bin(res).replace("0b","")
    pp=bin(p).replace("0b","")
    qq=bin(q).replace("0b","")
    rr=bin(r).replace("0b","")
    l=list(x)
    lp=list(pp)
    lq=list(qq)
    lr=list(rr)
    m=max(len(lp),len(lq),len(lr))
    if len(lp)<m:
        lp=[0]*(m-len(lp))+lp
    if len(lq)<m:
        lq=[0]*(m-len(lq))+lq
    if len(lr)<m:
        lr=[0]*(m-len(lr))+lr 
    p=1
    k=1
    for i in range(len(l)):
        if l[i]=="1":
            x=int(lp[i])
            y=int(lq[i])
            z=int(lr[i])
            if x+y+z==1:
                print(0)
                k=0
                break 
            elif x+y+z==2:
                continue
            else:
                p*=4
    if k==1:
        print(p)
                
            
    t-=1
