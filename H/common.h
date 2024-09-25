#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef __GET_METHOD__
#define __GET_METHOD__
struct Method{
	char *methodContent[1250];
	
};
typedef struct Method Method;

char** getMethods(char* filename);
Method ** getMethod(char *fileName, char **fileContent);

/*
Method* getPerlMethod(int index, char **file);
Method* getPythonMethod(int index, char **file);
Method* getCCPPJavaMethod(int index, char **file);
*/
#endif
