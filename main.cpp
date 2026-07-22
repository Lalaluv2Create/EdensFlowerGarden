//Eden's Flower Garden
#include <iostream>
#include <string>

using namespace std;

struct Flower{ //the blueprint for every flower 
	
	string name;
	int seedCost;
	int value;
	bool discovered;
};

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

void plantFlower(string garden[], int growthStage[], int seedInventory[], Flower flowers[]){ //choice 2
	
	cout << "What flower would you like to plant? " << endl;	
	char flowerChoice;		
	for(int i = 0; i < 7; i++){
		cout << i + 1 << ". " << flowers[i].name << endl;
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
				
			garden[gardenSpot - 1] = flowers[flowerIndex].name;
			growthStage[gardenSpot - 1] = 1;
			seedInventory[flowerIndex]--;
				
			cout << "(You planted a " << flowers[flowerIndex].name << " seed!)" << endl;
			cout << endl;
			cout << "Eden: I hope its becomes very pretty! Ribbit! " << endl;
			cout << endl;
			cout << "We have " << seedInventory[flowerIndex] 
			<< " " << flowers[flowerIndex].name
			<< " seeds left." << endl;		
		}
		else{//inventory restriction
			cout << "Eden: Oh no, little frog! We don't have that seed..." << endl;
			cout << endl;
			cout << "Eden: Maybe we should visit Choco the Chipmunk's shop!" << endl;			}
		}
	
		//cout << "Tulip's are my favorite! Or was it Bellflowers? " << endl;
		//cout << "You chose a rose, I sure hope it grows!" << endl;
		//cout << "Why is it called a bellflower if I cant hear any bells?" << endl;
		//cout << "The sun must have its favorite flower Ribbit! " << endl;
		//cout << "Lavender is my favorite color! " << endl;
		//cout << "Hibiscus flowers remind me of summer! " << endl;
	else{ 
		cout << "Eden: Ribbit! Oh no! There is already a flower here! Can you place it somewhere else " << endl;
	}
}

