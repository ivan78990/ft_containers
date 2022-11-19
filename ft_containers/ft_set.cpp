//
// Created by Ivan Fedotov on 14.09.2022.
//
#include <iostream>
#if 0
    #include <set>
	namespace ft = std;
#else

#include "tree.hpp"
#include "set.hpp"
#endif

template<class Key, class Compare, class Alloc>
void    print_set(ft::set<Key, Compare, Alloc> m, std::string name_set)
{
    std::cout << "print " << name_set << ": ";
    if (m.size() == 0)
    {
        std::cout << "<null>" << std::endl;
        return ;
    }
    bool	is_first = true;
    for (typename ft::set<Key, Compare, Alloc>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        if (!is_first)
            std::cout << ", ";
        else
            is_first = false;
        std::cout << "{" << *it << "}";
    }
    std::cout << std::endl;
}

template<class T1, class T2>
std::ostream&    operator<<(std::ostream& out, const ft::pair<T1, T2>& p)
{
    out << "{" << p.first << "}";
    return (out);
}

int	main(void)
{
    {
        std::cout << "[set1] Default constructor:" << std::endl;
        ft::set<int> set1;
        std::cout << "set1.size(): " << set1.size() << std::endl;
        std::cout << "set1.empty(): " << std::boolalpha << set1.empty() << std::endl;
        std::cout << "set1.begin() == set1.end(): " << (set1.begin() == set1.end()) << std::endl;
        set1.insert(3);
        set1.insert(2);
        set1.insert(4);
        set1.insert(8);
        set1.insert(7);
        set1.insert(10);
        std::cout << "set1.insert(3)" << std::endl;
        std::cout << "set1.insert(2)" << std::endl;
        std::cout << "set1.insert(4)" << std::endl;
        std::cout << "set1.insert(8)" << std::endl;
        std::cout << "set1.insert(7)" << std::endl;
        std::cout << "set1.insert(10)" << std::endl;
        std::cout << "set1.size(): " << set1.size()		<< std::endl;
        std::cout << "set1.empty(): " << std::boolalpha << set1.empty() << std::endl;
        std::cout << "set1.begin() == set1.end(): " << (set1.begin() == set1.end()) << std::endl;
        print_set(set1, "set1");

        std::cout << "*******************************************************************************" << std::endl;

        std::cout << "[set2] Iterator constructor:" << std::endl;
        ft::set<int> set2(set1.begin(), set1.end());
        std::cout << "set2.size(): " << set2.size() << std::endl;
        std::cout << "set2.empty(): " << std::boolalpha << set2.empty() << std::endl;
        std::cout << "set2.begin() == set2.end(): " << (set2.begin() == set2.end()) << std::endl;
        print_set(set2, "set2");
        set2.insert(99);
        set2.insert(111);
        set2.insert(989);
        std::cout << "set2.insert(make_pair(8, 888))" << std::endl;
        std::cout << "set2.insert(make_pair(9, 999))" << std::endl;
        std::cout << "set2.size(): " << set2.size() << std::endl;
        print_set(set2, "set2");
        std::cout << "set1.clear()"  << std::endl;
        set1.clear();
        std::cout << "set1.size(): " << set1.size() << std::endl;
        print_set(set1, "set1");
        print_set(set2, "set2");

        std::cout << "****************************************************************************" << std::endl;

        std::cout << "[set3] Default constructor:" << std::endl;
        ft::set<int> set3;
        std::cout << "set3.insert(set2.begin(), set2.end())" << std::endl;
        set3.insert(set2.begin(), set2.end());
        std::cout << "set3.size(): " << set3.size() << std::endl;
        print_set(set3, "set3");
        std::cout << "set3.erase(set3.begin())" << std::endl;
        std::cout << "set3.erase(set3.begin())" << std::endl;
        std::cout << "set3.erase(set3.begin())" << std::endl;
        std::cout << "set3.erase(set3.begin())" << std::endl;
        set3.erase(set3.begin());
        set3.erase(set3.begin());
        set3.erase(set3.begin());
        set3.erase(set3.begin());
        std::cout << "set3.size(): " << set3.size() << std::endl;
        print_set(set3, "set3");
        std::cout << "set3.erase(--set3.end())" << std::endl;
        set3.erase(--set3.end());
        std::cout << "set3.size(): " << set3.size() << std::endl;
        print_set(set3, "set3");
        std::cout << "set3.erase(5): " << set3.erase(5) << std::endl;
        std::cout << "set3.erase(5): " << set3.erase(5) << std::endl;
        std::cout << "set3.size(): " << set3.size() << std::endl;
        print_set(set3, "set3");
        for (int i = 1; i < 6; i++) {
            set1.insert(i);
        }
        print_set(set1, "set1");
        std::cout << "set1.size(): " << set1.size() << std::endl;
        print_set(set2, "set2");
        std::cout << "set2.size(): " << set2.size() << std::endl;
        std::cout << "set1.swap(set2)" << std::endl;
        set1.swap(set2);
        print_set(set1, "set1");
        std::cout << "set1.size(): " << set1.size() << std::endl;
        print_set(set2, "set2");
        std::cout << "set2.size(): " << set2.size() << std::endl;
        std::cout << "set2.count(1): " << set2.count(1) << std::endl;
        std::cout << "set2.count(2): " << set2.count(2) << std::endl;
        std::cout << "set2.count(5): " << set2.count(5) << std::endl;
        std::cout << "set2.count(6): " << set2.count(6) << std::endl;
        std::cout << "set2.count(50): " << set2.count(50) << std::endl;

        std::cout << "********************************************************************************" << std::endl;

        std::cout << "[set4] Copy constructor set4(set2):" << std::endl;
        ft::set<int>   set4(set2);
        print_set(set4, "set4");
        std::cout << "set4.size(): " << set4.size() << std::endl;
        for (int i = 10; i  < 20; i++)
            set4.insert(i);
        print_set(set4, "set4");
        std::cout << "set4.size(): " << set4.size() << std::endl;

        std::cout << "set4.find(1): " << *set4.find(1) << std::endl;
        std::cout << "set4.find(5): " << *set4.find(5) << std::endl;
        std::cout << "set4.find(9): " << *set4.find(9) << std::endl;
        print_set(set4, "set4");

        std::cout << "set4.lower_bound(1): " << *set4.lower_bound(1) << std::endl;
        std::cout << "set4.lower_bound(5): " << *set4.lower_bound(5) << std::endl;
        std::cout << "set4.lower_bound(6): " << "{" << *set4.lower_bound(6) << "}" << std::endl;
        std::cout << "set4.lower_bound(7): " << "{" << *set4.lower_bound(7) <<  "}" << std::endl;
        std::cout << "set4.lower_bound(0): " << "{" << *set4.lower_bound(0) << "}" << std::endl;
        std::cout << "set4.upper_bound(0): " << *set4.upper_bound(0) << std::endl;
        std::cout << "set4.upper_bound(1): " << *set4.upper_bound(1) << std::endl;
        std::cout << "set4.upper_bound(5): " << *set4.upper_bound(5) << std::endl;
        std::cout << "set4.equal_range(0): " << *set4.equal_range(0).first << std::endl;
        std::cout << "set4.equal_range(0): " << *set4.equal_range(0).second << std::endl;
        std::cout << "set4.equal_range(1): " << *set4.equal_range(1).first << std::endl;
        std::cout << "set4.equal_range(1): " << *set4.equal_range(1).second << std::endl;
        std::cout << "set4.equal_range(5): " << *set4.equal_range(5).first << std::endl;
        std::cout << "set4.equal_range(5): " << *set4.equal_range(5).second << std::endl;
    }
    std::cout << "********************************************************************************" << std::endl;
    {
        std::cout << "[set5] Default string constructor set5:" << std::endl;
        ft::set<std::string>   set5;
        set5.insert("one");
        set5.insert("one");
        set5.insert("two");
        set5.insert("three");
        set5.insert("four");
        set5.insert("five");

        print_set(set5, "set5");
        std::cout << "set5.size(): " << set5.size() << std::endl;
        std::cout << "set5.lower_bound(1): " << *set5.lower_bound("one") << std::endl;
        std::cout << "set5.lower_bound(5): " << *set5.lower_bound("two") << std::endl;
        std::cout << "set5.upper_bound(1): " << *set5.upper_bound("three") << std::endl;
        std::cout << "set5.upper_bound(5): " << *set5.upper_bound("four") << std::endl;
        std::cout << "set5.equal_range(1): " << *set5.equal_range("five").first << " " << *set5.equal_range("five").second << std::endl;
        std::cout << "set5.equal_range(5): " << *set5.equal_range("one").first << " " << *set5.equal_range("one").second << std::endl;
        print_set(set5, "set5");
    }
    return (0);
}
