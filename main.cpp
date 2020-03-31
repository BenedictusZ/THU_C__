#include <iostream>
#include <cassert>
#include <iomanip>
#include <vector>
#include <regex>

using namespace std;

//郑莉 C++ improve
/*int main() {
	Rectangle rect;
	rect.initRectangle(3, 2, 20, 10);
	rect.move(3, 2);
	cout << "The data of rect(x,y,w,h):" << endl;
	cout << rect.getX() << ","
	     << rect.getY() << ","
	     << rect.getW() << ","
	     << rect.getH() << endl;
	return 0;
}*/

/*
class Base1 { //基类Base1定义
public:
	void display() const {
		cout << "Base1::display()" << endl;
	}
};
class Base2: public Base1 { //公有派生类Base2定义
public:
	void display() const {
		cout << "Base2::display()" << endl;
	}
};
class Derived: public Base2 { //公有派生类Derived定义
public:
	void display() const {
		cout << "Derived::display()" << endl;
	}
};
void fun(Base1 *ptr) {  //参数为指向基类对象的指针
	ptr->display();     //"对象指针->成员名"
}
int main() {    //主函数
	Base1 base1;    //声明Base1类对象
	Base2 base2;    //声明Base2类对象
	Derived derived;    //声明Derived类对象
	
	fun(&base1);    //用Base1对象的指针调用fun函数
	fun(&base2);    //用Base2对象的指针调用fun函数
	fun(&derived); //用Derived对象的指针调用fun函数
	
	return 0;
}*/

//派生类构造函数
/*
class Base1{
public:
	Base1(int i) {cout<<"Constructing Base1"<<i<<endl;}
};
class Base2{
public:
	Base2(int j) {cout<<"Constructing Base2"<<j<<endl;}
};class
Base3{
public:
	Base3() {cout<<"Constructing Base3"<<endl;}
};
class Derived:public Base2,public Base1,public Base3{
public:
	Derived(int a, int b, int c, int d):Base1(a),member2(d),member1(c),Base2(b){}
private:
	Base1 member1;
	Base2 member2;
	Base3 member3;
};
int main(){
	Derived obj(1,2,3,4);
	system("pause");
	return 0;
}*/

//派生类析构函数
/*
class Base1 {
public:
	Base1(int i)
	{ cout << "Constructing Base1 " << i << endl; }
	~Base1() { cout << "Destructing Base1" << endl; }
};
class Base2 {
public:
	Base2(int j)
	{ cout << "Constructing Base2 " << j << endl; }
	~Base2() { cout << "Destructing Base2" << endl; }
};
class Base3 {
public:
	Base3() { cout << "Constructing Base3 *" << endl; }
	~Base3() { cout << "Destructing Base3" << endl; }
};
class Derived: public Base2, public Base1, public Base3 {
public:
	Derived(int a, int b, int c, int d): Base1(a), member2(d), member1(c), Base2(b)
	{ }
private:
	Base1 member1;
	Base2 member2;
	Base3 member3;
};
int main() {
	Derived obj(1, 2, 3, 4);
	return 0;
}*/

//访问从基类继承的成员
/*
class Base1{
public:
	int var;void fun(){cout<<"Member of Base1"<<endl;}
};
class Base2{
public:
	int var;void fun(){cout<<"Member of Base2"<<endl;}
};
class Derived:public Base1,public Base2{
public:
	int var;void fun(){cout<<"Member of Derived"<<endl;}
};
int main()
{
	Derived d;
	Derived *p=&d;
	d.var=1;
	d.fun();
	d.Base1::var=2;
	d.Base1::fun();
	p->Base2::var=3;
	p->Base2::fun();
}*/

//虚基类
/*
class Base0{
public:
	Base0(int var):var0(var) {}
	int var0;
	void fun0(){cout<<"Member of Base0"<<endl;}
};
class Base1:virtual public Base0{
public:
	Base1(int var):Base0(var){}
	int var1;
};
class Base2:virtual public Base0{
public:
	Base2(int var):Base0(var){};
	int var2;
};
class Derived:public Base1,public Base2{
public:
	Derived(int var):Base0(var),Base1(var),Base2(var){}
	int var;
	void fun(){cout<<"Member of Derived"<<endl;}
};
int main(){
	Derived d(1);
	d.var0=2;
	d.fun0();
	return 0;
}*/

