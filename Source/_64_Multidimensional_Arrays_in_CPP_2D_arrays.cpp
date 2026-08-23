//
// Created by LiMi on 2026/8/24.
//

#include "../Header/_64_Multidimensional_Arrays_in_CPP_2D_arrays.h"

void _64_Multidimensional_Arrays_in_CPP_2D_arrays::main() {
    //今天我们要深入讲解C++中的多维数组
    //统一称为多维数组，因为维度的数量可以任意增加
    //所以说二维数组本质上就是嵌套的数组结构

    int* array = new int[100];
    //现在变成了指向整型指针的二级指针
    int** a2d = new int *[100]; //这些内存空间用于存储50个整型指针
    for (int i = 0; i < 100; i++) {
        a2d[i] = new int[100];
    }

    //这里我们处理的是三重指针
    int*** a3d = new int **[100];
    for (int i = 0; i < 100; i++) {
        a3d[i] = new int *[100];
        for (int j = 0; j < 100; j++) {
            int** ptr = a3d[i];
            ptr[j] = new int[100];
        }
    }

    a3d[0][0][0] = 1; //分配内容

    //delete[] a2d;
    for (int i = 0; i < 100; i++) {
        delete[] a2d[i];
    }

    //delete[] a3d;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            delete a3d[i][j];
        }
    }

    //我们不能保证它们的内存位置一定会相邻
    //正是因为这样，这种方式的遍历速度反而会更慢
    //若能将被频繁访问的数据紧凑存储 并合理规划其存储位置 从而提高缓存命中率
    //降低缓存失效概率，即可显著提升程序执行效率
    //比方说处理位图存储时，存储整幅图像的像素矩阵就适用
}
