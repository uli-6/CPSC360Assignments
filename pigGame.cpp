#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void scores(int playerScore, int cpuScore){
    std::cout << "==============" << std::endl;
    std::cout << "Player score: " << playerScore << std::endl;            
    std::cout << "CPU score: " << cpuScore << std::endl;
    std::cout << "==============" << std::endl;
}

int main() {

    srand(time(0));
    
    int cpuScore = 0, playerScore = 0, currentPlayer;
    int roll = 0, turnScore;
    char choice;

    std::cout << "Welcome to the Pig Game" << std::endl;
    currentPlayer = rand() % 2;

    if (currentPlayer == 0) 
        std::cout << "You will be player 1" << std::endl;
    else
        std::cout << "CPU be player 1" << std::endl;
    
    while (cpuScore < 100 and playerScore < 100)
    {
        if (currentPlayer == 0) {
            turnScore = 0;
            std::cout << "Players turn" << std::endl;
            scores(playerScore, cpuScore); 

            while (roll != 1)
            {
                roll = rand() % 6 + 1;
                std::cout << "Roll: " << roll << std::endl;
                if (roll == 1){
                    roll = 0;
                    break;
                }
                turnScore = turnScore + roll;
                std::cout << "Turn score: " << turnScore << std::endl;
                std::cout << "Roll or Hold (R):" << std::endl;
                std::cin >> choice; 

                if (choice != 'R'){
                    playerScore = playerScore + turnScore;
                    break;
                }
                

                
            }
            

            currentPlayer = 1;
            continue;
        }else
        {
            turnScore = 0;
            std::cout << "CPUs turn" << std::endl;
            scores(playerScore, cpuScore);  

            while (roll != 1)
            {
                roll = rand() % 6 +1;
                std::cout << "Roll: " << roll << std::endl;
                
                if (roll != 1){
                    turnScore = turnScore + roll;
                    std::cout << "Turn score: " << turnScore << std::endl;
                }
                else
                {
                    roll = 0;
                    break;
                }

                if (turnScore >= 20){
                    cpuScore = cpuScore + turnScore;
                    break;
                }
                
            }
            

            currentPlayer = 0;
        }
   
    }

    if (playerScore >= 100){
        std::cout << "You Won" << std::endl;
    }else
    {
        std::cout << "CPU Won" << std::endl;
    }
    

}