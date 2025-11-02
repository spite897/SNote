
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

#define CLASS
#define TEST class_test()

using std::cout;
using std::endl;

std::vector<int> vec;

std::string d;
char global_var = 124;
int* p = nullptr;

//inline 内联函数 约等于 宏
//类的成员函数类外定义推荐定义为内联函数  inline int statement（）

int iostream_test() {

	using namespace std;
	int input = 0;
	cout << "iostream" << endl;
	cin >> input;
	cout << input << endl;
	std::cout << "std::cout" << std::endl;

	return 0;
}

namespace a1 {
	std::string var1 = "hjnjjx";
	char var2[7] = "hjnjjx";
}
int namespace_test() {

	char global_var[6] = "spite";
	printf("global_var:%s\n", global_var);
	printf("::global_var:%d\n", ::global_var);

	return 0;
}
// float& 强制转化时不改变内存
int type_test() {
	
	int a = 10;
	float f = reinterpret_cast<float&>(a);
	printf("a:%d\n", a);
	printf("低级转化 用于指针转化\t");
	printf("reinterpret_cast:%f\n" , f);
	printf("常量转化 去除常属性 \t");
	printf("const_cast:%f\n", f);
	printf("动态转化 判断子类 \t");
	printf("dynamic_cast:%f\n", f);
	printf("静态转化 \t");
	printf("static_cast:%f\n", static_cast<float>(a));
	return 0;
}

int vector_test() {
	std::cout << "加入元素 .push_back()" << std::endl;
	vec.push_back(10);
	std::cout << "访问元素 [] or .at()" << std::endl;
	std::cout << "获取大小 .size" << std::endl;
	for (int &i : vec) std::cout << i;
	std::cout << ".erase(begin) .begin .clear()" << std::endl;
	return 0;
}

#ifdef CONST
class Example {
public:
	int get_value() const {
		return value_; // const 关键字表示该成员函数不会修改对象中的数据成员
	}
	void set_value(int value) const {
		value_ = value; // mutable 关键字允许在 const 成员函数中修改成员变量
	}
private:
	mutable int value_;
};
#endif 
#ifdef CLASS
class Father {
public:
	std::string getName();
	Father(const char* n);//普通构造函数
	Father(const Father &obj);//拷贝构造函数 传值时调用
	~Father();			//析构函数
	friend void printName(Father F);//能调用private的全局函数

	/*
	virtual void function(){};	虚函数 多态的实现
	virtual void function() = 0; 纯虚函数 抽象类不允许实例
	*/
protected:
	std::string name;
private:
	int strategy;
};

void printName(Father F) {
	cout << "Father's name" << F.name << endl;
	cout << "Father'strategy" << F.strategy << endl;
}
inline Father::Father(const char* n) : name(n) {
	std::cout << "Father created" << std::endl;
	this->strategy = 256133;
}
inline Father :: Father(const Father& obj) {
	cout << "Father Copy Be Used" << endl;
}
inline Father::~Father() {
	std::cout << "Father destroyed" << std::endl;
}
inline std::string Father::getName() {
	return this->name;
}

//修饰符继承即加密升级 父类所有低于指定加密的加密到指定程度（？表述不准）
class Son : public Father {
	/*
	子类不能直接调用父类private成员 不能直接修改
	定义同名成员不会报错 在父类成员函数中使用父类中的成员变量 子类反之
	*/
};
#endif

int class_test() {
	Father* F = new Father("LaoLi");
	std::cout << F->getName();
	Father* F2 = new Father(*F);
	delete F ;
	delete F2;
	return 0;
}


int main(){
	d = "string";
	printf("hello world\n");

	TEST;

	return 0;
}