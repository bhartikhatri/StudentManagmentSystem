//22K-5161: Hafsa Salman
//22K-4832: Bharti

//PROGRAMMING FUNDAMENTALS: FINAL PROJECT
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>

//Declaration of student structure to store details and mark attendance
struct student
{
	char name[50];
	int id;
	
	struct course
	{
		char subject[30];
		int attendance;
	};
	
	struct course data[5];
};

//Functions to check the login details of the student.
//The program will only proceed when correct ID and password is entered.
int student_login_detail()
{
	int id, password, fid, fpassword, found, var;
	
	printf("\n\t\t\t Login Details: \n");
	
	printf("\t\t\t Enter ID: ");
	scanf("%d", &id);
	
	printf("\t\t\t Enter Password: ");
	scanf("%d", &password);
	
	FILE *ptr;
	
	ptr = fopen("studentlogin.txt", "r");
	
	//Checking the entered ID and password with the already stored data in the FILE
	if (ptr == NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("\n\t\t\t File could not be opened.\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	
	else
	{
		fscanf (ptr, "%d %d", &fid, &fpassword);
		found = 0;
		
		while (!feof (ptr))
		{
			//Comparing the entered ID with the stored ID in the file
			if (id == fid)
			{
				found = 1;
				
				//Comparing the entered password with the stored password in the file
				if (password == fpassword)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
					printf("\n\t\t\t Valid ID and Password");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					
					var = 1;
					//Checking variable (var) has been updated to 1, as both conditions have been met.
				}
				
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					printf("\t\t\t Incorrect password entered");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					
					var = 0;
					//Checking variable (var) remains 0, as incorrect password was entered.
				}
			}
			
			fscanf(ptr, "%d %d", &fid, &fpassword);
		}
		
		if (found == 0)
		{
			if (id == fid)
			{
				found = 1;
				
				if (password == fpassword)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
					printf("\n\t\t\t Valid ID and password");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					
					var=1;
					//Checking variable (var) has been updated to 1, as both conditions have been met.
				}
				
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					printf("\n\t\t\t Invalid ID or password");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					
					var=0;
					//Checking variable (var) remains 0, as incorrect password was entered.
				}
			}
			
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				printf("\n\t\t\t Invalid ID or password");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				
				var=0;
				//Checking variable (var) remains 0, as incorrect ID was entered.
			}
		}
	}
	
	fclose(ptr);
	
	return (var);
}

//Function to mark attendance of the students
void mark_attendance(struct student record[])
{
	int d, uid, s;
	char cn[10];
	char ans;
	
	printf("\n\t\t\t Enter ID: ");
	scanf("%d", &uid);
	
	//Loop to check the entered ID with all 10 students
	for (d=0; d<10; d++)
	{
		if (record[d].id == uid)
		{
			printf("\n\t\t\t Courses: \n\t\t\t Physics\n\t\t\t Calculus\n\t\t\t ICT\n\t\t\t Programming\n\t\t\t English");
			printf("\n\t\t\t Enter the course name to mark attendance: ");
			scanf(" %s", &cn);
			
			//Loop to check the entered subject name with all 5 subjects
			for (s=0; s<5; s++)
			{
				if (strcmp (record[d].data[s].subject, cn) == 0)
				{
					record[d].data[s].attendance++;
					
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
					printf("\n\t\t\t Your attendance has been marked successfully!");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					
					printf("\a");
					
					break;
				}
			}
		}
	}
}

//Function to view attendance
void view_attendance (struct student record[])
{
	int d, s;
	int ID;
	printf("\n\t\t\t Enter the ID :");
	scanf("%d",&ID);
	//Loop for printing attendance
	for (d=0; d<10; d++)
	{
		for (s=0; s<5; s++)
		{
			if(ID==record[d].id){
			printf("\n\t\t\t ID: %d", record[d].id);
			printf("\n\t\t\t %s attendance: %d", record[d].data[s].subject, record[d].data[s].attendance);
			}
		}
	}
}

