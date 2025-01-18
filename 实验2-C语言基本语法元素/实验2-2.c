/*实验教材P63 程序设计第(2)题
输入一个十进制正整数n，求它是几位数并计算各位数字之和*/
 #include<stdio.h>
 int main()
 {
     int x,i,k,m,sum;//x shu i yushu k linshi m weishu
     scanf ("%d",&m);
     k=m;
     sum=0;
     while (k!=0){
         i=k%10;
         k=k/10;
         sum+=i;
         x+=1;
     }
    printf ("%d是%d位数，且各位数字之和为%d。",m,x,sum);

 }