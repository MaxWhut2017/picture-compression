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
void tree_merge(node* a,node* b){//节点(子树)合并,返回新树根
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
    if(min1>min2){
        swap(cur[0],cur[1]);
    }
}
//这个函数本来是用来先根法输出树测试用的,后来改一下用来拿到huffman_code数组
string huffman_code[256];
void tree_origin(node* temp_root,string str="$"){
    if(temp_root->value!=-1){
///        printf("%d(%c): ",temp_root->value,temp_root->value);\
///        cout << str << endl;
///        cout << temp_root->value << ": " << str << endl;
        huffman_code[temp_root->value]=str;
        return;
    }
    if(temp_root->left_child){
        tree_origin(temp_root->left_child,str+"0");
    }
    if(temp_root->right_child){
        tree_origin(temp_root->right_child,str+"1");
    }
}
void print(){
    for(int i=0;i<new_node_cnt;i++){
        cout << i << " " << n[i].value << " " << n[i].freq << "\n";
    }
}
void tree_build(int* weight,int len){
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
        tree_merge(&n[cur[0]],&n[cur[1]]);
    }
    int root=2*len-2;//256+256-1-1
    //测一下生成的树是否正确
///    print();
    tree_origin(&n[root]);
}
void trans(char* filename,int* bit,int& len){
///    哈夫曼树初始化完毕,开始生成01串
    FILE* in=fopen(filename,"rb");
    int cur=0;
    char ch;
    while((ch=getc(in))!=EOF){
        string temp=huffman_code[ch];
        for(int i=1;i<temp.size();i++){
            bit[cur++]=temp[i]-'0';
        }
    }
    len=cur;
///    for(int i=0;i<cur;i++){
///        printf("%d",bit[i]);
///    }
    fclose(in);
}
void huffman(char* filename,int* weight,int weightlen,int* bit,int& bitlen){
    tree_build(weight,weightlen);
    trans(filename,bit,bitlen);
}
    
    












