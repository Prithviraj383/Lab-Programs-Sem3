#include<iostream>

using namespace std;

int main(){

	const int cities = 5;
	const int days = 6;
	float temp[cities][days];
	float h=0, l=0;
	int hCity = 0, lCity = 0, hDay = 0, lDay = 0;
	cout  << "Enter the temperature of 5 cities for 6 days:  \n";
	for(int i=0;i<cities;++i){
		cout << "Enter temperatures of City " << i+1 << " with a space " << endl;
		for(int j=0;j<days;++j){
			cin >> temp[i][j];
		}
	}
	h = l = temp[0][0];
	for(int i=0;i<cities;++i){
		for(int j = 0;j<days;++j){
			if(temp[i][j] > h){
				h = temp[i][j];
				hCity = i;
				hDay = j;
			}
			else{
				l = temp[i][j];
				lCity = i;
				lDay = j;
			}
		}
	}
	
	cout << "\nHighest temperature = " << h <<  " ( City = " << hCity + 1 << " , Day = " << hDay +1 << " )\n";
	
		
	cout << "\nLowest temperature = " << l <<  " ( City = " << lCity + 1 << " , Day = " << lDay +1 << " )\n";
	return 0;
}