//第七章实验
/*class Animal{
public:
	int age;
};
class Dog:public Animal{
public:
	void SetAge(int n){age=n;};
};
int main(){
	Dog d;
	d.SetAge(2);
	return 0;
}*/
/*
class BaseClass{
public:
	int Number;
	int getNumber(){ return Number;}
	BaseClass(){cout<<"BaseClass construct"<<endl;}
	~BaseClass(){cout<<"BaseClass construct"<<endl;}
};
class DerivedClass:BaseClass{
public:
	DerivedClass() {
		Number=0;
		Number++;
		cout<<"DerivedClass Construction.Number="<<getNumber()<<endl;
	}
	virtual ~DerivedClass() {
		Number--;
		cout<<"DerivedClass Destruction.Number="<<getNumber()<<endl;
	}
};
int main(){
	DerivedClass d;
	return 0;
}*/

//重载加减乘除
/*class Complex{
public:
	Complex(double r=0.0,double i=0.0):real(r),imag(i){}
	Complex operator+(const Complex&c2);
	Complex operator-(const Complex&c2);
	Complex operator*(const Complex&c2);
	Complex operator/(const Complex&c2);
	void display()const ;
private:
	double real;
	double imag;
};
Complex Complex::operator+(const Complex&c2){
	return Complex(real+c2.real,imag+c2.imag);
};
Complex Complex::operator-(const Complex&c2){
	return Complex(real-c2.real,imag-c2.imag);
};
Complex Complex::operator*(const Complex&c2){
	return Complex(real*c2.real,imag*c2.imag);
};
Complex Complex::operator/(const Complex&c2){
	return Complex(real/c2.real,imag/c2.imag);
};
void Complex::display() const {
	cout<<"("<<real<<", "<<imag<<")"<<endl;
}
int main(){
	Complex c1(5,4),c2(2,10),c3;
	cout<<"c1=";
	c1.display();
	cout<<"c2=";
	c2.display();
	c3=c1-c2;
	c3.display();
	c3=c1+c2;
	c3.display();
	c3=c1*c2;
	c3.display();
	c3=c1/c2;
	c2.display();
	
}*/

//重载前置++和后置++为时钟类成员函数
/*class Clock {
public:
	Clock(int hour = 0, int minue = 0, int second = 0);
	
	void showTime() const;
	
	Clock operator++();
	
	Clock operator++(int);

private:
	int hour, minute, second;
};
Clock::Clock(int hour, int minue, int second) {
	if (0 <= hour && hour < 24 && 0 <= minute && minute < 60
	    && 0 <= second && second < 60) {
		this->hour = hour;
		this->minute = second;
		this->second = second;
	} else
		cout << "Time error!" << endl;
}
void Clock::showTime() const {
	cout << hour << ":" << minute << ":" << second << endl;
}
Clock Clock::operator++() {
	second++;
	if (second >= 60) {
		second -= 60;
		minute++;
		if (minute >= 60) {
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}
Clock Clock::operator++(int) {
	Clock old = *this;
	++(*this);
	return old;
}
int main() {
	Clock myClock(23, 59, 59);
	cout << "First time output:";
	myClock.showTime();
	cout << "Show myClock++:";
	(myClock++).showTime();
	cout << "show ++myClock:";
	(++myClock).showTime();
	return 0;
}*/

