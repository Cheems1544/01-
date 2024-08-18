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
using namespace std;

/*
题目：
从1-n这n个整数排成一排并打乱次序，
按字典序输出所有可能的选择方案。
*/

int arr[10], vis[10] = {0};

void print_one_result(int n) {
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        
        cout << arr[i];
    }
    
    cout << endl;
    
    return ;
}

void f(int i, int n){
    if(i == n){
        print_one_result(n);
    }
    
    for(int k = 1; k <= n; k++){
    	if(vis[k]){
        	continue;
        }
        
        arr[i] = k;
        vis[k] = 1;
        
        f(i + 1, n);
        
        vis[k] = 0;
    }
    
    return ;
}

int main(){
    int n;
    
    cin >> n;
    
    f(0, n);
    
    return 0;
}
