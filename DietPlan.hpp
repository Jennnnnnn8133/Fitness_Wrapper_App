#pragma once
/*******************************************************************************************
* Programmer: Jenny Cheng                                                                   *
* Class: CptS 122, Spring 2022; Lab Section 4											   *
* Programming Assignment#4: Basic Fitness Application in C++							   *
* Date: March 06, 2022																	   *
* Description: Write a basic fitness application, in C++, that allows the user of the	   *
* application to manually edit ¡°diet¡± and ¡°exercise¡± plans. For this application you   *
* will need to create three classes: DietPlan, ExercisePlan, and FitnessAppWrapper.		   *
*******************************************************************************************/

#include "pa4.hpp"

#ifndef DIETPLAN_HPP
#define DIETPLAN_HPP

class DietPlan
{
public:
	DietPlan(); // Constructor
	DietPlan(const DietPlan& copy); // Copy constructor
	~DietPlan(); // Destructor

	// Setters
	void setPlanName(const string newPlanName);
	void setGoalCalories(const int newGoalCalories);
	void setDate(const string newDate);

	// Getters
	string getPlanName() const;
	int getGoalCalories() const;
	string getDate() const;

	// editGoal
	void editPlanName();
	void editGoalCalories();
	void editDate();

private:
	// Declaring datas
	string mPlanName;
	int mGoalCalories;
	string mDate;
};

// Ex.
// DiePlan A, B, C
// A << B << C

ostream& operator<< (ostream& lhs, const DietPlan& rhs);

fstream& operator<< (fstream& lhs, const DietPlan& rhs);

fstream& operator>> (fstream& lhs, DietPlan& rhs);

#endif