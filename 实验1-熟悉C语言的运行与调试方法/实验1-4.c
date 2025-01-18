/*实验教材  1.5 实验一 第4题
找出1000内的所有完数（P36）*/
 #include<stdio.h>
 /*判断x是否是完全数，是则返回1，否则返回0*/
int isPerfect(int x)
{
    int y, s;//y是因数，s为何
    for(s=0, y=1; y<=x/2; y++){
        if(!(x % y)){ 
            s+=y;}
    }
    if(s == x){
        return 1;}
    return 0;
}

int main()
{
    int a;
    for(a=1; a <= 1000; a++)    /*遍历所有数*/
        if(isPerfect(a))
            printf("%d\n", a);
    return 0;
}
