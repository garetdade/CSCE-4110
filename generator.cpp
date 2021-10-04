#include <bits/stdc++.h>
using namespace std;

const int END = 1000000;
const int RANGE1 = 10;
const int RANGE2 = 1000000;

int main(){
	char name[20];
	stringstream s;
	ofstream outfile;
	
	for(int i=1;i<=10;i++)
	{
		s.clear();
		s<<i<<"_10.txt";
		s>>name;
		outfile.open(name);
		for(int j=0;j<END;j++) {
			outfile << rand() % RANGE1 + 1 << endl;
		}
		outfile.close();
	}
	
	for(int i=1;i<=10;i++)
	{
		s.clear();
		s<<i<<"_M.txt";
		s>>name;
		outfile.open(name);
		for(int j=0;j<END;j++) {
			outfile << rand() % RANGE2 + 1 << endl;
		}
		outfile.close();
	}
	
	return 0;
}