/*class Complex {
public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) { }
	friend Complex operator+(const Complex &c1, const Complex &c2);
	friend Complex operator-(const Complex &c1, const Complex &c2);
	friend ostream & operator<<(ostream &out, const Complex &c);
private:
	double real; //复数实部
	double imag; //复数虚部
};
Complex operator+(const Complex &c1, const Complex &c2){
	return Complex(c1.real+c2.real, c1.imag+c2.imag);
}
Complex operator-(const Complex &c1, const Complex &c2){
	return Complex(c1.real-c2.real, c1.imag-c2.imag);
}
ostream & operator<<(ostream &out, const Complex &c){
	out << "(" << c.real << ", " << c.imag << ")";
	return out;
}
int main(){
	Complex c1(5, 4), c2(2, 10), c3;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	c3 = c1 - c2; //使用重载运算符完成复数减法
	cout << "c3 = c1 - c2 = " << c3 << endl;
	c3 = c1 + c2; //使用重载运算符完成复数加法
	cout << "c3 = c1 + c2 = " << c3 << endl;
	return 0;
}*/

/*template<typename T>
void outputArray(const T *array,int count){
	for (int i = 0; i < count; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
int main(){
	const int A_COUT=8,B_COUT=8,C_COUT=20;
	int a[A_COUT]={1,2,3,4,5,6,7,8};
	double b[B_COUT]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8};
	char c[C_COUT]="Welcome";
	cout<<"a array contains:"<<endl;
	outputArray(a,A_COUT);
	cout<<"b array contains:"<<endl;
	outputArray(b,B_COUT);
	cout<<"c array contains:"<<endl;
	outputArray(c,C_COUT);
}*/

/*
template <class T> //数组类模板定义
class Array {
private:
	T* list; //用于存放动态分配的数组内存首地址
	int size; //数组大小（元素个数）
public:
	Array(int sz = 50); //构造函数
	Array(const Array<T> &a); //复制构造函数
	~Array(); //析构函数
	Array<T> & operator = (const Array<T> &rhs); //重载"=“
	T & operator [] (int i); //重载"[]”
	const T & operator [] (int i) const; //重载"[]”常函数
	operator T * (); //重载到T*类型的转换
	operator const T * () const;
	int getSize() const; //取数组的大小
	void resize(int sz); //修改数组的大小
};*/

/*
class Complex {
public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

	Complex operator+(const Complex &c2) const;

	Complex operator-(const Complex &c2) const;

	void display() const;

private:
	double real;
	double imag;
};

Complex Complex::operator+(const Complex &c2) const {
	return Complex(real + c2.real, imag + c2.imag);
}

Complex Complex::operator-(const Complex &c2) const {
	return Complex(real - c2.real, imag - c2.imag);
}

void Complex::display() const {
	cout << "(" << real << "," << imag << ")" << endl;
}

int main() {
	Complex c1(5, 4), c2(2, 10), c3;
	cout << "c1=";
	c1.display();
	cout << "c2=";
	c2.display();
	c3 = c1 - c2;
	cout << "c1-c2=";
	c3.display();
	c3 = c1 + c2;
	cout << "c1+c2=";
	c3.display();
	return 0;
}
*/

/*
class Clock{
public:
	Clock(int hour=0,int minute=0,int second=0);
	void showTime()const ;
	Clock& operator++();;
	Clock operator ++(int);
private:
	int hour,minute,second;
};
Clock::Clock(int hour, int minute, int second) {
	if (0<=hour&&hour<24&&0<=minute&&minute<60&&0<=second&&second<60){
		this->hour=hour;
		this->minute=minute;
		this->second=second;
	} else
		cout<<"Time error!"<<endl;
}
void Clock::showTime() const {
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}
Clock &Clock::operator++() {
	second++;
	if (second>=60) {
		second -= 60;
		minute++;
		if ( minute >= 60 ) {
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}
Clock Clock::operator++(int) {
	Clock old=*this;
	++(*this);  //调用前置“++”运算符
	return old;
}
int main(){
	Clock myClock(23,59,59);
	cout<<"First time output:";
	myClock.showTime();
	cout<<"Show myClock++:";
	(myClock++).showTime();
	cout<<"Show ++myClock:";
	(++myClock).showTime();
	return 0;
}*/

