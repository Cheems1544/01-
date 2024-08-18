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
��һ��С�������һ�������ĵ��ɰ��ϣ�С���䵽ĳһ�����ɰ��
�ᱻ����ĳһ���ص㣬ֱ��С�򱻵������ɰ�����ĵط���

������ n �������ĵ��ɰ壬ÿ�����ɰ�ռһ����λ���룬
a[i] �������� i �����ɰ���С����ǰ�� a[i] �����롣
����λ�� 1 �ĵ�������С��ǰ�� 2 �����뵽��λ�� 3 ��
���С���䵽ĳ�����ɰ�󣬾���һϵ�е����ᱻ�������ɰ壬
��ôС����ܴ�������ɰ嵯������

����С�������1 �ŵ��ɰ����棬��ô���С��ᱻ������ٴΣ�
�Żᵯ�����ɰ塣 1�ŵ��ɰ�Ҳ��һ�Ρ�
*/

int f(int i, vector<int> &arr, int n){
    if(i >= n){
    	return 0;
    }
    
    return f(i +arr[i], arr, n) + 1;
}

int main(){
    int n;
    
    cin >> n;
    
    vector<int> arr;
    
    for(int i = 0, a; i < n; i++){
    	cin >> a;
    	
    	arr.push_back(a);
    }
    
    cout << f(0, arr, n) << endl;
    
    return 0;
}
