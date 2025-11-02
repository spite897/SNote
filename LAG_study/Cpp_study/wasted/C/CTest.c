#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>			

#include "ADD.h"

#define ten 10		
#define MAX(X,Y) (X>Y?X:Y)
//定义宏 - int a = MAX(b,c);

/*
srand  --  rand -- RAND_MAX  --不要多次设定种子  -- 结果% 限定范围
Sleep()  --Windows.h
system("cls")
NULL  -- 空指针
time  -- 返回t_time 类型的时间戳
函数传递数组是指针  sizeof ==>操作符
数组名 即数组首元素地址  arr  <==>  &arr[0]
除了&arr ==> 整个数组的地址
sizeof(arr)  ==> 整个数组的大小
指针作差结果是相差的元素个数
只允许指针比较数组外的后一个元素
*/

static int a = 10;
//静态全局变量/函数-表示变量的作用域限定在定义它的源文件中
//静态局部变量-生命周期延迟整个程序

int main() {
	for (int i = 0; i <= 5; i++) {
		if (i == 3) continue;
		printf("%d", i);
	}
	return 0;
}			

struct Book {
	char name[20];
	int price;
};
int struct_part() {
	struct Book b1 = {"C development",50};

	b1.price = 30;
	printf("%d", b1.price);

	struct Book* pb = &b1;
	printf(" %s", pb -> name);
	return 0;
}

int p_part() {
	int a = 10;
	int* p = &a;
	printf("%d %p \n", a, p);
	*p = 20;
	printf("%d %p \n", a, p);
	p = 20;
	printf("%d %p \n", a, p);
	// *p <==> a
	// p <==> &a
	// 指针大小   32位 ==> 4bit   64位 ==> 8bit
	return 0;
}

int define_part() {
	int a, b;
	a = ten;
	b = 9;
	b = a + b;
	printf("%d %d", a, b);
	return 0;
}

int scanf_part() {
	int a,b;
	printf("please send me a number to remember : ");
	b=scanf("%d", &a);		//输入缓冲区   []  -->   [输入内容\n]  (scanf)-->  [\n]
	printf("a=%d b=%d", a,b);
	return a;
}

int getputchar_part() {
	int a;
	printf("send me a message :");
	a = getchar();
	putchar(a);
	return 0;
}

int forwhile_part() {
	int i = 0;

	for (;;) {
		printf("An endless routine\n");
		break;
	}

	printf("A for-form count routine");

	for (int i = 0; i < 5; i++) {
		printf(" %d",i);
	}

	printf("\ncurrent i : %d", i);
	printf("\nA while-form count routine");

	while (i<5) {
		printf(" %d", i++);
	}

	printf("\ncurrent i : %d", i);
	
	i = 0;
	printf("\nA do-while-form count routine");
	do {
		printf(" %d", i++);
	} while (i < 5);

	printf("\ncurrent i : %d", i);
	return 0;
}

int choice_part() {
	int a = 5 , n = 5;
	if (8 < n <= 10) {
		printf( "1");
	}
	else if (6 < n <= 8) {
		printf("2");
	}
	else { printf("3"); }
	printf("\n");
	switch (a) {
	case 5://case 只能跟整形
	case 4:
		printf("1");
		break;
	case 3:
	case 2:
		printf("2");
		break;
	case 1:
		printf("3");
		break;
	default :
		printf("error");
	}
	printf("\n");

	(n + a == 10) ? printf("great"): printf("normal");// a ? b : c ==>   if a:b  else:c

	return 0;
}
/*
	int a = 1000L;	==>长整型
	int b = 100U;	==>无符号整形 unsigned
	int c = 0180;	==>八进制
	int d = 0x180;	==>十六进制

	a && b  ==>与
	a || b  ==>或

	auto  ==>自动销毁
	const    具有常属性 ==>不可更改		仍是变量==>不看做常量
	register  ==>建议储存到寄存器   寄存器==>高速缓存==>内存==>处理器
	unsigned  ==>无符号变量

	&a  ==>取地址
	int*  ==>指针变量/解引用操作符

*/
int arr_part() {
	int num[10] = { 0 };
	printf("%d", num[0]);
	return 0;
}
enum Sex {
	MALE=1,FEMALE,UNKNOOWN
};
int enum_part() {
	printf("male is %d\n",MALE);	//相当于define

	enum Color {RED,BLUE,YELLOW};
	enum Color color1 = RED;
	enum Color color2 = 2;
	printf("%d %d",color1,color2);
	return 0;
}

int strring_part() {
	char s1[] = "101";//{'1','0','1','\0'}
	printf("%s",s1);
	/*
	"string" == "string"  ==> false 
	strcmp("","")  ==> 0

	char[] a = {1,2,3}		==> {1,2,3}
	char[] a = "123"		==> {'1','2','3',\0}
	*/
	return 0;
}
