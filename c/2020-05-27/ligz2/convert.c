#include  <stdio.h>
#define MAX_LINE 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    int i;
    char c;
    char input[MAX_LINE], out[MAX_LINE],  revert[MAX_LINE];
    for ( i=0; (i< MAX_LINE) && (c = getchar()) != EOF; i++) {
        input[i] = c;
    }
    printf("%s", input);
    escape(out, input);
    printf("%s\n", out);
    unescape(revert, out);
    printf("%s", revert);
    return 0;
}

void escape(char s[], char t[])
{  
    int  j=0;
    for(int i=0; i<MAX_LINE;i++)
    {
        switch (t[i])
        {
        case '\t'/* constant-expression */:
            s[j++] = '\\';
            s[j++] = 't';
            break;
            /* code */
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;

        case '\r':
            s[j++] = '\\';
            s[j++] = 'r';
            break;
        case '\a': 
            s[j++] = '\\';
            s[j++] = 'a';
            break;

        case '\b': 
            s[j++] = '\\';
            s[j++] = 'b';
            break;

        case '\v': 
            s[j++] = '\\';
            s[j++] = 'v';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
}

void unescape(char s[], char t[])
{
    int j=0;
    for(int i=0; i<MAX_LINE;i++)
    {
        if (t[i] == '\\') {
            switch (t[i+1])
            {
            case 't':
                s[j++] = '\t';
                i++;
                break;
            case 'n':
                s[j++] = '\n';
                i++;
                break;
            case 'r':
                s[j++] = '\r';
                i++;
                break;
            case 'a': 
                s[j++] = '\a';
                i++;
                break;
            case 'b': 
                s[j++] = '\b';
                i++;
                break;
            case 'v': 
                s[j++] = '\v';
                i++;
                break;
            default:
                s[j++] = t[i];
                break;
            }
    
        } else {
            s[j++] = t[i];
        }
   }

}