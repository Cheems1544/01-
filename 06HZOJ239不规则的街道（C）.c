#include <stdio.h>
#include <math.h>

// HZOJ239不规则的街道

/*
这段C代码的功能是解决一个数学/几何问题，
具体是计算在一个特定的、自相似的几何图形中任意两点之间的距离。
这个几何图形可以想象成一个由更小的、相似的四个子图形组成的方形区域，
这个过程可以递归地进行多次，形成一个多层次的结构。

代码中定义的函数`f`是递归函数，
它的主要作用是根据输入的参数`n`（递归层数或图形的层次）和`s`（点的编号），
计算出这个点在最终图形中的坐标`x`和`y`。
这个编号系统和坐标系统是根据图形的自相似性质和递归构造过程设计的。

具体功能描述如下：

1. **坐标计算**:
   - 如果`n`为1，即最底层的图形，函数直接根据`s`的值确定点的坐标。
     这里，`s`的取值范围是1到4，每个值对应图形中一个确定的位置。
   - 如果`n`大于1，函数会根据`s`的值判断该点属于第几个子区块，
     然后递归地调用自身，计算在子区块中对应的坐标，
     再根据子区块的位置将坐标映射回当前层级的坐标系统。

2. **距离计算**:
   - 在`main`函数中，用户输入`n`、`s`和`d`，其中`s`和`d`是两点的编号。
   - 代码调用`f`函数两次，分别计算编号`s`和`d`对应的坐标。
   - 然后，利用欧几里得距离公式计算两点之间的距离，并输出。
     注意，输出的距离是实际距离的10倍，这可能是因为题目的具体要求。

简而言之，这段代码可以视为一个解决特定几何问题的工具，
它能精确计算在一个具有自相似性质的图形中任意两点间的实际距离。
这个图形通过递归定义，每个层次由四个子图形组成，
而点的位置则由一个全局编号系统确定。
*/

#define S(a) ((a) * (a)) // 定义平方函数

void f(long long n, long long s, long long *x, long long *y){
    // 递归函数，计算坐标(x, y)
    if(n == 1){
        // 当n为1时，根据s的值确定坐标
        if(s == 1){
            *x = 0;
            *y = 0;
        }
        else if(s == 2){
            *x = 0;
            *y = 1;
        }
        else if(s == 3){
            *x = 1;
            *y = 1;
        }
        else{
            *x = 1;
            *y = 0;
        }
        return;
    }
    
    long long L = 1LL << (n -1); // 计算L的值
    long long block = L * L; // 计算block的值
    long long xx, yy;
    
    if(s <= block){ // 情况1：(x, y) -> (y, x)
        f(n - 1, s, &xx, &yy);
        *x = yy;
        *y = xx;
    }
    else if(s <= 2 * block){ // 情况2：(x, y) -> (x, y + L)
        f(n - 1, s - block, &xx, &yy);
        *x = xx;
        *y = yy + L;
    }
    else if(s <= 3 *block){ // 情况3：(x, y) -> (x + L, y + L)
        f(n-1, s - 2 *block, &xx, &yy);
        *x = xx + L;
        *y = yy + L;
    }
    else{ // 情况4：(x, y) -> (2 * L - y - 1, L - x - 1)
        f(n - 1, s - 3 * block, &xx, &yy);
        *x = 2 * L - yy - 1;
        *y = L - xx - 1;
    }
    
    return;
}

int main(){
    long long t, n, s, d;
    
    scanf("%lld", &t); // 输入测试用例数量
    
    while(t--){
        scanf("%lld%lld%lld", &n, &s, &d); // 输入n, s, d的值
        
        long long sx, sy, dx, dy;
        
        f(n, s, &sx, &sy); // 计算起点坐标(sx, sy)
        f(n, d, &dx, &dy); // 计算终点坐标(dx, dy)
        
        printf("%.0lf\n", 10 * sqrt(S(sx - dx) + S(sy - dy))); // 输出两点之间的距离乘以10的结果
    }
    
    return 0;
}
