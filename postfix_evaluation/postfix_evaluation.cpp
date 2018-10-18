#include<iostream>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
const int MAX=50;
class postfix
{
	private:
		int stack[MAX];
		int top,nn;
		char *s;
	public:
		postfix();
		void setexpr(char *str);
		int push(int item);
		int pop();
		void show();
		void calc();
};
postfix::postfix()
{
	top=-1;
}
void postfix::setexpr(char *str)
{
	s=str;
}
int postfix::pop()
{
	if(top==-1)
	{
		cout<<endl<<"stack is empty";
		return NULL;
	}
	int data=stack[top];
	top--;
	return data;
}
int postfix::push(int item)
{
	if(top==MAX-1)
	{
		cout<<endl<<"stack is full";
	}
	else
	{
		top++;
		stack[top]=item;
	}
}
void postfix::calc()
{
	int n1,n2,n3;
	while(*s)
	{
		if(*s==' '||*s=='\t')
		{
			s++;
			continue;
		}
		if(isdigit(*s))
		{
			nn=*s-'0';
			push(nn);
		}
		else
		{
			n1=pop();
			n2=pop();
			switch(*s)
			{
				case '+':
						n3=n2+n1;
						break;	
				case '-':
						n3=n2-n1;
						break;
				case '/':	
						n3=n2/n1;
						break;
				case '*':
						n3=n2*n1;
						break;
				case '%':
						n3=n2%n1;
						break;
				case '$':
						n3=pow(n2,n1);
						break;
				default:
						cout<<"unknown operator\n";
						exit(1);
						break;
			}
			push(n3);
		}
		s++;
	}
}
void postfix::show()
{
	nn=pop();
	cout<<"Result is:\n"<<nn<<endl;
}
int main()
{
	cout<<"------POSTFIX EVALUATION------\n";
	cout<<"\n";
	char expr[MAX];
	cout<<"enter postfix expression to be evaluated\n";
	cin.getline(expr,MAX);
	postfix q;
	q.setexpr(expr);
	q.calc();
	q.show();
}

