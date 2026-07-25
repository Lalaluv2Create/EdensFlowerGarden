//Eden's Flower Garden
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Flower{ //the blueprint for every flower 
	
	string name;
	int seedCost;
	int value;
	int growDays;
	bool discovered;
	int harvestCount;
};

struct Fruit{ //the blueprint for every fruit 
	
	string name;
	int seedCost;
	int value;
	int growDays;
	bool discovered;
	int harvestCount;
};

struct Vegetable{//the blueprint for every veggie
	
	string name;
	int seedCost;
	int value;
	int growDays;
	bool discovered;
	int harvestCount;
};

void saveGame(int coins, int day, string garden[], int growthStage[], int seedInventory[], int fruitInventory[], int vegetableInventory[], Flower flowers[], Fruit fruits[], Vegetable vegetables[]){//option 8
	
	ofstream saveFile("eden_save.txt");
	saveFile << coins << endl;
	saveFile << day << endl;
	saveFile << endl;
	for(int i = 0; i < 10; i++){
		saveFile << garden[i] << endl;
	}
	saveFile << endl;
	for(int i = 0; i < 10; i++){
		saveFile << growthStage[i] << endl;
	}
	saveFile << endl;
	for(int i = 0; i < 7; i++){
		saveFile << seedInventory[i] << endl;
	}
	saveFile << endl;
	for(int i = 0; i < 3; i++){
		saveFile << fruitInventory[i] << endl;
	}
	saveFile << endl;
	for(int i = 0; i < 3; i++){
		saveFile << vegetableInventory[i] << endl;
	}
	saveFile << endl;
	for(int i = 0; i < 7; i++){ 
		saveFile << flowers[i].discovered << endl;
		saveFile << flowers[i].harvestCount << endl;
	}
	saveFile << endl;
	for(int i = 0; i < 3; i++){
		saveFile << fruits[i].discovered << endl;
		saveFile << fruits[i].harvestCount << endl;
	}
	saveFile << endl;
	for(int i = 0; i < 3; i++){
		saveFile << vegetables[i].discovered << endl;
		saveFile << vegetables[i].harvestCount << endl;
	}
	saveFile << endl;
}

void loadGame(int &coins, int &day, string garden[], int growthStage[], int seedInventory[], int fruitInventory[], int vegetableInventory[], Flower flowers[], Fruit fruits[], Vegetable vegetables[]){
	
	ifstream loadFile("eden_save.txt");
	
	loadFile >> coins;
	loadFile >> day;
	
	for(int i = 0; i < 10; i++){
		loadFile >> garden[i];
	}
	for(int i = 0; i < 10; i++){
		loadFile >> growthStage[i];
	}
	for(int i = 0; i < 7; i++){
		loadFile >> seedInventory[i];
	}
	for(int i = 0; i < 3; i++){
		loadFile >> fruitInventory[i];
	}
	for(int i = 0; i < 3; i++){
		loadFile >> vegetableInventory[i];
	}
	for(int i = 0; i < 7; i++){
		loadFile >> flowers[i].discovered;
		loadFile >> flowers[i].harvestCount;
	}
	for(int i = 0; i < 3; i++){
		loadFile >> fruits[i].discovered;
		loadFile >> fruits[i].harvestCount;
	}
	for(int i = 0; i < 3; i++){
		loadFile >> vegetables[i].discovered;
		loadFile >> vegetables[i].harvestCount;
	}
}

