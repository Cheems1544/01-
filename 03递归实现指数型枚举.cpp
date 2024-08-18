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
从1-n这n个整数中随机选取任意多个，每种方案里的数从小到大排列，
按字典序输出所有可能的选择方案。
*/

int arr[10];

void print_one_result(int n) {
    for(int i = 0; i <= n; i++) {
        if(i) {
        	cout << " ";
        }
        cout << arr[i];
    }
    
    cout << endl;
    
    return ;
}

void f(int i, int j, int n) {
    if(j > n) {
        return ;
    }
    
    for(int k = j;k < n; k++) {
    	arr[i] = k;
    	
    	print_one_result(i);
    	
    	f(i + 1, k + 1, n);
    }
    
    return ;
}

int main() {
    int n;
    
    cin >> n;
    
    f(0, 1, n);
    
    return 0;
}
