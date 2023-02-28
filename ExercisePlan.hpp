#pragma once
/*******************************************************************************************
* Programmer: Jenny Cheng                                                                     *
* Class: CptS 122, Spring 2022; Lab Section 4											   *
* Programming Assignment#4: Basic Fitness Application in C++							   *
* Date: March 06, 2022																	   *
* Description: Write a basic fitness application, in C++, that allows the user of the	   *
* application to manually edit ¡°diet¡± and ¡°exercise¡± plans. For this application you   *
* will need to create three classes: DietPlan, ExercisePlan, and FitnessAppWrapper.		   *
*******************************************************************************************/

#include "pa4.hpp"

#ifndef EXERCISEPLAN_HPP
#define EXERCISEPLAN_HPP

class ExercisePlan
{
public:
	ExercisePlan(); // Constructor
	ExercisePlan(ExercisePlan &copy); // Copy constructor
	~ExercisePlan(); // Destructor

	// Setters
	void setPlanName(const string newPlanName);
	void setGoalSteps(const int newGoalSteps);
	void setDate(const string newDate);

	// Getters
	string getPlanName() const;
	int getGoalSteps() const;
	string getDate() const;

	// editGoal
	void editPlanName();
	void editGoalSteps();
	void editDate();

private:
	string mPlanName;
	int mGoalSteps;
	string mDate;
};

// Ex.
// DiePlan A, B, C
// A << B << C

ostream& operator<< (ostream& lhs, const ExercisePlan& rhs);

fstream& operator<< (fstream& lhs, const ExercisePlan& rhs);

fstream& operator>> (fstream& lhs, ExercisePlan& rhs);

#endif