///Create: 2019-04-25 15:21:18
///Last Modified: 2019-04-25 15:21:18
///
///count.h:
///压缩:统计源文件的字节频率,接口返回一个字节-频率数组.
///解压:源文件的字符串已经完整的由huffman.cpp得到,接口只需要原封不动的把他保存为解压后的文件decompression-{{originalname}}.bmp,放到压缩文件同目录.
///源文件的bit数不一定是8的倍数,不能完美的化为字节串.这里被建议采用 甩尾高位补零 方法.例如最后甩尾10101,则高位补零为000 10101.
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

void get_weight(int* weight,char* filename){
///    保存256个字节分别的权重的权重数组
///    以只读二进制格式打开文件
    FILE *in=fopen(filename,"rb");
///    while循环扫描文件,初始化权重数组
    char ch;
    //ch=getc(in)一定要用括号括起来以后判断!=EOF,常见的错误写法ch=getc(in)!=EOF实际上在读到文件末尾前始终等价于ch=0.别问我怎么知道的.
    while((ch=getc(in))!=EOF){
        weight[ch]++;
    }
///    用完随手关
    fclose(in);
}

void savefile(){
    return;
}

