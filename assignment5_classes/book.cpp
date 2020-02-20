#include <iostream>
#include "book.h"
#include <random>
#include <string>


Book::Book()
{
    srand(time(0));
    title = "No Title";
    id = (rand() % 1000) + 1;
    checkedOut = false;
}

Book::Book(std::string title, int id)
{
    title = title;
    id = id;
    checkedOut = false;
}

Book::Book(std::string t, int i, bool cout)
{
    title = t;
    id = i;
    checkedOut = cout;
}

Book::Book(const Book &obj)
{
    title = obj.title;
    id = obj.id;
    checkedOut = obj.checkedOut;
}

std::string Book::getTitle() const
{
    return title;
}

int Book::getId() const
{
    return id;
}

void Book::setTitle(std::string t)
{
    title = t;
}

void Book::setId(int i)
{
    id = i;
}

bool Book::isCheckedOut()
{
    return checkedOut;
}

void Book::borrowBook()
{
    if (checkedOut)
    {
        std::cout << "Book is already checked out" << std::endl;
    }else
    {
        std::cout << "Book is available, checking out now" << std::endl;
        checkedOut = true;
    }
    
}

void Book::returnBook()
{
    std::cout << "returning book" << std::endl;
    checkedOut = false;
}