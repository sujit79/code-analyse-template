#include "../H/common.h"


char** getMethods(char *fileName){
   FILE *fp;
   int bytes_read = 0;
   int nbytes = 1250;
   char **sources = (char *)malloc(sizeof(sources));
   fp = fopen(fileName, "r+");
   int index = 0; 
   while(!feof(fp)){
      char *my_string = (char *) malloc (nbytes + 1);
      bytes_read = getline (&my_string, &nbytes, fp);
      sources[index] = my_string;
      index++;
   }
   fclose(fp);
   return sources;

}
bool endsWith(const char *pre, const char *str){
	
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? false : strncmp(pre, str, lenpre) == 0;
}
bool startsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? false : strncmp(pre, &str[lenstr], lenpre) == 0;
}
Method* getPerlMethod(int index, char **file){
	Method *method = (Method *)malloc(sizeof(Method));
	int index1 = 0;
	while(!strrchr(file[index][index1], "sub")){
		strcat(method->methodContent, file[index][index1++]);
	}
	return method;
}
Method* getPythonMethod(int index, char **file){
	Method *method = malloc(sizeof(Method));
	int index1 = 0;
	while(!strrchr(file[index][index1], ":") || !startsWith(file[index][index1],"/t/t")){
		strcat(method->methodContent, file[index][index1]);
		index1++;
	}
	return method;
}
Method* getCCPPJavaMethod(int index, char **file){
	Method *method = malloc(sizeof(Method));
	if(endsWith("){",file[index]) || (endsWith(")",file[index]) && startsWith("{", file[index + 1]))){
		int index1 = 0;
		while(!strrchr(file[index][index1], "({")){
			strcat(method->methodContent, file[index][index1++]);
		}
	}	
	return method;
}
Method** getMethod(char *fileName, char **fileContent){
        char *extension = strrchr(fileName, ".");
	int count = 0;
	int flag = 0;
	if(strcmp(extension, ".py")){
		flag = 1;
	}else if(strcmp(extension, ".pl")){
		flag = 2;
	}
	return NULL;
}
