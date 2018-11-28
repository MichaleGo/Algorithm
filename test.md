# String Konwledge
* [Representation](#Representation)
    * ""
    * {}
* [Frequently used Funcs](#jump)
    * memcpy()
    * strcpy()
        * deffirences
    * strcat() 连接两个字符串
* [Basic Input](#BasicInput)
    * scanf()
    * gets()
    * getchar()
    * fgets()
* [Basic Output](#BasicOutput)
    * printf()
    * puts()
    * fputs()  

<span id = "Representation"></span>  
## Representation
1.`const char *ptr = "Representation"`  replace ` char *ptr = "Representation"`  
如果在操作字符串常量时使用指针，那么用指针更改字符串时就会导致其他指向相同的字符串也改变，因为指针只保存地址，不拷贝内容，操作的是静态存储区的字符串。  
所以，==C PrimerPlus==建议使用数组对字符串进行处理。如果一定要用指针对字符串常量进行处理，推荐这样声名：

　　const char * pch 

防止更改不应该更改的内容。  

2.`""`自动加上`\0`, ` {}`并不会加上`\0`
<span id = "jump"></span>
## Frequently uesd Funcs
### memcpy

>原型：extern void *memcpy(void *dest, const void *src, size_t n);

>用法:  
C语言：#include<string.h>  
C++：#include<cstring>
  
>功能：由src所指内存区域复制count个字节到dest所指内存区域。
  
>说明：  
src和dest所指内存区域不能重叠，==函数返回指向dest的指针==。  
void *dest 表示dest指针类型是任意类型。


**example**
```
#include<stdio.h>
#include<string.h>
int main(){
	const char *s = "Lebron";//注意 const
	char temp[20];
	memcpy(temp,s,strlen(s));//strlen(s) = 6, strlen(s)不包含'\0'
	temp[strlen(s)]='\0';//printf输出时，以\0为结束标志，但并不会输出'\0'，C语言中'\0'作为字符时，代表字符串结束符，属于不显示的特殊字符
	printf("%s,%d\0\n\n\n\n\n",temp,strlen(s));//'\0'使输出提前结束
	return 0;
}

```
---
### strcpy
>原型声明：char *strcpy(char* dest, const char *src);  
<br>
头文件：  
#include <string.h>   
#include <stdio.h>  
<br>
功能：把从src地址开始且含有NULL结束符的字符串复制到以dest开始的地址空间   
<br>
说明：src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。  
<br>
返回指向dest的指针,复制过后，dest仍然指向原来的位置。不一定要利用返回值。

**example 1**
```
#include<stdio.h>
#include<string.h>
int main()
{
	const char *s = "Lebron";
	char temp[20];
	strcpy(temp,s);//遍历s，直至'\0',包括'\0',按字节复制到temp
	printf("%s,%d,I",temp,strlen(temp));
	return 0;
}
```

**example 2**
```
**错误示例**dst指针移动。
char * strcpy(char *dst,const char *src)   
{
    if((dst==NULL)||(src==NULL))
         
           return NULL; 

    char *ret = dst;

    while ((*dst++=*src++)!='\0'); //[2]

    return ret;
}
```
### comparison
>strcpy和memcpy主要有以下3方面的区别。  
1、复制的内容不同。strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。    
<br />
2、复制的方法不同。strcpy不需要指定长度，它遇到被复制字符的串结束符"\0"才结束，所以容易溢出。memcpy则是根据其第3个参数决定复制的长度。  
<br>
3、用途不同。通常在==复制字符串时用strcpy==，而需要复制==其他类型数据用memcpy==

<span id = "BasicInput"></span>
## String basic input
1. `sacnf():` 有专门的%s来输入字符串，但它的终止条件是遇到如==空格，换行符等空白字==符。
2. `gets:`  
遇到换行符就返回。  
gets()函数并==不读取换行符'\n'==,它会`'\n'`替换成`'\0'`,作为c语言字符串结束的标志。  
`puts()`用于显示字符串，并自动在字符串后面添加一个换行标志'\n'.  
` char cha[20] ;gets(cha); `  
   ==易导致溢出==！有一些UNIX系统的代码大量使用了gets()，使得黑客有机会通过这个漏洞编写程序将垃圾数据写入系统，导致系统瘫痪. 不建议掌握。

3.
```
char * cha[16];
fgets(cha, 16, stdin); //fgets(名称，大小，读取文件)
//如果要用这个函数从键盘读取，请在读取文件的地方用上stdin
```
传入的大小为n，它就最多读取n - 1个字符或遇到换行符时终止,遇到换行符时，读取换行符，并在会在`cha`末端添加`'\0'`,返回`cha`指针. 

4.`getchar`


**下面是C Primer Plus第五版的有关程序示例：**
![image](https://images2015.cnblogs.com/blog/992009/201608/992009-20160801183628575-1628601389.png)

6.==for循环暴力输出：==按照程序特定要求编写具体的函数====。====


<span id = "BasicOutput"></span>
### String basic output
`printf()`以参数"%s"输出字符串时过程为：


（1）从首地址开始逐字节寻址输出。
（2）直到某一个字节内存的元素为字符'\0'时，输出此字符并且寻址结束。可能会因为没有结束的'\0'而多输出一些乱码或是字符串。

`puts()`和`printf`相比，多输出一个`\n`

`fputs()`适用于标准I/O和文件
```
Declaration:int fputs(const char *str, FILE *stream)  

str -- 这是一个数组，包含了要写入的以空字符终止的字符序列。
stream -- 这是指向 FILE 对象的指针，该 FILE 对象标识了要被写入字符串的流。

返回值
该函数返回一个非负值，如果发生错误则返回 EOF。

fputs 和 fgets 配套使用，所以它在输出字符串之后不加上'\n'
```


1.[Markdown 教程](https://hacpai.com/guide/markdown)  
2.<https://hacpai.com/guide/markdown>  
3.[标准MD语法教程-简书](https://www.jianshu.com/p/86e7fa33de8e)  
4.[String参考资料](https://www.google.com)

