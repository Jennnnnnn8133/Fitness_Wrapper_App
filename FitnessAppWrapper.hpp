#pragma once
/*******************************************************************************************
* Programmer: Jenny Cheng                                                                     *
* Class: CptS 122, Spring 2022; Lab Section 4   										   *
* Programming Assignment#4: Basic Fitness Application in C++							   *
* Date: March 06, 2022																	   *
* Description: Write a basic fitness application, in C++, that allows the user of the	   *
* application to manually edit ¡°diet¡± and ¡°exercise¡± plans. For this application you   *
* will need to create three classes: DietPlan, ExercisePlan, and FitnessAppWrapper.		   *
*******************************************************************************************/

#include "pa4.hpp"
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

#ifndef FITNESSAPPWRAPPER_HPP
#define FITNESSAPPWRAPPER_HPP

class FitnessAppWrapper
{
public:
	FitnessAppWrapper(); // Constructor
	~FitnessAppWrapper(); // Destructor

	void runApp(void);

	void loadDailyPlan(fstream& fileStream, DietPlan& plan);
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);
	void loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);

	void displayDailyPlan(DietPlan oneDayDisplay);
	void displayDailyPlan(ExercisePlan oneDayDisplay);
	void displayWeeklyPlan(DietPlan oneWeekDisplay[]);
	void displayWeeklyPlan(ExercisePlan oneWeekDisplay[]);

	void storeDailyPlan(fstream& fileStream, DietPlan& oneDayStore);
	void storeDailyPlan(fstream& fileStream, ExercisePlan& oneDayStore);
	void storeWeeklyPlan(DietPlan oneWeekStore[]);
	void storeWeeklyPlan(ExercisePlan oneWeekStore[]);

	int getEditDailyOption();
	int getEditDailyDietPlanOption();
	int getEditDailyExercisePlanOption();
	void editDailyPlan(DietPlan& oneDayDisplay);
	void editDailyPlan(ExercisePlan& oneDayDisplay);

	int displayMenu();

private:
	DietPlan dietPlanWeekly[7];
	ExercisePlan exercisePlanWeekly[7];

	fstream dietPlanfstr;
	fstream exercisePlanfstr;
};

#endif