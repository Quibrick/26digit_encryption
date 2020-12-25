#import <stdio.h>
#import <cs50.h>
#import <ctype.h>
#import <string.h>


bool isvalid(char string[]);


int main(int argc, char* argv[])
{
    if(argc == '\0' || argc < 2)
    {
        printf("ERROR: WRONG ENCRYPTION KEY\n");
        return 1;
    }
    else if (isvalid(argv[1]))
    {
        return 1;
    }
    
    int lenkey = strlen(argv[1]);
    for (int i = 0; i < lenkey; i++)
    {
        argv[1][i] = (char)(toupper(argv[1][i]));
    }
        
    string original = get_string("plainetext: ");
    
    int index = 0,i;
    char asciitable[26];
    
    for (i = 65; i <= 90; i++)
    {   
        asciitable[index] = i;
        index += 1;
    }
    
    int pointer;
    int length = strlen(original);

    for (i = 0; i < length ; i++)
    {
        pointer = (int)original[i];

        for (int j = 0; j < 26; j++)
        {
            if ((int)toupper(original[i]) == asciitable[j])
            {   
                pointer = j;
               
                if (islower(original[i]))
                {
                    original[i] = (int)argv[1][pointer];
                    original[i] = tolower((char)original[i]);
                    break;    
                }
                else
                {
                    original[i] = (int)argv[1][pointer];
                    break;
                }
                
            }
        }
        
    }
    printf("ciphertext: ");
    for (i = 0; i < length; i++)
    {
        printf("%c",(char)original[i]);
    }
    printf("\n");
    
}






bool isvalid(char string[])
{
    int length = strlen(string),asciisum = 0;

    if (length != 26)
    {
        printf("ERROR: KEY MUST CONTAIN EXACTLY 26 CHARACTERS\n");
        return 1;
    }
    for (int i=0; i<length; i++)
    {
        asciisum += toupper(string[i]);

        if (!isalpha(string[i]))
        {
            printf("ERROR: KEY MUST ONLY CONTAIN ALPHABETICAL VALUES\n");
            return 1;
        }
    }
    if (asciisum != 2015 )
    {
        printf("ERROR : KEY MUST NOT CONTAIN DUBLICATES\n");
        return 1;
    }
    return 0;
}
