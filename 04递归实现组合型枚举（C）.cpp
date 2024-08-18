#include <stdio.h>

/*
题目：
从 1-n 这 n 个整数中随机选取 m 个，每种方案里的数从小到大排列，
按字典序输出所有可能的选择方案。
*/

/*
这段代码的功能是计算一个字符串中每个字符出现的次数，并将结果存储在一个字典中。
具体步骤如下：

1. 创建一个空字典`char_count`用于存储字符及其出现次数。
2. 遍历输入的字符串`s`中的每个字符。
3. 如果字符已经在字典`char_count`中，
   则将其对应的计数值加1；
   如果字符不在字典中，则将其添加到字典中并设置计数值为1。
4. 返回填充好的字典`char_count`。
*/

int arr[10]; // 存储当前选择的 m 个数

// 打印一个结果
void print_one_result(int n) {
    for(int i = 0; i < n; i++) {
        if(i) {
            printf(" ");
        }
        
        printf("%d", arr[i]);
    }
    printf("\n");
    
    return ;
}

// 递归函数，用于生成所有可能的组合
void f(int i, int j, int n, int m) {
    // 如果已经选择了 m 个数，则打印这个组合
    if(i == m) {
        print_one_result(m);
        return ;
    }
    
    // 从 j 开始遍历，确保每个组合中的数都是从小到大排列的
    for( int k = j; k <= n && m - i - 1 <= n - k; k++) {
        arr[i] = k; // 将当前数加入组合
        f(i + 1, k + 1, n, m); // 继续选择下一个数
    }
    
    return ;
}

int main() {
    int n, m;
    
    // 输入 n 和 m
    scanf("%d%d", &n, &m);
    
    // 调用递归函数生成所有组合并打印
    f(0, 1, n, m);
    
    return 0;
}
