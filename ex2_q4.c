// Course: Advanced C programming
// exercise 2, question 4
// file name: ex2_q3.c

// --------------------------- //
//
//	Assigned by:
//		Student1_Full_Name #ID
//		Student2_Full_Name #ID
//
// --------------------------- //

// --------------------------------------- //
// Include and definition package section:
// --------------------------------------- //
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf
#define PATH1 "c:\\temp\\file1.txt"
#define PATH2 "c:\\temp\\file2.txt"
#define PATH3 "c:\\temp\\file3.txt"

// --------------------------------------- //
// Functions declration section:
// --------------------------------------- //
int calculateSizeOfRow(char* s);

int memoryReport(char* filename);
// --------------------------------------- //
// Main section:
// --------------------------------------- //
int main()
{
	int total1, total2, total3;

	// Start Program:
	printf("Start Program\n");

	// call functions:
	total1 = memoryReport(PATH1);
	total2 = memoryReport(PATH2);
	total3 = memoryReport(PATH3);

	// write output:
	printf("Output:\n");
	printf("First file required %d bytes\n", total1);
	printf("Second file required %d bytes\n", total2);
	printf("Third file required %d bytes\n", total3);

	return 0;
}
// --------------------------- //


/// <summary>
/// The function receives a pointer to a string, representing a path to a file.
/// The function output all varibles declerations and their size in byte.
/// </summary>
/// <param>char *filename - valid path to a file</param>
/// <returns>total bytes required</returns>
/// 



