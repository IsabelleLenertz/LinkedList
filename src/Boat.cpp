/*
 * Boat.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: Isabelle
 */

#include "Boat.hpp"

Boat::Boat() {
	// TODO Auto-generated constructor stub

}

Boat::~Boat() {
	cout << "You are destroying a boat. " << endl;
}

double Boat::getLength(){
	return this->length;
}
double Boat::getWidth(){
	return this->width;
}
double Boat::getWeight()
{
	return this->weight;
}
string Boat::getModel()
{
	return this->model;
}

bool Boat::setLength(double newLength)
{
	this->length = newLength;
	return true;
}
bool Boat::setWidth(double newWidth)
{
	this->width = newWidth;
	return true;

}
bool Boat::setWeight(double newWeight){
	this->weight = newWeight;
	return true;
}
bool Boat::setModel(string newModel){
	this->model = newModel;
	return true;
}

string Boat::whatAmI(){
	string theWeight;

	ostringstream converter;
	converter << this->getWeight();

	theWeight = converter.str();

	return "I am a " + this->getModel()+ ", " + theWeight + " meters long";
}
