struct node {
  int l,r,val;
}t[4*maxn];
int sz=2;
void upd(ll v,ll tl,ll tr,ll pos,ll x){
    if(tl==tr){
        t[v].val+=x;
    }
    else{
        ll tm=(tl+tr)/2ll;
        if(pos<=tm){
            if(!t[v].l){
                t[v].l=sz;
                sz++;
            }
        upd(t[v].l,tl,tm,pos,x);
    }
    else{
        if(!t[v].r){
            t[v].r=sz;
            sz++;
        }
        upd(t[v].r,tm+1,tr,pos,x);
    }
    t[v].val=t[t[v].l].val+t[t[v].r].val;
    }
}
ll get(ll v,ll tl,ll tr,ll l,ll r){
    if(tl>r || l>tr){
        return 0;
    }
    if(l<=tl && tr<=r){
        return t[v].val;
    }
    ll tm=(tl+tr)/2ll;
    ll x=0;
    if(t[v].l){
        x+=get(t[v].l,tl,tm,l,r);
    }
    if(t[v].r){
        x+=get(l,r,t[v].r,tm+1,tr);
    }
    return x;
}
