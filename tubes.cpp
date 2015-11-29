#include "tubes.h"

//Ricky

void creategroup(list &g)
{
    first(g)=NULL;
    last(g)=NULL;
}

adrgrup alokasigrup(grup gg)
{
    adrgrup x=new elemengrup;
    x->info=gg;
    x->next=NULL;
    x->prev=NULL;
    x->child=NULL;
    return x;
}

void insertlast_g(list &g, adrgrup gr)
{
    if (g.first==NULL)
    {
        g.first=gr;
        g.last=gr;
    }
    else
    {
        (g.last)->next = gr;
        gr->prev = g.last;
        g.last = gr;
    }
}

void insertafter_g(list &g, adrgrup gr,adrgrup prec)
{
    if (prec == g.last)
    {
        insertlast_g(g,gr);
    }
    else
    {
        gr->next = prec->next;
        gr->prev = prec;
        prec->next = gr;
        (gr->next)->prev = gr;
    }
}

void add_grup (list &l, adrgrup p)
{
    if (first(l)!=nil)
    {
        next(p) = first(l);
        prev(first(l)) = p;
    }
    else
    {
        last(l) = p;
    }
    first(l) = p;
}

void deletefirst (list &l, adrgrup &p)
{
    if (first(l)!=nil)
    {
        if (first(l)==last(l))
        {
            p = first(l);
            first(l)=nil;
            last(l)=nil;
        }
        else
        {
            p = first(l);
            first(l) = next(p);
            prev(first(l))=nil;
            next(p) = nil;
        }
    }
}

void sort_grupid (list &l)
{
    adrgrup p,prec;
    list temp;

    creategroup(temp);
    while (first(l)!=nil)
    {
        deletefirst(l,p);
        prec = first(temp);
        if (prec == nil)
        {
            add_grup(temp,p);
        }
        else if (info(p).id < info(prec).id)
        {
            add_grup(temp,p);
        }
        else
        {
            while (info(p).id > info(prec).id && next(prec) != nil)
            {
                if (info(next(prec)).id > info(p).id)
                {
                    break;
                }
                prec = next(prec);
            }
            insertafter_g(temp,p,prec);
        }

    }
    while (first(temp)!= nil)
    {
        deletefirst(temp,p);
        insertlast_g(l,p);
    }
}


void sort_grupnama (list &g)
{
    adrgrup p,prec;
    list temp;
    string lower,lower1,lower2;
    creategroup(temp);
    while (first(g)!=nil)
    {
        deletefirst(g,p);
        lower = info(p).nama_grup;
        transform(lower.begin(), lower.end(),lower.begin(), ::tolower);
        prec = first(temp);
        if (prec != nil)
        {
            lower1 = info(prec).nama_grup;
            transform(lower1.begin(), lower1.end(),lower1.begin(), ::tolower);
        }
        if (prec == nil)
        {
            add_grup(temp,p);
        }
        else if (lower < lower1)
        {
            add_grup(temp,p);
        }
        else
        {
            while (lower > lower1 && next(prec) != nil)
            {
                lower2 = info(next(prec)).nama_grup;
                transform(lower2.begin(), lower2.end(),lower2.begin(), ::tolower);
                if (lower2 > lower)
                {
                    break;
                }
                prec = next(prec);
            }
            insertafter_g(temp,p,prec);
        }

    }
    while (first(temp)!= nil)

    {
        deletefirst(temp,p);
        insertlast_g(g,p);
    }
}

adrgrup find_idgrup (list g, int id)
{
    adrgrup xx=(g).first;
    while ((xx!=NULL)and(xx->info).id!=id)
    {
        xx=xx->next;
    }
    return xx;
}


//Ranny
adrgrup del_grup_danstatus (list &g, adrgrup &w)
{
    adrstatus p;
    p=child(w);
    string x;
    if (p!=NULL)
    {
        do
        {
            adrstatus q = p;
            p = next(p);
            x = infoc(q).status;
            q = del_status_grup(w,x);

        }
        while (p!=NULL);

        x = info(w).nama_grup;
        w=del_grupnama(g,x);
        dealokasigrup (w);
    }
    else
    {
        x = info(w).nama_grup;
        w=del_grupnama(g,x);
        dealokasigrup (w);
    }
}


void dealokasigrup (adrgrup p)
{
    delete p;
}
void view_grup (list l )
{
    adrgrup p;
    p=first(l);
    while ((p)!=NULL)
    {

        cout<<"id grup: "<<info(p).id<<endl;
        cout<<"nama grup: "<<info(p).nama_grup<<endl;
        cout<<"tanggal dibuat: "<<info(p).tanggaldibuat<<endl;
        cout<<"nama admin: "<<info(p).admin<<endl;
        cout<<endl;
        //view_status_grup(p);
        p=next(p);
    }
}
adrgrup del_grupid (list &g, int x)
{
    adrgrup p=find_idgrup(g,x);
    if (p!=NULL)
    {
        if(p==first(g))  //first
        {
            first(g)=next(p);
            next(p)=NULL;
            prev(first(g))=NULL;
            dealokasigrup (p);
        }
        else if(p==last(g))  //LAST
        {
            last(g)=prev(p);
            prev(p)=NULL;
            next(last(g))=NULL;
            dealokasigrup (p);
        }
        else  //after
        {
            adrgrup prec;
            prec=first(g);
            while (next(prec)!=p)
            {
                prec=next(prec);
            }
            next(prec)=next(p);
            prev(next(p))=prec;
            next(p)=NULL;
            prev(p)=NULL;
            dealokasigrup(p);
        }
    }
    return p;
}


