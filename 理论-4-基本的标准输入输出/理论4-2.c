/*编写完整的程序，从终端输入一个无符号短整数k，输出将k的高4位和低4位交换后的结果。例如，程序执行时：
输入：54321（对应二进制为11010100 00110001）；
输出：5181 （对应二进制为00010100 00111101）。
根据提示，在右侧编辑器Begin-End补充完整代码。（要求此题只能使用第二、三两章的知识完成，不建议使用条件语句与循环语句等）*/
#include <stdio.h>

int main(){
	/**********Begin**********/
    unsigned short k,result;
    scanf("%hu", &k); // 读取无符号短整数

    // 提取高4位和低4位
    unsigned short low4=k&0x000F; // 高4位
    unsigned short high4=k&0xF000; // 低4位
    unsigned short mid8=k&0x0FF0;
    // 交换高4位和低4位
    unsigned short newlow=(high4>>12);
    unsigned short newhigh=(low4<<12);
    result=((newhigh|newlow)|mid8);

    printf("%hu\n", result); // 输出结果
	/**********End**********/
	return 0;
}