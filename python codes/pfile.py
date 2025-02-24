
def repeatLimitedString( s, repeatLimit):
    crl=0
    d={}
    l=[]
    for i in s:
        if i not in l:
            l.append(i)
        d[i]=d.get(i,0)+1
    l.sort(reverse=True)
    ans=""
    print(l)
    while len(ans)<=len(s):
        while crl<repeatLimit and d[l[0]]>0:
            ans+=l[0]
            crl+=1
            d[l[0]]-=1
            print("yay",d[l[0]],crl,l[0])
        if crl==repeatLimit:
            if len(l)==1:
                break
            d[l[1]]-=1
            crl=0
            ans+=l[1]
            if d[l[0]]==0:
                l.pop(0)
                crl=1
            # print("nay",d[l[0]],d[l[1]],crl,l[1])
        if d[l[0]]==0:
            l.pop(0)
            crl=0
            print("popped")
            if len(l)==0:
                break
        
    return ans
final=repeatLimitedString("xyutfpopdynbadwtvmxiemmusevduloxwvpkjioizvanetecnuqbqqdtrwrkgt",1)
print(final)