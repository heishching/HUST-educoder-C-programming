/*实验教材  1.5 实验一 第5题
输入一个正整数，统计该数各位数字中零的个数，以及找出最大的数字。（P38）*/
 #include<stdio.h>
 int main()
 {
     int count, max, x, t;
     scanf("%d", &x);
     count = 0;
     max = 0;
     while(x)
     {
         t = x % 10;
         if(t == 0){
            count++;
         }
         if(t > max){
            max = t;
         }
         x = x/10;
     }
     printf("该数有%d个零,最大数字是%d\n", count, max);
     return 0;
 }