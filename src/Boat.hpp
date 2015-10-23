/*
 * Boat.hpp
 *
 *  Created on: Oct 22, 2015
 *      Author: Isabelle
 */

#ifndef BOAT_HPP_
#define BOAT_HPP_

#include <iostream>
#include <sstream>

using namespace std;


class Boat {

private:
	double length;
	double width;
	double weight;
	string model;

public:
	Boat();
	virtual ~Boat();

	double getLength();
	double getWidth();
	double getWeight();
	string getModel();

	bool setLength(double);
	bool setWidth(double);
	bool setWeight(double);
	bool setModel(string);

	string whatAmI();
};

#endif /* BOAT_HPP_ */
