/*******************************************************************************************
* Programmer: Jenny Cheng                                                                     *
* Class: CptS 122, Spring 2022; Lab Section 4											   *
* Programming Assignment#4: Basic Fitness Application in C++							   *
* Date: March 06, 2022																	   *
* Description: Write a basic fitness application, in C++, that allows the user of the	   *
* application to manually edit ¡°diet¡± and ¡°exercise¡± plans. For this application you   *
* will need to create three classes: DietPlan, ExercisePlan, and FitnessAppWrapper.		   *
*******************************************************************************************/

#include "DietPlan.hpp"
#include "ExercisePlan.hpp"
#include "FitnessAppWrapper.hpp"

int main(void)
{
	FitnessAppWrapper basicFitnessApplication;
	basicFitnessApplication.runApp();

	return 0;
}