int calculateSizeOfRow(char* ptr) {
	int count=0;
	int num1 = 0,n2=0;
	int i = 0,j=0,n=0;
	char w='c',u='c';
	char num[10] = { 0 };
	char num2[10] = { 0 };
	char s[10] = { 0 };
	int flag = 0, flagP=0;
	while((ptr[i] < 'a' || ptr[i] >'z') && (ptr[i] < 'A' || ptr[i] > 'Z')&& ptr[i]!=0)  i++;
		if (ptr[i] == 'i' || ptr[i] == 'f' || ptr[i] == 'u' ) {
			if (ptr[i] == 'u') u = 'u';
			while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') i++;
			if (u == 'u') {
				i++;
				while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') i++;
			}
			while (ptr[i] != ';') {
				
				while (ptr[i] == ' ' || ptr[i] == '*' || ptr[i] == ',') i++;
				if (ptr[i] == ';') return count;
				while ((ptr[i] < 'a' || ptr[i] >'z') && (ptr[i] < 'A' || ptr[i] > 'Z')&& ptr[i] != ';')  i++; //
				if (ptr[i] == ';') return count;
				while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') {

					s[j] = ptr[i];
					i++;
					j++;
				}

				while (ptr[i] == '[' || ptr[i] == ']') {
					i++;
					while (ptr[i] == ' ' || ptr[i] == ',') i++;
					while (ptr[i] >= '0' && ptr[i] <= '9') {
						num[n] = ptr[i];
						n++;
						i++;
					}
					while (ptr[i] == ' ' || ptr[i] == ',') i++;
					if (ptr[i] == ']' && ptr[i + 1] == '[') {
						flag = 2;
						i += 2;
						while (ptr[i] == ' ' || ptr[i] == ',') i++;
						while (ptr[i] >= '0' && ptr[i] <= '9') {
							num2[n2] = ptr[i];
							n2++;
							i++;
						}
						num1 += atoi(num);
						num1 *= atoi(num2);
						num1 *= 4;
						j = 0;
						while (s[j] != 0) {

							printf("%c", s[j]);
							j++;
						}
						printf("  requires %d bytes\n", num1);
						count += num1;
						for (n = 0; n < 10; n++) {
							num[n] = 0;
						}
						for (n2 = 0; n2 < 10; n2++) {
							num2[n2] = 0;
						}
						n2 = 0;
					}
					else if (ptr[i - 1] != ']') {
						flag = 1;
						num1 = atoi(num);
						num1 *= 4;
						while (s[j] != 0) {
							j = 0;
							printf("%c", s[j]);
							j++;
						}
						printf("  requires %d bytes\n", num1);
						count += num1;
						for (n = 0; n < 10; n++) {
							num[n] = 0;
						}
					}
					n = 0;
				}
				
				if (flag == 0) {
					j = 0;
					count += 4;
					while (s[j] != 0) {
						printf("%c", s[j]);
						j++;
					}
					
					printf("  requires 4 bytes\n");
				}
				flag = 0;
				for (j = 0; j < 10; j++) {
					s[j] = 0;
				}
				j = 0;

			}
			return count;
		}

		if (ptr[i] == 'c') {
			while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') i++;
			while (ptr[i] != ';') {

				while (ptr[i] == ' ' || ptr[i] == ',') i++;
				if (ptr[i] == ';') return count;
				if (ptr[i] == '*') {
					flagP = 1;
					i++;
				}
				if (ptr[i] == ';') return count;
				while ((ptr[i] < 'a' || ptr[i] >'z') && (ptr[i] < 'A' || ptr[i] > 'Z') && (ptr[i] != ';'))  i++; //
				if (ptr[i] == ';') return count;
				while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') {

					s[j] = ptr[i];
					i++;
					j++;
				}

				while (ptr[i] == '[' || ptr[i] == ']') {
					i++;
					while (ptr[i] == ' ' || ptr[i] == ',') i++;
					while (ptr[i] >= '0' && ptr[i] <= '9') {
						num[n] = ptr[i];
						n++;
						i++;
					}
					while (ptr[i] == ' ' || ptr[i] == ',') i++;
					if (ptr[i] == ']' && ptr[i + 1] == '[') {
						flag = 2;
						i += 2;
						while (ptr[i] == ' ' || ptr[i] == ',') i++;
						while (ptr[i] >= '0' && ptr[i] <= '9') {
							num2[n2] = ptr[i];
							n2++;
							i++;
						}
						num1 += atoi(num);
						if (flagP == 1) {
							num1 *= 4;
						}
						else
						num1 *= atoi(num2);
						
						j = 0;
						while (s[j] != 0) {

							printf("%c", s[j]);
							j++;
						}
						printf("  requires %d bytes\n", num1);
						count += num1;
						for (n = 0; n < 10; n++) {
							num[n] = 0;
						}
						for (n2 = 0; n2 < 10; n2++) {
							num2[n2] = 0;
						}
						n2 = 0;
					}
					else if (ptr[i - 1] != ']') {
						flag = 1;
						num1 = atoi(num);
						if (flagP == 1) {
							num1 *= 4;
						}
						j = 0;
						while (s[j] != 0) {

							printf("%c", s[j]);
							j++;
						}
						printf("  requires %d bytes\n", num1);
						count += num1;
						for (n = 0; n < 10; n++) {
							num[n] = 0;
						}
					}
					n = 0;
				}
				if (flag == 0 && flagP == 1) {
					j = 0;
					count += 4;
					while (s[j] != 0) {
						printf("%c", s[j]);
						j++;
					}
					printf("  requires 4 bytes\n");
				}

				else if (flag == 0) {
					j = 0;
					count++;
					while (s[j] != 0) {
						printf("%c", s[j]);
						j++;
					}
					printf("  requires 1 byte\n");
				}
				flag = 0;
				flagP = 0;
				for (j = 0; j < 10; j++) {
					s[j] = 0;
				}
				j = 0;

			}
			return count;
		}


		if (ptr[i] == 'l' ) {

			while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') i++;
			if (ptr[i + 1] == 'l') {
				w = 'w';
				
			}

			while (ptr[i] != ';' && w!='w') {

				while (ptr[i] == ' ' || ptr[i] == '*' || ptr[i] == ',') i++;
				if (ptr[i] == ';') return count;
				while ((ptr[i] < 'a' || ptr[i] >'z') && (ptr[i] < 'A' || ptr[i] > 'Z') && (ptr[i] != ';'))  i++; //
				if (ptr[i] == ';') return count;
				while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') {

					s[j] = ptr[i];
					i++;
					j++;
				}

				while (ptr[i] == '[' || ptr[i] == ']') {

					i++;
					while (ptr[i] == ' ' || ptr[i] == ',') i++;
					while (ptr[i] >= '0' && ptr[i] <= '9') {
						num[n] = ptr[i];
						n++;
						i++;
					}
					if (ptr[i - 1] != ']') {
						flag = 1;
						num1 = atoi(num);
						num1 *= 4;
						while (s[j] != 0) {
							j = 0;
							printf("%c", s[j]);
							j++;
						}
						printf("  requires %d bytes\n", num1);
						count += num1;
						for (n = 0; n < 10; n++) {
							num[n] = 0;
						}
					}
					n = 0;
				}

				if (flag == 0) {
					j = 0;
					count += 4;
					while (s[j] != 0) {
						printf("%c", s[j]);
						j++;
					}

					printf("  requires 4 bytes\n");
				}
				flag = 0;
				for (j = 0; j < 10; j++) {
					s[j] = 0;
				}
				j = 0;

			}
			if(w!='w')
			return count;
		}

		if (ptr[i] == 'd' || w=='w') {

			while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') i++;
			if (w == 'w') {
				i++;
				while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') i++;
			}
			while (ptr[i] != ';') {

				
				while (ptr[i] == ' ' ||  ptr[i] == ',') i++;
				if (ptr[i] == '*') {
					flagP = 1;
					i++;
				}
				if (ptr[i] == ';') return count;
				while ((ptr[i] < 'a' || ptr[i] >'z') && (ptr[i] < 'A' || ptr[i] > 'Z') && (ptr[i] != ';'))  i++;
				if (ptr[i] == ';') return count;
				while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') {

					s[j] = ptr[i];
					i++;
					j++;
				}
				while (ptr[i] == ' ' ||  ptr[i] == ',') i++;
				while (ptr[i] == '[' || ptr[i] == ']') {
					i++;
					while (ptr[i] == ' ' || ptr[i] == ',') i++;

					while (ptr[i] >= '0' && ptr[i] <= '9') {
						num[n] = ptr[i];
						n++;
						i++;
					}
					while (ptr[i] == ' ' || ptr[i] == ',') i++;
					if (ptr[i] == ']' && ptr[i + 1] == '[') {
						flag = 2;
						i += 2;
						while (ptr[i] == ' ' || ptr[i] == ',') i++;
						while (ptr[i] >= '0' && ptr[i] <= '9') {
							num2[n2] = ptr[i];           
							n2++;
							i++;
						}
						num1 += atoi(num);

						num1 *= atoi(num2);
						if (flagP == 1) {
							num1 *= 4;
						}
						else
						num1 *= 8;
						j = 0;
						while (s[j] != 0) {

							printf("%c", s[j]);
							j++;
						}
						printf("  requires %d bytes\n", num1);
						count += num1;
						for (n = 0; n < 10; n++) {
							num[n] = 0;
						}
						for (n2 = 0; n2 < 10; n2++) {
							num2[n2] = 0;
						}
						n2 = 0;
					}

					else if (ptr[i - 1] != ']' && flag!=2) {
						flag = 1;
						
						num1 = atoi(num);
						if (flagP == 1) {
							num1 *= 4;
						}
						else
						num1 *= 8;
						j = 0;
						while (s[j] != 0) {
							
							printf("%c", s[j]);
							j++;
						}
						printf("  requires %d bytes\n", num1);
						count += num1;
						for (n = 0; n < 10; n++) {
							num[n] = 0;
						}
					}
					n = 0;
				}

				if (flag == 0 && flagP == 1) {
					j = 0;
					count += 4;
					while (s[j] != 0) {
						printf("%c", s[j]);
						j++;
					}
					printf("  requires 4 bytes\n");
				}

				if (flag == 0 && flagP != 1) {
					j = 0;
					count += 8;
					while (s[j] != 0) {
						printf("%c", s[j]);
						j++;
					}

					printf("  requires 8 bytes\n");
				}
				flagP = 0;
				flag = 0;
				for (j = 0; j < 10; j++) {
					s[j] = 0;
				}
				j = 0;

			}
			return count;
		}

		if (ptr[i] == 's' ) {

			while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') i++;
			while (ptr[i] != ';') {

				while (ptr[i] == ' ' ||  ptr[i] == ',') i++;
				if (ptr[i] == '*') {
					flagP = 1;
					i++;
				}
				if (ptr[i] == ';') return count;
				while ((ptr[i] < 'a' || ptr[i] >'z') && (ptr[i] < 'A' || ptr[i] > 'Z')&&(ptr[i] != ';'))  i++;
				if (ptr[i] == ';') return count;
				while (ptr[i] >= 'a' && ptr[i] <= 'z' || ptr[i] >= 'A' && ptr[i] <= 'Z') {

					s[j] = ptr[i];
					i++;
					j++;
				}

				while (ptr[i] == '[' || ptr[i] == ']') {
					i++;
					while (ptr[i] == ' ' || ptr[i] == ',') i++;
					while (ptr[i] >= '0' && ptr[i] <= '9') {
						num[n] = ptr[i];
						n++;
						i++;
					}
					while (ptr[i] == ' ' || ptr[i] == ',') i++;
					if (ptr[i] == ']' && ptr[i + 1] == '[') {
						flag = 2;
						i += 2;
						while (ptr[i] == ' ' || ptr[i] == ',') i++;
						while (ptr[i] >= '0' && ptr[i] <= '9') {
							num2[n2] = ptr[i];
							n2++;
							i++;
						}
						num1 += atoi(num);
						num1 *= atoi(num2);
						if (flagP == 1) {
							num1 *= 4;
						}
						else
						num1 *= 2;
						j = 0;
						while (s[j] != 0) {

							printf("%c", s[j]);
							j++;
						}
						printf("  requires %d bytes\n", num1);
						count += num1;
						for (n = 0; n < 10; n++) {
							num[n] = 0;
						}
						for (n2 = 0; n2 < 10; n2++) {
							num2[n2] = 0;
						}
						n2 = 0;
					}
					else if (ptr[i - 1] != ']') {
						flag = 1;
						num1 = atoi(num);
						if (flagP == 1) {
							num1 *= 4;
						}
						else
						num1 *= 2;
						j = 0;
						while (s[j] != 0) {
							
							printf("%c", s[j]);
							j++;
						}
						printf("  requires %d bytes\n", num1);
						count += num1;
						for (n = 0; n < 10; n++) {
							num[n] = 0;
						}
					}
					n = 0;
				}
				if (flag == 0 && flagP == 1) {
					j = 0;
					count += 4;
					while (s[j] != 0) {
						printf("%c", s[j]);
						j++;
					}
					printf("  requires 4 bytes\n");
				}


				if (flag == 0 && flagP != 1) {
					j = 0;
					count += 2;
					while (s[j] != 0) {
						printf("%c", s[j]);
						j++;
					}

					printf("  requires 2 bytes\n");
				}
				flagP = 0;
				flag = 0;
				for (j = 0; j < 10; j++) {
					s[j] = 0;
				}
				j = 0;

			}
			return count;
		}


		return 0;
}


int memoryReport(char* filename)
{
	// your code:
	int count,counter=0;
	
	int i;
	FILE* fptr = fopen(filename, "r");
	FILE* head = fptr;
	char buffer[200];
	if (!fptr) return 0;

	while (!feof(fptr)) {

		fgets(buffer, 200, fptr);

		counter += calculateSizeOfRow(buffer);
		for (i = 0; i < 200; i++) {
			buffer[i] = 0;
		}
	}

	fclose(fptr);
	return counter;
}
// --------------------------- //
