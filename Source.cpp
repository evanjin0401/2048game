#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<cstdlib>
#include <time.h>  
#include <fstream>
#include "Users.cpp"
#include <time.h> 
#include <direct.h>
using namespace std;
void gameover(vector < vector < stack<int>>> matrix) {
	int iz, jz, znew, val;
	vector < vector<int> > zeroes{};
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j].top() == 0) {
				zeroes.push_back({ i, j }); //If (i,j)=0, then add to list
			}
		}
	}
	if (zeroes.size() != 0) {
		//No gameover :-)
	}
	else {
		//Maybe game over
		//Check for pairs
		//If no pairs, then gameover
		//Check rows
		bool pairsfound = false;
		for (int i = 0; i < matrix.size(); i++) {
			if ((matrix[i][0].top() == matrix[i][1].top()) || (matrix[i][1].top() == matrix[i][2].top()) || (matrix[i][2].top() == matrix[i][3].top())) {
				pairsfound = true;
			}
		}
		//Check columns
		for (int i = 0; i < matrix.size(); i++) {
			if ((matrix[0][i].top() == matrix[1][i].top()) || (matrix[1][i].top() == matrix[2][i].top()) || (matrix[2][i].top() == matrix[3][i].top())) {
				pairsfound = true;
			}
		}
		if (~pairsfound){
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\tGAME OVER\n\n\t\t\tEnter a number to continue."; int omega;
			cin >> omega;
			exit(0);


		}
	}

}
void gameover(vector < vector < stack<int>>> matrix,Users& user,int score,int step) {
	int iz, jz, znew, val;
	vector < vector<int> > zeroes{};
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j].top() == 0) {
				zeroes.push_back({ i, j }); //If (i,j)=0, then add to list
			}
		}
	}
	if (zeroes.size() != 0) {
		//No gameover :-)
	}
	else {
		//Maybe game over
		//Check for pairs
		//If no pairs, then gameover
		//Check rows
		bool pairsfound = false;
		for (int i = 0; i < matrix.size(); i++) {
			if ((matrix[i][0].top() == matrix[i][1].top()) || (matrix[i][1].top() == matrix[i][2].top()) || (matrix[i][2].top() == matrix[i][3].top())) {
				pairsfound = true;
			}
		}
		//Check columns
		for (int i = 0; i < matrix.size(); i++) {
			if ((matrix[0][i].top() == matrix[1][i].top()) || (matrix[1][i].top() == matrix[2][i].top()) || (matrix[2][i].top() == matrix[3][i].top())) {
				pairsfound = true;
			}
		}
		if (~pairsfound){
			user.Record(score, step);
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\tGAME OVER\n\n\t\t\tEnter a number to continue."; int omega;
			cin >> omega;
			exit(0);


		}
	}

}
void makeFile(string name) {
	ofstream myfile;
	string filename = name + ".txt";
	myfile.open(filename);
	myfile.close();
}
int getCurrentScore(vector<vector<stack<int>>> matrix) {
	int Zscore = 0;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j].top() >= Zscore) {
				Zscore = matrix[i][j].top();
			}
		}
	}
	return Zscore;
}
void randombit(vector<vector<stack<int>>>& matrix) {
	//Creates a random 2 or 4 on a zero space of the grid
	int iz, jz, znew, val;
	vector < vector<int> > zeroes{};
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j].top() == 0) {
				zeroes.push_back({ i, j }); //If (i,j)=0, then add to list
			}
		}
	}
	if (zeroes.size() != 0) { //If there are zeroes, then randomly set one to 2
		srand(time(NULL));
		val = (((rand() % 2) + 1) * 2);		//Val is either 2 or 4
		znew = rand() % (zeroes.size());
		iz = zeroes[znew][0];
		jz = zeroes[znew][1];
		matrix[iz][jz].pop();
		matrix[iz][jz].push(val);
	}


}
void randomtwo(vector<vector<stack<int>>>& matrix) {
	//Creates two ‘2’ randomly on a zero space in the matrix
	int iz, jz, znew, znew2, val;
	vector < vector<int> > zeroes{};
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j].top() == 0) {
				zeroes.push_back({ i, j }); //If (i,j)=0, then add to list
			}
		}
	}
	if (zeroes.size() != 0) { //If there are zeroes, then randomly set two of em
		srand(time(NULL));
		//First ‘2’
		znew = rand() % (zeroes.size());
		iz = zeroes[znew][0];
		jz = zeroes[znew][1];
		matrix[iz][jz].pop();
		matrix[iz][jz].push(2);
		//Second ‘2’
		znew2 = rand() % (zeroes.size());
		while (znew2 == znew) { znew2 = rand() % (zeroes.size()); }
		iz = zeroes[znew2][0];
		jz = zeroes[znew2][1];
		matrix[iz][jz].pop();
		matrix[iz][jz].push(2);
	}


}
void undo(vector<vector<stack<int>>>& matrix, int& step) {
	//Pop the first element of all stacks, decrement #steps
	//The # of moves taken should remain the same.
	int temp;
	temp = step;
	if (step > 0) {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++) {
				matrix[i][j].pop();
			}
		}
	}


}
void shiftRight(vector<vector<stack<int>>>& matrix, int& step, int& move) {
	//Create duplicate layer on stack
	int count(0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j].push(matrix[i][j].top());
		}
	}
	for (int i = 3; i >= 0; i--) {
		if (matrix[i][1].top() == 0 && matrix[i][0].top() != 0) {
			count++;
			matrix[i][1].pop();
			matrix[i][1].push(matrix[i][0].top());
			matrix[i][0].pop();
			matrix[i][0].push(0);
		}
		if (matrix[i][2].top() == 0 && (matrix[i][1].top() != 0
			| matrix[i][0].top() != 0))
		{
			count++;
			matrix[i][2].pop();
			matrix[i][2].push(matrix[i][1].top());
			matrix[i][1].pop();
			matrix[i][1].push(matrix[i][0].top());
			matrix[i][0].pop();
			matrix[i][0].push(0);
		}
		if (matrix[i][3].top() == 0 && (matrix[i][2].top() != 0 | matrix[i][1].top() != 0
			| matrix[i][0].top() != 0)) {
			matrix[i][3].pop();
			matrix[i][3].push(matrix[i][2].top());
			matrix[i][2].pop();
			matrix[i][2].push(matrix[i][1].top());
			matrix[i][1].pop();
			matrix[i][1].push(matrix[i][0].top());
			matrix[i][0].pop();
			matrix[i][0].push(0);
		}
	}
	for (int i = 0; i <4; i++) {
		if (matrix[i][3].top() == matrix[i][2].top() && matrix[1][2].top() != 0)
		{
			count++;
			matrix[i][3].pop();
			matrix[i][3].push(2 * matrix[i][2].top());
			matrix[i][2].pop();
			matrix[i][2].push(matrix[i][1].top());
			matrix[i][1].pop();
			matrix[i][1].push(matrix[i][0].top());
			matrix[i][0].pop();
			matrix[i][0].push(0);
		}
		//Check the second element
		if (matrix[i][1].top() == matrix[i][2].top() && matrix[i][1].top() != 0)//equal to the left element
		{
			count++;
			matrix[i][2].pop();
			matrix[i][2].push(2 * matrix[i][1].top());
			matrix[i][1].pop();
			matrix[i][1].push(matrix[i][0].top());
			matrix[i][0].pop();
			matrix[i][0].push(0);
		}
		//Check the third element
		if (matrix[i][0].top() == matrix[i][1].top() && matrix[i][0].top() != 0)//equal to the left element
		{
			count++;
			matrix[i][1].pop();
			matrix[i][1].push(2 * matrix[i][0].top());
			matrix[i][0].pop();
			matrix[i][0].push(0);
		}
	}
	if (count > 0)
	{
		step++;
		move++;
		randombit(matrix);
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrix[i][j].pop();
			}
		}
	}


}
void shiftLeft(vector<vector<stack<int>>>& matrix, int& step, int& move) {
	//Create duplicate layer on stack
	int count(0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j].push(matrix[i][j].top());
		}
	}
	for (int i = 0; i <4; i++) {
		if (matrix[i][2].top() == 0 && matrix[i][3].top() != 0) {
			count++;
			cout << count << " I:" << i << endl;
			cout << "1" << endl;
			matrix[i][2].pop();
			matrix[i][2].push(matrix[i][3].top());
			matrix[i][3].pop();
			matrix[i][3].push(0);
		}
		if (matrix[i][1].top() == 0 && (matrix[i][2].top() != 0 || matrix[i][3].top() != 0)) {
			count++;
			cout << count << " I:" << i << endl;
			cout << "2" << endl;
			matrix[i][1].pop();
			matrix[i][1].push(matrix[i][2].top());
			matrix[i][2].pop();
			matrix[i][2].push(matrix[i][3].top());
			matrix[i][3].pop();
			matrix[i][3].push(0);
		}
		if (matrix[i][0].top() == 0 && (matrix[i][1].top() != 0 || matrix[i][2].top() != 0
			|| matrix[i][3].top() != 0)) {
			count++;
			cout << count << " I:" << i << endl;
			cout << "3" << endl;
			matrix[i][0].pop();
			matrix[i][0].push(matrix[i][1].top());
			matrix[i][1].pop();
			matrix[i][1].push(matrix[i][2].top());
			matrix[i][2].pop();
			matrix[i][2].push(matrix[i][3].top());
			matrix[i][3].pop();
			matrix[i][3].push(0);
		}
	}
	for (int i = 0; i <4; i++) {
		if (matrix[i][0].top() == matrix[i][1].top() && matrix[i][1].top() != 0)//equal to the left element
		{
			count++;
			cout << count << " I:" << i << endl;
			cout << "+1" << endl;
			matrix[i][0].pop();
			matrix[i][0].push(2 * matrix[i][1].top());
			matrix[i][1].pop();
			matrix[i][1].push(matrix[i][2].top());
			matrix[i][2].pop();
			matrix[i][2].push(matrix[i][3].top());
			matrix[i][3].pop();
			matrix[i][3].push(0);
		}
		//Check the second element
		if (matrix[i][1].top() == matrix[i][2].top() && matrix[i][2].top() != 0)//equal to the left element
		{
			count++;
			cout << count << " I:" << i << endl;
			cout << "+2" << endl;
			matrix[i][1].pop();
			matrix[i][1].push(2 * matrix[i][2].top());
			matrix[i][2].pop();
			matrix[i][2].push(matrix[i][3].top());
			matrix[i][3].pop();
			matrix[i][3].push(0);
		}
		//Check the third element
		if (matrix[i][2].top() == matrix[i][3].top() && matrix[3][i].top() != 0)//equal to the left element
		{
			count++;
			cout << count << " I:" << i << endl;
			cout << "+3" << endl;
			matrix[i][2].pop();
			matrix[i][2].push(2 * matrix[i][3].top());
			matrix[i][3].pop();
			matrix[i][3].push(0);
		}
	}

	if (count > 0)
	{
		step++;
		move++;
		randombit(matrix);
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrix[i][j].pop();
			}
		}
	}
}
void shiftUp(vector<vector<stack<int>>>& matrix, int& step, int& move) {
	int count(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			matrix[i][j].push(matrix[i][j].top());
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (matrix[2][i].top() == 0 && matrix[3][i].top() != 0) {
			count++;
			matrix[2][i].push(matrix[3][i].top());
			matrix[3][i].pop();
			matrix[3][i].push(0);
		}
		if (matrix[1][i].top() == 0 && (matrix[2][i].top() != 0 || matrix[3][i].top() != 0)) {
			count++;
			matrix[1][i].pop();
			matrix[1][i].push(matrix[2][i].top());
			matrix[2][i].pop();
			matrix[2][i].push(matrix[3][i].top());
			matrix[3][i].pop();
			matrix[3][i].push(0);
		}
		if (matrix[0][i].top() == 0 && (matrix[1][i].top() != 0 || matrix[2][i].top() != 0
			|| matrix[3][i].top() != 0)) {
			count++;
			matrix[0][i].pop();
			matrix[0][i].push(matrix[1][i].top());
			matrix[1][i].pop();
			matrix[1][i].push(matrix[2][i].top());
			matrix[2][i].pop();
			matrix[2][i].push(matrix[3][i].top());
			matrix[3][i].pop();
			matrix[3][i].push(0);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (matrix[0][i].top() == matrix[1][i].top() && matrix[1][i].top() != 0)//equal to the left element
		{
			count++;
			matrix[0][i].pop();
			matrix[0][i].push(2 * matrix[1][i].top());
			matrix[1][i].pop();
			matrix[1][i].push(matrix[2][i].top());
			matrix[2][i].pop();
			matrix[2][i].push(matrix[3][i].top());
			matrix[3][i].pop();
			matrix[3][i].push(0);
		}
		if (matrix[1][i].top() == matrix[2][i].top())//equal to the left element
		{
			count++;
			matrix[1][i].pop();
			matrix[1][i].push(2 * matrix[2][i].top());
			matrix[2][i].pop();
			matrix[2][i].push(matrix[3][i].top());
			matrix[3][i].pop();
			matrix[3][i].push(0);
		}
		//Check the third element
		if (matrix[2][i].top() == matrix[3][i].top())//equal to the left element
		{
			count++;
			matrix[2][i].pop();
			matrix[2][i].push(2 * matrix[3][i].top());
			matrix[3][i].pop();
			matrix[3][i].push(0);
		}
	}


	if (count > 0)
	{
		step++;
		move++;
		randombit(matrix);
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrix[i][j].pop();
			}
		}
	}
}
void shiftDown(vector<vector<stack<int>>>& matrix, int& step, int& move) {
	int count(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			matrix[i][j].push(matrix[i][j].top());
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (matrix[1][i].top() == 0 && matrix[0][i].top() != 0) {
			count++;
			matrix[1][i].pop();
			matrix[1][i].push(matrix[0][i].top());
			matrix[0][i].pop();
			matrix[0][i].push(0);
		}
		if (matrix[2][i].top() == 0 && (matrix[1][i].top() != 0 || matrix[0][i].top() != 0)) {
			count++;
			matrix[2][i].pop();
			matrix[2][i].push(matrix[1][i].top());
			matrix[1][i].pop();
			matrix[1][i].push(matrix[0][i].top());
			matrix[0][i].pop();
			matrix[0][i].push(0);
		}
		if (matrix[3][i].top() == 0 && (matrix[2][i].top() != 0 || matrix[1][i].top() != 0
			|| matrix[0][i].top() != 0)) {
			count++;
			matrix[3][i].pop();
			matrix[3][i].push(matrix[2][i].top());
			matrix[2][i].pop();
			matrix[2][i].push(matrix[1][i].top());
			matrix[1][i].pop();
			matrix[1][i].push(matrix[0][i].top());
			matrix[0][i].pop();
			matrix[0][i].push(0);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (matrix[3][i].top() == matrix[2][i].top() && matrix[2][i].top() != 0)//equal to the left element
		{
			count++;
			matrix[3][i].pop();
			matrix[3][i].push(2 * matrix[2][i].top());
			matrix[2][i].pop();
			matrix[2][i].push(matrix[1][i].top());
			matrix[1][i].pop();
			matrix[1][i].push(matrix[0][i].top());
			matrix[0][i].pop();
			matrix[0][i].push(0);
		}
		if (matrix[2][i].top() == matrix[1][i].top() && matrix[1][i].top() != 0)//equal to the left element
		{
			count++;
			matrix[2][i].pop();
			matrix[2][i].push(2 * matrix[1][i].top());
			matrix[1][i].pop();
			matrix[1][i].push(matrix[0][i].top());
			matrix[0][i].pop();
			matrix[0][i].push(0);
		}
		if (matrix[1][i].top() == matrix[0][i].top() && matrix[0][i].top() != 0)//equal to the left element
		{


			count++;
			matrix[1][i].pop();
			matrix[1][i].push(2 * matrix[0][i].top());
			matrix[0][i].pop();
			matrix[0][i].push(0);
		}
	}
	if (count > 0)
	{
		step++;
		move++;
		randombit(matrix);
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrix[i][j].pop();
			}
		}
	}
}
int checkPass(vector<Users>& users, string name, string pass) {
	for (int i = 0; i < users.size(); i++) {
		if (name.compare(users[i].getName()) == 0) {
			if (users[i].equals(name, pass)) {
				return i;
			}
		}
	}
	return -1;
}
int checkName(vector<Users>& users, string name, string pass) {
	for (int i = 0; i < users.size(); i++) {
		if (name.compare(users[i].getName()) == 0) {
			return -1; //Flag if username already exists
		}
	}
	return 1; //valid new name!!!
}
void checkUserSize(vector<Users>& users, int countUsers) {
	if (countUsers == users.size() - 1) {
		vector<Users> newUsers(users.size() * 2); //If the size is not enough,then double it!
		for (int i = 0; i < users.size(); i++) {
			newUsers[i] = users[i];
		}
		users = newUsers;
	}
}
void playGame(Users& user) {
	vector<vector<stack<int>>> matrix(4, vector<stack<int>>(4));
	bool success = false;
	int step = 0, score = 0;;
	int move = 0;
	int choose;
	//Initialize all 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j].push(0);
		}
	}
	//Create two random bits on on the matrix
	randomtwo(matrix);
	//Print the updated matrix
	score = getCurrentScore(matrix);


	cout << " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "\t\t";
		for (int j = 0; j < 4; j++) {
			cout << "\t" << matrix[i][j].top();
		}
		cout << "\n" << endl;
	}
	cout << "\t\tCurrent Score: " << score << "\t\tStep #: " << step << endl;
	cout << "\n" << " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n" << endl;


	// Success = 2048 exists on the game board
	//While not success, we continue to play the game.
	while (!success) {
		
		// Receive  instructions
		cout << "\t\t\tWhat are you going to do next?\n\tShift Right: 6\tShift Left: 4\tShift Up: 8\tShift Down:2\n\tUndo: 5\t\tQuit: 0" << endl;
		cin >> choose;
		switch (choose) {
		case 6: shiftRight(matrix, step, move);
			break;
		case 4: shiftLeft(matrix, step, move);
			break;
		case 8: shiftUp(matrix, step, move);
			break;
		case 2: shiftDown(matrix, step, move);
			break;
		case 5: undo(matrix, step); step--; move++;
			break;
		case 0: break;
		default: cout << ("Enter another number!") << endl;
			break;
		}
		gameover(matrix, user, getCurrentScore(matrix), step);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (matrix[i][j].top() == 2048) {
					success = true;  //if there is a 2048, then change success true
					break;
				}
			}
		}
		if (success) {
			user.Record(2048, step);
			cout << "YOU WIN!!!!!!!!" << endl;
			break;
		}
		if (choose == 0) {
			int score = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (matrix[i][j].top() >score) {
						score = matrix[i][j].top();
					}
				}
			}
			user.Record(score, step);
			break;
		}
		system("cls"); //clear the console
		//Print the updated matrix
		score = getCurrentScore(matrix);


		cout << " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n" << endl;
		for (int i = 0; i < 4; i++) {
			cout << "\t\t";
			for (int j = 0; j < 4; j++) {
				cout << "\t" << matrix[i][j].top();
			}
			cout << "\n" << endl;
		}
		cout << "\t\tCurrent Score: " << score << "\t\tStep #: " << step << endl;
		cout << "\n" << " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n" << endl;


	}
}
void playGame() {
	vector<vector<stack<int>>> matrix(4, vector<stack<int>>(4));
	bool success = false;
	int step = 0, score = 0;;
	int move = 0;
	int choose;
	//initialize all 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrix[i][j].push(0);
		}
	}
	//Create the initial two random bits on the matrix
	randomtwo(matrix);
	//Print the updated matrix
	score = getCurrentScore(matrix);
	cout << " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n" << endl;
	for (int i = 0; i < 4; i++) {
		cout << "\t\t";
		for (int j = 0; j < 4; j++) {
			cout << "\t" << matrix[i][j].top();
		}
		cout << "\n" << endl;
	}
	cout << "\t\tCurrent Score: " << score << "\t\tStep #: " << step << endl;
	cout << "\n" << " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n" << endl;

	// Success = 2048 exists on the game board
	//While not success, we continue to play the game.
	while (!success) {
		
		// receive  instructions
		cout << "\t\t\tWhat are you going to do next?\n\tShift Right: 6\tShift Left: 4\tShift Up: 8\tShift Down:2\n\tQuit: 0" << endl;
		cin >> choose;
		switch (choose) {
		case 6: shiftRight(matrix, step, move);
			break;
		case 4: shiftLeft(matrix, step, move);
			break;
		case 8: shiftUp(matrix, step, move);
			break;
		case 2: shiftDown(matrix, step, move);
			break;
		case 0: break;
		default: cout << ("Enter another number!") << endl;
		}
		system("cls"); //clear the console
		// print after every change 
		if (choose == 0) break;
		gameover(matrix);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (matrix[i][j].top() == 2048) {
					success = true;  //if there is a 2048, then change success true
					break;
				}
			}
		}
		if (success) break;
		//Print the updated matrix
		score = getCurrentScore(matrix);
		cout << " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n" << endl;
		for (int i = 0; i < 4; i++) {
			cout << "\t\t";
			for (int j = 0; j < 4; j++) {
				cout << "\t" << matrix[i][j].top();
			}
			cout << "\n" << endl;
		}
		cout << "\t\tCurrent Score: " << score << "\t\tStep #: " << step << endl;
		cout << "\n" << " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n" << endl;
	}
}
void printHistory(Users& user) {
	ifstream file;
	string filename = user.getName();
	filename.append(".txt");
	file.open(filename);
	if (file.fail())
	{
		cerr << "There was an error opening this user's record.\n";
		exit(1);
	}
	cout << user.getName() << "'s History:" << endl;
	cout << "Score\tStep" << endl;
	int score, step;
	for (int i = 0; i < user.getRecordNumber(); i++){
		file >> score >> step;
		cout << score <<"\t"<< step << endl;
	}
	file.close();
}
void titlescreen() {
	//Print title screen
	cout << " = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n" << endl;
	cout << "\t	#####   #######   #     #   #######	" << endl;
	cout << "\t	    #   #     #   #     #   #     #		" << endl;
	cout << "\t	    #   #     #   #     #   #     #		" << endl;
	cout << "\t	#####   #     #   #######   #######		" << endl;
	cout << "\t	#       #     #         #   #     #		" << endl;
	cout << "\t	#       #     #         #   #     #		" << endl;
	cout << "\t	#####   #######         #   #######	" << endl;
	cout << "\n = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n" << endl;
	cout << "\n     Programmed by Yiwen Jin, Haiying Jiang and Kurt Butler.\n\n\t\t\tPress enter to continue.";
	getchar();
}
//for bonus
void sortPrint(vector<Users> users,int count){
	Users tmp;
	for (int i = 0; i < count; i++){
		for (int j = 1; j < count; j++){
			if (users[i].maxScore() < users[j].maxScore()){
				tmp = users[i];
				users[i] = users[j];
				users[j] = tmp;
			}
			if (users[i].maxScore() == users[j].maxScore()){
				if (users[i].maxStep() > users[j].maxStep()){
					tmp = users[i];
					users[i] = users[j];
					users[j] = tmp;
				}
				if (users[i].maxStep() == users[j].maxStep()){
					if ((users[i].getName()).compare(users[j].getName()) == 1){
						tmp = users[i];
						users[i] = users[j];
						users[j] = tmp;
					}
				}
			}
		}
	}
	int r = 1;
	vector<int> rank(count);
	rank[0] = 1;
	for (int i = 1; i < count; i++){
		if (users[i].maxScore() == users[i - 1].maxScore() && users[i].maxStep() == users[i - 1].maxStep()){
			rank[i] = r;
		}
		else{
			r++;
			rank[i] = r;		
		}
	}
	cout << "Rank\tName\tScore\tStep" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << rank[i] << "\t"
			<< users[i].getName() << "\t"
			<< users[i].maxScore() << "\t"
			<< users[i].maxStep() << endl;
	}


}


