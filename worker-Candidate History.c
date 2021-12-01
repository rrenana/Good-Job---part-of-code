#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 30
#define S 10



typedef struct
{
	char name_of_job[N];
	char name_of_company[N];
	char employment_catagory[N];//תחום המשרה
	char location_area[N];//מיקום
	char scope_of_the_job[N];//היקף המשרה
	char salary_range[N];//טווח השכר לשעה
	int index_boss;
	int arr_index_worker[100];//את מערך כל המגישים לאתחל לנאל?????????????
	int code;//מספר סידורי של משרה
	//char job_requirements[N];//דרישות התפקיד
}Job;

typedef struct 
{
	char first_name[S];
	char last_name[S];
	char gender[S];
	char id[S];
	int age[S];
	char phone_number[S];
	int password;
	char Email[25];
	char living_area[5];
	char Driving_License[5];
	char Education_level[N];
	char Employment_Catagory[N];
	int policies;
	int apply_jobs[10];
}Employee;

int main()
{
	printf("For Candidate history press 2\n");


	return 0;
}


Job* pull_from_file(Employee arr[], int size)
{
	int i;
	FILE* fp = fopen("secret.log", "r");
	for (i = 0; i < size; i++)
		fscanf(fp, "%s %s %s %s %d %s %d %s %s %s %s %s %d %d \n ",
			arr[i].first_name, arr[i].last_name, arr[i].gender, arr[i].id, &arr[i].age, arr[i].phone_number,
			&arr[i].password, arr[i].Email, arr[i].living_area, arr[i].Driving_License, arr[i].Education_level, 
			arr[i].Employment_Catagory,&arr[i].policies,&arr[i].apply_jobs);//לבדוק אם צריך לבטל את ה& לפני מערך העובדים
	if (!fp)
	{
		printf("error!\n");
		return 0;
	}
	fclose(fp);
	return arr;
}