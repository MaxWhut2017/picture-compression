///Create: 2019-04-25 15:41:58
///Last Modified: 2019-04-25 15:54:27
///
#include <cstdio>
#include <conio.h>
#include <stlib.h>
#include <cmath>
#include <queue> 
#include <stack>
#include <vector>
#include <iostream>
//接口include
#include "count.h"
using namespace std;

int main(){
    cout << "====哈夫曼文件压缩====";
    cout << "输入源文件完整路径(带名称): ";
    char filename[256];
    cin >> filename;
    int *weight=get_weight(filename);
	return 0;
}