void flowerShop(int &coins, int seedInventory[], Flower flowers[]){ //choice 4
	
	cout << endl;
	cout << "-----------------" << endl;
	cout << "Choco the Chipmunk's Flower Shop " << endl;
	cout << "-----------------"<< endl;
	cout << endl;
	cout << "Choco: Hi! Hi! Hiya! Welcome to MY flower shop! Chip Chip! " << endl;
	cout << endl;
	cout << "Choco: Take a look around!! Chip Chip! " << endl;
	cout << endl;
	cout << "Eden: Thank you Choco! " << endl;
	cout << endl;
	cout << "Choco: Hey little frog, do you see anything interesting? " << endl;
	cout << endl;
	
	int chocoChoice;
	//Choco the Chipmunk shop options
	for(int i = 0; i < 7; i++){
		cout << i + 1 << ". Buy " << flowers[i].name << " Seeds " << endl;
	}
	cout << "8. Leave Shop " << endl;
	cin >> chocoChoice;
	int flowerIndex = chocoChoice - 1;
	
	if(chocoChoice >= 1 && chocoChoice <= 7){
	cout << "(" << flowers[flowerIndex].name << " seeds cost " << flowers[flowerIndex].seedCost << " coin(s))" << endl;
		int amount;
		cout << "Choco: How many would you like to buy? " << endl;
		cin >> amount;
		int totalCost = flowers[flowerIndex].seedCost * amount;
		
		if(coins >= totalCost){
			cout << "Choco: Chip Chip! You can afford that! " << endl;
			cout << "Choco: That will cost " << totalCost << " coin(s)." << endl;
			if(amount > 0){
				cout << "Choco: Here is your " << amount << " " << flowers[flowerIndex].name << " seeds! Chip Chip!" << endl;
				coins -= totalCost;
				seedInventory[flowerIndex] += amount;
				cout << "(You bought " << amount << " " << flowers[flowerIndex].name << " seeds!) " << endl;
				cout << flowers[flowerIndex].name << " Seeds: " << seedInventory[flowerIndex] << endl;
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

void harvestFlower(string garden[], int growthStage[], int &coins, Flower flowers[]){//choice 3
	
	int gardenSpot;
	cout << "Which garden spot would you like to harvest? (1-5)" << endl;
	cin >> gardenSpot;
	int flowerValue = 0; 
	
	if(growthStage[gardenSpot - 1] >= 3){
		cout << "You harvested a " << garden[gardenSpot - 1] << "!" << endl;
		
		for(int i = 0; i < 7; i++){
			if(garden[gardenSpot - 1] == flowers[i].name){
				flowerValue = flowers[i].value;
				if(flowers[i].discovered == false){
					flowers[i].discovered = true;
					cout << "Eden: A new flower was added to my journal! " << endl;
					cout << endl;
					cout << "Eden: Good job little frog! Ribbit Ribbit! " << endl;
					cout << endl;
				}
			}	
		}
		garden[gardenSpot - 1] = "Empty"; //after picking, return garden spot to empty
		growthStage[gardenSpot - 1] = 0;
		
		coins += flowerValue; //increase coins as a reward for harvesting 
		cout << endl;
		cout << "Eden: Ribbit! We earned " << flowerValue << " beautiful coins!" << endl;
		cout << endl;
		cout << "Coins: " << coins << endl;
	}
	else if(garden[gardenSpot - 1] == "Empty"){
		cout << "Eden: Oh silly! You haven't planted anythign here yet. Ribbit! " << endl;
	}
	else{
		cout << "Eden: Oh Ribbit! That flower isn't ready to harvest yet... " << endl;
	}
}

void viewInventory(int seedInventory[], Flower flowers[]){

	cout << endl;
	cout << "---- Eden's Inventory ----" << endl;
	
	for(int i = 0; i < 7; i++){
		cout << flowers[i].name << " Seeds: " << seedInventory[i] << endl;
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

void viewFlowerJournal(Flower flowers[]){//choice 7
	
	cout << endl;
	cout << " ---- Eden's Flower Journal ---- " << endl;
	cout << endl;
	
	for(int i = 0; i < 7; i++){
		if(flowers[i].discovered){//show flower info
			cout << flowers[i].name << endl;
			cout << "Seed Cost: " << flowers[i].seedCost << endl;
			cout << "Sell Value: " << flowers[i].value << endl;
			cout << endl;
		}
		else{
			cout << "Undiscovered Flower " << endl;
			cout << endl;
		}
	}
}

int main(){
	
	cout << "Welcome to Eden's Flower Garden!" << endl;
	cout << endl;
	cout << "Ribbit! My name is Eden the Frog! " << endl;
	cout << "Can you help me with my garden?" << endl;
	int coins = 10;
	int seedInventory[7] = {2,0,0,0,0,0,0}; //# of daisy seeds, # of tulip seeds, etc..
	Flower flowers[7] = {
		{"Daisy", 1, 3, false},
		{"Tulip", 1, 5, false},
		{"Rose", 3, 8, false},
		{"Bellflower", 1, 6, false},
		{"Sunflower", 1, 10, false},
		{"Lavender", 1, 7, false},
		{"Hibiscus", 1, 9, false},
	};
	
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
	cout << "7. View Flower Journal " << endl;
	cout << "8. Quit " << endl;
	cout << endl; 
	cout << "(What should Eden do?)" << endl;
	cin >> choice;
	
	if(choice == '1'){//option 1
		lookAtGarden(garden,growthStage);
	}
	else if(choice == '2'){//option 2
		plantFlower(garden, growthStage, seedInventory, flowers);
	}
	else if(choice == '3'){//option 3
		harvestFlower(garden, growthStage, coins, flowers);
	}
	else if(choice == '4'){//option 4
		flowerShop(coins, seedInventory, flowers);
	}
	else if(choice == '5'){//option 5
		viewInventory(seedInventory, flowers);
	}
	else if(choice == '6'){ //option 6
		sleep(growthStage, day);
	}
	else if(choice == '7'){ //option 7
		viewFlowerJournal(flowers);
	}
	else if(choice == '8'){ //option 8
		cout << "Thanks for me with my garden! Come back soon, Ribbit!" << endl;
		playing = false;
	}
	else{
		cout << "That's not a valid choice!." << endl;
	}
	}
	
	return 0;
}