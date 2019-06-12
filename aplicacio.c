/**
*	@file aplicacio.c
*	@author Daniel Segura
*	@version 1.0
*	@date 2019-06-04
*	@warning aixo es el arxiu del guillem perque no recordo res de c
*	@copyright GNU Public License
*	@mainpage SavePass DanielSegura (aplicacio)
*	@section intro_sec Introduction
*	This program was developed to store your passwords, during m08 uf 4
*	@section compile_sec Compilation
*	To compile this program, use gcc aplicacio.c -o aplicacio
**/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief This function is the option c) of the menu: get_password
* \details Prints in screen the password of the username the user inputted
* \param test_param this param doesnt exist, its just a test for dogygen
* \return doesn't return anything, its a void
**/
void get_password(){

	FILE * fp; /** Pointer to the file that stores passwords */
	char *line = NULL; /** This string stores every line of the file.txt */
	size_t len = 0;
	ssize_t read;
	int i, found = 0; /** Variable found is used for some stuff */

	char * pch;
 
	fp = fopen ("file.txt", "r");
	
	char param[32]; /** We store the username of the password we want here */

	printf("Enter a username:\n");
	scanf("%s", param);

	while ((read = getline(&line, &len, fp)) != -1) {

		pch = strtok (line,",");
		i = 0;
		while (pch != NULL)
		{
			if(i == 1){
				if(!strcmp(pch,param)){
					found = 1;
				}
			}
			if(i == 2 && found == 1){
				printf("The password for username: '%s' is: %s\n",param, pch);
				found = 0;
			}
			pch = strtok (NULL, ",");
			i++;
		}
	}
}

/*!
* @brief This function is the option b) of the menu: list_usernames
* @details Prints in screen all the combinations of description + usernames
* @return doesn't return anything, its a void
*/
void list_usernames(){

	FILE * fp; /** Pointer to the file that stores passwords */
	char *line = NULL; /** This string stores every line of the file.txt */
	size_t len = 0;
	ssize_t read;
	int i;

	char * pch;
  
  
	fp = fopen ("file.txt", "r");

	while ((read = getline(&line, &len, fp)) != -1) {

		pch = strtok (line,",");
		i = 0;
		while (pch != NULL)
		{
			if(i == 0) printf("Description: %s\t\t",pch);
			if(i == 1) printf("Username: %s\n",pch);

			pch = strtok (NULL, ",");
			i++;
		}

		printf("\n");
	}
}

/**
* @brief This function is the option a) of the menu: add_password
* @details Asks the user to input a description, username and password, then opens the file and stores the data
* @return doesn't return anything, its a void
**/
void add_password(){

	FILE * fp; /** Pointer to the file that stores passwords */

	fp = fopen ("file.txt", "a+");

	char* description[64], username[32], password[32];

	printf("Enter a description:\n");
	scanf("%s", description);

	printf("Enter the username:\n");
	scanf("%s", username);

	printf("Enter the password:\n");
	scanf("%s", password);

	fprintf(fp, "%s,%s,%s\n", description, username, password);

	fclose(fp);

	printf("Your password has been stored!\n\n");

}

/*!
* \brief Main function
* \details This function prints a menu, and depending on the choice of the user, does one function and then exits the program
* \return returns 0 if successfull
*/
int main () {

   int choice;

   printf("-------Menu-------\n");
   printf("1) ADD A PASSWORD [1]\n");
   printf("2) LIST ALL USERNAMES [2]\n");
   printf("3) REMEMBER A PASSWORD [3]\n");
   printf("4) EXIT [4]\n");
 
	
   scanf("%d", &choice);

   system("clear");
 
   if (choice==1)
   {
      add_password();
   }
   else if (choice==2)
   {
      list_usernames();
   }
   else if (choice==3)
   {
      get_password();
   }

   return 0;

}

