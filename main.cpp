///Create: 2019-04-25 15:41:58
///Last Modified: 2019-04-28 01:10:14
///
#include <cstdio>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <queue> 
#include <stack>
#include <vector>
#include <iostream>
#include <string>
//接口include
#include "count.h"
#include "com.h"
#include "huffman.h"
using namespace std;

int file_size(char* filename){
    FILE* fp=fopen(filename,"r");
    if(!fp){
        cout << "wrong file path.\n";
        return -1;
    }
    fseek(fp,0L,SEEK_END);  
    int size=ftell(fp); 
    fclose(fp);
    return size;
}
int CreateFile(char* filename){
    string path=filename;
    fstream file;
    file.open(path,ios::out);
    if (!file){
        return false;
    }
    file.close();
    return true;
}
int bit[1000000];//这个函数的规模直接决定解压文件的大小上限.中途需要把所有数据存在这个数组中,而且是以最终压缩文件的8倍大小
int main(){
    cout << "====huffman picture compression====" << endl;
    cout << "input the path of the target file: ";
    char filename[256]="C:/Users/Max/Documents/picture-compression/pic/image.bmp";
    int size=file_size(filename);
    if(size==-1){
        return 0;
    }
    int weight[256];
    memset(weight,0,sizeof(weight));
    cout << "analysing the weight..." << endl;
    get_weight(weight,filename);
///    cout << "Byte " << "Weight\n";
///    for(int i=0;i<256;i++)if(weight[i]!=0){
///        printf("0x%02X( %c ) %d\n",i,i,weight[i]);//使用print.cout的格式控制比较难.
///    }
    int bitlen,weightlen=256;
    cout << "compressing..." << endl;
    huffman(filename,weight,weightlen,bit,bitlen);
    char suffix[]=".huf";
    cout << "About to complete.saving..." << endl;
    strcat(filename,suffix);
    bit2zip(bit,bitlen,filename);
    int zipsize=file_size(filename);
    cout << "ok!" << endl;
    cout << "compression rate is: " << (double)zipsize/(double)size << endl;
	return 0;
}

