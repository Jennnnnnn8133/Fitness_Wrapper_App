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
#include "FitnessAppWrapper.hpp"

FitnessAppWrapper::FitnessAppWrapper()
{
	for (int i = 0; i < 7; i++)
	{
		dietPlanWeekly[i].setPlanName(""); // Initialize An Empty String
		dietPlanWeekly[i].setGoalCalories(0);
		dietPlanWeekly[i].setDate("");
	}

	for (int i = 0; i < 7; i++)
	{
		exercisePlanWeekly[i].setPlanName("");
		exercisePlanWeekly[i].setGoalSteps(0);
		exercisePlanWeekly[i].setDate("");
	}
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	cout << "Inside Fitness App Wrapper Destructor!" << endl;
}

void FitnessAppWrapper::runApp()
{
	int  menuOption = 0, editDailyOption = 0;

	while (menuOption != 9)
	{
		menuOption = displayMenu();

		switch (menuOption)
		{
		case 1:
			dietPlanfstr.open("dietPlans.txt");
			loadWeeklyPlan(dietPlanfstr, dietPlanWeekly);
			dietPlanfstr.close();
			break;

		case 2:
			exercisePlanfstr.open("exercisePlans.txt");
			loadWeeklyPlan(exercisePlanfstr, exercisePlanWeekly);
			exercisePlanfstr.close();
			break;

		case 3:
			storeWeeklyPlan(dietPlanWeekly);
			break;

		case 4:
			storeWeeklyPlan(exercisePlanWeekly);
			break;

		case 5:
			displayWeeklyPlan(dietPlanWeekly);
			break;

		case 6:
			displayWeeklyPlan(exercisePlanWeekly);
			break;

		case 7:
			cout << "You Choose To Edit Daily Diet Plan!" << endl;
			editDailyOption = getEditDailyOption();
			editDailyPlan(dietPlanWeekly[editDailyOption]);
			break;

		case 8:
			cout << "You Choose To Edit Daily Exercise Plan!" << endl;
			editDailyOption = getEditDailyOption();
			editDailyPlan(exercisePlanWeekly[editDailyOption]);
			break;

		case 9:
			cout << "Exit!" << endl;
			break;
		}
	}
}

void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[])
{
	string line;
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[])
{
	string line;
	for (int i = 0; i < 7; i++)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan oneDayDisplay)
{
	cout << "Plan Name: " << oneDayDisplay.getPlanName() << endl;
	cout << "Goal Calories: " << oneDayDisplay.getGoalCalories() << endl;
	cout << "Date: " << oneDayDisplay.getDate() << endl << endl; // One more '<< endl' for '(blank line)'
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan oneDayDisplay)
{
	cout << "Plan Name: " << oneDayDisplay.getPlanName() << endl;
	cout << "Goal Steps: " << oneDayDisplay.getGoalSteps() << endl;
	cout << "Date: " << oneDayDisplay.getDate() << endl << endl; // One more '<< endl' for '(blank line)'
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan oneWeekDisplay[])
{
	cout << "---------- Displaying Eeekly Diet Plan ----------" << endl << endl;
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(oneWeekDisplay[i]);
	}
	cout << "-------------------------------------------------" << endl << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan oneWeekDisplay[])
{
	cout << "-------- Displaying Weekly Exercise Plan --------" << endl << endl;
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(oneWeekDisplay[i]);
	}
	cout << "-------------------------------------------------" << endl << endl;
}

void FitnessAppWrapper::storeDailyPlan(fstream& fileStream, DietPlan& oneDayStore)
{
	fileStream << oneDayStore.getPlanName() << endl;
	fileStream << oneDayStore.getGoalCalories() << endl;
	fileStream << oneDayStore.getDate() << endl << endl; // One more '<< endl' for '(blank line)'
}

void FitnessAppWrapper::storeDailyPlan(fstream& fileStream, ExercisePlan& oneDayStore)
{
	fileStream << oneDayStore.getPlanName() << endl;
	fileStream << oneDayStore.getGoalSteps() << endl;
	fileStream << oneDayStore.getDate() << endl << endl; // One more '<< endl' for '(blank line)'
}

