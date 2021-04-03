#include <iostream>
#include <cmath>
using namespace std;
const double pi=3.14159265;

double Function(double x)//���غ���sqrt(1-x*x)��ֵ
{
    if((1-x*x)<0)return 0;//sqrt(1-x*x)�����ڣ������м���
    return sqrt(1-x*x);
}

double Sin(double x)//���غ���sin(x)��ֵ
{
    return sin(x);
}

double Definite_intergration(double a,double b,double(*Fn)(double x))//���㺯��Fn��a,b�ϵĶ�����
{
    double deltx=1e-5,sum=0;//deltxΪ�ָ����䳤��
    while(a<=b)
    {
        sum+=Fn(a)*deltx;
        a+=deltx;
    }
    return sum;
}
int main()
{
    cout<<"���� B51714004"<<endl;
    double a,b;
    cout<<"����sqrt(1-x*x):"<<endl;
    a=-1,b=1;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Function)<<endl;
    a=-2,b=1;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Function)<<endl;
    a=0,b=1;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Function)<<endl;
    cout<<"����sin(x):"<<endl;
    a=-pi,b=pi;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Sin)<<endl;
    a=0,b=pi;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Sin)<<endl;
    a=0,b=pi/2;
    cout<<"["<<a<<","<<b<<"]"<<":"<<Definite_intergration(a,b,Sin)<<endl;
}
