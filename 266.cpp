#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define pbk push_back
#define fir first
#define sec second
#define pii pair<int,int>
#define mem(aaa,bbb) memset(aaa,bbb,sizeof aaa)
using namespace std;
template <typename T> inline void read(T &x){
    x=0;T f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    x*=f;
}
template<typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}
template <typename T> void wrt(T x){
    if(x<0) x=-x,putchar('-');
    if(x>9) wrt(x/10);
    putchar(x%10+48);
}
template <typename T> void wrt(T x,char c){wrt(x),putchar(c);}
template <typename T1,typename T2> void wrt(T1 x1,char c1,T2 x2,char c2){wrt(x1,c1),wrt(x2,c2);}
const ll N=5e5+10;
int n,m,a[N];
template<typename _Tp>
class SplayTree{
    private:
        int depth;
        struct __node{
            _Tp key,min_val,add_tag;
            bool reverse_tag;
            int count,sizeofTree;
            __node *leftTree,*rightTree,*parent;
            __node(_Tp val){
                key=val,reverse_tag=add_tag=0;
                count=sizeofTree=1,min_val=val;
                leftTree=rightTree=parent=NULL;
            }
        };
        inline int is_leftTree(__node *p){return p->parent->leftTree==p;}
        inline int size_safe(__node *p){return p==NULL?0:p->sizeofTree;}
        inline _Tp min_safe(__node *p){return p==NULL?INT_MAX>>1:p->min_val;}
        inline void __update(__node *p){
            if(p==NULL)return;
            __node *ls=p->leftTree,*rs=p->rightTree;
            int lsize=size_safe(ls),rsize=size_safe(rs);
            _Tp lmin=min_safe(ls),rmin=min_safe(rs);
            p->sizeofTree=lsize+rsize+p->count;
            // printf("%d %d\n",lmin,rmin);
            p->min_val=min(p->key,min(lmin,rmin));
        }
        inline void __push_down_reverse_tag(__node *p){
            if(p==NULL||!p->reverse_tag)return;
            __node *ls=p->leftTree,*rs=p->rightTree;
            p->reverse_tag=0;
            if(ls!=NULL)ls->reverse_tag^=1,swap(ls->leftTree,ls->rightTree);
            if(rs!=NULL)rs->reverse_tag^=1,swap(rs->leftTree,rs->rightTree);
        }
        inline void __update_self(__node *p,_Tp val){
            if(p==NULL)return;
            p->add_tag+=val,p->key+=val;
            p->min_val+=val;
        }
        inline void __push_down_add_tag(__node *p){
            if(p==NULL||!p->add_tag)return;
            __node *ls=p->leftTree,*rs=p->rightTree;
            __update_self(ls,p->add_tag);
            __update_self(rs,p->add_tag);
            p->add_tag=0;
        }
        inline void __push_down(__node *p){
            __push_down_add_tag(p);
            __push_down_reverse_tag(p);
        }
        inline void __print_inorder(__node *p){
            if(p==NULL)return;
            __push_down(p);
            __print_inorder(p->leftTree);
            if(p->key>1&&p->key<n+2)wrt(p->key-1,' ');
            __print_inorder(p->rightTree);
        }
        inline void print_one_node(__node *p){
            if(p==NULL)puts("NULL");
            else cout<<"key:"<<p->key<<"\tsize:"<<p->sizeofTree<<"\tcnt:"<<p->count<<"\tmin:"<<p->min_val
            <<"\tadd_tag:"<<p->add_tag<<"\treverse_tag:"<<p->reverse_tag<<"\n";
        }
        inline void debug_inorder(__node *p){
            if(p==NULL)return;
            __push_down(p);
            debug_inorder(p->leftTree);
            cout<<++depth<<":",print_one_node(p),putchar('\t');
            print_one_node(p->leftTree),putchar('\t');
            print_one_node(p->rightTree);
            debug_inorder(p->rightTree);
        }
        inline void __rotate_parent(__node *p){
            // printf("before rotate:%d\n",p->key);
            __node *pa=p->parent,*gf=pa->parent;
            if(gf!=NULL)(is_leftTree(pa)?gf->leftTree:gf->rightTree)=p;
            if(is_leftTree(p)){
                // printf("while rotate:%d\n",p->key);
                pa->leftTree=p->rightTree;
                p->rightTree=pa,pa->parent=p;
                if(pa->leftTree!=NULL)pa->leftTree->parent=pa;
            }else{
                // printf("while rotate:%d\n",p->key);
                pa->rightTree=p->leftTree;
                p->leftTree=pa,pa->parent=p;
                if(pa->rightTree!=NULL)pa->rightTree->parent=pa;
            }
            p->parent=gf,pa->parent=p;
            __update(pa),__update(p);
            // printf("after rotate:%d\n",p->key);
        }
        inline void __splay(__node *p,__node *tar){
            // printf("start to spaly %d\n",p->key);
            for(__node *pa=NULL;(pa=p->parent)!=tar;__rotate_parent(p)){
                // printf("p:%d\n",p->key);
                if(pa->parent!=tar)__rotate_parent(is_leftTree(p)==is_leftTree(pa)?pa:p);
                // puts("");
            }
            if(tar==NULL)__root=p;
        }
        inline __node* __find_by_order(_Tp order){
            __node *p=__root;
            _Tp ord;
            while(p!=NULL){
                __push_down(p);
                ord=(p->leftTree?p->leftTree->sizeofTree:0);
                if(ord>=order)p=p->leftTree;
                else if((order-=ord+p->count)<=0)return p;
                else p=p->rightTree;
            }
            return NULL;
        }
        inline __node* __build(_Tp l,_Tp r,__node *pa){
            if(l>r)return NULL;
            // printf("st[%d,%d]\n",l,r);
            _Tp mid=(l+r)>>1;
            __node *ne=new __node(a[mid]);
            ne->parent=pa;
            ne->leftTree=__build(l,mid-1,ne);
            ne->rightTree=__build(mid+1,r,ne);
            // printf("md[%d,%d]\n",l,r);
            // print_one_node(ne);
            __update(ne);
            // printf("ed[%d,%d]\n",l,r);
            return ne;
        }
        inline __node* __split(_Tp l,_Tp r){
            __node *p=__find_by_order(l-1);
            // printf("%d find:%d\n",l-1,p->key);
            __splay(p,NULL);
            // printf("%d find:%d root:%d\n",l-1,p->key,__root->key);
            p=__find_by_order(r+1);
            // printf("%d find:%d\n",r+1,p->key);
            __splay(p,__root);
            // printf("split(%d,%d):\n",l,r),debug();
            return p->leftTree;
        }
    public:
        SplayTree(){__root=NULL;}
        inline _Tp range_min(_Tp l,_Tp r){return __split(l,r)->min_val;}
        inline void add(_Tp l,_Tp r,_Tp val){
            __node *p=__split(l,r);
            __update_self(p,val);
            // print_one_node(p);
            __update(p->parent),__update(__root);
        }
        inline void reverse(_Tp l,_Tp r){
            __node *p=__split(l,r);
            // puts("middle:");
            // debug();
            p->reverse_tag^=1;
            swap(p->leftTree,p->rightTree);
            __update(p->parent),__update(__root);
        }
        inline void erase(_Tp pos){
            __node *p=__split(pos,pos);
            p->parent->leftTree=NULL;
            delete p;
            __update(__root->rightTree),__update(__root);
        }
        inline void insert(_Tp pos,_Tp val){
            __split(pos+1,pos);
            __node *p=__root->rightTree;
            // puts("middle:");
            // debug();
            __node *ne=new __node(val);
            ne->parent=p,p->leftTree=ne;
            __update(p),__update(__root);
        }
        inline void revolve(_Tp l,_Tp r,_Tp cnt){
            cnt%=(r-l+1);
            if(!cnt)return;
            __node *p=__split(r-cnt+1,r);
            p->parent->leftTree=NULL,p->parent=NULL;
            __update(__root->rightTree),__update(__root);
            __split(l,l-1);
            __node *q=__root->rightTree;
            q->leftTree=p,p->parent=q;
            __update(q),__update(__root);
        }
        inline void build(_Tp l,_Tp r){
            __root=__build(l,r,NULL);
        }
        inline void inorder(){__print_inorder(__root);}
        inline void debug(){
            puts("-----------------start-----------------");
            if(__root!=NULL){
                depth=0;
                cout<<"root:"<<__root->key<<"\tsize:"<<__root->sizeofTree<<"\n";
                debug_inorder(__root);
            }else puts("The tree is empty!");
            puts("------------------end------------------");
        }
    protected:
        __node *__root;
};
SplayTree<int>bst;
char s[N];
void file(){
    freopen("P2042_3.in","r",stdin);
    freopen("my.out","w",stdout);
}
int main(){
    // file();
    read(n);
    a[1]=a[n+2]=INT_MAX>>1;
    for(int i=2;i<=n+1;i++)read(a[i]);
    bst.build(1,n+2);
    read(m);
    while(m--){
        char s[10];
        int x,y,z;
        scanf("%s",s+1),read(x),x++;
        if(s[1]=='A'){
            read(y,z),y++;
            bst.add(x,y,z);
        }
        if(s[1]=='R'&&s[4]=='E'){
            read(y),y++;
            bst.reverse(x,y);
        }
        if(s[1]=='R'&&s[4]=='O'){
            read(y,z),y++;
            bst.revolve(x,y,z);
        }
        if(s[1]=='I'){
            read(z);
            bst.insert(x,z);
        }
        if(s[1]=='D'){
            bst.erase(x);
        }
        if(s[1]=='M'){
            read(y),y++;
            wrt(bst.range_min(x,y),'\n');
        }
        // bst.debug();
    }
    return 0;
}
/*
9 8 
2 -6 3 5 1 -5 -3 6 3 
GET-SUM 5 4
MAX-SUM
INSERT 8 3 -5 7 2
DELETE 12 1
MAKE-SAME 3 3 2
REVERSE 3 6
GET-SUM 5 4
MAX-SUM

*/