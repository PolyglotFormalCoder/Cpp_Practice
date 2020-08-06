#include <iostream>

template<typename T>
class Line
{
private:
	T point;
public:
	Line(T x) :point(x){}
	~Line() {}
	T Scale() { return (point * point); }
};

int main()
{
	Line<int> line_int(2);
	std::cout << "Integer scaled:" << line_int.Scale() << std::endl;

	Line<float> line_float(2.3);
	std::cout << "Float scaled:" << line_float.Scale() << std::endl;

	Line<double> line_double(2.35656565656);
	std::cout << "Double scaled:" << line_double.Scale() << std::endl;
}

