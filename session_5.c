#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[20] = "hello";
    char str2[20] = "world";
    char str3[20] = "hello";
    char str4[20] = "world";
    char str5[20] = "hello";
    char str6[20] = "world";
    char str7[20] = "hello";
    char str8[20] = "world";
    char str9[20] = "hello";
    char str10[20] = "world";
    char str11[20] = "Hello";
    char str12[20] = "WORLD";
    char str13[10] = "1234";
    int num = 1234;
    
    //strcpy
    strcpy(str1, str2);
    printf("strcpy: %s\n", str1);
    
    //strcmp
    if(strcmp(str3, str4) == 0)
        printf("strcmp: Strings are equal\n");
    else
        printf("strcmp: Strings are not equal\n");
    
    //strcat
    strcat(str5, str6);
    printf("strcat: %s\n", str5);
    
    //strlen
    printf("strlen: %d\n", strlen(str6));
    
    //strrev
    strrev(str7);
    printf("strrev: %s\n", str7);
    
    //strncpy
    strncpy(str8, str9, 3);
    printf("strncpy: %s\n", str8);
    
    //strncmp
    if(strncmp(str9, str10, 3) == 0)
        printf("strncmp: Strings are equal\n");
    else
        printf("strncmp: Strings are not equal\n");
    
    //stricmp
    if(stricmp(str11, str12) == 0)
        printf("stricmp: Strings are equal\n");
    else
        printf("stricmp: Strings are not equal\n");
    
    //strncat
    strncat(str5, str6, 3);
    printf("strncat: %s\n", str5);
    
    //strstr
    printf("strstr: %s\n", strstr(str5, "wor"));
    
    //strlwr
    strlwr(str11);
    printf("strlwr: %s\n", str11);
    
    //strupr
    strupr(str12);
    printf("strupr: %s\n", str12);
    
    //atoi
    printf("atoi: %d\n", atoi(str13));
    
    //itoa
    char str14[10];
    itoa(num, str14, 10);       //this will change integer to string but in decimal format.   if we use 2 instead of 10 then answer would be in binery format 1's and 0's.
    printf("itoa: %s\n", str14);
    
    return 0;
}