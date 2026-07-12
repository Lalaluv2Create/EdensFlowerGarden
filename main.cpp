//Eden's Flower Garden
#include <iostream>
#include <string>

using namespace std;

void lookAtGarden(string garden[], int growthStage[]){ //choice 1
	
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

void plantFlower(string garden[], int growthStage[]){ //choice 2
	
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
			cout << "(You planted a Daisy seed! )" << endl;
			cout << "I hope its pretty Ribbit! " << endl;
		}
		else if (flowerChoice == '2'){
			garden[gardenSpot - 1] = "Tulip";
			growthStage[gardenSpot - 1] = 1;
			cout << "(You planted a Tulip seed!) " << endl;
			cout << "Tulip's are my favorite! Or was it Bellflowers? " << endl;
		}
		else if (flowerChoice == '3'){
			garden[gardenSpot - 1] = "Rose";
			growthStage[gardenSpot - 1] = 1;
			cout << "(You planted a Rose seed!) " << endl;
			cout << "You chose a rose, I sure hope it grows!" << endl;
		}
		else if (flowerChoice == '4'){
			garden[gardenSpot - 1] = "Bellflower";
			growthStage[gardenSpot - 1] = 1;
			cout << "(You planted a Bellflower seed!) " << endl;
			cout << "Why is it called a bellflower if I cant hear any bells?" << endl;
		}
		else if (flowerChoice == '5'){
			garden[gardenSpot - 1] = "Sunflower";
			growthStage[gardenSpot - 1] = 1;
			cout << "(You planted a Sunflower seed!) " << endl;
			cout << "The sun must have its favorite flower Ribbit! " << endl;
		}
		else if (flowerChoice == '6'){
			garden[gardenSpot - 1] = "Lavender";
			growthStage[gardenSpot - 1] = 1;
			cout << "(You planted a Lavender seed!) " << endl;
			cout << "Lavender is my favorite color! " << endl;
		}
		else if (flowerChoice == '7'){
			garden[gardenSpot - 1] = "Hibiscus";
			growthStage[gardenSpot - 1] = 1;
			cout << "(You planted a Hibiscus seed! )" << endl;
			cout << "Hibiscus flowers remind me of summer! " << endl;
		}
		else{
			cout << "Aw silly! That's not a flower choice!" << endl;
		}
	}
	else{ 
		cout << "Ribbit! Oh no! There is already a flower here! Can you place it somewhere else " << endl;
	}
}

void harvestFlower(string garden[], int growthStage[], int &coins){//choice 3
	int gardenSpot;
	
	cout << "Which garden spot would you like to harvest? (1-5)" << endl;
	cin >> gardenSpot;
	int flowerValue = 0; 
	
	if(growthStage[gardenSpot - 1] >= 3){
		cout << "You harvested a " << garden[gardenSpot - 1] << "!" << endl;
		
		if(garden[gardenSpot - 1] == "Daisy"){
			flowerValue = 3;
		}
		else if(garden[gardenSpot - 1] == "Tulip"){
			flowerValue = 5;
		}
		else if(garden[gardenSpot - 1] == "Rose"){
			flowerValue = 8;
		}
		else if(garden[gardenSpot - 1] == "Bellflower"){
			flowerValue = 6;
		}
		else if(garden[gardenSpot - 1] == "Sunflower"){
			flowerValue = 10;
		}
		else if(garden[gardenSpot - 1] == "Lavender"){
			flowerValue = 7;
		}
		else if(garden[gardenSpot - 1] == "Hibiscus"){
			flowerValue = 9;
		}
		
		garden[gardenSpot - 1] = "Empty"; //after picking, return garden spot to empty
		growthStage[gardenSpot - 1] = 0;
		
		coins += flowerValue; //increase coins as a reward for harvesting 
		cout << "Ribbit! We earned " << flowerValue << " beautiful coins!" << endl;
		cout << "Coins: " << coins << endl;
	}
	else{
		cout << "Oh Ribbit! That flower isn't ready to harvest yet... " << endl;
	}
}

void sleep(int growthStage[], int &day){//choice 4

	cout << "I'm feeling so sleepy. " << endl;
	cout << "Hopefully tomorrow is an even better day for our garden! " << endl;
		day++; //increases day after sleeping 
		
		for(int i = 0; i < 5; i++){
			if(growthStage[i] > 0){
				growthStage[i]++;
			}
		}
		cout << "Day " << day << " begins!" << endl;
}

int main(){
	
	cout << "Welcome to Eden's Flower Garden!" << endl;
	cout << endl;
	cout << "Ribbit! My name is Eden the Frog! " << endl;
	cout << "Can you help me with my garden?" << endl;
	int coins = 10;
	cout << endl;
	cout << "Coins " << coins << endl;
	
	cout << "Press enter to start " << endl;
	//if player hits enter the game starts
	cin.get();
	
	cout << "(Eden wakes up!)" << endl;

	char choice;
	string garden [5] = {
		"Empty", "Empty", "Empty", "Empty", "Empty" };
	int growthStage[5] = {
		0,0,0,0,0 };
	int day = 1; //day counter
	bool playing = true; //bool = true (yes) OR false (no)
	
	while(playing){
	cout << "-----------------"<< endl;
	cout << "Day: " << day << endl; //updates day and coins after sleeping
	cout << "Coins: " << coins << endl;
	cout << "-----------------"<< endl;
	cout << endl; //add options for what Eden does

	cout << "Hi little frog! What should we work on today? " << endl;
	cout << "1. Look at garden" << endl;
	cout << "2. Plant flower seeds " << endl;
	cout << "3. Harvest flowers " << endl;
	cout << "4. Sleep " << endl;
	cout << "5. Quit " << endl;
	cout << endl; 
	cout << "(What should Eden do?)" << endl;
	cin >> choice;
	
	if(choice == '1'){//option 1
		lookAtGarden(garden,growthStage);
	}
	else if(choice == '2'){//option 2
		plantFlower(garden,growthStage);
	}
	
	else if(choice == '3'){//option 3
		harvestFlower(garden, growthStage, coins);
	}
	
	else if(choice == '4'){ //option 4
		sleep(growthStage, day);
	}
	
	else if (choice == '5'){ //option 5
		cout << "Thanks for me with my garden! Come back soon, Ribbit!" << endl;
		playing = false;
	}
	else{
		cout << "That's not a valid choice!." << endl;
	}
	}
	
	return 0;
}