/*
class Complex{
public:
	Complex(double r=0.0,double i=0.0):real(r),imag(i) {}
	friend Complex operator+(const Complex &c1,const Complex &c2);
	friend Complex operator-(const Complex &c1,const Complex &c2);
	friend ostream &operator<<(ostream &out, const Complex &c);
private:
	double real;
	double imag;
};
Complex operator+(const Complex &c1,const Complex &c2){
	return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
Complex operator-(const Complex &c1,const Complex &c2){
	return Complex(c1.real-c2.real,c1.imag-c2.imag);
}
ostream &operator<<(ostream &out, const Complex &c){
	out<<"("<<c.real<<","<<c.imag<<")";
	return out;
}
int main(){
	Complex c1(5,4),c2(2,10),c3;
	cout<<"c1="<<c1<<endl;
	cout<<"c2="<<c2<<endl;
	c3=c1-c2;
	cout<<"c1-c2="<<c3<<endl;
	c3=c1+c2;
	cout<<"c1+c2="<<c3<<endl;
}*/

//虚函数
/*
class Base1{
public:
	virtual void display()const;
	void Base1::display() const {
		cout<<"Base1::display()"<<endl;
	}
};
class Base2:public Base1{
public:
	virtual void display()const ;
	void Base2::display() const {
		cout<<"Base2::display()"<<endl;
	}
};
class Derived: public Base2{
	virtual void display()const ;
	void Derived::display() const {
		cout<<"Derived::display()"<<endl;
	}
};
void fun(Base1 *ptr){
	ptr->display();
}
int main(){
	Base1 base1;
	Base2 base2;
	Derived derived;
	fun(&base1);
	fun(&base2);
	fun(&derived);
	return 0;
}*/

//虚析构函数
/*class Base {
public:
	virtual ~Base();
};
Base::~Base(){
	cout<<"Base destructor"<<endl;
};
class Derived: public Base{
public:
	Derived();
	virtual ~Derived();
private:
	int* p;
};
Derived::Derived() {
	p=new int (0);
}
Derived::~Derived() {
	cout<<"Derived destructor"<<endl;
	delete p;
}
void fun(Base* b){
	delete b;
}
int main(){
	Base* b=new Derived();
	fun(b);
	return 0;
}*/

//虚表与动态绑定

//抽象类
/*
class Base1{
public:
	virtual void display()const=0;
};
class Base2: public Base1{
public:
	virtual void display()const ;
};
void Base2::display() const {
	cout<<"Base2::display()"<<endl;
}
class Derived: public Base2{
public:
	virtual void display()const ;
};
void Derived::display() const {
	cout<<"Derived::display()"<<endl;
}
void fun(Base1* ptr){
	ptr->display();
}
int main(){
	Base2 base2;
	Derived derived;
	fun(&base2);
	fun(&derived);
	return 0;
}*/

//override显示覆盖
/*class Base{
public:
	virtual void f1(int )const ;
	virtual ~Base(){

	};
};
void Base::f1(int) const {
	cout<<"Base f1"<<endl;
	return;
}
class Derived: public Base{
public:
	void fi(int );
	~Derived(){

	}
};
void Derived::fi(int) {
	cout<<"derived fi"<<endl;
}
int main(){
	Base *b;
	b=new Base;
	b->f1(1);
	b=new Derived;
	b->f1(1);
	return 0;
}*/

/*struct Base1 final {};
struct Derived:Base1{};
struct Basw2{
	virtual void f() final ;
};*/

/*class Point{
int _x,_y;
public:
	Point(int x=0,int y=0):_x(x),_y(y){}
	Point& operator++();
	Point operator++(int );
	Point& operator--();
	Point operator--(int );

	friend ostream &operator<<(ostream &os, const Point &point);
};
Point& Point::operator++() {
	_x++;
	_y++;
	return *this;
}
Point Point::operator++(int) {
	Point temp=*this;
	++*this;
	return temp;
}
Point& Point::operator--() {
	_y--;
	_x--;
	return *this;
}
Point Point::operator--(int) {
	Point temp=*this;
	--*this;
	return temp;
}

ostream &operator<<(ostream &os, const Point &point) {
	os << "_x: " << point._x << " _y: " << point._y;
	return os;
}
int main(){
	Point p(1,2);
	cout<<p<<endl;
	cout<<p++<<endl;
	cout<<++p<<endl;
	cout<<p--<<endl;
	cout<<--p<<endl;
}*/

