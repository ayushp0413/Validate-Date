#include <stdio.h>
#include <string.h>
void isValidDate(const char* dateString,int* isValid,int* d,int* m,int* y)
{
    int dd,mm,yy;
    char sep;
    int sepIndex1,sepIndex2;
    char mth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    *isValid=0;
    if(dateString==NULL)return;
    int x=strlen(dateString);
    if(x<8 || x>10)return;
    if(!(dateString[1]=='/' ||dateString[1]=='-' || dateString[2]=='/' || dateString[2]=='-')) return;
    //confirm 1 or 2 pr separator hai
    if(dateString[1]=='/' || dateString[1]=='-')sepIndex1=1;
    else sepIndex1=2;
    //whatever in sepIndex put in sep variable
    sep=dateString[sepIndex1];
    if(dateString[0]<48 || dateString[0]>57)return;
    if(sepIndex1==2 &&(dateString[1]<48 || dateString[1]>57))return;
    //confirm that date is numeric
    if(sepIndex1==1)
    {
        dd=dateString[0]-48;
        if(dd==0)return;
    }
    else
    {
        dd=((dateString[0]-48)*10)+(dateString[1]-48);
        if(dd==0)return;;
    }
    //----------------day done----------------------------------------------------------
    int i=sepIndex1+1;//ek ghar aage se kahani start krna h
    if(!(dateString[i+1]==sep ||dateString[i+2]==sep))return;
    if(dateString[i+1]==sep)sepIndex2=i+1;
    else sepIndex2=i+2;
    if(dateString[i]<48 || dateString[i]>57)return;
    if(sepIndex2==i+2 && (dateString[i]<48 || dateString[i]>57))return;
    if(sepIndex2==i+1)mm=dateString[i]-48;
    else
    {
        mm=((dateString[i]-48)*10)+(dateString[i+1]-48);;
    }
    if(mm<1 || mm>12)return;
    //------------------Month Done------------------------------------------------------------------
    i=sepIndex2+1;
    yy=0;
    int r=0;
    while(r<=3)
    {
        if(dateString[i+r]<48 || dateString[i+r]>57)return;
        yy=(yy*10)+(dateString[i+r]-48);
        r++;
    }
    if(yy<1901)return;
    if(yy%400==0)mth[1]=29;
    else if(yy%100==0)mth[1]=28;
    else if(yy%4==0)mth[1]=29;
    else mth[1]=28;
    if(dd<1 || dd>mth[mm-1])return;
    *d=dd;
    *m=mm;
    *y=yy;
    *isValid=1;
}
int main()
{
    int d,m,y,isValid;
    char dateString[52];
    printf("Enter date:");
    scanf("%s",&dateString);
    isValidDate(dateString,&isValid,&d,&m,&y);
if(isValid)
{
    printf("%d/%d/%d",d,m,y);
}
else
{
    printf("chaal chutiye\n");
}
    
    return 0;
    
}