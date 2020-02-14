#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string readFile;
    std::string sentence;
    std::string longestWordWithE;
    std::string tempWord;
    std::cout << "name of text file: ";
    std::cin >> readFile;
    std::fstream dataFile(readFile, std::ios::in);

    int wordsWithE = 0;
    int temp = 0;

    if (!dataFile)
    {
        std::cout << "file did not open successfully" << std::endl;
        exit(1);
    }

    while (!dataFile.eof())
    { // while file hasnt ended keep going
        getline(dataFile, sentence);
        for (int i= 0; i < sentence.length(); i++)
        { // for loop that loops trough every character of the line
            if (sentence[i] == 'e' | sentence[i] == 'E')
            { // if the word has an e temp variable will increase to mark that the word is good
                temp = temp + 1;
            }

            if (sentence[i] != ' ')
            { // if there isnt a space then it keeps putting characters together to make the word
                tempWord = tempWord + sentence[i];
            }
            
            if (sentence[i] == ' ' &  temp > 0)
            { // if there is a space and it has an e then it increases wordsWithE and compares word with longest word with e
                wordsWithE ++;
                if (tempWord.length() > longestWordWithE.length())
                { // if temp word is longer than longest word it replaces longest word
                    longestWordWithE = tempWord;
                }
                
                //std::cout << tempWord << std::endl;
                tempWord = ""; // clears temp variables to restart process with fresh variables
                temp = 0;

            }else if (sentence[i] == ' ')
            { // if word doesnt have e then it empties tempword and keeps going
                tempWord = "";
            } 
        }
    }
    dataFile.close();  

    std::fstream writeFile("filestats.txt", std::ios::out | std::ios::app);
    writeFile << "number of words with e: " << wordsWithE << std::endl;
    writeFile << "longest word with e: " << longestWordWithE << std::endl;
    writeFile << "number of chars in longest word: " << longestWordWithE.length() << std::endl;

    writeFile.close();

}