//用辗转相除法计算两个数的最大公约数，要求用递归函数实现求最大公约数。
/**
  按任务要求补全该函数
  用递归实现辗转相除法
 **/
 //求最大公约数
int gcd(int x, int  y)
{
	/**********  Begin  **********/
  int remain,max,min;
  if (x==y) return x;
  if(x<y) {
    max=y;
    min=x;
  }
  else{
    max=x;
    min=y;
  }
  remain=max%min;
  printf("%d %d\n",max,min);
  if(remain==0) {
    printf("%d 0\n",min);
    return min;
  }
  return gcd(min,remain);
    /**********  End  **********/
}

#include<stdio.h>
#include"step6_stu.h"

//请根据此主函数流程，使用递归补全step6_stu.h文件中gcd()函数

int main() {
		int x,y;
		
		scanf("%d%d",&x,&y);
		printf("%d",gcd(x,y));
		
		return 0;
}