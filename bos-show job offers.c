#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 30



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

Job* pull_from_file(Job arr[], int size);
void print_job_offers(Job arr[], int index);
void print_job_struct(Job job);
void push_to_file(Job arr[], int size);


int main()
{




	return 0;
}

void push_to_file(Job arr[], int size)
{
	int i;
	FILE* fp = fopen("arr.txt", "w");
	for (i = 0; i < size; i++)
		fprintf(fp, "%s %s %s %s %s %s %d %d %d \n ", arr[i].name_of_job, arr[i].name_of_company, arr[i].employment_catagory, arr[i].location_area, arr[i].scope_of_the_job, arr[i].salary_range, &arr[i].index_boss, &arr[i].arr_index_worker, &arr[i].code);//לבדוק אם צריך לבטל את ה& לפני מערך העובדים
	fclose(fp);
}






Job* pull_from_file(Job arr[], int size)
{
	int i;
	FILE* fp = fopen("secret.log", "r");
	for (i = 0; i < size; i++)
		fscanf(fp, "%s %s %s %s %s %s %d %d %d \n ", arr[i].name_of_job ,arr[i].name_of_company, arr[i].employment_catagory, arr[i].location_area, arr[i].scope_of_the_job, arr[i].salary_range, &arr[i].index_boss, &arr[i].arr_index_worker, &arr[i].code);//לבדוק אם צריך לבטל את ה& לפני מערך העובדים
	if (!fp)
	{
		printf("error!\n");
		return 0;
	}
	fclose(fp);
	return arr;
}

void print_job_offers(Job arr[], int index)
{
	for (int i = index; i < index * 10; ++i)
	{
		int count = 0;
		if (!arr[i]) // לבדוק מה הבעיה
		{
			print_job_struct(arr[i]);
			++count;
		}
		if (count == 0)
			printf("No job offers\n");

	}


}

void print_job_struct(Job job)
{
	printf("Job number: %d", job.code);
	printf("\n");
	gets(job.name_of_job);
	printf("\n");
	gets(job.name_of_company);
	printf("\n");
	gets(job.employment_catagory);
	printf("\n");
	gets(job.location_area);
	printf("\n");
	gets(job.scope_of_the_job);
	printf("\n");
	gets(job.salary_range);
	printf("\n");
}
