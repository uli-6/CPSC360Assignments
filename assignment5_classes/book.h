#include <string>


class Book
{
private:
    std::string title;
    int id;
    bool checkedOut;    
public:
    //getters
    std::string getTitle() const;
    int getId() const;
    

    //setters
    void setTitle(std::string title);
    void setId(int id);

    bool isCheckedOut();
    void borrowBook();
    void returnBook();

    //constructors
    Book();
    Book(std::string title, int id);
    Book(std::string title, int id, bool checkedOut);
    Book(const Book &obj);
    
};