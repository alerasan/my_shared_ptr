#include <iostream>
#include "Inc/my_shared_pointer.h"

class Square
{
public:
    int length, width;
    Square() : length(0), width(0)
    {
    }
};
int main()
{
    my_shared_ptr<Square> obj;
    std::cout << "Empty obj count: " << obj.get_count() << std::endl;

    my_shared_ptr<Square> square1(new Square());
    std::cout << "Creating obj1, counter is: " << square1.get_count() << std::endl;
    
    my_shared_ptr<Square> square2(square1);
    std::cout << "Copied obj1 to obj2" << std::endl;
    my_shared_ptr<Square> square3(square1);
    std::cout << "Copied obj1 to obj3" << std::endl;
    
    std::cout << "obj1 counter: " << square1.get_count() << std::endl;
    std::cout << "obj2 counter: " << square2.get_count() << std::endl;
    std::cout << "obj3 counter: " << square3.get_count() << std::endl;

    square1.reset(new Square());

    std::cout << "Resetting obj1" << std::endl;
    std::cout << "obj1 counter: " << square1.get_count() << std::endl;
    std::cout << "obj2 counter: " << square2.get_count() << std::endl;
    std::cout << "obj3 counter: " << square3.get_count() << std::endl;

    return 0;
}