#define NDEBUG
#include<iostream>
#include<cassert>
double ddouble(double x) {
	assert(x >= 0.0);
	return x * 2;
}
int main() {
	std::cout<<ddouble(1.0);
	std::cout<<ddouble(-1.0);
}