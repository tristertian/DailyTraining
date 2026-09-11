// 使用代码手搓一个栈

#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
typedef struct Node  //创建链表 
{
	int data;
	struct Node* next;
};
struct Node* createList()  //创建表头头节点，节点数据域为空 
{
	struct Node* headNode=(struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
} 
struct Node* createNode(int data)  //动态创建新节点 
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next = NULL;
	return newNode;
}
struct stack//创建栈顶节点
{
	struct Node* stackTop;  //用栈顶表示整个链表 
	int size;       //记录数据个数 
};
struct stack* createStack()//创建栈的结构体变量
{
	struct stack* mystack=(struct stack*)malloc(sizeof(struct stack));
	mystack->stackTop =NULL;
	mystack->size =0;
	return mystack;
}
void push(struct stack* mystack,int data)//入栈 
{
	struct Node* newNode=createNode(data);  //创建新节点 
	newNode->next =mystack->stackTop ;      //新节点的下一个指向当前栈顶 
	mystack->stackTop =newNode;             //把栈顶指向新节点 
	mystack->size++;                        //节点加一 
}
int top(struct stack* mystack)//获取栈顶元素
{
	if(mystack->size ==0)
	{
		return mystack->size ;   //返回栈的size为0 
	}
	return mystack->stackTop->data ;
} 
void pop(struct stack* mystack)//出栈
{
	if(mystack->size ==0)
	{
		return ;
	}
	else
	{
		struct Node* nextNode=mystack->stackTop->next; //创建新节点记录栈顶的下一个节点 
		free(mystack->stackTop );       //把栈顶节点释放 
		mystack->stackTop =nextNode;    //栈顶标记移到下一个
		mystack->size--; 
	}
} 
int empty(struct stack* mystack) //判断栈是否为空 
{
	if(mystack->size ==0)  
		return 0;         //为空返回0 
	return 1;             //不为空返回一 
}
int main()
{
	int i,j=0,k=0,tmp1=0,tmp2=0,count=0,num1[10],num2[10],tmp=0;
	char str;
	struct stack* mystack=createStack();
	do
	{
		scanf("%c",&str);	
		if(str!='*'&&str!='/'&&str!='+'&&str!='-'&&str!='@')
		{
			push(mystack,str);
		}
		else
		{
			do
			{
				if(top(mystack)=='.')
				{
					count++;
					if(count==3)
					{
						break;
					} 
				}	
				else
				{
					if(count<2)
					{
						num1[j]=top(mystack)-48;
						j++;	
					}	
					else
					{
						num2[k]=top(mystack)-48;
						k++;
					}
				}
				pop(mystack);	
			}while(empty(mystack));
			for(i=0;i<j;i++)
			{
				tmp1=tmp1+num1[i]*pow(10,i);
			}
			for(i=0;i<k;i++)
			{
				tmp2=tmp2+num2[i]*pow(10,i);
			}
			if(str=='*')
			{
				tmp=tmp1*tmp2;
			}
			if(str=='/')
			{
				tmp=tmp2/tmp1;
			}
			if(str=='+')
			{
				tmp=tmp1+tmp2;
			}
			if(str=='-')
			{
				tmp=tmp2-tmp1;
			}
			push(mystack,tmp+48);
			push(mystack,'.');		
			count=j=k=0;
			tmp1=0;
			tmp2=0;
		}		
	}while(str!='@');
	printf("%d",tmp);
} 
