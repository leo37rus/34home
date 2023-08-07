#include <iostream>
#include<string>

template <typename T> concept ComplexConcept = requires(T value)//концепт
{
	{value.tostring() } -> std::same_as<std::string>;
	{value.hash()} -> std::convertible_to<long>;
	requires !std::has_virtual_destructor<T>::value;
};

//провкрка концепта
class Complex {
private:
	short _n = 0;
public:

	Complex(short n) : _n(n) {};
	~Complex() {};

	std::string tostring() {
		std::string str;
		str.push_back(_n);
		return str;
	}

	long hash() {
		long n = _n * 100'000'000;
		return n;
	}
};

void printComplexConcept(ComplexConcept auto& cc) {
	std::cout << cc.hash();
}

// Проверка
int main()
{
	Complex com = 5;
	printComplexConcept(com);	

	return 0;
}



