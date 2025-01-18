/*本关任务：
设计一个字段结构 struct bits, 它将一个 8 位无符号字节从最低位到最高位声明为 8 个字段，依次为 bit0, bit1,..., bit7，且 bit0 优先级最高。同时设计8个函数，第 i 个函数以 biti(i=0, 1, ..., 7)为参数，并且在函数体内输出 biti 的值。将 8 个函数的名字存入一个函数指针数组 p_fun。如果 bit0 为 1, 调用 p_fun[0] 指向的函数。如果 struct bits 中有多位为 1，则根据优先级从高到低顺序依次调用函数指针数组 p_fun 中相应元素指向的函数。
8 个函数中的第 0 个函数可以设计为：

void f0(int b){
    printf("the function %d is called!",b);
}*/
/*****************Begin*****************/
#include<stdio.h>
struct bits{
    unsigned int bit0:1;
    unsigned int bit1:1;
    unsigned int bit2:1;
    unsigned int bit3:1;
    unsigned int bit4:1;
    unsigned int bit5:1;
    unsigned int bit6:1;
    unsigned int bit7:1;
} input;
void f0(int b){
    printf("the function 0 is called!\n",b);
}
void f1(int b){
    printf("the function 1 is called!\n",b);
}
void f2(int b){
    printf("the function 2 is called!\n",b);
}
void f3(int b){
    printf("the function 3 is called!\n",b);
}
void f4(int b){
    printf("the function 4 is called!\n",b);
}
void f5(int b){
    printf("the function 5 is called!\n",b);
}
void f6(int b){
    printf("the function 6 is called!\n",b);
}
void f7(int b){
    printf("the function 7 is called!\n",b);
}
int main(){
    int n,m=1;//m用作遮罩
    void (*function[]) (int b)={f0,f1,f2,f3,f4,f5,f6,f7};
    scanf("%d",&n);
    input.bit0=(n&0x1);
    input.bit1=(n&0x2)>>1;
    input.bit2=(n&0x4)>>2;
    input.bit3=(n&0x8)>>3;//这里得用16进制
    input.bit4=(n&0x10)>>4;
    input.bit5=(n&0x20)>>5;
    input.bit6=(n&0x40)>>6;
    input.bit7=(n&0x80)>>7;
    if(input.bit0) (*function[0])(input.bit0);
    if(input.bit1) (*function[1])(input.bit0);
    if(input.bit2) (*function[2])(input.bit0);
    if(input.bit3) (*function[3])(input.bit0);
    if(input.bit4) (*function[4])(input.bit0);
    if(input.bit5) (*function[5])(input.bit0);
    if(input.bit6) (*function[6])(input.bit0);
    if(input.bit7) (*function[7])(input.bit0);
    return 0;
}
/*****************End*****************/