int main() {
	titlescreen();
	system("cls");
	//Declaring and initializing objects
	int choose = 0;
	ifstream userInfoRead;  //this is to open usersInfromations file
	userInfoRead.open("userInfo.txt");
	if (userInfoRead.fail()) {


		cerr << "Can not find userInfo!" << endl;
		exit(1);
	}
	string Name, Password;
	vector<Users> users(100);

	//Initializing user vector
	int countUsers = 0;
	string a;
	//load user information into vector
	while (a != "end") {
		userInfoRead >> a;
		if (a.compare("") == 0){
			break;
		}
		else{
			Name = a;
			userInfoRead >> Password;
			users[countUsers++] = Users(Name, Password);
		}
	}
	countUsers--;
	userInfoRead.close();
	//Load the record from the users' files
	for (int i = 0; i < countUsers; i++) {
	users[i].LoadRecord();
	}	
	cout << "Do you want to play as Trial User(0) or Advanced User(1) or Just Check Ranks(2): ";
	cin >> choose;
	system("cls");//clear the console
	//test if the user enters a wrong number
	while (choose != 1 && choose != 0 && choose!=2) {
		cout << "You entered a wrong number!" << endl;
		cout << "Do you want to play as Trial User(0) or Advanced User(1) or Just Check Ranks(2): ";
		cin >> choose;
		system("cls");//clear the console
	}
	//this is for trial user
	if (choose == 0){
		playGame();
	}
	else if (choose == 2){
		sortPrint(users, countUsers);
	}
	//this is for advanced users;
	else if (choose == 1) {
		cout << "Do you want to create a new account(0) or just login(1)?";
		cin >> choose;
		system("cls");//clear the console
		//test if the user enters a wrong number
		while (choose != 0 && choose != 1) {
			cout << "You entered a wrong number!" << endl;
			cout << "Do you want to create a new account(0) or just login(1)?";
			cin >> choose;
			system("cls");//clear the console
		}
		//for login for advanced users
		if (choose == 1) {
			string name, pass;
			cout << "Please enter your name:";
			cin >> name;
			cout << "Please enter your password:";
			cin >> pass;
			system("cls");//clear the console
			while (checkPass(users, name, pass) == -1) {
				cout << "The name or password is wrong!!!" << endl;
				cout << "Please enter your name:";
				cin >> name;
				cout << "Please enter your password:";
				cin >> pass;
				system("cls");//clear the console
			}
			
			
			cout << "Do you want to print game history(0) or print best record(1) or play game(2): " << endl;
			cin >> choose;
			system("cls");//clear the console		
			while (choose != 0 && choose != 1 && choose != 2) {
				cout << "You entered a wrong number!" << endl;
				cout << "Do you want to print game history(0) or print best record(1) or play game(2): " << endl;
				cin >> choose;
				system("cls");//clear the console
			}
			switch (choose) {
			case 0:printHistory(users[checkPass(users, name, pass)]);
				break;
			case 1:cout << "The best score for " << users[checkPass(users, name, pass)].getName() << " is " << users[checkPass(users, name, pass)].maxScore() << endl;
				break;
			case 2:playGame(users[checkPass(users, name, pass)]);
			}
		}
		//create a new account for advanced users
		else  {
			int position = 0;
			//check whether the size is enough	
			checkUserSize(users, countUsers);
			string name, pass;
			cout << "Please enter your name:";
			cin >> name;
			cout << "Please enter your password:";
			cin >> pass;
			system("cls");//clear the console
			//check whether name already exists!
			while (checkName(users, name, pass) == -1) {
				cout << "The name has already exists!!!" << endl;
				cout << "Please enter the name:";
				cin >> name;
				cout << "Please enter the password:";
				cin >> pass;
				system("cls");//clear the console
			}
			// record the user information in UserInfo.txt;
			ofstream userInfoWrite;
			//Reopen it for writing new information in it
			userInfoWrite.open("userInfo.txt");
			for (int i = 0; i < countUsers; i++) {
			userInfoWrite << users[i].getName() << " " << users[i].getPass() << endl;
			}
			userInfoWrite << name << " " << pass << endl;
			userInfoWrite << "end" << endl;
			userInfoWrite.close();
			//creat an file named by userName to store the history;	
			makeFile(name);
			users[countUsers] = Users(name, pass);
			countUsers++;
			//then, play the game!!!
			playGame(users[countUsers - 1]);			
		}
	}	
	getchar();
	getchar();
	return 0;
}






