#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

/*
路飞买了一堆桃子不知道个数，第一天吃了一半的桃子，还不过瘾，又多吃了一个。
以后他每天吃剩下的桃子的一半还多一个，到 n 天只剩下一个桃子了。
路飞想知道一开始买了多少桃子
*/

using namespace std;

int f(int n){
    if(n == 1){
        return 1;
    }
    
    return (f(n - 1) + 1) * 2;
}

int main(){
    int n;
    cin >> n;
    cout << f(n) << endl;;
    
    
    return 0;
}