void FitnessAppWrapper::storeWeeklyPlan(DietPlan oneWeekStore[])
{
	dietPlanfstr.open("dietPlans.txt");

	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(dietPlanfstr,oneWeekStore[i]);
	}

	dietPlanfstr.close();
}

void FitnessAppWrapper::storeWeeklyPlan(ExercisePlan oneWeekStore[])
{
	exercisePlanfstr.open("exercisePlans.txt");

	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(exercisePlanfstr, oneWeekStore[i]);
	}

	exercisePlanfstr.close();
}

int FitnessAppWrapper::getEditDailyOption()
{
	int editDailyOption = 0;

	cout << "Please Enter The Day Of The Plan You Want To Edit(1-7): " << endl;
	cin >> editDailyOption;

	if ((editDailyOption < 1) || (editDailyOption > 7))
	{
		editDailyOption = getEditDailyOption();
	}

	return editDailyOption - 1;
}

int FitnessAppWrapper::getEditDailyDietPlanOption()
{
	int editDailyDietPlanOption = 0;

	cout << "------------- Edit Daily Diet Plans -------------" << endl << endl;
	cout << "1.Plan Name" << endl;
	cout << "2.Goal Calories" << endl;
	cout << "3.Date" << endl;
	cout << "4.Finished" << endl;
	cout << "-------------------------------------------------" << endl << endl;

	cout << "Please Enter The Serial Number Of Your Option: " << endl;
	cin >> editDailyDietPlanOption;

	return editDailyDietPlanOption;
}

int FitnessAppWrapper::getEditDailyExercisePlanOption()
{
	int editDailyExercisePlanOption = 0;

	cout << "----------- Edit Daily Exercise Plans -----------" << endl << endl;
	cout << "1.Plan Name" << endl;
	cout << "2.Goal Steps" << endl;
	cout << "3.Date" << endl;
	cout << "4.Finished" << endl;
	cout << "-------------------------------------------------" << endl << endl;

	cout << "Please Enter The Serial Number Of Your Option: " << endl;
	cin >> editDailyExercisePlanOption;

	return editDailyExercisePlanOption;
}

void FitnessAppWrapper::editDailyPlan(DietPlan &oneDayDisplay)
{
	int editDailyDietPlanOption = 0;

	while (editDailyDietPlanOption != 4)
	{
		editDailyDietPlanOption = getEditDailyDietPlanOption();

		switch (editDailyDietPlanOption)
		{
		case 1:
			oneDayDisplay.editPlanName();
			break;

		case 2:
			oneDayDisplay.editGoalCalories();
			break;

		case 3:
			oneDayDisplay.editDate();
			break;

		case 4:
			cout << "Edit Successfully!" << endl;
			break;
		}
	}
}

void FitnessAppWrapper::editDailyPlan(ExercisePlan &oneDayDisplay)
{
	int editDailyExercisePlanOption = 0;

	while (editDailyExercisePlanOption != 4)
	{
		editDailyExercisePlanOption = getEditDailyExercisePlanOption();

		switch (editDailyExercisePlanOption)
		{
		case 1:
			oneDayDisplay.editPlanName();
			break;

		case 2:
			oneDayDisplay.editGoalSteps();
			break;

		case 3:
			oneDayDisplay.editDate();
			break;

		case 4:
			cout << "Edit Successfully!" << endl;
			break;
		}
	}
}

int FitnessAppWrapper::displayMenu()
{
	int menuOption = 0;

	cout << "******************** M E N U ********************" << endl;
	cout << "1.Load Weekly Diet Plan From File" << endl;
	cout << "2.Load Weekly Exercise Plan From File" << endl;
	cout << "3.Store Weekly Diet Plan To File" << endl;
	cout << "4.Store Weekly Exercise Plan To File" << endl;
	cout << "5.Display Weekly Diet Plan To Screen" << endl;
	cout << "6.Display Weekly Exercise Plan To Screen" << endl;
	cout << "7.Edit Daily Diet Plan" << endl;
	cout << "8.Edit Daily Exercise Plan" << endl;
	cout << "9.Exit" << endl;
	cout << "*************************************************" << endl;
	
	cout << "Please Enter The Serial Number Of Your Option: " << endl;
	cin >> menuOption;

	return  menuOption;
}
