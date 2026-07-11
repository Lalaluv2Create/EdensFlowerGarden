//Eden's Flower Garden
#include <iostream>
#include <string>

using namespace std;
int main(){
	
	cout << "Welcome to Eden's Flower Garden!" << endl;
	cout << endl;
	cout << "Eden the Frog needs your help with her garden!" << endl;
	int coins = 10;
	cout << endl;
	cout << "Coins " << coins << endl;
	
	cout << "Press enter to start " << endl;
	//if player hits enter the game starts
	cin.get();
	
	cout << "The frog wakes up! " << endl;

	char choice;
	string garden [5] = {
		"Empty", "Empty", "Empty", "Empty", "Empty" };
	int growthStage[5] = {
		0,0,0,0,0 };
	int day = 1; //day counter
	bool playing = true; //bool = true (yes) OR false (no)
	
	while (playing){
	cout << endl; //add options for what Eden does
	cout << "What should Eden do first? " << endl;
	cout << "1. Look at garden" << endl;
	cout << "2. Plant flower seeds " << endl;
	cout << "3. Sleep " << endl;
	cout << "4. Quit " << endl;
	
		
	cout << "What should Eden do?" << endl;
	cin >> choice;
	
	if(choice == '1'){//option 1
		cout << endl;
		cout << " ---- Eden's Garden ----" << endl;
		
		for(int i = 0; i < 5; i++){
			cout << i+1 << ". " << garden[i];
			if(growthStage[i] == 1){ //Day 1
				cout << " (Seed)";
			}
			else if(growthStage[i] == 2){ //Day 2
				cout << " (Sprout)";
			}
			else if(growthStage[i] >= 3){ //Day 3
				cout << " (Bloomed)";
			}
			cout << endl;
		}
	}
	else if(choice == '2'){//option 2
		cout << "What flower would you like to plant? " << endl;
		
		char flowerChoice;		
		cout << "1. Daisy " << endl;
		cout << "2. Tulip " << endl;
		cout << "3. Rose " << endl;
		cout << "4. Bellflower " << endl;
		cout << "5. Sunflower " << endl;
		cout << "6. Lavender " << endl;
		cout << "7. Hibiscus " << endl;
		cin >> flowerChoice; 
		
		int gardenSpot;
		cout << "Which garden spot? (1-5)" << endl;
		cin >> gardenSpot;
		
	//prevent replacing already existing flowers 
	if(garden[gardenSpot - 1] == "Empty"){
		
		if (flowerChoice == '1'){//if player choose daisy, go to garden array,
			garden[gardenSpot - 1] = "Daisy";// take player spot number, subtract 1 & store daisy there 
			growthStage[gardenSpot - 1] = 1;
			cout << "You planted a Daisy seed! " << endl;
		}
		else if (flowerChoice == '2'){
			garden[gardenSpot - 1] = "Tulip";
			growthStage[gardenSpot - 1] = 1;
			cout << "You planted a Tulip seed! " << endl;
		}
		else if (flowerChoice == '3'){
			garden[gardenSpot - 1] = "Rose";
			growthStage[gardenSpot - 1] = 1;
			cout << "You planted a Rose seed! " << endl;
		}
		else if (flowerChoice == '4'){
			garden[gardenSpot - 1] = "Bellflower";
			growthStage[gardenSpot - 1] = 1;
			cout << "You planted a Bellflower seed! " << endl;
		}
		else if (flowerChoice == '5'){
			garden[gardenSpot - 1] = "Sunflower";
			growthStage[gardenSpot - 1] = 1;
			cout << "You planted a Sunflower seed! " << endl;
		}
		else if (flowerChoice == '6'){
			garden[gardenSpot - 1] = "Lavender";
			growthStage[gardenSpot - 1] = 1;
			cout << "You planted a Lavender seed! " << endl;
		}
		else if (flowerChoice == '7'){
			garden[gardenSpot - 1] = "Hibiscus";
			growthStage[gardenSpot - 1] = 1;
			cout << "You planted a Hibiscus seed! " << endl;
		}
		else{
			cout << "That is not a flower option!" << endl;
		}
	}
	else{ 
		cout << "There is already a flower here!" << endl;
	}
	}
	
	
	else if(choice == '3'){ //option 3
		cout << "Eden goes to sleep... " << endl;
		day++;
		
		for(int i = 0; i < 5; i++){
			if(growthStage[i] > 0){
				growthStage[i]++;
			}
		}
		cout << "Day " << day << " begins!" << endl;
	}
	
	else if (choice == '4'){ //option 4
		cout << "Thanks for helping Eden's Garden!" << endl;
		playing = false;
	}
	else{
		cout << "That's not a valid choice!." << endl;
	}
	
	}
	return 0;
}