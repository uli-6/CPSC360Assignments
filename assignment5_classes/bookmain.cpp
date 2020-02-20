#include <iostream>
#include "book.h"
#include <string>

int main()
{
    std::string t;
    int i;
    Book b1;

    std::cout << "enter the name of the book" << std::endl;
    std::cin >> t;
    b1.setTitle(t);
    std::cout << "enter the id of the book" << std::endl;
    std::cin >> i;
    b1.setId(i);
    std::cout << "Book title is: " << b1.getTitle() << std::endl;
    std::cout << "Book id is: " << b1.getId() << std::endl;
    b1.borrowBook();
    

    std::cout << "      BOOK2" << std::endl;
    std::string ti = "Strange Case of Dr Jekyll and Mr Hyde";
    int id = 23;
    bool st = true;
    Book b2(ti, id, st);
    std::cout << "Book title is: " << b2.getTitle() << std::endl;
    std::cout << "Book id is: " << b2.getId() << std::endl;
    b2.borrowBook();
   
    b2.returnBook();
    std::cout << "Book title is: " << b2.getTitle() << std::endl;
    std::cout << "Book id is: " << b2.getId() << std::endl;
    b2.borrowBook();
   

    std::cout << "      BOOK3" << std::endl;
    Book b3(b1);
    std::cout << "Book title is: " << b3.getTitle() << std::endl;
    std::cout << "Book id is: " << b3.getId() << std::endl;
    
    b3.borrowBook();

}