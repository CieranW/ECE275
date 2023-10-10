#include "Instrument.h"

void Instrument::SetName(string userName) {
	instrumentName = userName;
}

string Instrument::GetName() {
	return instrumentName;
}

void Instrument::SetManufacturer(string userManufacturer) {
	instrumentManufacturer = userManufacturer;
}

string Instrument::GetManufacturer() {
	return instrumentManufacturer;
}

void Instrument::SetYearBuilt(int userYearBuilt) {
	yearBuilt = userYearBuilt;
}

int Instrument::GetYearBuilt() {
	return yearBuilt;
}

void Instrument::SetCost(int userCost) {
	cost = userCost;
}

int Instrument::GetCost() {
	return cost;
}

void Instrument::PrintInfo() {
	cout << "Instrument Information: " << endl;
	cout << "   Name: " << instrumentName << endl;
	cout << "   Manufacturer: " << instrumentManufacturer << endl;
	cout << "   Year built: " << yearBuilt << endl;
	cout << "   Cost: " << cost << endl;
}