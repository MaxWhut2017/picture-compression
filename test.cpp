///Create: 2019-04-25 15:46:54
///Last Modified: 2019-04-25 16:24:34
///
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <queue> 
#include <stack>
#include <vector>
#include <iostream>
///接口include
#include "count.h"
///压缩接口测试:输出其返回的权重数组
///
using namespace std;

void compression_count_test(){
    char filename[256]="C:/Users/Max/Documents/picture-compression/pic/testcnt.bmp";
    int *weight;
    weight=get_weight(filename);
    cout << "Byte " << "Weight";
    for(int i=0;i<256;i++){
        printf("0x%02X( %c ) %d\n",i,i,weight[i]);//使用print.cout的格式控制比较难.
    }
}
int main(){
    compression_count_test();
	return 0;
}

