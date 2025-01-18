/*实验课本P85 程序设计第（1）题
假设工资税金按以下方法计算：x<1000元，不收取税金；1000≤x<2000，收取5%的税金；2000≤x<3000,收取10%的税金；3000≤x<4000，收取15%的税金；4000≤x<5000，收取20%的税金；x>5000，收取25%的税金。

输入工资金额（单位：元），输出应收取的税金额度（设税金为整数）。*/
#include<stdio.h>
int main()
{
	int salary,tax;
    scanf("%d",&salary);
    if(salary<1000)
        tax=0;
    else if(salary<2000)
        tax=(salary-1000)*0.05;
    else if(salary<3000)
        tax=(salary-2000)*0.1+1000*0.05;
    else if(salary<4000)
        tax=(salary-3000)*0.15+1000*0.05+1000*0.1;    
    else if(salary<5000)
        tax=(salary-4000)*0.2+1000*0.05+1000*0.1+1000*0.15;
    else
        tax=(salary-5000)*0.25+1000*0.05+1000*0.1+1000*0.15+1000*0.2;
    printf("%d",tax);
    return 0;
}
