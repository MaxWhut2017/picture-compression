///Create: 2019-04-27 20:36:38
///Last Modified: 2019-04-27 20:36:45
///
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <queue> 
#include <stack>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
const int oo=21e8;
///压缩:将字节-频率数组转化为哈夫曼树,并输出转换后的01串,接口返回01串.
struct node{
    int value=-1;
    int freq=-1;
    node* left_child=NULL;
    node* right_child=NULL;
    node* father=NULL;
};
node n[512];
bool vis[512];
int new_node_cnt;
void tree_build(node* a,node* b){//节点(子树)合并,返回新树根
    n[new_node_cnt].left_child=a;
    n[new_node_cnt].right_child=b;
    a->father=b->father=&n[new_node_cnt];
    n[new_node_cnt].freq=a->freq+b->freq;
    new_node_cnt++;
}
void find_min_2(int* cur,int len){
    int min1_cur=-1,min2_cur=-1;
    int min1=oo,min2=oo;
    //1,被访问过的节点已经不是子树根节点了
    //2,freq==-1的节点是后面的还没有成为树的节点,不考虑
    //3,至少比现有的两个min值的其中一个小才考虑
    for(int i=0;i<2*len;i++)if(!vis[i] && n[i].freq!=-1 && (n[i].freq<min1 || n[i].freq<min2)){
        if(min1<min2){
            min2=n[i].freq;
            min2_cur=i;
        }
        else {
            min1=n[i].freq;
            min1_cur=i;
        }
    }
    cur[0]=min1_cur;
    cur[1]=min2_cur;
    vis[cur[0]]=vis[cur[1]]=true;
}
void test_print_tree(node* temp_root,string str="$"){
    cout << temp_root->freq << "\n";
    if(temp_root->value!=-1){
        cout << temp_root->value << ": " << str << endl;
        return;
    }
    if(temp_root->left_child){
        test_print_tree(temp_root->left_child,str+"0");
    }
    if(temp_root->right_child){
        test_print_tree(temp_root->right_child,str+"1");
    }
}
void print(){
    for(int i=0;i<new_node_cnt;i++){
        cout << i << " " << n[i].value << " " << n[i].freq << "\n";
    }
}
void huf(int* weight,int len,int* bit){
    new_node_cnt=len;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<len;i++){
        n[i].value=i;
        n[i].freq=weight[i];
    }
    for(int i=0;i<len-1;i++){//256个节点合并成一棵哈夫曼树只需要255次合并
        int cur[2];
        find_min_2(cur,len);
        vis[cur[0]]=vis[cur[1]]=true;
        tree_build(&n[cur[0]],&n[cur[1]]);
    }
    int root=2*len-2;//256+256-1-1
    //测一下生成的树是否正确
    print();
    test_print_tree(&n[root]);
///    哈夫曼树初始化完毕,开始生成01串
    
}











