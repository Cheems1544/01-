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
·������һ�����Ӳ�֪����������һ�����һ������ӣ�������񫣬�ֶ����һ����
�Ժ���ÿ���ʣ�µ����ӵ�һ�뻹��һ������ n ��ֻʣ��һ�������ˡ�
·����֪��һ��ʼ���˶�������
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
