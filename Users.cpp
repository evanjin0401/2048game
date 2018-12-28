#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;


class Users{
private:
	string name;
	string password;
	vector<vector<int>> record;
	int countRecord = 0;
public:
	Users() {
		name = "";
		password = "";
	}
	Users(string newname, string newpass) {
		name = newname;
		password = newpass;
		vector<vector<int>> temp(100, vector<int>(2));
		record = temp;
	}
	string getName() {
		return name;
	}
	string getPass() {
		return password;
	}
	bool equals(string newname, string newpass) {
		if (newname.compare(name) == 0 && newpass.compare(password) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void Record(int score, int step) {
		//check if the size is enough...
		if (countRecord == record.size() - 1) {
			vector<vector<int>> newRecord(record.size() * 2); //if the size is not enough,then double it!
			for (int i = 0; i < record.size(); i++) {
				newRecord[i][0] = record[i][0];
				newRecord[i][1] = record[i][1];
			}
			record = newRecord;
		}
		
		//update the information in userName.txt
		ofstream file;
		string filename = name;
		filename.append(".txt");
		file.open(filename);
		if (file.fail())
		{
			cerr << "There was an error opening this user's record.\n";
			exit(1);
		}

		for (int i = 0; i < countRecord; i++){
			file << record[i][0] <<" "<< record[i][1]<<endl;
		}
		record[countRecord][0] = score;
		record[countRecord][1] = step;
		file << score <<" "<< step << endl;
		file.close();
	}
	vector<vector<int>> getRecord() {
		return record;
	}
	int maxScore() {
		int max = 0;
		for (int i = 0; i < record.size(); i++) {
			if (record[i][0] > record[max][0]) max = i; //compare the scores;
			//if the scores are same, just check step
			if (record[i][0] == max &&record[i][1] <= record[max][1]) max = i;
		}
		return record[max][0];
	}
	int maxStep() {
		int max = 0;
		for (int i = 0; i < record.size(); i++) {
			if (record[i][0] > record[max][0]) max = i; //compare the scores;
			//if the scores are same, just check step
			if (record[i][0] == record[max][0] && record[i][1] <= record[max][1]) max = i;
		}
		return record[max][1];
	}
	void LoadRecord() {
		ifstream file;
		string filename = name;
		filename.append(".txt");
		file.open(filename);
		if (file.fail())
		{
			cerr << "There was an error opening this user's record.\n";
			exit(1);
		}
		countRecord = 0;
		while (!file.eof())
		{
			file >> record[countRecord][0] >> record[countRecord][1];
			countRecord++;
		}
		countRecord--;
		file.close();
	}
	vector<vector<int>> getRecords() {
		return record;
	}
	int getRecordNumber(){
		return countRecord;
	}
};