adrgrup del_grupnama (list &g, string x)
{
    adrgrup p=find_namagrup(g,x);
    if (p!=NULL)
    {
        if(p==first(g))  //first
        {
            first(g)=next(p);
            next(p)=NULL;
            prev(first(g))=NULL;
            dealokasigrup (p);
        }
        else if(p==last(g))  //LAST
        {
            last(g)=prev(p);
            prev(p)=NULL;
            next(last(g))=NULL;
            dealokasigrup (p);
        }
        else  //after
        {
            adrgrup prec;
            prec=first(g);
            while (next(prec)!=p)
            {
                prec=next(prec);
            }
            next(prec)=next(p);
            prev(next(p))=prec;
            next(p)=NULL;
            prev(p)=NULL;
            dealokasigrup(p);
        }
    }
    return p;
}



adrgrup find_namagrup (list l, string x)
{
    adrgrup p=first(l);
    while ((info(p).nama_grup!=x)&&(p!=NULL))
    {
        p=next(p);
    }
    if (p==NULL)
    {
        return NULL;
    }
    else
    {
        return p;
    }
}


//Fadhil
adrstatus alokasistatus(status ss)
{
    adrstatus x=new elemenchild;
    x->infoc=ss;
    x->next=NULL;
    return x;
}
void insertlast_g(adrgrup &g, adrstatus a)
{
    if (child(g)==NULL)
    {
        child(g)=a;
    }
    else
    {
        adrstatus q = child(g);
        while(next(q) != NULL) q = next(q);
        next(q) = a;
    }
}

void inserafter_s(adrgrup &g, adrstatus in,int id)
{
    if (child(g)==NULL)
    {
        child(g)=in;
    }
    else
    {
        adrstatus after=(g)->child;
        while ((after!=NULL) && (infoc(after).id!=id))
        {
            after=next(after);
        }
        if (infoc(after).id == id)
        {
            next(in)=next(after);
            next(after)=in;
        }
    }
}

void add_status_grup (adrgrup &g, adrstatus in)
{
    if (child(g)==NULL)
    {
        child(g)=in;
    }
    else
    {
        next(in) = child(g);
        child(g) = in;
    }
}


void view_status_grup(adrgrup g)
{
    if (child(g)!=nil)
    {
        adrstatus a=child(g);
        while (a!=nil)
        {
            cout<<"id: "<<infoc(a).id<<endl;
            cout<<"tanggal: "<<infoc(a).tanggal<<endl;
            cout<<"status: "<<infoc(a).status<<endl;
            cout<<endl;
            a=next(a);
        }
    }
}

adrstatus findStatus_Status(adrgrup &g, string in)
{
    adrstatus p = child(g);
    while ((p != NULL) && (infoc(p).status != in)) p = next(p);
    return p;
}

adrstatus del_status_grup(adrgrup &g, string in)
{
    adrstatus after=findStatus_Status(g,in);
    if (after==child (g))
    {
        if(next(after)==nil)
        {
            child(g)=nil;
        }
        else
        {
            child(g)=next(after);
            next(after)=nil;
        }
    }
    else if (next(after)==nil)
    {
        adrstatus s=child(g);
        while (next(s)!=after)
        {
            s=next(s);

        }
        next(s)=nil;
    }
    else
    {
        adrstatus s=child(g);
        while (next(s)!=after)
        {
            s=next(s);

        }
        next(s)=next(after);
        next(after)=nil;
    }
}

//Christ
adrstatus find_status (adrgrup p, int id)
{
    while (child(p)!=nil)
    {
        adrstatus q;
        while (infoc(child(p)).id!=id)
        {
            q=next(child(p));
        }
        if(infoc(child(p)).id==id)
        {
            return q;
        }
        else
        {
            return nil;
        }
    }
}

void sort_status_id(adrgrup &p)
{
    adrstatus q;
    adrstatus t;
    adrgrup g;
    child(g) = nil;
    do
    {
        q = child(p);
        while((infoc(q)).id != nil)
        {
            if((infoc(q)).id>(infoc(t)).id)
            {
                t=q;
            }
            q=next(q);
        }
        add_status_grup(g,t);
    }
    while(child(p)!=nil);
    p=g;
}
int jumlah_status_dalam_grup(adrgrup &p)
{
    int j;
    adrstatus q;
    q=child(p);
    j=0;
    while (q!=nil)
    {
        q=next(q);
        j++;
    }
    return j;
}
void edit_status_grup(adrgrup p,int id)
{
    adrstatus q;
    q=find_status(p,id);
    cin>>(infoc(q)).status;
}

