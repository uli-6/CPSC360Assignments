#include <iostream>
//include any other libraries needed

//you may want to create the following constants
const int ROWS = 15;
const int SEATS_PER_ROW = 30;
const int FRONT_ROW_COST = 50;
const int BACK_ROW_COST = 40;
const int DIVIDER = 7; //first 7 rows are "front"

//function to print out the seating wiht row numbers and column numbers
void seats(char seats[ROWS][SEATS_PER_ROW]){ 
    std::cout << "                1         2         3" << std::endl;
    std::cout << "       123456789012345678901234567890" << std::endl;
    for(int i=0; i< ROWS; i++) {
        if (i>9)
        {
            std::cout << "Row " << i << " ";
        }else{
            std::cout << "Row " << i << "  "; 
        }
        for(int j=0; j<SEATS_PER_ROW; j++) {
            std::cout << seats[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {

    //declare and initialize seating array
    char concertSeats[ROWS][SEATS_PER_ROW];
    for(int i=0; i< ROWS; i++)
        for(int j=0; j<SEATS_PER_ROW; j++)
            concertSeats[i][j]='#';

    int totalSales = 0;  //tracks total sales
    int seatSales = 0;
    int rowSales = 0;
    int ticketsToBuy;
    int seatchoiceA;
    int seatchoiceB;
    char userChoice;

    

    do {
        //displays the possible user choices
        std::cout << std::endl;
        std::cout << "(D)isplay seating chart" << std::endl;
        std::cout << "(B)uy tickets" << std::endl;
        std::cout << "(T) show total sales" << std::endl;
        std::cout << "(S)how seating info" << std::endl;
        std::cout << "(Q)uit" << std::endl;
        std::cout << std::endl;

		/*TO DO:ask user for choice here, e.g.:
			'D' - display seating chart
			'B'	- buy tickets
			'T' - show total sales
			'S' - show seating info
			'Q' - quit
			--display the choices that are available in the prompt
			--you may also want to validate that choice is valid
		*/		
 		//display choices
		std::cout << "Enter option ";
		std::cin >> userChoice;
		//validate option - check if it's a a valid choice
		//convert to uppercase using toupper
		userChoice = std::toupper(userChoice);		
		
		//here, you can use a switch statement to write the code for what needs to be done depending on the user choice
        switch (userChoice) {
            case 'D':
                seats(concertSeats);
                break;
            case 'B':
				/*TO DO: code for letting user buy tickets
					-also updates total sales and seating chart
					-up to you to implement, but the following steps may help:
					Steps:
					1. Ask how many tickets user wants to buy 
					2. For each ticket they want to purchase
						-Ask user to enter row number followed by seat number
						-Validate that the rows selected are valid (not taken)
						-If seat selection is valid, update order cost and seating chart
						-Repeat until user has purchased the number of tickets they entered
				*/

                std::cout << "How many tickets do you want to buy: ";
		        std::cin >> ticketsToBuy;

                for (int i = 0; i < ticketsToBuy; i++)
                {
                    std::cout << "Enter seat number ([row] [column]): ";
		            std::cin >> seatchoiceA >> seatchoiceB;

                    std::cout << seatchoiceA << std::endl;
                    std::cout << seatchoiceB << std::endl;
                    std::cout << concertSeats[seatchoiceA][seatchoiceB] << std::endl;

                    // if the seat is free it changes it and calculates the price depending on the row
                    if (concertSeats[seatchoiceA][seatchoiceB] == '#'){
                        concertSeats[seatchoiceA][seatchoiceB] = '*';

                        if (seatchoiceA <= DIVIDER)
                        {
                            totalSales = totalSales + FRONT_ROW_COST;
                        }else
                        {
                            totalSales = totalSales + BACK_ROW_COST;
                        }
                        seatSales += 1;
                        std::cout << "Seat successfully bought" << std::endl;
                    }else // in case a value that does not exist or a seat that has already been taken
                    {
                        std::cout << "Seat already taken or does not exist, pick another" << std::endl;
                        i = i -1;
                    }
                    
                }
                

                break;
            case 'T':
				//TO DO: code for displaying total sales

                /*
                for(int i=0; i< ROWS; i++)
                    for(int j=0; j<SEATS_PER_ROW; j++)
                        if (concertSeats[i][j] == '*'){
                            totalSales +=1;
                        }
                */

                std::cout << "Total sales: " << totalSales << std::endl;

                break;
            case 'S':
				/*TO DO: code for displaying seat info, e.g.
					-how many seats have sold
					-how many seats available for each row
					-how many seats available for the entire auditorium
				*/

                std::cout << "Venue Size: 450" << std::endl;
                std::cout << "Seats sold: " << seatSales << std::endl;
                std::cout << std::endl;
                std::cout << "Seats available: " << std::endl;
                
                // loops through all the rows to check if the seats have been sold or not
                for(int i=0; i< ROWS; i++){
                    for(int j=0; j<SEATS_PER_ROW; j++){
                        if (concertSeats[i][j] == '*'){
                            rowSales +=1;
                        }
                    }
                    // if else to make output nicer
                    if (i < 9)
                    {
                        std::cout << "Row " << i+1 << " :  " << SEATS_PER_ROW - rowSales << std::endl;
                    }else
                    {
                        std::cout << "Row " << i+1 << " : " << SEATS_PER_ROW - rowSales << std::endl;
                    }
                    
                    
                    rowSales = 0;
                }

                std::cout << "Total seats available: " << 450 - seatSales << std::endl;

                break;
            case 'Q':
				//code to quit program
                std::cout << "Thank you for using Seat Charter";
                break;
            default:
                std::cout << "Invalid choice" << std::endl; //this should never happen
        }

    } while (userChoice != 'Q');
    return 0;
}