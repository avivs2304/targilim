#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "main.h"
const int SHELF=11;

void PrintOptions(Drink* stock[SHELF]){
	printf("(0)     list options\n"
		  "(1)	   Heineken\n"
		  "(2)	   Goldstar\n"
		  "(3)	   Maccabi\n"
		  "(4)	   Tuborg\n"
		  "(5)	   %s\n"
		  "(6)	   %s\n"
		  "(7)	   %s\n"
		  "(8)	   %s\n"
		  "(9)	   %s\n"
		  "(10)	   %s\n"
		  "(11)	   %s\n"
		  "(99)	   How did you prepare my last drink?\n"
		  "(100)   Leave the bar\n",stock[4]->getName(),stock[5]->getName(),stock[6]->getName(),
		  stock[7]->getName(),stock[8]->getName(),stock[9]->getName(),stock[10]->getName());
}
int main(int argc, char* argv[]){
	Drink *stock[SHELF];
	stock[0] = new Beer("Heineken");
	stock[1] = new Beer("Goldstar");
	stock[2] = new Beer("Maccabi");
	stock[3] = new Beer("Tuborg");
	stock[4] = new CarmelAmerledRizling(1986);
	stock[5] = new GolanSmadar(1989);
	stock[6] = new YardenHarHermonRed(1994);
	stock[7] = new ChadeauMargot(1997);
	stock[8] = new Kyanti(1997);
	stock[9] = new YardenKevrnaSovinion(1997);
	stock[10] = new YardenShradona(1997);
	Drink* prev_drink = stock[0];
	int i=0;
	while(i!=100){
		if(i!=0 && i!=99){
			printf("One %s coming up, sir.\n", stock[i-1]->getName());
			prev_drink=stock[i-1];
		}
		std::cout << "What can I get you, sir? (0 - list options) " << std::endl << std::endl;
		std::cin >> i;
		if(i==0){
			 PrintOptions(stock);
			 std::cin >> i;
		}
		if(i==99){
			printf("You ordered %s.\n", prev_drink->getName());
			prev_drink->prepare();
		}
		if(i==100){
			std::cout << "Bar is closed. Good night." << std::endl;
			break;
		}
	}
	return 0;
}