//Main body begins here
int main ()
{
	int b, sid;
	float a, pay;
	char ans;
	struct student record[10];
	
	//Storing data of students in the structure sstudent
	//Initializing the names, IDs and attendance of each subject
	
	//Student 01
	strcpy(record[0].name, "Amna");
	record[0].id = 2000;
	strcpy(record[0].data[0].subject, "Physics");
	record[0].data[0].attendance = 0;
	strcpy(record[0].data[1].subject, "Calculus");
	record[0].data[1].attendance = 0;
	strcpy(record[0].data[2].subject, "Programming");
	record[0].data[2].attendance = 0;
	strcpy(record[0].data[3].subject, "English");
	record[0].data[3].attendance = 0;
	strcpy(record[0].data[4].subject, "ICT");
	record[0].data[4].attendance = 0;
	
	//Student 02
	strcpy(record[1].name, "Bharti");
	record[1].id = 2001;
	strcpy(record[1].data[0].subject, "Physics");
	record[1].data[0].attendance = 0;
	strcpy(record[1].data[1].subject, "Calculus");
	record[1].data[1].attendance = 0;
	strcpy(record[1].data[2].subject, "Programming");
	record[1].data[2].attendance = 0;
	strcpy(record[1].data[3].subject, "English");
	record[1].data[3].attendance = 0;
	strcpy(record[1].data[4].subject, "ICT");
	record[1].data[4].attendance = 0;
	
	//Student 03
	strcpy(record[2].name, "Maham");
	record[2].id = 2002;
	strcpy(record[2].data[0].subject, "Physics");
	record[2].data[0].attendance = 0;
	strcpy(record[2].data[1].subject, "Calculus");
	record[2].data[1].attendance = 0;
	strcpy(record[2].data[2].subject, "Programming");
	record[2].data[2].attendance = 0;
	strcpy(record[2].data[3].subject, "English");
	record[2].data[3].attendance = 0;
	strcpy(record[2].data[4].subject, "ICT");
	record[2].data[4].attendance = 0;
	
	//Student 04
	strcpy(record[3].name, "Amal");
	record[3].id = 2003;
	strcpy(record[3].data[0].subject, "Physics");
	record[3].data[0].attendance = 0;
	strcpy(record[3].data[1].subject, "Calculus");
	record[3].data[1].attendance = 0;
	strcpy(record[3].data[2].subject, "Programming");
	record[3].data[2].attendance = 0;
	strcpy(record[3].data[3].subject, "English");
	record[3].data[3].attendance = 0;
	strcpy(record[3].data[4].subject, "ICT");
	record[3].data[4].attendance = 0;
	
	//Student 05
	strcpy(record[4].name, "Fatima");
	record[4].id = 2004;
	strcpy(record[4].data[0].subject, "Physics");
	record[4].data[0].attendance = 0;
	strcpy(record[4].data[1].subject, "Calculus");
	record[4].data[1].attendance = 0;
	strcpy(record[4].data[2].subject, "Programming");
	record[4].data[2].attendance = 0;
	strcpy(record[4].data[3].subject, "English");
	record[4].data[3].attendance = 0;
	strcpy(record[4].data[4].subject, "ICT");
	record[4].data[4].attendance = 0;
	
	//Student 06
	strcpy(record[5].name, "Alizah");
	record[5].id = 2005;
	strcpy(record[5].data[0].subject, "Physics");
	record[5].data[0].attendance = 0;
	strcpy(record[5].data[1].subject, "Calculus");
	record[5].data[1].attendance = 0;
	strcpy(record[5].data[2].subject, "Programming");
	record[5].data[2].attendance = 0;
	strcpy(record[5].data[3].subject, "English");
	record[5].data[3].attendance = 0;
	strcpy(record[5].data[4].subject, "ICT");
	record[5].data[4].attendance = 0;
	
	//Student 07
	strcpy(record[6].name, "Faiza");
	record[6].id = 2006;
	strcpy(record[6].data[0].subject, "Physics");
	record[6].data[0].attendance = 0;
	strcpy(record[6].data[1].subject, "Calculus");
	record[6].data[1].attendance = 0;
	strcpy(record[6].data[2].subject, "Programming");
	record[6].data[2].attendance = 0;
	strcpy(record[6].data[3].subject, "English");
	record[6].data[3].attendance = 0;
	strcpy(record[6].data[4].subject, "ICT");
	record[6].data[4].attendance = 0;
	
	//Student 08
	strcpy(record[7].name, "Hafsah");
	record[7].id = 2007;
	strcpy(record[7].data[0].subject, "Physics");
	record[7].data[0].attendance = 0;
	strcpy(record[7].data[1].subject, "Calculus");
	record[7].data[1].attendance = 0;
	strcpy(record[7].data[2].subject, "Programming");
	record[7].data[2].attendance = 0;
	strcpy(record[7].data[3].subject, "English");
	record[7].data[3].attendance = 0;
	strcpy(record[7].data[4].subject, "ICT");
	record[7].data[4].attendance = 0;
	
	//Student 09
	strcpy(record[8].name, "Hafsa");
	record[8].id = 2008;
	strcpy(record[8].data[0].subject, "Physics");
	record[8].data[0].attendance = 0;
	strcpy(record[8].data[1].subject, "Calculus");
	record[8].data[1].attendance = 0;
	strcpy(record[8].data[2].subject, "Programming");
	record[8].data[2].attendance = 0;
	strcpy(record[8].data[3].subject, "English");
	record[8].data[3].attendance = 0;
	strcpy(record[8].data[4].subject, "ICT");
	record[8].data[4].attendance = 0;
	
	//Student 10
	strcpy(record[9].name, "Sabina");
	record[9].id = 2009;
	strcpy(record[9].data[0].subject, "Physics");
	record[9].data[0].attendance = 0;
	strcpy(record[9].data[1].subject, "Calculus");
	record[9].data[1].attendance = 0;
	strcpy(record[9].data[2].subject, "Programming");
	record[9].data[2].attendance = 0;
	strcpy(record[9].data[3].subject, "English");
	record[9].data[3].attendance = 0;
	strcpy(record[9].data[4].subject, "ICT");
	record[9].data[4].attendance = 0;
	
	int count_1, count_2, choice, code, id, hours, check;
	//Initializing arrays
	char subject[40];
	char day[20], category;
	
	struct student data[10];
	int teacher[5][2]={100, 0, 101, 0, 102, 0, 103, 0, 104, 0};
	
	//Function to display the current date and time
	time_t t;
	time(&t);
	
	puts(ctime(&t));
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	printf("\n \n \t \t \tAttendance Management System\n");
	printf("\t \t \t---------------------------- ");
	
	printf("\a");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	do
	{
		printf("\n\n\t\t\t Enter the category\n\t\t\t 's' for student \n\t\t\t 't' for teacher faculty\n\t\t\t  ");
		scanf(" %c", &category);
		
		//Main switch: divided into teachers and students
		switch (category)
		{
			//Category: Student
			case 's':
			{
				//Function to check the login details for student
				check = student_login_detail();
				
				if (check != 0)
				{
					printf("\n\n\t\t\t Menu: \n\t\t\t 1. Mark Attendance \n\t\t\t 2. View Attendance \n\t\t\t 3. Exam eligibility");
					printf("\n\t\t\t Enter your choice: ");
					scanf("%d", &choice);
					
					//Nested switch for different options in student's category
					switch (choice)
					{
						case 1:
						{
							//Calling the mark attendance function
							mark_attendance(record);
						}
						
						break;
						
						case 2:
						{
							//Calling the view attendance function
							view_attendance(record);
						}
						
						break;
						
						case 3:
						{
							//Code for checking the exam eligibility of the student
							a = 10;
							
							int i, d;
							float c;
							char course[20];
							
							printf("\n\t\t\t The minimum attendance for giving the examination is 30 percent.");
							printf("\n\t\t\t Enter details to check eligibility: ");
							printf("\n\t\t\t Enter ID: ");
							scanf("%d", &sid);
							
							printf("\t\t\t Enter course: ");
							
							scanf(" %s", &course);
							
							printf("\t\t\t The total number of classes held were 10.");
							
							for (i=0; i<10; i++)
							{
								if (record[i].id == sid)
								{
									for (d=0; d<5; d++)
									{
										if (strcmp(record[i].data[d].subject, course) == 0)
										{
											printf("\n\t\t\t Your attendance for %s is %d.", record[i].data[d].subject, record[i].data[d].attendance);
											b = record[i].data[d].attendance;
											c = b/a;
											
											if (c * 100 <= 30)
											{
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
												printf("\n\t\t\t Your attendance is less than 30%.\n");
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
											}
											
											else
											{
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
												printf("\n\t\t\t Attendance is more than 30%.\n\t\t\t You are eligible to sit in the exam!");
												SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
											}
											
											break;
										}
									}
								}
							}
						}
						
						default:
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
							printf("\n\t\t\t Incorrect option entered! Please try again! \n");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						}
						
						break;
					}
				}
			}
			
			break;
			
			//Category: Teacher
			case 't':
			{
				printf("\n\t\t\t Enter your faculty code: ");
				scanf("%d", &code);
				
				if (code != 100 && code != 101 && code != 102 && code != 103 && code != 104)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					printf("\n\t\t\t Invalid code entered!");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				}
				
				else
				{
					printf("\n\t\t\t Menu: \n\t\t\t 1. Mark Attendance \n\t\t\t 2. View Work Hours \n\t\t\t 3. View Attendance \n\t\t\t 4. Generate Pay");
					printf("\nEnter your choice: ");
					scanf("%d", &choice);
					
					int *ptr;
					
					//Nested switch for different options in teacher's category
					switch (choice)
					{
						case 1:
						{
							for (count_1=0; count_1<5; count_1++)
							{
								if (code == teacher[count_1][0])
								{
									teacher[count_1][1]++;
									
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
									printf("\n\t\t\t Your attendance has been marked successfully.\n");
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
									
									printf("\a");
								}
								
								break;
							}
						}
						
						break;
						
						case 2:
						{
							for (count_1=0; count_1<5; count_1++)
							{
								if (code == teacher[count_1][0])
								{
									printf("\n\t\t\t Your work hours are %d.\n", teacher[count_1][1]);
								}
								
								break;
							}
						}
						
						break;
						
						case 3:
						{
							//Pointers
							for (count_1=0; count_1<5; count_1++)
							{
								ptr = &teacher[count_1][0];
								
								if (code == (ptr[count_1]))
								{
									ptr++;
									
									printf("\n\t\t\t Your attendance is %d.\n", (*(ptr)));
								}
								
								break;
							}
						}
						
						break;
						
						case 4:
						{
							for (count_1=0; count_1<5; count_1++)
							{
								if (code == teacher[count_1][0])
								{
									pay = teacher[count_1][1] * 5000;
									printf("\n\t\t\t Generated pay: %.2f Rupees\n", pay);
								}
								
								break;
							}
						}
						
						break;
						
						default:
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
							printf("\n\t\t\t You have entered a wrong input. Please try again!");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						}
						
						break;
					}
				}
			}
			
			break;
			
			default:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				printf("\n\t\t\t You have entered a wrong input. Please try again!");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}
			
			break;
		}
		
		//Option to continue or end the program
		printf("\n\n\t\t\t Enter 'y' to continue the program or enter any key to exit: ");
		scanf(" %c", &ans);
		
		if (ans != 'y')
		{
			printf("\n\t\t\t The program has been exited. Thank you!");
		}
		
		else
		{
			system("CLS");
		}
	}
	while (ans == 'y');
	
	return 0;
}
