#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

const int END = 1000000;
const int RANGE = 1000000;

int main(){
	string name;
	cout << "name of file: ";
	cin >> name;
	name += ".txt";
	
	ofstream file(name);
	//file.open(name);
	
	for(int i = 0; i < END; i++) {
		file << rand() % RANGE + 1 << endl;
	}
	
	file.close();
	
	return 0;
}