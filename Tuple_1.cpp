#include <iostream>
#include <tuple>
int main()
{   
	//create and assign tuple 1
	std::tuple <int, int,int,int,int> test_tuple1(0, 1, 2, 3, 4);
	//create and assign tuple 2
	std::tuple <int, int, int, int, int> test_tuple2(99,99, 99, 99,99);
	//assign tuple 1
	//test_tuple1 = std::make_tuple(0, 1,2,3,4);
	//find tuple size
	std::cout << "Tuple 1 values: "<<std::get<0>(test_tuple1) << std::get<1>(test_tuple1) << std::get<2>(test_tuple1)<< std::get<3>(test_tuple1)<< std::get<4>(test_tuple1)<<std::endl;
	std::cout << "The size of tuple is : ";
	std::cout << std::tuple_size<decltype(test_tuple1)>::value << std::endl;
	//swap tuple 1 with tuple 2
	test_tuple2.swap(test_tuple1);
	int i1, i2, i3, i4, i5;
	std::tie(i1, i2, i3, i4, i5) = test_tuple1;
	std::tie(i1, i2, i3, i4, i5) = test_tuple1;
	std::cout << "After Swap and Tie, Tuple 1 values: " << std::get<0>(test_tuple1) << std::get<1>(test_tuple1) << std::get<2>(test_tuple1) << std::get<3>(test_tuple1) << std::get<4>(test_tuple1) << std::endl;
	std::cout << "After Swap and Tie, Tuple 2 values: " << std::get<0>(test_tuple2) << std::get<1>(test_tuple2) << std::get<2>(test_tuple2) << std::get<3>(test_tuple2) << std::get<4>(test_tuple2) << std::endl;
	std::cout << "After Tie, Individual values: " << i1 << i2 << std::endl;
	//cat tuples
	auto tuple_combined = std::tuple_cat(test_tuple1, test_tuple2);
	std::cout << "After cat, Tuple values: " << std::get<8>(tuple_combined) << std::get<9>(tuple_combined) << std::endl;
	return 0;
}