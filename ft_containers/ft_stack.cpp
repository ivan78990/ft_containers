#include <iostream>

#if 0
    #include <stack>
	namespace ft = std;
#else
#include "stack.hpp"
#endif

int main(void)
{
	std::cout << "[my_stack1] Default constructor:" << std::endl;
	ft::stack<int>	my_stack1;
	std::cout << "my_stack1.empty(): " << std::boolalpha << my_stack1.empty() << std::endl;
	std::cout << "my_stack1.size(): " << my_stack1.size() << std::endl;
	std::cout << "my_stack1.push(1) " << std::endl;
	std::cout << "my_stack1.push(3) " << std::endl;
	std::cout << "my_stack1.push(5) " << std::endl;
	std::cout << "my_stack1.push(7) " << std::endl;
	std::cout << "my_stack1.push(9) " << std::endl;
    my_stack1.push(1);
    my_stack1.push(3);
    my_stack1.push(5);
    my_stack1.push(7);
    my_stack1.push(9);
    
	std::cout << "my_stack1.empty(): " << my_stack1.empty() << std::endl;
	std::cout << "my_stack1.size(): " << my_stack1.size() << std::endl;
	std::cout << "my_stack1.pop() " << std::endl;
    my_stack1.pop();
    std::cout << "my_stack1.size(): " << my_stack1.size() << std::endl;
    std::cout << "my_stack1.top(): " << my_stack1.top() << std::endl;

	std::cout << "*********************************************************" << std::endl;

	std::cout << "[my_stack2] Copy constructor my_stack2(my_stack1):" << std::endl;
	ft::stack<int>	my_stack2(my_stack1);
    std::cout << "my_stack1 == my_stack2: " <<  (my_stack1 == my_stack2) << std::endl;
    std::cout << "my_stack1 == my_stack2: " <<  (my_stack1 == my_stack2) << std::endl;
    std::cout << "my_stack1 != my_stack2: " <<  (my_stack1 != my_stack2) << std::endl;
    std::cout << "my_stack1  < my_stack2: " <<  (my_stack1 < my_stack2) << std::endl;
    std::cout << "my_stack1  > my_stack2: " <<  (my_stack1 > my_stack2) << std::endl;
    std::cout << "my_stack1 <= my_stack2: " <<  (my_stack1 <= my_stack2) << std::endl;
    std::cout << "my_stack1 >= my_stack2: " <<  (my_stack1 >= my_stack2) << std::endl;
	std::cout << "my_stack2.empty(): " << my_stack2.empty() << std::endl;
	std::cout << "my_stack2.size(): " << my_stack2.size() << std::endl;
	std::cout << "my_stack1.push(7) " << std::endl;
	std::cout << "my_stack1.push(9) " << std::endl;
	my_stack1.push(7);
	my_stack1.push(9);
	std::cout << "my_stack1.size(): " << my_stack1.size() << std::endl;
	std::cout << "my_stack2.push(7) " << std::endl;
	std::cout << "my_stack2.push(10) " << std::endl;
	my_stack2.push(7);
	my_stack2.push(10);
    std::cout << "*******************************************************************" << std::endl;

    std::cout << "my_stack1 == my_stack2: " <<  (my_stack1 == my_stack2) << std::endl;
	std::cout << "my_stack1 != my_stack2: " <<  (my_stack1 != my_stack2) << std::endl;
	std::cout << "my_stack1  < my_stack2: " <<  (my_stack1 < my_stack2) << std::endl;
	std::cout << "my_stack1  > my_stack2: " <<  (my_stack1 > my_stack2) << std::endl;
	std::cout << "my_stack1 <= my_stack2: " <<  (my_stack1 <= my_stack2) << std::endl;
	std::cout << "my_stack1 >= my_stack2: " <<  (my_stack1 >= my_stack2) << std::endl;

	std::cout << "my_stack1.top(): " << my_stack1.top() << std::endl;
	std::cout << "my_stack1.top(): " << my_stack1.top() << std::endl;
	std::cout << "my_stack1.pop() " << std::endl;
	my_stack1.pop();
	std::cout << "my_stack1.top(): " << my_stack1.top() << std::endl;
	std::cout << "my_stack1.pop() " << std::endl;
	my_stack1.pop();
	std::cout << "my_stack1.top(): " << my_stack1.top() << std::endl;
	std::cout << "my_stack1.pop() " << std::endl;
	my_stack1.pop();
	std::cout << "my_stack1.top(): " << my_stack1.top() << std::endl;
	std::cout << "my_stack1.pop() " << std::endl;
	my_stack1.pop();
	std::cout << "my_stack1.top(): " << my_stack1.top() << std::endl;
	std::cout << "my_stack1.pop() " << std::endl;
	my_stack1.pop();
	std::cout << "my_stack1.top(): " << my_stack1.top() << std::endl;
	std::cout << "my_stack1.pop() " << std::endl;
	my_stack1.pop();

	std::cout << "my_stack2.top(): " << my_stack2.top() << std::endl;
	std::cout << "my_stack2.top(): " << my_stack2.top() << std::endl;
	std::cout << "my_stack2.pop() " << std::endl;
	my_stack2.pop();
	std::cout << "my_stack2.top(): " << my_stack2.top() << std::endl;
	std::cout << "my_stack2.pop() " << std::endl;
	my_stack2.pop();
	std::cout << "my_stack2.top(): " << my_stack2.top() << std::endl;
	std::cout << "my_stack2.pop() " << std::endl;
	my_stack2.pop();

	return (0);
}
