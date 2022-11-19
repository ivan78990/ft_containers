//clang++ -Wall -Wextra -Werror -std=c++98 ft_map.cpp -o map1
#include <iostream>

#if 0
    #include <map>
	namespace ft = std;
#else

#include "tree.hpp"
#include "map.hpp"

#endif

template<class Key, class T, class Compare, class Alloc>
void    print_map(ft::map<Key, T, Compare, Alloc> m, std::string name_map)
{
    std::cout << "print " << name_map << ": ";
    if (m.size() == 0)
    {
        std::cout << "<null>" << std::endl;
        return ;
    }
    bool	is_first = true;
    for (typename ft::map<Key, T, Compare, Alloc>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        if (!is_first)
            std::cout << ", ";
        else
            is_first = false;
        std::cout << "{" << it->first << ", " << it->second << "}";
    }
    std::cout << std::endl;
}

template<class T1, class T2>
std::ostream&    operator<<(std::ostream& out, const ft::pair<T1, T2>& p)
{
    out << "{" << p.first << ", " << p.second << "}";
    return (out);
}

int	main(void)
{
	{
		
        std::cout << "[map1] Default constructor:" << std::endl;
		ft::map<int, int> map1;
        std::cout << "map1.size(): " << map1.size() << std::endl;
        std::cout << "map1.empty(): " << std::boolalpha << map1.empty() << std::endl;
        std::cout << "map1.begin() == map1.end(): " << (map1.begin() == map1.end()) << std::endl;
        map1.insert(ft::make_pair(3, 333));
        map1.insert(ft::make_pair(1, 111));
        map1.insert(ft::make_pair(2, 222));
        map1.insert(ft::make_pair(4, 444));
        map1.insert(ft::make_pair(7, 777));
        map1.insert(ft::make_pair(5, 555));
        std::cout << "map1.insert(make_pair(3, 333))" << std::endl;
        std::cout << "map1.insert(make_pair(1, 111))" << std::endl;
        std::cout << "map1.insert(make_pair(2, 222))" << std::endl;
        std::cout << "map1.insert(make_pair(4, 444))" << std::endl;
        std::cout << "map1.insert(make_pair(7, 777))" << std::endl;
        std::cout << "map1.insert(make_pair(5, 555))" << std::endl;
        std::cout << "map1.size(): " << map1.size()		<< std::endl;
        std::cout << "map1.empty(): " << std::boolalpha << map1.empty() << std::endl;
        std::cout << "map1.begin() == map1.end(): " << (map1.begin() == map1.end()) << std::endl;
		print_map(map1, "map1");

        std::cout << "**********************************************************************" << std::endl;

        std::cout << "[map2] Iterator constructor:" << std::endl;
        ft::map<int, int> map2(map1.begin(), map1.end());
        std::cout << "map2.size(): " << map2.size() << std::endl;
        std::cout << "map2.empty(): " << std::boolalpha << map2.empty() << std::endl;
		std::cout << "map2.begin() == map2.end(): " << (map2.begin() == map2.end()) << std::endl;
		print_map(map2, "map2");
		map2.insert(ft::make_pair(8, 888));
		map2.insert(ft::make_pair(9, 999));
		map2.insert(ft::make_pair(0, 0));
		std::cout << "map2.insert(make_pair(8, 888))" << std::endl;
		std::cout << "map2.insert(make_pair(9, 999))" << std::endl;
		std::cout << "map2.size(): " << map2.size() << std::endl;
		print_map(map2, "map2");
		std::cout << "map1.clear()"  << std::endl;
		map1.clear();
        std::cout << "map1.size(): " << map1.size() << std::endl;
		print_map(map1, "map1");
		print_map(map2, "map2");

		std::cout << "***************************************************************" << std::endl;

        std::cout << "[map3] Default constructor:" << std::endl;
        ft::map<int, int> map3;
        std::cout << "map3.insert(map2.begin(), map2.end())" << std::endl;
        map3.insert(map2.begin(), map2.end());
        std::cout << "map3.size(): " << map3.size() << std::endl;
        print_map(map3, "map3");
        std::cout << "map3.erase(map3.begin())" << std::endl;
        std::cout << "map3.erase(map3.begin())" << std::endl;
        std::cout << "map3.erase(map3.begin())" << std::endl;
        std::cout << "map3.erase(map3.begin())" << std::endl;
        map3.erase(map3.begin());
        map3.erase(map3.begin());
        map3.erase(map3.begin());
        map3.erase(map3.begin());
        std::cout << "map3.size(): " << map3.size() << std::endl;
        print_map(map3, "map3");
        std::cout << "map3.erase(--map3.end())" << std::endl;
        map3.erase(--map3.end());
        std::cout << "map3.size(): " << map3.size() << std::endl;
        print_map(map3, "map3");
        std::cout << "map3.erase(5): " << map3.erase(5) << std::endl;
        std::cout << "map3.erase(5): " << map3.erase(0) << std::endl;
        std::cout << "map3.size(): " << map3.size() << std::endl;
        print_map(map3, "map3");
        for (int k = 1; k  < 6; k++)
           map1.insert(ft::make_pair(k, k * 10));
        print_map(map1, "map1");
        std::cout << "map1.size(): " << map1.size() << std::endl;
        print_map(map2, "map2");
        std::cout << "map2.size(): " << map2.size() << std::endl;
        std::cout << "map1.swap(map2)" << std::endl;
        map1.swap(map2);
        print_map(map1, "map1");
        std::cout << "map1.size(): " << map1.size() << std::endl;
        print_map(map2, "map2");
        std::cout << "map2.size(): " << map2.size() << std::endl;
        std::cout << "map2.count(1): " << map2.count(1) << std::endl;
        std::cout << "map2.count(2): " << map2.count(2) << std::endl;
        std::cout << "map2.count(5): " << map2.count(5) << std::endl;
        std::cout << "map2.count(6): " << map2.count(6) << std::endl;
        std::cout << "map2.count(50): " << map2.count(50) << std::endl;

        std::cout << "********************************************************************" << std::endl;

        std::cout << "[map4] Copy constructor map4(map2):" << std::endl;
        ft::map<int, int>   map4(map2);
        print_map(map4, "map4");
        std::cout << "map4.size(): " << map4.size() << std::endl;
        for (int k = 1; k  < 10; k++)
            map4.insert(ft::make_pair(k, k * 10));
        print_map(map4, "map4");
        std::cout << "map4.size(): " << map4.size() << std::endl;

        std::cout << "map4.find(1): " << *map4.find(1) << std::endl;
        std::cout << "map4.find(5): " << *map4.find(5) << std::endl;
        std::cout << "map4.find(9): " << *map4.find(9) << std::endl;
        std::cout << "map4.at(1): " << map4.at(1) << std::endl;
        std::cout << "map4.at(9): " << map4.at(9) << std::endl;
        try
        {
            std::cout << "try map4.at(11): " << map4.at(11) << std::endl;
        }
        catch (std::out_of_range exception)
        {
            std::cout << "exception " << exception.what() << std::endl;
        }
        print_map(map4, "map4");
        std::cout << "map4[1]: " << map4[1] << std::endl;
        std::cout << "map4[6]: " << map4[6] << std::endl;
        std::cout << "map4[10]: " << map4[10] << std::endl;
        print_map(map4, "map4");
        std::cout << "map4.lower_bound(1): " << *map4.lower_bound(1) << std::endl;
        std::cout << "map4.lower_bound(5): " << *map4.lower_bound(5) << std::endl;
		std::cout << "map4.lower_bound(6): " << "{" << map4.lower_bound(6)->first << ", " << map4.lower_bound(6)->second << "}" << std::endl;
		std::cout << "map4.lower_bound(7): " << "{" << map4.lower_bound(7)->first << ", " << map4.lower_bound(7)->second << "}" << std::endl;
		std::cout << "map4.lower_bound(0): " << "{" << map4.lower_bound(0)->first << ", " << map4.lower_bound(0)->second << "}" << std::endl;
		std::cout << "map4.upper_bound(0): " << *map4.upper_bound(0) << std::endl;
		std::cout << "map4.upper_bound(1): " << *map4.upper_bound(1) << std::endl;
        std::cout << "map4.upper_bound(5): " << *map4.upper_bound(5) << std::endl;
        std::cout << "map4.equal_range(0): " << *map4.equal_range(0).first << std::endl;
		std::cout << "map4.equal_range(0): " << *map4.equal_range(0).second << std::endl;
		std::cout << "map4.equal_range(1): " << *map4.equal_range(1).first << std::endl;
		std::cout << "map4.equal_range(1): " << *map4.equal_range(1).second << std::endl;
        std::cout << "map4.equal_range(5): " << *map4.equal_range(5).first << std::endl;
		std::cout << "map4.equal_range(5): " << *map4.equal_range(5).second << std::endl;
	}
		std::cout << "*************************************************************************" << std::endl;
    {
        std::cout << "[map5] Default string constructor map5:" << std::endl;
        ft::map<std::string, std::string>   map5;
        map5["1"] = "one";
        map5["2"] = "two";
        map5["4"] = "four";
        map5["6"] = "six";
        map5["7"] = "seven";
        print_map(map5, "map5");
        std::cout << "map5.size(): " << map5.size() << std::endl;
        std::cout << "map5.lower_bound(1): " << *map5.lower_bound("1") << std::endl;
        std::cout << "map5.lower_bound(5): " << *map5.lower_bound("5") << std::endl;
        std::cout << "map5.upper_bound(1): " << *map5.upper_bound("1") << std::endl;
        std::cout << "map5.upper_bound(5): " << *map5.upper_bound("5") << std::endl;
        std::cout << "map5.equal_range(1): " << *map5.equal_range("1").first << *map5.equal_range("1").second << std::endl;
        std::cout << "map5.equal_range(5): " << *map5.equal_range("5").first << *map5.equal_range("5").second << std::endl;
        print_map(map5, "map5");
    }
	return (0);
}
