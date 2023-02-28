# Fitness_Wrapper_App
Basic fitness application, in C++
The project aims to develop a FitnessAppWrapper class that wraps a fitness application. This class should contain two lists, one for diet and one for exercise weekly plans, and two file streams, one for input and one for output. The weekly plans will consist of seven daily plans, and each daily plan will be a separate instance of either a DietPlan or ExercisePlan class. These plans will be stored in a linear data structure, such as an array, vector, or linked list, with each plan being inserted into the next available position.

One important consideration when developing the solution is the time complexity of inserting plans into the linear data structure. Inserting at the end of an array or vector requires constant time, while inserting at the end of a linked list with only a head pointer requires linear time. Therefore, the developer should take this into account when selecting the appropriate data structure for the application.

The FitnessAppWrapper class must define several member functions, including runApp() to start the main application, loadDailyPlan() to read one record from the given file stream for either a DietPlan or an ExercisePlan, and loadWeeklyPlan() to read all seven daily plans from the file stream. The displayDailyPlan() function should write a daily plan to the screen using an overloaded stream insertion operator, and displayWeeklyPlan() should write a weekly plan to the screen by calling displayDailyPlan() for each day. The storeDailyPlan() function writes a daily plan to a file and overwrites the file entirely, while storeWeeklyPlan() writes a weekly plan to a file by calling storeDailyPlan() for each day.

- The project involves creating DietPlan and ExercisePlan classes that store plans in a linear data structure such as an array, vector, or linked list.
- Inserting at the end of an array or vector takes constant time, while inserting at the end of a linked list takes linear time.
- The FitnessAppWrapper class is used to wrap the application and must contain two lists of weekly plans (one for diet and one for exercise) as well as two file streams (one for input and one for output).
- The member functions of FitnessAppWrapper include runApp, loadDailyPlan, loadWeeklyPlan, displayDailyPlan, displayWeeklyPlan, storeDailyPlan, storeWeeklyPlan, and displayMenu.
- The loadDailyPlan function reads one record from the given stream and is overloaded for DietPlan and ExercisePlan.
- The loadWeeklyPlan function reads in all seven daily plans from the given stream and is also overloaded for DietPlan and ExercisePlan. It calls loadDailyPlan directly.
- The displayDailyPlan function writes a daily plan to the screen using the overloaded stream insertion operator. It is also overloaded for DietPlan and ExercisePlan.
- The displayWeeklyPlan function writes a weekly plan to the screen and calls displayDailyPlan. It is also overloaded for DietPlan and ExercisePlan.
- The storeDailyPlan function writes a daily plan to a file and overwrites the file entirely. It uses the overloaded stream insertion operator and is also overloaded for DietPlan and ExercisePlan.
- The storeWeeklyPlan function writes a weekly plan to a file and calls storeDailyPlan. It uses the overloaded stream insertion operator and is also overloaded for DietPlan and ExercisePlan.
- The displayMenu function displays nine menu options, including loading and storing weekly plans, displaying weekly plans, and editing daily plans for both diet and exercise.

Finally, the displayMenu() function displays nine menu options, including loading and storing weekly diet and exercise plans, displaying weekly plans to the screen, and editing daily plans. Each of these options should be implemented using the appropriate member functions defined in the FitnessAppWrapper class. Overall, the project aims to create a fitness application that allows users to manage their diet and exercise plans by reading, writing, and editing plans using a simple menu interface.
