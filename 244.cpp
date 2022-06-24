#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ldb long double
#define db double
#define pbk push_back
#define fir first
#define sec second
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
template<typename _Tp>
class Treap{
    private:
        static const int LEFT=0,RIGHT=1;
        struct __node{
            _Tp key;
            int count,sizeofTree;
            int random_key;
            __node *subTree[2],*parent;
            __node* leftTree(){return subTree[LEFT];}
            __node* rightTree(){return subTree[RIGHT];}
            __node(int __rand_){key=_Tp(),count=sizeofTree=1,random_key=__rand_,subTree[LEFT]=subTree[RIGHT]=parent=NULL;}
        };
        inline int __node_dir(__node *p){//p isn't root
            return p->parent->rightTree()==p;
        }
        inline int sizeofleftTree(__node *p){
            if(p==NULL)return 0;
            if(p->leftTree()==NULL)return 0;
            return p->leftTree()->sizeofTree;
        }
        inline void __update(__node *p){
            p->sizeofTree=p->count;
            if(p->leftTree()!=NULL)p->sizeofTree+=p->leftTree()->sizeofTree;
            if(p->rightTree()!=NULL)p->sizeofTree+=p->rightTree()->sizeofTree;
        }
        inline __node* __rotate(__node *p,int dir){//return the new root
            __node *gp=p->parent;
            __node *dirt=p->subTree[dir^1];
            __node *op_dirt;
            // assert(dirt!=NULL);
            op_dirt=dirt->subTree[dir];
            p->subTree[dir^1]=op_dirt;
            if(op_dirt!=NULL)op_dirt->parent=p;
            dirt->subTree[dir]=p;
            p->parent=dirt;
            dirt->parent=gp;
            if(gp!=NULL)gp->subTree[p==gp->leftTree()?LEFT:RIGHT]=dirt;
            else __root=dirt;
            if(p!=NULL)__update(p);
            if(dirt!=NULL)__update(dirt);
            return dirt;
        }
        inline void __prefix_max(__node *p,_Tp value){
            if(p==NULL)return;
            if(p->key<value)result_of_query=p,__prefix_max(p->rightTree(),value);
            else __prefix_max(p->leftTree(),value);
        }
        inline void __suffix_min(__node *p,_Tp value){
            if(p==NULL)return;
            if(value<p->key)result_of_query=p,__suffix_min(p->leftTree(),value);
            else __suffix_min(p->rightTree(),value);
        }
        inline int __order_of(__node *p,_Tp value){
            if(p==NULL)return 1;
            if(p->key<value)return __order_of(p->rightTree(),value)+sizeofleftTree(p)+p->count;
            if(value<p->key)return __order_of(p->leftTree(),value);
            return sizeofleftTree(p)+1;
        }
        inline _Tp __find_by_order(__node *p,int order){
            if(p==NULL)return _Tp();
            if(sizeofleftTree(p)>=order)return __find_by_order(p->leftTree(),order);
            if(sizeofleftTree(p)+p->count>=order)return p->key;
            return __find_by_order(p->rightTree(),order-sizeofleftTree(p)-p->count);
        }
        inline void __insert(_Tp value){
            __node *p=__root,*pa=NULL;
            while(p!=NULL){
                pa=p;
                p->sizeofTree++;
                if(p->key<value)p=p->rightTree();
                else if(value<p->key)p=p->leftTree();
                else break;
            }
            if(p!=NULL)return void(p->count++);
            __node *new_node=new __node(rand());
            new_node->parent=pa;
            new_node->key=value;
            if(pa!=NULL)pa->subTree[pa->key<value]=new_node;
            else __root=new_node;
            while(new_node->parent!=NULL
                  &&new_node->random_key>new_node->parent->random_key)
                __rotate(new_node->parent,__node_dir(new_node)^1);
        }
        inline void __erase(_Tp value){
            __node *p=__root;
            while(p!=NULL){
                p->sizeofTree--;
                if(value<p->key)p=p->leftTree();
                else if(p->key<value)p=p->rightTree();
                else break;
            }
            p->count--;
            if(p->count)return;
            if(p->rightTree()!=NULL){
                __node *tmp=p->rightTree();
                while(tmp->leftTree()!=NULL)tmp=tmp->leftTree();
                int tmp_count=tmp->count;
                p->key=tmp->key,p->count=tmp_count,tmp->count=0;
                p=p->rightTree();
                while(p!=tmp)p->sizeofTree-=tmp_count,p=p->leftTree();
                p->sizeofTree-=tmp_count;
            }
            __node *child=p->leftTree()==NULL?p->rightTree():p->leftTree();
            if(p->parent==NULL){
                if(child==NULL){
                    __root=NULL;
                    delete p;
                    return;
                }else{
                    child->parent=NULL;
                    __root=child;
                    delete p;
                    return;
                }
            }
            p->parent->subTree[__node_dir(p)]=child;
            if(child!=NULL)child->parent=p->parent;
            delete p;
            return;
        }
        inline void erasewholeTree(__node *p){
            if(p==NULL)return;
            erasewholeTree(p->leftTree());
            erasewholeTree(p->rightTree());
            delete p;
        }
    public:
        Treap(){
            srand(time(0));
            for(int i=0;i<10;i++)srand(rand());
            __root=NULL;
        }
        ~Treap(){erasewholeTree(__root);}
        inline void clear(){erasewholeTree(__root);}
        inline bool empty(){return __root==NULL;}
        inline int size(){return __root->sizeofTree();}
        inline _Tp prefix_max(_Tp value){
            __prefix_max(__root,value);
            return result_of_query->key;
        }
        inline _Tp suffix_min(_Tp value){
            __suffix_min(__root,value);
            return result_of_query->key;
        }
        inline int order_of(_Tp value){return __order_of(__root,value);}
        inline _Tp find_by_order(int order){return __find_by_order(__root,order);}
        inline void insert(_Tp value){__insert(value);}
        inline void erase(_Tp value){__erase(value);}
    protected:
        __node *__root,*result_of_query;
};
Treap<int>bst;
const ll N=1e5+10;
int n,p[N],h[N];
int main(){
    read(n);
    for(int i=1;i<=n;i++)bst.insert(i);
    for(int i=2;i<=n;i++)read(p[i]);
    for(int i=n;i;i--){
        h[i]=bst.find_by_order(p[i]+1);
        bst.erase(h[i]);
    }
    for(int i=1;i<=n;i++)wrt(h[i],'\n');
    return  0;
}