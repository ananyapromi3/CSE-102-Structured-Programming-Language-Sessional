#include<stdio.h>
#include<string.h>
int main()
{
    int i, key;
    scanf("%d",&key);
    char cipher[500], decipher[500];
    scanf("%s",cipher);
    int l=strlen(cipher);
    int j=0;
    for(i=0;i<l;i++)
    {
        if(i!=0 && *(cipher+i)>='a' && *(cipher+i)<='z' && *(cipher+i-1)>='A' && *(cipher+i-1)<='Z')
        {
            *(decipher+j)=' ';
            j++;
        }
        else if (*(cipher+i)>='A' && *(cipher+i)<='Z')
        {
            if((*(cipher+i)-'A')>=key) *(decipher+j)=*(cipher+i)-key;
            else *(decipher+j)=*(cipher+i)+(26-key);
            j++;
        }
    }
    *(decipher+j)='\0';
    printf("%s\n",decipher);
    return 0;
}

