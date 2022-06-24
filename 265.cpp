#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define ldb long double
#define ebk emplace_back
#define mkp make_pair
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
template <typename T1,typename T2> void wrt(T1 x,char c1,T2 y,char c2){wrt(x,c1),wrt(y,c2);}
template<typename _Tp>
class RedBlackTree{
    private:
        int depth;
        struct __node{
            _Tp key;
            bool is_RED;
            int sizeofTree,count;
            __node *leftTree,*rightTree,*parent;
            __node(const _Tp &value){
                key=value;
                is_RED=1;
                sizeofTree=count=1;
                leftTree=rightTree=parent=NULL;
            }
        };
        inline bool is_leftTree(__node *p){return p->parent->leftTree==p;}
        inline void __update(__node *p){
            p->sizeofTree=p->count;
            if(p->leftTree!=NULL)p->sizeofTree+=p->leftTree->sizeofTree;
            if(p->rightTree!=NULL)p->sizeofTree+=p->rightTree->sizeofTree;
        }
        inline void __rotate_parent(__node *p){
            __node *pa=p->parent,*gf=pa->parent;
            if(gf!=NULL)(is_leftTree(pa)?gf->leftTree:gf->rightTree)=p;
            if(is_leftTree(p)){
                pa->leftTree=p->rightTree;
                p->rightTree=pa,pa->parent=p;
                if(pa->leftTree!=NULL)pa->leftTree->parent=pa;
            }else{
                pa->rightTree=p->leftTree;
                p->leftTree=pa,pa->parent=p;
                if(pa->rightTree!=NULL)pa->rightTree->parent=pa;
            }
            p->parent=gf,pa->parent=p;
            __update(pa),__update(p);
        }
        void print_inorder(__node *p){
            if(p==NULL)return;
            print_inorder(p->leftTree);
            for(int i=0;i<p->count;i++)cout<<++depth<<"\t:"<<p->key<<"\n";
            print_inorder(p->rightTree);
        }
        inline void insert_case(__node *p){
            __node *un,*pa,*gf;
            while(p->parent!=NULL&&p->parent->is_RED){
                pa=p->parent,gf=pa->parent;
                un=is_leftTree(pa)?gf->rightTree:gf->leftTree;
                //because pa is is_RED,so pa isn't the root,so gf!=NULL
                if(un!=NULL&&un->is_RED)un->is_RED=pa->is_RED=0,gf->is_RED=1,p=gf;
                //case 3
                else{
                    if(gf==__root)__root=(is_leftTree(p)==is_leftTree(pa)?pa:p);
                    if(is_leftTree(p)==is_leftTree(pa)){
                        __rotate_parent(pa);
                        pa->is_RED=0,gf->is_RED=1;//case 4
                    }else{
                        __rotate_parent(p),__rotate_parent(p);
                        p->is_RED=0,gf->is_RED=1;
                    }//case 5
                    return;//in these case we don't need to while again
                }
            }
            if(p==__root)p->is_RED=0;//case 1&2
        }
        inline void erase_case(__node *p){//p is BLACK and it has 2 NIL subTree
            __node *sib,*pa,*csib;
            while(p!=__root){
                pa=p->parent,sib=is_leftTree(p)?pa->rightTree:pa->leftTree,csib=NULL;
                if(sib->is_RED){
                    if(pa==__root)__root=sib;
                    __rotate_parent(sib),sib->is_RED=0,pa->is_RED=1;
                    continue;//case 2:need to go on and fix
                }else{
                    if(sib->leftTree!=NULL&&sib->leftTree->is_RED)csib=sib->leftTree;
                    if(sib->rightTree!=NULL&&sib->rightTree->is_RED)csib=sib->rightTree;
                    if(csib!=NULL){
                        if(pa==__root)__root=(is_leftTree(csib)==is_leftTree(sib)?sib:csib);
                        if(is_leftTree(csib)==is_leftTree(sib)){
                            __rotate_parent(sib);
                            sib->is_RED=pa->is_RED,pa->is_RED=csib->is_RED=0;
                            //case 6
                        }else{
                            __rotate_parent(csib),__rotate_parent(csib);
                            csib->is_RED=pa->is_RED,pa->is_RED=0;
                            //case 5
                        }
                        return;
                    }
                }
                if(pa->is_RED){
                    pa->is_RED=0,sib->is_RED=1;
                    return;
                }else sib->is_RED=1,p=pa;
            }
        }
        inline void erasewholeTree(__node *p){
            if(p==NULL)return;
            erasewholeTree(p->leftTree);
            erasewholeTree(p->rightTree);
            delete p;
        }
    public:
        RedBlackTree(){__root=NULL;}
        inline void clear(){erasewholeTree(__root),__root=NULL;}
        inline bool empty(){return __root==NULL;}
        inline int size(){return __root==NULL?0:__root->sizeofTree;}
        inline void inorder(){
            puts("\n-------------------------start-------------------------");
            depth=0;
            if(__root==NULL)puts("the Tree is empty");
            else print_inorder(__root);
            puts("--------------------------end--------------------------");
        }
        inline void insert(const _Tp &value){
            __node *p=__root,*pa=NULL;
            while(p!=NULL){
                pa=p,p->sizeofTree++;
                if(value<p->key)p=p->leftTree;
                else if(p->key<value)p=p->rightTree;
                else break;
            }
            if(p!=NULL)p->count++;
            else{
                p=new __node(value);
                if(__root==NULL)__root=p;
                else p->parent=pa,(value<pa->key?pa->leftTree:pa->rightTree)=p;
                insert_case(p);
            }
        }
        inline void erase(const _Tp &value){
            __node *p=__root;
            while(p!=NULL){
                p->sizeofTree--;
                if(value<p->key)p=p->leftTree;
                else if(p->key<value)p=p->rightTree;
                else break;
            }
            if(p!=NULL&&!(--p->count)){
                if(p->leftTree!=NULL&&p->rightTree!=NULL){
                    __node *tmp=p->rightTree;
                    while(tmp->leftTree!=NULL)tmp=tmp->leftTree;
                    int tmp_count=tmp->count;
                    p->key=tmp->key,p->count=tmp_count,tmp->count=0;
                    p=p->rightTree;
                    while(p!=tmp){
                        p->sizeofTree-=tmp_count;
                        p=p->leftTree;
                    }
                    p->sizeofTree-=tmp_count;
                }
                __node *child=(p->leftTree==NULL?p->rightTree:p->leftTree);
                if(!p->is_RED){
                    if(child==NULL||!child->is_RED)erase_case(p);
                    else if(child!=NULL)child->is_RED=0;
                }
                if(child!=NULL)child->parent=p->parent;
                if(p->parent!=NULL)(is_leftTree(p)?p->parent->leftTree:p->parent->rightTree)=child;
                if(p==__root)__root=child;
                delete p;
            }
        }
        inline int order_of(const _Tp &value){
            __node *p=__root;
            int res=1;
            while(p!=NULL)
                if(value<p->key)p=p->leftTree;
                else if(p->key<value)res+=(p->leftTree?p->leftTree->sizeofTree:0)+p->count,p=p->rightTree;
                else return res+(p->leftTree?p->leftTree->sizeofTree:0);
            return res;
        }
        inline _Tp find_by_order(int order){
            __node *p=__root;
            int ord;
            while(p!=NULL){
                ord=(p->leftTree?p->leftTree->sizeofTree:0);
                if(ord>=order)p=p->leftTree;
                else if((order-=ord+p->count)<=0)return p->key;
                else p=p->rightTree;
            }
            return _Tp();
        }
        inline _Tp prefix_max(const _Tp &value){
            __node *p=__root;
            _Tp res;
            while(p!=NULL)
                if(p->key<value)res=p->key,p=p->rightTree;
                else p=p->leftTree;
            return res;
        }
        inline _Tp suffix_min(const _Tp &value){
            __node *p=__root;
            _Tp res;
            while(p!=NULL)
                if(value<p->key)res=p->key,p=p->leftTree;
                else p=p->rightTree;
            return res;
        }
    protected:
        __node *__root;
};
RedBlackTree<int>bst;
int n,ans;
int main(){
    read(n),bst.insert(-1e6-10),bst.insert(1e6+10);
    read(ans),n--,bst.insert(ans);
    while(n--){
        int x,res=1e6+10;read(x);
        int pre=bst.prefix_max(x+1),suf=bst.suffix_min(x-1);
        if(pre>=-1e6)res=min(res,x-pre);
        if(suf<=1e6)res=min(res,suf-x);
        ans+=res,bst.insert(x);
    }
    wrt(ans);
    return 0;
}