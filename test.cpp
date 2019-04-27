///Create: 2019-04-25 15:46:54
///Last Modified: 2019-04-27 20:31:11
///
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <queue> 
#include <stack>
#include <vector>
#include <cstring>
#include <iostream>
///接口include
#include "count.h"
#include "com.h"
///压缩接口测试:输出其返回的权重数组
///
using namespace std;

void compression_count_test(){//pass
    char filename[256]="C:/Users/Max/Documents/picture-compression/pic/testcnt.bmp";
    int weight[256];
    memset(weight,0,sizeof(weight));
    get_weight(weight,filename);
    cout << "Byte " << "Weight\n";
    for(int i=0;i<256;i++)if(weight[i]!=0){
        printf("0x%02X( %c ) %d\n",i,i,weight[i]);//使用print.cout的格式控制比较难.
    }
}
void compression_com_test(){
    char filename[256]="C:/Users/Max/Documents/picture-compression/pic/test01.bmp";
    int bit[17]={0,0,1,1,0,1,1,1, 0,0,1,1,0,1,1,0, 1};//63
    int len=17;
    bit2zip(bit,len,filename);
}
int main(){
///    compression_count_test();
    compression_com_test();
	return 0;
}

