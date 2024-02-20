#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const std::string &copy)
{
	(void)copy;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
	(void)ref;
	return *this;
}



ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string lit)
{
	lit = "";
}