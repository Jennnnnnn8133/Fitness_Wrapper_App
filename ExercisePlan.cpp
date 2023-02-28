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
#include "ExercisePlan.hpp"

ExercisePlan::ExercisePlan()
{
	mPlanName = '\0';
	mGoalSteps = 0;
	mDate = '\0';
}

ExercisePlan::ExercisePlan(ExercisePlan& copy)
{
	mPlanName = copy.getPlanName();
	mGoalSteps = copy.getGoalSteps();
	mDate = copy.getDate();
}

ExercisePlan::~ExercisePlan()
{

}

void ExercisePlan::setPlanName(const string newPlanName)
{
	mPlanName = newPlanName;
}

void ExercisePlan::setGoalSteps(const int newGoalSteps)
{
	// Set the goal steps as the valid data
	if (newGoalSteps >= 0)
	{
		mGoalSteps = newGoalSteps;
		//cout << "New Goal Steps Is valid!" << endl;
		//cout << "Set Goal Steps As New Goal Steps!" << endl;
	}

	else
	{
		mGoalSteps = 0;
		//cout << "New Goal Steps Is invalid!" << endl;
		//cout << "Set Goal Steps As Zero!" << endl;
	}
}

void ExercisePlan::setDate(const string newDate)
{
	mDate = newDate;
}

string ExercisePlan::getPlanName() const
{
	return mPlanName;
}

int ExercisePlan::getGoalSteps() const
{
	return mGoalSteps;
}

string ExercisePlan::getDate() const
{
	return mDate;
}

void ExercisePlan::editPlanName()
{
	string newPlanName;
	cout << "Plan Name: " << getPlanName() << endl;
	cout << "Set New Plan Name: " << endl;
	cin >> newPlanName;
	setPlanName(newPlanName);
	cout << "Edit Successfully!" << endl;
	cout << "New Plan Name: " << mPlanName << endl;
}

void ExercisePlan::editGoalSteps()
{
	int newGoalSteps = 0;
	cout << "Goal Steps: " << getGoalSteps() << endl;
	cout << "Set New Goal Steps: " << endl;
	cin >> newGoalSteps;
	setGoalSteps(newGoalSteps);
	cout << "Edit Successfully!" << endl;
	cout << "New Goal Steps: " << mGoalSteps << endl;
}

void ExercisePlan::editDate()
{
	string newDate;
	cout << "Date: " << getDate() << endl;
	cout << "Set New Date(MM/DD/YYYY): " << endl;
	cin >> newDate;
	setDate(newDate);
	cout << "Edit Successfully!" << endl;
	cout << "New Date: " << mDate << endl;
}

ostream& operator<< (ostream& lhs, const ExercisePlan& rhs)
{
	lhs << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs;
}

fstream& operator<< (fstream& lhs, const ExercisePlan& rhs)
{
	(ofstream&)lhs << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs;
}

fstream& operator>> (fstream& lhs, ExercisePlan& rhs)
{
	int goalSteps = 0;
	string line;

	if ((lhs.is_open()) && (!lhs.eof()))
	{
		getline(lhs, line);
		rhs.setPlanName(line);
		getline(lhs, line);
		// stoi: const string*; atoi: const char*
		// c_str() can be used to transform const string* to const char*
		goalSteps = stoi(line);
		rhs.setGoalSteps(goalSteps);
		getline(lhs, line);
		rhs.setDate(line);
		getline(lhs, line);
	}

	return lhs;
}

