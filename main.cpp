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

void plantFlower(string garden[], int growthStage[], int seedInventory[], string flowerNames[]){ //choice 2
	
	cout << "What flower would you like to plant? " << endl;
		
	char flowerChoice;		
	for(int i = 0; i < 7; i++){
		cout << i + 1 << ". " << flowerNames[i] << endl;
	}
	cin >> flowerChoice; 
	//check for error
	if(flowerChoice < '1' || flowerChoice > '7'){
		cout << "Aww silly! That's not a flower choice! " << endl;
		return;
	}
	int flowerIndex = flowerChoice - '1';
		
	int gardenSpot;
	cout << "Which garden spot? (1-5)" << endl;
	cin >> gardenSpot;
		
	//prevent replacing already existing flowers 
	if(garden[gardenSpot - 1] == "Empty"){
		
		if(seedInventory[flowerIndex] > 0){
				
			garden[gardenSpot - 1] = flowerNames[flowerIndex];
			growthStage[gardenSpot - 1] = 1;
			seedInventory[flowerIndex]--;
				
			cout << "(You planted a " << flowerNames[flowerIndex] << " seed!)" << endl;
			cout << "I hope its becomes very pretty! Ribbit! " << endl;
			cout << endl;
			cout << "We have " << seedInventory[flowerIndex] << " seeds left." << endl;		
		}
		else{//inventory restriction
			cout << "Oh no, little frog! We don't have that seed..." << endl;
			cout << "Maybe we should visit Choco the Chipmunk's shop!" << endl;			}
		}
	
		//cout << "Tulip's are my favorite! Or was it Bellflowers? " << endl;
		//cout << "You chose a rose, I sure hope it grows!" << endl;
		//cout << "Why is it called a bellflower if I cant hear any bells?" << endl;
		//cout << "The sun must have its favorite flower Ribbit! " << endl;
		//cout << "Lavender is my favorite color! " << endl;
		//cout << "Hibiscus flowers remind me of summer! " << endl;
	else{ 
		cout << "Ribbit! Oh no! There is already a flower here! Can you place it somewhere else " << endl;
	}
}

void flowerShop(int &coins, int seedInventory[], string flowerNames[]){
	
	cout << endl;
	cout << "-----------------" << endl;
	cout << "Choco's the Chipmunk's Flower Shop " << endl;
	cout << "-----------------"<< endl;
	cout << endl;
	cout << "Choco: Hi! Hi! Hiya! Welcome to MY flower shop! Chip Chip! " << endl;
	cout << endl;
	cout << "Choco: Take a look around!! Chip Chip! " << endl;
	cout << endl;
	cout << "Eden: Thank you Choco! " << endl;
	cout << endl;
	cout << "Hey little frog, do you see anything interesting? " << endl;
	cout << endl;
	
	int chocoChoice;
	//Choco the Chipmunk shop options
	for(int i = 0; i < 7; i++){
		cout << i + 1 << ". Buy " << flowerNames[i] << " Seeds " << endl;
	}
	cout << "8. Leave Shop " << endl;
	cin >> chocoChoice;
	int flowerIndex = chocoChoice - 1;
	
	if(chocoChoice >= 1 && chocoChoice <= 7){
	cout << "(" << flowerNames[flowerIndex] << " seeds cost 1 coin.)" << endl;
		int amount;
		cout << "Choco: How many would you like to buy? " << endl;
		cin >> amount;
		
		int seedprice = 1;
		int totalCost = seedprice * amount;
		
		if(coins >= totalCost){
			cout << "Choco: Chip Chip! You can afford that! " << endl;
			cout << "Choco: That will cost " << totalCost << " coin(s)." << endl;
			if(amount > 0){
				cout << "Choco: Here is your " << amount << " " << flowerNames[flowerIndex] << " seeds! Chip Chip!" << endl;
				coins -= totalCost;
				seedInventory[flowerIndex] += amount;
				cout << "(You bought " << amount << " " << flowerNames[flowerIndex] << " seeds!) " << endl;
				cout << flowerNames[flowerIndex] << " Seeds: " << seedInventory[flowerIndex] << endl;
				cout << "Coins: " << coins << endl;
			
			}
			else if(amount == 0){
				cout << "Eden: Ribbit! oh you changed your mind. That's okay!" << endl;
				cout << endl;
				cout << "Choco: Okay for you, less money for me Chip Chip... " << endl;
			}
		}
		else{
			cout << "Choco: Oh... You don't have enough coins for that haha! Chip Chip!" << endl;
		}
		
	}
	else if(chocoChoice == 8){
		cout << "Choco: Come again soon! Chipy! Chip Chip! " << endl;
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

void viewInventory (int seedInventory[], string flowerNames[]){

	cout << endl;
	cout << "---- Eden's Inventory ----" << endl;
	
	for(int i = 0; i < 7; i++){
		cout << flowerNames[i] << " Seeds: " << seedInventory[i] << endl;
	}
}

void sleep(int growthStage[], int &day){//choice 5

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
	int seedInventory[7] = {2,0,0,0,0,0,0}; //# of daisy seeds, # of tulip seeds, etc..
	string flowerNames[7] = {"Daisy", "Tulip", "Rose", "Bellflower", "Sunflower", "Lavender", "Hibiscus"};
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
	cout << "4. Visit Choco the Chipmunk's flower shop " << endl;
	cout << "5. View Inventory " << endl;
	cout << "6. Sleep " << endl;
	cout << "7. Quit " << endl;
	cout << endl; 
	cout << "(What should Eden do?)" << endl;
	cin >> choice;
	
	if(choice == '1'){//option 1
		lookAtGarden(garden,growthStage);
	}
	else if(choice == '2'){//option 2
		plantFlower(garden, growthStage, seedInventory, flowerNames);
	}
	else if(choice == '3'){//option 3
		harvestFlower(garden, growthStage, coins);
	}
	else if(choice == '4'){//option 4
		flowerShop(coins, seedInventory, flowerNames);
	}
	
	else if(choice == '5'){//option 5
		viewInventory(seedInventory, flowerNames);
	}
	else if(choice == '6'){ //option 6
		sleep(growthStage, day);
	}
	else if(choice == '7'){ //option 7
		cout << "Thanks for me with my garden! Come back soon, Ribbit!" << endl;
		playing = false;
	}
	else{
		cout << "That's not a valid choice!." << endl;
	}
	}
	
	return 0;
}