/*class Vehicel{
public:
	int MaxSpeed;
	int Weight;
//	void Run(){cout<<"vechicle run!"<<endl;}
//	void Stop(){cout<<"vechicle stop!"<<endl;}
	virtual void Run(){cout<<"vechicle run!"<<endl;}
	virtual void Stop(){cout<<"vechicle stop!"<<endl;}
};
class Bicycle:virtual public Vehicel{
public:
	int Height;
	void Run(){cout<<"Bicycle run!"<<endl;}
	void Stop(){cout<<"Bicycle stop!"<<endl;}
};
class Motorcae:virtual public Vehicel{
public:
	int SeatNum;
	void Run(){cout<<"Motorcae run!"<<endl;}
	void Stop(){cout<<"Motorcae stop!"<<endl;}
};
class Motorcycle: public Bicycle, public Motorcae{
public:
	void Run(){cout<<"Motorcycle run!"<<endl;}
	void Stop(){cout<<"Motorcycle stop!"<<endl;}
};
int main(){
	Vehicel v;
	v.Run();
	v.Stop();
	Bicycle b;
	b.Run();
	b.Stop();
	Motorcae m;
	m.Run();
	m.Stop();
	Motorcycle mc;
	mc.Run();
	mc.Stop();
	Vehicel* vp=&v;
	vp->Run();
	vp->Stop();
	vp=&b;
	vp->Run();
	vp->Stop();
	vp=&m;
	vp->Run();
	vp->Stop();
	vp=&mc;
	vp->Run();
	vp->Stop();
	return 0;
}*/

//TODO 第九章
//函数模板
/*template<typename T>
     T abs(T x){
	return x<0?-x:x;
}
int main(){
	int n=-5;
	double d=-5.5;
	cout<<abs(n)<<endl;
	cout<<abs(d)<<endl;
	return 0;
}*/

/*template<class T>
void outputArray(const T * array,int count){
	for ( int i = 0; i < count; i++ )
		cout<<array[i]<<" ";
	cout<<endl;
}
int main(){
	const int A_COUNT=8,B_COUNT=8,C_COUNT=20;
	int a[A_COUNT]={1,2,3,4,5,6,7,8};
	double b[B_COUNT]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8};
	char c[C_COUNT]="welcome!";

	outputArray(a,A_COUNT);
	outputArray(b,A_COUNT);
	outputArray(c,A_COUNT);
}*/

/*struct Student{
	int id;
	float gpa;
};
template<class T>
class Store{
private:
	T item;
	bool haveValue;
public:
	Store();
	T& getElement();
	void putElem(const T& x);
};

template<class T>
Store<T>::Store():haveValue(false){}

template<class T>
T& Store<T>::getElement() {
	if (!haveValue){
		cout<<"No item present!"<<endl;
		exit(1);
	}
	return item;
}
template<class T>
void Store<T>::putElem(const T &x) {
	haveValue=true;
	item=x;
}
int main(){
	Store<int>s1,s2;
	s1.putElem(3);
	s2.putElem(-7);
	cout<<s1.getElement()<<" "<<s2.getElement()<<endl;
}*/

//数组类模板
/*template<class T>
class Array{
private:
	T* list;
	int size;
public:
	Array(int size=50);
	Array(const Array<T>& a);
	~Array();
	Array<T>& operator=(const Array<T>& rhs);
	T& operator[](int i)const;
	operator T* ();
	operator const T *()const ;
	int getSize()const ;
	void resize(int sz);
};

template<class T>Array<T>::Array(int sz){
	assert(sz>=0);
	size=sz;
	list=new T [size];
}

template<class T>Array<T>::~Array{
		delete [] list;
	}*/

/*int main(){
	Array<int>a(10);
	int n,count=0;
	cout<<"Enter a value >=2 as upper limit for prime number:";
	cin>>n;
	for ( int i = 2; i < n; i++ ) {
		bool isPrime= true;
		for ( int j = 0; j < count; j++ )
			if (i%a[j]==0){
				isPrime=false;
				break;;
			}
		if (isPrime){
			if (count==a.getSize())
				a.resize(count*2);
			a[count++]=i;
		}
	}
	for ( int k = 0; k < count; k++ ) {
		cout<<setw(8)<<a[k];
		cout<<endl;
		return 0;
	}
}*/

