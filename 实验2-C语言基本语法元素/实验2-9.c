//实验教材P64 程序设计第(13)题
//输入一行明文字符串，按题中算法进行加密后输出密文。
#include<stdio.h>
int main(){
    char input[100];
    int i;
    scanf("%[^\n]",&input);//it means that read keyboard input until \n appear
    for(i=0;input[i]!=0;i++){
        int x135,x024,x7,x8,x78,preout1,num,preout2,output;
        //x78 is used to store the 7th&8th of the char,while num is used to store the num of move 
        x7=((input[i]&0x40)>>6)&0x1;//0x40=64(10)=0100 0000(2),this sentence can draw 7th num  
        x8=((input[i]&0x80)>>7)&0x1;//0x80=128(10)=1000 0000(2),this sentence can draw 8th num
        x78=((x8<<1)|x7)<<6;
        num=(x8*2)+x7;
        x024=input[i]&0x15;//0x15=0001 0101(2)
        x135=input[i]&0x2a;//0x2a=32+10=0010 1010(2)
        preout1=((x135>>1)&0x7f)|((x024<<1));//0x7f=0111 1111(2),when right move, the empty position may filled with 0 or 1 randomly,so use it to ensure that the 8th is 0 
        switch(num)
        {
            case 0:output=preout1;break;
            case 1:preout2=(preout1&0x20)>>5;//to draw the 6th,and put it to the 1st,0x20=0010 0000(2)
            output=((preout2|(preout1<<1)&0x3f)|x78);break;//0x3f=0011 1111
            case 2:preout2=(preout1&0x30)>>4;//to draw the 6th,and put it to the 1st,0x=0011 0000(2)
            output=((preout2|(preout1<<2)&0x3f)|x78);break;//0x3f=0011 1111
            case 3:preout2=(preout1&0x40)>>3;//to draw the 6th,and put it to the 1st,0x20=0010 0000(2)
            output=((preout2|(preout1<<3)&0x3f)|x78);break;//0x3f=0011 1111
        }
    printf("%c",output);
    }
}