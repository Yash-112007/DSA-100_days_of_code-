#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int freq[26] = {0};
    
    // input string
    scanf("%s", s);
    
    int len = strlen(s);

    // Step 1: count frequency
    for(int i = 0; i < len; i++)
    {
        freq[s[i] - 'a']++;
    }

    // Step 2: find first non-repeating character
    for(int i = 0; i < len; i++)
    {
        if(freq[s[i] - 'a'] == 1)
        {
            printf("%c", s[i]);
            return 0;
        }
    }

    // Step 3: if none found
    printf("$");
    return 0;
}
