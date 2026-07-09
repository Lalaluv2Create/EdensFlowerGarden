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
		"Empty", "Empty", "Empty", "Empty", "Empty"
	};
	
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
			cout << i+1 << ". " << garden[i] << endl;
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
		
		if (flowerChoice == '1'){//if player choose daisy, go to garden array,
			garden[gardenSpot - 1] = "Daisy";// take player spot number, subtract 1 & store daisy there 
			cout << "You planted a Daisy! " << endl;
		}
		else if (flowerChoice == '2'){
			garden[gardenSpot - 1] = "Tulip";
			cout << "You planted a Tulip! " << endl;
		}
		else if (flowerChoice == '3'){
			garden[gardenSpot - 1] = "Rose";
			cout << "You planted a Rose! " << endl;
		}
		else if (flowerChoice == '4'){
			garden[gardenSpot - 1] = "Bellflower";
			cout << "You planted a Bellflower! " << endl;
		}
		else if (flowerChoice == '5'){
			garden[gardenSpot - 1] = "Sunflower";
			cout << "You planted a Sunflower! " << endl;
		}
		else if (flowerChoice == '6'){
			garden[gardenSpot - 1] = "Lavender";
			cout << "You planted a Lavender! " << endl;
		}
		else if (flowerChoice == '7'){
			garden[gardenSpot - 1] = "Hibiscus";
			cout << "You planted a Hibiscus! " << endl;
		}
	}
	
	else if(choice == '3'){ //option 3
		cout << "Eden goes to sleep... " << endl;
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