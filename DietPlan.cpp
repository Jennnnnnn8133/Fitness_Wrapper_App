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
#include "DietPlan.hpp"

DietPlan::DietPlan()
{
	mPlanName = '\0';
	mGoalCalories = 0;
	mDate = '\0';
}

DietPlan::DietPlan(const DietPlan& copy)
{
	mPlanName = copy.getPlanName();
	mGoalCalories = copy.getGoalCalories();
	mDate = copy.getDate();
}

DietPlan::~DietPlan()
{

}

void DietPlan::setPlanName(const string newPlanName)
{
	mPlanName = newPlanName;
}

void DietPlan::setGoalCalories(const int newGoalCalories)
{
	// Set the goal calories as the valid data
	if (newGoalCalories >= 0)
	{
		mGoalCalories = newGoalCalories;
		//cout << "New Goal Calories Is valid!" << endl;
		//cout << "Set Goal Calories As New Goal Calories!" << endl;
	}

	else
	{
		mGoalCalories = 0;
		//cout << "New Goal Calories Is invalid!" << endl;
		//cout << "Set Goal Calories As Zero!" << endl;
	}
}

void DietPlan::setDate(const string newDate)
{
	mDate = newDate;
}

string DietPlan::getPlanName() const
{
	return mPlanName;
}

int DietPlan::getGoalCalories() const
{
	return mGoalCalories;
}

string DietPlan::getDate() const
{
	return mDate;
}

void DietPlan::editPlanName()
{
	string newPlanName;
	cout << "Plan Name: " << getPlanName() << endl;
	cout << "Set New Plan Name: " << endl;
	cin >> newPlanName;
	setPlanName(newPlanName);
	cout << "Edit Successfully!" << endl;
	cout << "New Plan Name: " << mPlanName << endl;
}

void DietPlan::editGoalCalories()
{
	int newGoalCalories = 0;
	cout << "Goal Calories: " << getGoalCalories() << endl;
	cout << "Set New Goal Calories: " << endl;
	cin >> newGoalCalories;
	setGoalCalories(newGoalCalories);
	cout << "Edit Successfully!" << endl;
	cout << "New Goal Calories: " << mGoalCalories << endl;
}

void DietPlan::editDate() 
{
	string newDate;
	cout << "Date: " << getDate() << endl;
	cout << "Set New Date(MM/DD/YYYY): " << endl;
	cin >> newDate;
	setDate(newDate);
	cout << "Edit Successfully!" << endl;
	cout << "New Date: " << mDate << endl;
}

ostream& operator<< (ostream& lhs, const DietPlan& rhs)
{
	lhs << rhs.getPlanName() << endl << rhs.getGoalCalories() << endl << rhs.getDate();

	return lhs;
}

fstream& operator<< (fstream& lhs, const DietPlan& rhs)
{
	(ofstream&) lhs << rhs.getPlanName() << endl << rhs.getGoalCalories() << endl << rhs.getDate();

	return lhs;
}

fstream& operator>> (fstream& lhs, DietPlan& rhs)
{
	int goalCalories = 0;
	string line;

	if ((lhs.is_open()) && (!lhs.eof()))
	{
		getline(lhs, line);
		rhs.setPlanName(line);
		getline(lhs, line);
		// stoi: const string*; atoi: const char*
		// c_str() can be used to transform const string* to const char*
		goalCalories = stoi(line);
		rhs.setGoalCalories(goalCalories);
		getline(lhs, line);
		rhs.setDate(line);
		getline(lhs, line);
	}

	return lhs;
}
