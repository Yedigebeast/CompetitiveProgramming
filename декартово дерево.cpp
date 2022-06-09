ll merge(ll x,ll y){
    if(x==0 || y==0){
        if(y>0){
            return y;
        }
        else{
            return x;
        }
    }
    if(pr[x]>pr[y]){
        r[x]=merge(r[x],y);
        return x;
    }
    else{
        l[y]=merge(x,l[y]);
        return y;
    }
}

pll split(ll v,ll k){
    if(v==0){
        return {0,0};
    }
    if(key[v]<=k){
        pii res=split(r[v],k);
        r[v]=res.F;
        return {v,res.S};
    }
    else{
        pii res=split(l[v],k);
        l[v]=res.S;
        return {res.F,v};
    }
}

pll implicitsplit(ll v,ll k){
    if(v==0){
        return {0,0};
    }
    ll key=sz[l[v]]+1;
    if(key<=k){
        pll res=implicitsplit(r[v],k-key);
        r[v]=res.F;
        sz[v]=sz[l[v]]+sz[r[v]]+1;
        return {v,res.S};
    }
    pll res=implicitsplit(l[v],k);
    l[v]=res.S;
    sz[v]=sz[l[v]]+sz[r[v]]+1;
    return {res.F,v};
}

ll Erase(ll v,ll k){
    pii res=split(v,k);
    res.F=split(res.F,k-1).F;
    return merge(res.F,res.S);
}

ll add_new(ll k){
    cntr++;
    key[cntr]=k;
    pr[cntr]=rand();
    return cntr;
}

ll insert(ll v,ll x){
    pii res=split(v,x);
    res.F=merge(res.F,add_new(x));
    return merge(res.F,res.S);
}

ll next(ll v,ll k){
    ll ans=-1;
    while(v!=0){
        if(key[v]<k){
            v=r[v];
        }
        else{
            if(ans==-1){
                ans=key[v];
            }
            else{
                ans=min(ans,key[v]);
            }
            v=l[v];
        }
    }
    return ans;
}
