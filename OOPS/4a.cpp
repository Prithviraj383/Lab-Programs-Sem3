// an election ins contested by 5 cnadidates the candidates are membered 1 to 5 and coting is done by marking the candidates number on the ballot and count they votes cast for each candidate using an arrya variables count. in case a number reas in outside the range 1 to 5
#include<iostream>
using namespace std;
int main(){
	int votes,candidate;
	
	cout << "Enter the number of votes" << endl;
	cin >> votes;
	int count[votes] = {0};
	for(int i = 0;i<votes;i++){
		cout<< "vote " << i+1<<" ";
		cin >> candidate;
		if(candidate >=1 && candidate <=5) count[candidate]++;
		else count[5]++;	
	}
	cout << "vote count" << endl;
	for(int i = 1;i<=5;i++){
		cout << "candidate " << i << " " << count[i] << endl;
	
	}
	cout << "spoilt ballots : " << count[5] << endl;
	return 0;
}