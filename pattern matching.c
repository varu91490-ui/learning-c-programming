#include<stdio.h>
void main()
{
    char STR[100],PAT[100],REP[100],ans[100];
    int i,j,k,m,c,flag=0;
    printf("\nEnter main string:\n");
    gets(STR);
    printf("Enter pattern string:\n");
    gets(PAT);
    printf("Enter replace string:\n");
    gets(REP);
    i=j=m=c=0;
    while(STR[c]!='\0')
    {
        if(STR[m]==PAT[i])
        {
            m++;
            i++;
            if(PAT[i]=='\0')
            {
                for(k=0;REP[k]!='\0';k++,j++)
                {
                    ans[j]=REP[k];
                    flag=1;
                }
                i=0;
                c=m;
            }
        }
        else
        {
            ans[j]=STR[c];
            j++;
            c++;
            i=0;
            m=c;
        }
    }
    if(flag==0)
    {
        printf("Pattern doesnt found\n");
    }
    else
    {
        ans[j]='\0';
        printf("The resultant string is :%s\n",ans);
    }
}
