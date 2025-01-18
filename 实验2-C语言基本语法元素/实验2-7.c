/*实验教材P63 程序设计第(8)题
输入一个仅有英文大写字母、逗号、句点和空格符组成的英文句子（字符数不超过80个）和正整数k（1<=k<=26），
将其中的大写英文字母替换成字母表中该字母开始的第k个字母，其它字符保持不变*/
/*测试输入：
ON A CLEAR DAY,YOU CAN SEE FOREVER
9
预期输出：
VWI K MTZIL GIG,CWK VIA MMN ZWDMZM*/
#include<stdio.h>
int main() {
	char input[80];
	int length,k,i,j,m;
	char c,transfer;
	for ( i = 0; i < 80; i++) {
		c=getchar();
        if ((c<='z'&&c>='a')||(c<='Z'&&c>='A')||(c==' ')||(c==',')||(c=='.')) {
			input[i]= c;
			length++;
		}
		else
			break;
		
	}
	scanf("%d",&k);
	for (j=0;j<length;j++) {
		if (input[j]<='Z'&&input[j]>='A') 
			input[j]=((input[j]-'A'+k-1)%26)+'A';
		}
		for (m=0;m<=(length-(length%2));m+=2) {
			transfer = input[m];
			input[m] = input[m+1];
			input[m+1] = transfer;
	}
		printf("%s",input);
        return 0;
}