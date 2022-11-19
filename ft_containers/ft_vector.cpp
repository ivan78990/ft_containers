#include <iostream>

#if 0
    #include <vector>
	namespace ft = std;
#else
#include "vector.hpp"
#endif

template<typename T, typename Alloc>
void	print_vector(ft::vector<T, Alloc> v, std::string name_vector)
{
	std::cout << "print " << name_vector << ": ";
	if (v.size() == 0)
	{
		std::cout << "<null>" << std::endl;
		return ;
	}
	bool	is_first = true;
	for (typename ft::vector<T, Alloc>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		if (!is_first)
			std::cout << ", ";
		else
			is_first = false;
		std::cout << "{" << *it << "}";
	}
	std::cout << std::endl;
}

int main()
{
	{
        
		std::cout << "[my_v1] Default constructor:" << std::endl;
		ft::vector<int> my_v1;

		std::cout << "my_v1.empty(): " << std::boolalpha << my_v1.empty()<< std::endl;
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.capacity(): " << my_v1.capacity()<< std::endl;
		std::cout << "my_v1.push_back(1)" << std::endl;
		my_v1.push_back(1);
		std::cout << "my_v1.push_back(2)" << std::endl;
		my_v1.push_back(2);
		std::cout << "my_v1.push_back(3)" << std::endl;
		my_v1.push_back(3);
		std::cout << "my_v1.empty(): " << std::boolalpha << my_v1.empty()<< std::endl;
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.capacity(): " << my_v1.capacity()<< std::endl;
		print_vector(my_v1, "my_v1");
		std::cout << "my_v1.resize(3)" << std::endl;
		my_v1.resize(3);
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.capacity(): " << my_v1.capacity()<< std::endl;
		print_vector(my_v1, "my_v1");
		std::cout << "my_v1.resize(4)" << std::endl;
		my_v1.resize(4);
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.capacity(): " << my_v1.capacity()<< std::endl;
		print_vector(my_v1, "my_v1");
		std::cout << "my_v1.resize(10)" << std::endl;
		my_v1.resize(10);
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.capacity(): " << my_v1.capacity()<< std::endl;
		print_vector(my_v1, "my_v1");
		std::cout << "my_v1.resize(3)" << std::endl;
		my_v1.resize(3);
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.capacity(): " << my_v1.capacity()<< std::endl;
		print_vector(my_v1, "my_v1");
		std::cout << "my_v1.pop_back()" << std::endl;
		std::cout << "my_v1.pop_back()" << std::endl;
		my_v1.pop_back();
		my_v1.pop_back();
		my_v1.pop_back();
		print_vector(my_v1, "my_v1");
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.capacity(): " << my_v1.capacity()<< std::endl;
		std::cout << "my_v1.insert(my_v1.begin(), 3)" << std::endl;
		std::cout << "my_v1.insert(my_v1.begin(), 2)" << std::endl;
		std::cout << "my_v1.insert(my_v1.begin(), 1)" << std::endl;
		std::cout << "my_v1.insert(my_v1.begin(), 0)" << std::endl;
		my_v1.insert(my_v1.begin(), 3);
		my_v1.insert(my_v1.begin(), 2);
		my_v1.insert(my_v1.begin(), 1);
		my_v1.insert(my_v1.begin(), 0);
		print_vector(my_v1, "my_v1");
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.resize(7)" << std::endl;
		my_v1.resize(7);
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.capacity(): " << my_v1.capacity()<< std::endl;
		std::cout << "my_v1[4] = 4" << std::endl;
		std::cout << "my_v1[5] = 5" << std::endl;
		std::cout << "my_v1[6] = 6" << std::endl;
		my_v1[4] = 4;
		my_v1[5] = 5;
		my_v1[6] = 6;
		print_vector(my_v1, "my_v1");
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;

		std::cout << "****************************************************************" << std::endl;

		std::cout << "[my_v2] Copy constructor my_v2(my_v1):" << std::endl;
		ft::vector<int> my_v2(my_v1);
		print_vector(my_v2, "my_v2");
		std::cout << "my_v2.size(): " << my_v2.size()<< std::endl;
		std::cout << "my_v2.capacity(): " << my_v2.capacity()<< std::endl;
		std::cout << "my_v1.clear()" << std::endl;
		my_v1.clear();
		std::cout << "my_v2.insert(my_v2.end(), 7)" << std::endl;
		my_v2.insert(my_v2.end(), 7);
		print_vector(my_v1, "my_v1");
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.capacity(): " << my_v1.capacity()<< std::endl;
		std::cout << "my_v2.size(): " << my_v2.size()<< std::endl;
		std::cout << "my_v2.capacity(): " << my_v2.capacity()<< std::endl;
		std::cout << "my_v1 = my_v2" << std::endl;
		my_v1 = my_v2;
		std::cout << "my_v1.size(): " << my_v1.size()<< std::endl;
		std::cout << "my_v1.capacity(): " << my_v1.capacity()<< std::endl;
		std::cout << "my_v2.size(): " << my_v2.size()<< std::endl;
		std::cout << "my_v2.capacity(): " << my_v2.capacity()<< std::endl;
		std::cout << "my_v2.front(): " << my_v1.front()<< std::endl;
		std::cout << "my_v2.back(): " << my_v1.back()<< std::endl;
		std::cout << "my_v2.at(0): " << my_v1.at(0)<< std::endl;
		std::cout << "my_v2.at(5): " << my_v1.at(5)<< std::endl;
		std::cout << "my_v2[0]: " << my_v1[0] << std::endl;
		std::cout << "my_v2[6]: " << my_v1[6] << std::endl;
		try
		{
			std::cout << "try my_v2.at(10): " << my_v2.at(10) << std::endl;
		}
		catch (std::out_of_range excep)
		{
			std::cout << excep.what() << std::endl;
		}
		try
		{
			std::cout << "try my_v2.at(-1): " << my_v2.at(-1) << std::endl;
		}
		catch (std::out_of_range excep)
		{
			std::cout << excep.what() << std::endl;
		}
		std::cout << "my_v2.insert(my_v2.begin() + 2, 3, 7)" << std::endl;
		my_v2.insert(my_v2.begin() + 2, 3, 7);
		print_vector(my_v2, "my_v2");
		std::cout << "my_v2.size(): " << my_v2.size()<< std::endl;
		std::cout << "my_v2.capacity(): " << my_v2.capacity()<< std::endl;
		std::cout << "my_v2.erase(my_v2.begin() + 2)" << std::endl;
		my_v2.erase(my_v2.begin() + 2);
		std::cout << "my_v2.erase(my_v2.end() - 8)" << std::endl;
		my_v2.erase(my_v2.end() - 8);
		std::cout << "my_v2.erase(--my_v2.end())" << std::endl;
		my_v2.erase(--my_v2.end());
		print_vector(my_v2, "my_v2");
		std::cout << "my_v2.erase(my_v2.begin() + 2, my_v2.end() - 2)" << std::endl;
		my_v2.erase(my_v2.begin() + 2, my_v2.end() - 2);
		print_vector(my_v2, "my_v2");
		std::cout << "my_v2.erase(my_v2.begin(), my_v2.end())" << std::endl;
		my_v2.erase(my_v2.begin(), my_v2.end());
		print_vector(my_v2, "my_v2");
		std::cout << "my_v2.size(): " << my_v2.size()<< std::endl;
		std::cout << "my_v2.capacity(): " << my_v2.capacity()<< std::endl;
		print_vector(my_v1, "my_v1");
		print_vector(my_v2, "my_v2");
		my_v1.swap(my_v2);
		print_vector(my_v1, "my_v1");
		print_vector(my_v2, "my_v2");
	}
	std::cout << "****************************************************************" << std::endl;
	{
		ft::vector<int>	v;
	}
	{
		std::cout << "[my_v3] Default constructor (string):" << std::endl;
		ft::vector<std::string>	my_v3;
		std::cout << "size = " << my_v3.size() << "  cap = " << my_v3.capacity() << std::endl;
		my_v3.resize(1, "#");
		std::cout << "size = " << my_v3.size() << "  cap = " << my_v3.capacity() << std::endl;
		my_v3.resize(2, "$");
		std::cout << "size = " << my_v3.size() << "  cap = " << my_v3.capacity() << std::endl;
		my_v3.resize(3, "$");
		std::cout << "size = " << my_v3.size() << "  cap = " << my_v3.capacity() << std::endl;
		my_v3.push_back("*");
		std::cout << "size = " << my_v3.size() << "  cap = " << my_v3.capacity() << std::endl;
		my_v3.push_back("*");
		std::cout << "size = " << my_v3.size() << "  cap = " << my_v3.capacity() << std::endl;
		my_v3.resize(7, "%");
		std::cout << "size = " << my_v3.size() << "  cap = " << my_v3.capacity() << std::endl;
		for (size_t k = 0; k < my_v3.size(); k++)
			std::cout << my_v3[k] << " ";
		std::cout << std::endl;
		my_v3.resize(0);
		std::cout << "size = " << my_v3.size() << "  cap = " << my_v3.capacity() << std::endl;

		for (size_t k = 0; k < my_v3.size(); k++)
			std::cout << my_v3[k] << " ";
		std::cout << std::endl;
	}
	std::cout << "****************************************************************" << std::endl;
	{
		std::cout << "[my_v4] iterators:" << std::endl;
		ft::vector<int>	my_v4;
		for (int k = 1; k < 10; k++)
			my_v4.push_back(k);
		ft::vector<int>::iterator it = my_v4.begin();
		ft::vector<int>::reverse_iterator it_r = my_v4.rbegin();

		std::cout << "direct print" << std::endl;
		bool	is_first = true;
		for (size_t k = 0; k < my_v4.size(); k++)
		{
			if (!is_first)
				std::cout << ", ";
			else
				is_first = false;
			std::cout << it[k];
		}
		std::cout << std::endl;
		is_first = true;
		for (ft::vector<int>::iterator iter = my_v4.begin(); iter < my_v4.end(); iter++)
		{
			if (!is_first)
				std::cout << ", ";
			else
				is_first = false;
			std::cout << *iter;
		}
		std::cout << std::endl;
		is_first = true;
		for (ft::vector<int>::iterator iter = my_v4.begin(); iter < my_v4.end(); ++iter)
		{
			if (!is_first)
				std::cout << ", ";
			else
				is_first = false;
			std::cout << *iter;
		}
		std::cout << std::endl;
		is_first = true;
		for (ft::vector<int>::iterator iter = my_v4.end() - 1; iter != my_v4.begin(); iter--)
		{
			if (!is_first)
				std::cout << ", ";
			else
				is_first = false;
			std::cout << *iter;
		}
		std::cout << std::endl;
		is_first = true;
		for (ft::vector<int>::iterator iter = my_v4.end() - 1; iter != my_v4.begin(); --iter)
		{
			if (!is_first)
				std::cout << ", ";
			else
				is_first = false;
			std::cout << *iter;
		}
		std::cout << std::endl;
		std::cout << "my_v4.end() - my_v4.begin() = " << my_v4.end() - my_v4.begin() << std::endl;
		std::cout << "reverse print" << std::endl;
		is_first = true;
		for (size_t k = 0; k < my_v4.size(); k++)
		{
			if (!is_first)
				std::cout << ", ";
			else
				is_first = false;
			std::cout << it_r[k];
		}
		std::cout << std::endl;
		is_first = true;
		for (ft::vector<int>::reverse_iterator iter = my_v4.rbegin(); iter != my_v4.rend(); iter++)
		{
			if (!is_first)
				std::cout << ", ";
			else
				is_first = false;
			std::cout << *iter;
		}
		std::cout << std::endl;
		is_first = true;
		for (ft::vector<int>::reverse_iterator iter = my_v4.rbegin(); iter != my_v4.rend(); ++iter)
		{
			if (!is_first)
				std::cout << ", ";
			else
				is_first = false;
			std::cout << *iter;
		}
		std::cout << std::endl;
		is_first = true;
		for (ft::vector<int>::reverse_iterator iter = my_v4.rend() - 1; iter != my_v4.rbegin(); iter--)
		{
			if (!is_first)
				std::cout << ", ";
			else
				is_first = false;
			std::cout << *iter;
		}
		std::cout << std::endl;
		is_first = true;
		for (ft::vector<int>::reverse_iterator iter = my_v4.rend() - 1; iter != my_v4.rbegin(); --iter)
		{
			if (!is_first)
				std::cout << ", ";
			else
				is_first = false;
			std::cout << *iter;
		}
		std::cout << std::endl;
		std::cout << "my_v4.rend() - my_v4.rbegin() = " << my_v4.rend() - my_v4.rbegin() << std::endl;
	}
	return (0);
}