void lookAtGarden(string garden[], int growthStage[]){ //choice 1
	
	cout << endl;
	cout << " ---- Eden's Garden ----" << endl;
		
	for(int i = 0; i < 10; i++){
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

void plantSeed(string garden[], string cropType[], int growthStage[], int seedInventory[], int fruitInventory[], int vegetableInventory[], Flower flowers[], Fruit fruits[], Vegetable vegetables[]){ //choice 2
	
	char plantChoice;
	cout << endl;
	cout << "Eden: What would you like to plant? " << endl;	
	cout << endl;
	cout << "1. Flower" << endl;
	cout << "2. Fruit" << endl;
	cout << "3. Vegetable" << endl;
	cout << endl;
	cin >> plantChoice;
	
	if(plantChoice == '1'){ //flowers
		
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
		cout << endl;
		cout << "Which garden spot? (1-10)" << endl;
		cin >> gardenSpot;
		
		//prevent replacing already existing plants 
		if(garden[gardenSpot - 1] == "Empty"){
		
			if(seedInventory[flowerIndex] > 0){	
				garden[gardenSpot - 1] = flowers[flowerIndex].name;
				cropType[gardenSpot - 1] = "Flower";
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
		else{ 
			cout << "Eden: Ribbit! Oh no! Something is already growing here! Can you place it somewhere else? " << endl;
		}
	}
	else if(plantChoice == '2'){ //fruit
		
		char fruitChoice;		
		for(int i = 0; i < 3; i++){
			cout << i + 1 << ". " << fruits[i].name << endl;
		}
		cin >> fruitChoice; 
		//check for error
		if(fruitChoice < '1' || fruitChoice > '3'){
			cout << "Aww silly! That's not a fruit choice! " << endl;
			return;
		}
		int fruitIndex = fruitChoice - '1';
		
		int gardenSpot;
		cout << "Which garden spot? (1-10)" << endl;
		cin >> gardenSpot;
		
		//prevent replacing already existing plants 
		if(garden[gardenSpot - 1] == "Empty"){
		
			if(fruitInventory[fruitIndex] > 0){	
				garden[gardenSpot - 1] = fruits[fruitIndex].name;
				cropType[gardenSpot - 1] = "Fruit";
				growthStage[gardenSpot - 1] = 1;
				fruitInventory[fruitIndex]--;
				
				cout << "(You planted a " << fruits[fruitIndex].name << " seed!)" << endl;
				cout << endl;
				cout << "Eden: I hope its taste so fresh! Ribbit! " << endl;
				cout << endl;
				cout << "We have " << fruitInventory[fruitIndex] 
				<< " " << fruits[fruitIndex].name
				<< " seeds left." << endl;		
			}
			else{//inventory restriction
				cout << "Eden: Oh no, little frog! We don't have that seed..." << endl;
				cout << endl;
				cout << "Eden: Maybe we should visit Darling the Deer's shop!" << endl;			}
			}
		else{ 
			cout << "Eden: Ribbit! Oh no! Something is already growing here! Can you place it somewhere else? " << endl;
		}
	}
	else if(plantChoice == '3'){ //vegetables
		char vegetableChoice;		
		for(int i = 0; i < 3; i++){
			cout << i + 1 << ". " << vegetables[i].name << endl;
		}
		cin >> vegetableChoice; 
		//check for error
		if(vegetableChoice < '1' || vegetableChoice > '3'){
			cout << "Aww silly! That's not a veggie choice! " << endl;
			return;
		}
		int vegetableIndex = vegetableChoice - '1';
		
		int gardenSpot;
		cout << "Which garden spot? (1-10)" << endl;
		cin >> gardenSpot;
		
		//prevent replacing already existing plants 
		if(garden[gardenSpot - 1] == "Empty"){
		
			if(vegetableInventory[vegetableIndex] > 0){	
				garden[gardenSpot - 1] = vegetables[vegetableIndex].name;
				cropType[gardenSpot - 1] = "Vegetable";
				growthStage[gardenSpot - 1] = 1;
				vegetableInventory[vegetableIndex]--;
				
				cout << "(You planted a " << vegetables[vegetableIndex].name << " seed!)" << endl;
				cout << endl;
				cout << "Eden: I bet it's gonna grow wonderfully! Ribbit! " << endl;
				cout << endl;
				cout << "We have " << vegetableInventory[vegetableIndex] 
				<< " " << vegetables[vegetableIndex].name
				<< " seeds left." << endl;		
			}
			else{//inventory restriction
				cout << "Eden: Oh no, little frog! We don't have that seed..." << endl;
				cout << endl;
				cout << "Eden: Maybe we should visit BJ the Blue Jay's shop!" << endl;			}
			}
		else{ 
			cout << "Eden: Ribbit! Oh no! Something is already growing here! Can you place it somewhere else? " << endl;
		}
	}
	else{ //not an option
		cout << "Eden: Oh, that's not an option to grow Ribbit! " << endl;
	}
}

void flowerShop(int &coins, int seedInventory[], Flower flowers[]){
	
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

void harvestPlant(string garden[], string cropType[], int growthStage[], int &coins, Flower flowers[], Fruit fruits[], Vegetable vegetables[]){//choice 3
	
	int gardenSpot;
	cout << "Which garden spot would you like to harvest? (1-10)" << endl;
	cin >> gardenSpot;
	int plantValue = 0; 
	int requiredGrowth = 3;
	//find out what plant it is
	if(cropType[gardenSpot - 1] == "Flower"){
		for(int i = 0; i < 7; i++){
			if(garden[gardenSpot - 1] == flowers[i].name){
				requiredGrowth = flowers[i].growDays;
				plantValue = flowers[i].value;
				
				flowers[i].harvestCount++;
				
				if(flowers[i].discovered == false){
					flowers[i].discovered = true;
					cout << "Eden: A new flower was added to my journal! " << endl;
					cout << endl;
					cout << "Eden: Good job little frog! Ribbit Ribbit! " << endl;
					cout << endl;
				}
			}
		}
	}
	else if(cropType[gardenSpot - 1] == "Fruit"){
		for(int i = 0; i < 3; i++){
			if(garden[gardenSpot - 1] == fruits[i].name){
				requiredGrowth = fruits[i].growDays;
				plantValue = fruits[i].value;
				
				fruits[i].harvestCount++;
				
				if(fruits[i].discovered == false){
					fruits[i].discovered = true;
					cout << "Eden: A new fruit was added to my journal! " << endl;
					cout << endl;
					cout << "Eden: I know I can count on you, little frog! Ribbit Ribbit! " << endl;
					cout << endl;
				}
			}
		}
	}
	else if(cropType[gardenSpot - 1] == "Vegetable"){
		for(int i = 0; i < 3; i++){
			if(garden[gardenSpot - 1] == vegetables[i].name){
				requiredGrowth = vegetables[i].growDays;
				plantValue = vegetables[i].value;
				
				vegetables[i].harvestCount++;
				
				if(vegetables[i].discovered == false){
					vegetables[i].discovered = true;
					cout << "Eden: A new veggie was added to my journal! " << endl;
					cout << endl;
					cout << "Eden: You're so great Little Frog! Ribbit Ribbit! " << endl;
					cout << endl;
				}
			}
		}
	} 
	if(garden[gardenSpot - 1] == "Empty"){//nothing planted 
		cout << "Eden: Oh silly! You haven't planted anythign here yet. Ribbit! " << endl;
		return;
	}
	if(growthStage[gardenSpot - 1] < requiredGrowth){//not fully grown yet 
		cout << "Eden: Oh Ribbit! That flower isn't ready to harvest yet... " << endl;
		return;
	}
	//Harvest	
	cout << "You harvested a " << garden[gardenSpot - 1] << "!" << endl;
		
	garden[gardenSpot - 1] = "Empty"; //after picking, return garden spot to empty
	growthStage[gardenSpot - 1] = 0;
	cropType[gardenSpot - 1] = "Empty";
		
	coins += plantValue; //increase coins as a reward for harvesting 
	
	cout << endl;
	cout << "Eden: Ribbit! We earned " << plantValue << " beautiful coins!" << endl;
	cout << endl;
	cout << "Coins: " << coins << endl;
	}

void viewInventory(int seedInventory[], int fruitInventory[], int vegetableInventory[], Flower flowers[], Fruit fruits[], Vegetable vegetables[]){

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
		
		for(int i = 0; i < 10; i++){
			if(growthStage[i] > 0){
				growthStage[i]++;
			}
		}
		cout << "Day " << day << " begins!" << endl;
}

void viewGardenJournal(Flower flowers[], Fruit fruits[], Vegetable vegetables[]){//choice 7
	
	cout << endl;
	cout << " ---- Eden's Garden Journal ---- " << endl;
	cout << endl;
	
	cout << endl;
	cout << "Flowers" << endl;
	cout << "-------" << endl;
	
	//flower loop
	for(int i = 0; i < 7; i++){
		if(flowers[i].discovered){
			cout << flowers[i].name << endl;
			cout << "Seed Cost: " << flowers[i].seedCost << endl;
			cout << "Sell Value: " << flowers[i].value << endl;
			cout << "Harvested: " << flowers[i].harvestCount << endl;
			cout << endl;
		}
		else{
			cout << "Undiscovered Flower " << endl;
			cout << endl;
		}
	}
	
	cout << endl;
	cout << "Fruits:" << endl;
	cout << "-------" << endl;
	
	//fruit loop
	for(int i = 0; i < 3; i++){
		if(fruits[i].discovered){
			cout << fruits[i].name << endl;
			cout << "Seed Cost: " << fruits[i].seedCost << endl;
			cout << "Sell Value: " << fruits[i].value << endl;
			cout << "Harvested: " << fruits[i].harvestCount << endl;
			cout << endl;
		}
		else{
			cout << "Undiscovered Fruit " << endl;
			cout << endl;
		}
	}
	
	cout << endl;
	cout << "Vegetables:" << endl;
	cout << "-------" << endl;
	
	//veggie loop
	for(int i = 0; i < 3; i++){
		if(vegetables[i].discovered){
			cout << vegetables[i].name << endl;
			cout << "Seed Cost: " << vegetables[i].seedCost << endl;
			cout << "Sell Value: " << vegetables[i].value << endl;
			cout << "Harvested: " << vegetables[i].harvestCount << endl;
			cout << endl;
		}
		else{
			cout << "Undiscovered Vegetable " << endl;
			cout << endl;
		}
	}
}

void fruitShop(int &coins, int fruitInventory[], Fruit fruits[]){
	
	cout << endl;
	cout << "-----------------" << endl;
	cout << "Darling the Deer's Fruit Shop " << endl;
	cout << "-----------------"<< endl;
	cout << endl;
	cout << "Darling: My my, welcome to my fruit shop." << endl;
	cout << endl;
	cout << "Darling: Please let me know if you find anything that intrigues your interest. " << endl;
	cout << endl;
	cout << "Eden: Thank you Darling for your hospitality! " << endl;
	cout << endl;
	cout << "Darling: Dear little frog, do any of my fruits catch your eye?" << endl;
	cout << endl;
	
	int darlingChoice;
	//Darling the Dear shop options
	for(int i = 0; i < 3; i++){
		cout << i + 1 << ". Buy " << fruits[i].name << " Seeds " << endl;
	}
	cout << "4. Leave Shop " << endl;
	cin >> darlingChoice;
	int fruitIndex = darlingChoice - 1;
	
	if(darlingChoice >= 1 && darlingChoice <= 3){
	cout << "(" << fruits[fruitIndex].name << " seeds cost " << fruits[fruitIndex].seedCost << " coin(s))" << endl;
		int amount;
		cout << "Darling: So how many are you buying? " << endl;
		cin >> amount;
		int totalCost = fruits[fruitIndex].seedCost * amount;
		
		if(coins >= totalCost){
			cout << "Darling: My, I'm shocked that you can afford that! " << endl;
			cout << "Darling: That will cost " << totalCost << " coin(s)." << endl;
			if(amount > 0){
				cout << "Darling: Here is your " << amount << " " << fruits[fruitIndex].name << " seeds... " << endl;
				coins -= totalCost;
				fruitInventory[fruitIndex] += amount;
				cout << "(You bought " << amount << " " << fruits[fruitIndex].name << " seeds!) " << endl;
				cout << fruits[fruitIndex].name << " Seeds: " << fruitInventory[fruitIndex] << endl;
				cout << "Coins: " << coins << endl;
			
			}
			else if(amount == 0){
				cout << "Eden: Ribbit! oh you changed your mind. That's okay!" << endl;
				cout << endl;
				cout << "Darling: ...  " << endl;
			}
		}
		else{
			cout << "Darling: My my, are you sure you can afford that? You do not have enough coins" << endl;
		}
		
	}
	else if(darlingChoice == 4){
		cout << "Darling: My my, feel free to return whenever you like. " << endl;
	}
}

void vegetableShop(int &coins, int vegetableInventory[], Vegetable vegetables[]){
	
	cout << endl;
	cout << "-----------------" << endl;
	cout << "BJ the Blue Jay's Vegetable Shop " << endl;
	cout << "-----------------"<< endl;
	cout << endl;
	cout << "BJ: Hey, welcome to mi casa! " << endl;
	cout << endl;
	cout << "BJ: This house turned shop can help with anything you need." << endl;
	cout << endl;
	cout << "Eden: I know we can count on your hospitality BJ! " << endl;
	cout << endl;
	cout << "BJ: Of course Ms. Eden. Hey Little Frog, what you want? " << endl;
	cout << "I'll give you veggies half off since you and Eden are cool froggies. " << endl;
	cout << endl;
	
	int bjChoice;
	//BJ the Blue Jay shop options
	for(int i = 0; i < 3; i++){
		cout << i + 1 << ". Buy " << vegetables[i].name << " Seeds " << endl;
	}
	cout << "4. Leave Shop " << endl;
	cin >> bjChoice;
	int vegetableIndex = bjChoice - 1;
	
	if(bjChoice >= 1 && bjChoice <= 3){
	cout << "(" << vegetables[vegetableIndex].name << " seeds cost " << vegetables[vegetableIndex].seedCost << " coin(s))" << endl;
		int amount;
		cout << "BJ: How many? " << endl;
		cin >> amount;
		int totalCost = vegetables[vegetableIndex].seedCost * amount;
		
		if(coins >= totalCost){
			cout << "BJ: Great choice Little Froggie. " << endl;
			cout << "BJ: That will cost " << totalCost << " coin(s)." << endl;
			if(amount > 0){
				cout << "BJ: Here is your " << amount << " " << vegetables[vegetableIndex].name << " seeds. Remember, it's half off so no bargaining." << endl;
				coins -= totalCost;
				vegetableInventory[vegetableIndex] += amount;
				cout << "(You bought " << amount << " " << vegetables[vegetableIndex].name << " seeds!) " << endl;
				cout << vegetables[vegetableIndex].name << " Seeds: " << vegetableInventory[vegetableIndex] << endl;
				cout << "Coins: " << coins << endl;
			
			}
			else if(amount == 0){
				cout << "Eden: Ribbit! oh you changed your mind. That's okay!" << endl;
				cout << endl;
				cout << "BJ: Yeah its chill." << endl;
			}
		}
		else{
			cout << "BJ: (Whispering) Aye Little Frog, you can't afford that..." << endl;
		}
		
	}
	else if(bjChoice == 4){
		cout << "BJ: Come back anytime! " << endl;
		cout << "BJ: Remember mi casa es mi casa! Or something like that..." << endl;
	}
}

void village(int &coins, int seedInventory[], int fruitInventory[], int vegetableInventory[], Flower flowers[], Fruit fruits[], Vegetable vegetables[]){
	
	cout << endl;
	cout << "---- Ruby Village ----" << endl;
	cout << endl;
	
	cout << "Eden: Little Frog! This village has so many shops to choose from! Ribbit!" << endl;
	cout << endl;
	
	int townChoice;
	cout << "1. Visit Choco's Flower Shop" << endl; //Choco the Chipmunk 
	cout << "2. Visit Darling's Fruit Shop" << endl;// Darling the Deer
	cout << "3. Visit BJ's Vegetable Shop" << endl; // BJ the Blue Jay
	cout << "4. Return Home " << endl;
	cin >> townChoice;
	
	if(townChoice == 1){
		flowerShop(coins, seedInventory, flowers);
	}
	else if(townChoice == 2){
		fruitShop(coins, fruitInventory, fruits);
	}
	else if(townChoice == 3){
		vegetableShop(coins, vegetableInventory, vegetables);
	}
	else if(townChoice == 4){
		cout << "Eden: Let's head back home Little Frog! " << endl;
	}
	else{
		cout << "Eden: Theres no where in Ruby that has that... " << endl;
	}
}

int main(){
	
	cout << "Welcome to Eden's Flower Garden!" << endl;
	cout << endl;
	
	//game data 
	int coins = 10;
	int seedInventory[7] = {2,0,0,0,0,0,0}; //# of daisy seeds, # of tulip seeds, etc..
	Flower flowers[7] = {
		{"Daisy", 1, 3, 3, false, 0},
		{"Tulip", 1, 5, 3, false, 0},
		{"Rose", 3, 8, 3, false, 0},
		{"Bellflower", 1, 6, 3, false, 0},
		{"Sunflower", 1, 10, 3, false, 0},
		{"Lavender", 1, 7, 3, false, 0},
		{"Hibiscus", 1, 9, 3, false, 0},
	};
	int fruitInventory[3] = {0,0,0};
	Fruit fruits[3] = {
		{"Apple", 2, 6, 3, false, 0},
		{"Strawberry", 2, 7, 3, false, 0},
		{"Grapes", 3, 9, 4, false, 0},
	};
	int vegetableInventory[3] = {0,0,0};
	Vegetable vegetables[3] = {
		{"Tomato", 1, 6, 3, false, 0},
		{"Corn", 1, 4, 5, false, 0},
		{"Sweet Potato", 4, 12, 3, false, 0},
	};
	
	string garden [10] = {
		"Empty", "Empty", "Empty", "Empty", "Empty",
		"Empty", "Empty", "Empty", "Empty", "Empty"	};
	string cropType[10] = {
		"Empty", "Empty", "Empty", "Empty", "Empty",
		"Empty", "Empty", "Empty", "Empty", "Empty" };
	int growthStage[10] = {
		0,0,0,0,0,0,0,0,0,0};
	int day = 1; //day counter
	
	int startChoice;
	cout << "1. Start a New Garden" << endl;
	cout << "2. Load Garden" << endl;
	cout << endl;
	cin >> startChoice;
	
	if(startChoice == 1){//new game
		cout << "Ribbit! My name is Eden the Frog! " << endl;
		cout << endl;
		cout << "Eden: Can you help me with my garden?" << endl;
	}
	else if(startChoice == 2){//load game
		loadGame(coins, day, garden, growthStage, seedInventory, fruitInventory, vegetableInventory, flowers, fruits, vegetables);
		cout << "Eden: Welcome back Little Frog! " << endl;
		cout << endl;
		cout << "Eden: The garden and I missed you so much! Ribbit! " << endl;
	}
	else{
		cout << "Eden: Ribbit? That wasn't a choice silly Little Frog!" << endl;
	}
	
	cout << endl;
	cout << "Coins " << coins << endl;

	char choice;
	bool playing = true; //bool = true (yes) OR false (no)
	
	while(playing){
	cout << "-----------------"<< endl;
	cout << "Day: " << day << endl; //updates day and coins after sleeping
	cout << "Coins: " << coins << endl;
	cout << "-----------------"<< endl;
	cout << endl; //add options for what Eden does

	cout << "Eden: Hi little frog! What should we work on today? " << endl;
	cout << endl;
	cout << "1. Look At Garden" << endl;
	cout << "2. Plant Seeds " << endl;
	cout << "3. Harvest Plants " << endl;
	cout << "4. Visit Ruby Village" << endl;
	cout << "5. View Inventory " << endl;
	cout << "6. Sleep " << endl;
	cout << "7. View Eden's Garden Journal" << endl;
	cout << "8. Save Game " << endl;
	cout << "9. Quit " << endl;
	cout << endl; 
	cin >> choice;
	
	if(choice == '1'){//option 1
		lookAtGarden(garden,growthStage);
	}
	else if(choice == '2'){//option 2
		plantSeed(garden, cropType, growthStage, seedInventory, fruitInventory, vegetableInventory, flowers, fruits, vegetables);
	}
	else if(choice == '3'){//option 3
		harvestPlant(garden, cropType, growthStage, coins, flowers, fruits, vegetables);
	}
	else if(choice == '4'){//option 4
		village(coins, seedInventory, fruitInventory, vegetableInventory, flowers, fruits, vegetables);
	}
	else if(choice == '5'){//option 5
		viewInventory(seedInventory, fruitInventory, vegetableInventory, flowers, fruits, vegetables);
	}
	else if(choice == '6'){ //option 6
		sleep(growthStage, day);
	}
	else if(choice == '7'){ //option 7
		viewGardenJournal(flowers, fruits, vegetables);
	}
	else if(choice == '8'){ //option 8
		saveGame(coins, day, garden, growthStage, seedInventory, fruitInventory, vegetableInventory, flowers, fruits, vegetables);
	}
	else if(choice == '9'){ //option 9
		cout << "Eden: Thanks for helping me with my garden! " << endl;
		cout << endl;
		cout << "Come back soon, Ribbit!" << endl;
		playing = false;
	}
	else{
		cout << "Eden: That's not a valid choice!." << endl;
	}
	}
	return 0;
}