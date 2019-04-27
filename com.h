///Create: 2019-04-25 16:52:52
///Last Modified: 2019-04-25 16:52:52
///
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <queue> 
#include <stack>
#include <vector>
#include <iostream>
///com.h
using namespace std;

///01串bit 8位1字节转换后直接存入zipfilename
//01串与比特的表述略混乱.这里说的01串是哈夫曼树转换来的,是我们直接看到的01串,而最后压缩的文件是我们只有在二进制格式下在能看到的01串,以utf-8方式打开出现的是一堆乱码.
char bit2char(int* num){
    char c=0;
    int a=1;
    for(int i=7;i>=0;i--){
        c+=a*num[i];
        a*=2;
    }
    return c;
}
void bit2zip(int* bit,int len,char* zipfilename){
    int num[8];
    FILE *out=fopen(zipfilename,"wb");
    int cur=0;
    while(true){
        for(int i=0;i<8;i++){
            if(cur<len){
              num[i]=bit[cur++];
            }
            else num[i]=0; 
        }
        char ch=bit2char(num);
        printf("%c",ch);
        fputs(&ch,out);
        if(cur>=len){
            break;
        }
    }
    fclose(out);
}