//链表类模板

//栈的应用-整数计算器
/*#include <stack>
#include <stllock.h>
#include <sstream>
#include <cmath>
class Calculator{
private:
	stack<double >s;//操作数栈
	void enter(double num);//将操作数num压入栈
	//连续将两个操作数弹出栈，放在opnd1和opnd2中
	bool getTwoOperands(double &opnd1,double &opnd2);
	void compute(char op);

public:
	void run();
	void clear();
};

inline double stringToDouble(double string &str){
	istringstream stream(str);
	double result;
	stream>>result;
	return result;
}
void Calculator::enter(double num) {
	s.push(num);
}
bool Calculator::getTwoOperands(double &opnd1, double &opnd2) {
	if (s.isEmpty()){
		cerr<<"Missing operand!"<<endl;
		return false;
	}
	opnd1=s.pop();
	if (s.is)
}*/

/*
class VLA{
public:
	VLA(int len);  //构造函数
	~VLA();  //析构函数
public:
	void input();  //从控制台输入数组元素
	void show();  //显示数组元素
private:
	int *at(int i);  //获取第i个元素的指针
private:
	const int m_len;  //数组长度
	int *m_arr; //数组指针
	int *m_p;  //指向数组第i个元素的指针
};
VLA::VLA(int len): m_len(len){  //使用初始化列表来给 m_len 赋值
	if(len > 0){ m_arr = new int[len];  */
/*分配内存*//*
 }
	else{ m_arr = NULL; }
}
VLA::~VLA(){
	delete[] m_arr;  //释放内存
}
void VLA::input(){
	for(int i=0; m_p=at(i); i++){ cin>>*at(i); }
}
void VLA::show(){
	for(int i=0; m_p=at(i); i++){
		if(i == m_len - 1){ cout<<*at(i)<<endl; }
		else{ cout<<*at(i)<<", "; }
	}
}
int * VLA::at(int i){
	if(!m_arr || i<0 || i>=m_len){ return NULL; }
	else{ return m_arr + i; }
}
int main(){
	//创建一个有n个元素的数组（对象）
	int n;
	cout<<"Input array length: ";
	cin>>n;
	VLA *parr = new VLA(n);
	//输入数组元素
	cout<<"Input "<<n<<" numbers: ";
	parr -> input();
	//输出数组元素
	cout<<"Elements: ";
	parr -> show();
	//删除数组（对象）
	delete parr;
	return 0;
}
*/

/*
class Demo{
public:
	Demo(string s);
	~Demo();
private:
	string m_s;
};
Demo::Demo(string s): m_s(s){ }
Demo::~Demo(){ cout<<m_s<<endl; }
void func(){
	//局部对象
	Demo obj1("1");
}
//全局对象
Demo obj2("2");
int main(){
	//局部对象
	Demo obj3("3");
	//new创建的对象
	Demo *pobj4 = new Demo("4");
	func();
	cout<<"main"<<endl;

	return 0;
}
*/

//TODO 折半查找
/*
template<class T>
int binSearch(const T list[], int n, const T &key, int mid) {
	int low;
	int high=n-1;
	while (low<=high){
		int mid=(low+high)/2;
		if (key==list[mid])
			return mid;
		else if (key<list[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}
*/

/*
template<class T,class InputIterator,class OutputIterator>
void mySort(InputIterator first,InputIterator last,OutputIterator result){
	vector<T>s;
	for (;first!=last;++first)
		s.push_back(*first);
	sort(s.begin(),s.end());
	copy(s.begin(),s.end(),result);
}
int main(){
	double a[5]={1.2,2.4,0.8,3.3,3.2};
	mySort<double >(a,a+5,ostream_iterator<double>(cout," "));
	cout<<endl;
	mySort<int>(istream_iterator<int>(cin),istream_iterator<int>(),
	        ostream_iterator<int>(cout," "));
	cout<<endl;
	return 0;
}
*/




















