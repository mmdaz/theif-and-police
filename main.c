#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int cntp,cntd;
int g_dozd(int *xl, int *yl,int p, int xd, int yd)
{
    int i=0,cnt=0;
    for (; i<p; i++)
    {
        if (xl[i]==xd && yl[i]==yd)
        {
            cnt++;
        }
        if (cnt>0)
        {
            return 1;
        }
        else
            return 0;
    }
}

int sch(int *xl, int *yl, int p, int xd, int yd )
{
    int i,cnt=0;
    for (i=0; i<p; i++)
    {
        if (xd<=(xl[i]+2) && xd>=(xl[i]-2) && yd<=(yl[i]+2) && yd>=(yl[i]-2))
        {
            cnt++;
        }
    }
    if (cnt>0)
        return 1;
    else
        return 0;
}

int main()
{
    int n,m,p,i,j,k=0,x=0,y=0;
    printf("ertefa :\n");
    scanf("%d",&n);
    printf("arz :\n");
    scanf("%d",&m);
    printf("tedade police :");
    scanf("%d",&p);
    system("cls");
    int tab[n][m];
    srand(time(NULL));
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 26);

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            tab[i][j]=0;

        }
    }
    int xl[p],yl[p],x1,y1;

    while (k<p)
    {
        x=rand();
        x=x%n;
        y=rand();
        y=y%m;
        if (tab[x][y]==0)
        {
            xl[k]=x;
            yl[k]=y;
            tab[x][y]=1;
        }
        else
        {
            continue;
        }
        k++;
    }

    int xd,yd,xd1,yd1;
    while (1)
    {
        xd=rand();
        xd=xd%n;
        yd=rand();
        yd=yd%m;
        xd1=xd;
        yd1=yd;
        // printf("(%dd,%dd)\n",xd,yd);

        int cnt=0;
        if (tab[xd][yd]==1)
        {

            continue;
        }
        else
            tab[xd][yd]=-1;
        break;
    }

    int rl;

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            if (tab[i][j]==1)
            {
                printf("p");
            }
            else if (tab[i][j]==-1)
            {
                printf("D");
            }
            else
                printf(" ");

        }
        printf("\n");
    }
    Sleep(2000);
    system("cls");
    // for (i=0;i<p;i++){
    //  printf("(%d,%d)\n",xl[i],yl[i]);
    // }
    int r2;
    while(g_dozd(xl,yl,p,xd,yd)==0)
    {
        system("cls");
        //  printf("%d\n",g_dozd(xl,yl,p,xd,yd));
        // harakate dozd


        rl=rand();
        rl=rl%3;
        rl--;

        if (xd==0 && n!=1 && rl==-1)
        {
            r2=rand();
            r2=r2%2;
            r2++;
            rl=rl+r2;
        }
        else if (xd==(n-1) && n!=1 && rl==1)
        {
            r2=rand();
            r2=r2%2;
            r2++;
            rl=rl-r2;
        }
        else if (xd==(n-1) && n==1 && rl!=0){
            rl=0;
        }

        tab[xd1][yd1]=0;
        xd=xd+rl;

        rl=rand();
        rl=rl%3;
        rl--;

        if (yd==0 && m!=1 && rl==-1)
        {
            r2=rand();
            r2=r2%2;
            r2++;
            rl=rl+r2;
        }
        else if (yd==(m-1) && m!=1 && rl==1)
        {
            r2=rand();
            r2=r2%2;
            r2++;
            rl=rl-r2;
        }
        else if (yd==(m-1) && m==1 && rl!=0){
            rl=0;
        }
        yd=yd+rl;
        xd1=xd;
        yd1=yd;
        if (tab[xd1][yd1]==1)
        {
            printf("Dozd gerefte shod!!!\n");
            printf("H-P = %d \n H-D = %d ",cntp,cntd);
            return 0;
        }
        else if (xd==(n-1) && yd==(m-1) && rl!=0 ){
            rl=0;
        }


        cntd++;

        tab[xd][yd]=-1;
// printf("(%dd,%dd)\n",xd,yd);

        // harakate dozd
//printf("r\n");


        if (sch(xl,yl,p,xd,yd)==0)
        {
            i=0;
//printf("s\n");
            while(i<p)
            {
                rl=rand();
                rl=rl%3;
                rl--;
                if (xl[i]==0 && n!=1 && rl==-1)
                {
                    r2=rand();
                    r2=r2%2;
                    r2++;
                    rl=r2+rl;
                    //  printf("i1\n");
                }

                else if (xl[i]==(n-1) && n!=1 && rl==1)
                {
                    r2=rand();
                    r2=r2%2;
                    r2++;
                    rl=rl-r2;
                    //   printf("i2\n");
                }
                 else if (xl[i]==0 && n==1 && rl!=0 ){
                    rl=0;
                }
                // printf("ix\n");
                x=xl[i]+rl;

                rl=rand();
                rl=rl%3;
                rl--;
                if (yl[i]==0 && m!=1 && rl==-1)
                {
                    r2=rand();
                    r2=r2%2;
                    r2++;
                    rl=r2+rl;

                    //  printf("i3\n");
                }
                else if (yl[i]==(m-1) && m!=1 && rl==1)
                {
                    r2=rand();
                    r2=r2%2;
                    r2++;
                    rl=rl-r2;
                    //  printf("i4\n");
                }
                else if (yl[i]==0 && m==1 && rl!=0){
                    rl=0;
                }

                y=yl[i]+rl;

                if (tab[x][y]==-1)
                {
                    tab[x][y]=1;
                    cntp++;
                    printf("Dozd gerefte shod!!\n");
                    printf("H-P = %d \n H-D = %d ",cntp,cntd);

                    return 0;
                }



                if (tab[x][y]==0)
                {
                    tab[xl[i]][yl[i]]=0;
                    xl[i]=x;
                    yl[i]=y;
                    cntp++;
                    //   printf("%d,%d",x,y);
                    tab[x][y]=1;
                    i++;
                }
                else
                {
                    // printf("omadam\n");
                    continue;
                }

            }

        }

//printf("f\n");
        if (sch(xl,yl,p,xd,yd)==1)
        {


            i=0;
            while(i<p)
            {
                if (xd>xl[i] && yd>yl[i])
                {
                    rl=rand();
                    rl=rl%4;
                    //  printf("i1\n");
                    if (rl==1)
                    {
                        x=xl[i]+1;
                        y=yl[i]+1;

                    }
                    else if (rl==0)
                    {
                        x=xl[i];
                        y=yl[i]+1;

                    }
                    else if (rl==2)
                    {
                        y=yl[i];
                        x=xl[i]+1;

                    }
                    else
                    {
                        x=xl[i];
                        y=yl[i];
                         i++;

                        tab[x][y]=1;
                        continue;

                    }

                }
                else if (yd==yl[i] && xd>xl[i])
                {
                    rl=rand();
                    rl=rl%4;
                    if (rl==0)
                    {
                        x=xl[i]+1;
                        y=yl[i];
                    }
                    else if (rl==1)
                    {
                        x=xl[i]+1;
                        y=yl[i]+1;
                    }
                    else if (rl==2)
                    {
                        y=yl[i]-1;
                        x=xl[i]+1;
                    }
                    else
                    {
                        x=xl[i];
                        y=yl[i];
                        i++;

                        tab[x][y]=1;
                        continue;
                    }
                    // printf("i2\n");
                }


                else if (xd>xl[i] && yd<yl[i])
                {
                    rl=rand();
                    rl=rl%4;
                    //  printf("i3\n");
                    if (rl==1)
                    {
                        x=xl[i]+1;
                        y=yl[i]-1;
                    }

                    else if (rl==0)
                    {
                        x=xl[i]+1;
                        y=yl[i];
                    }
                    else if (rl==2)
                    {
                        y=yl[i]-1;
                        x=xl[i];
                    }
                    else
                    {
                        x=xl[i];
                        y=yl[i];
                        i++;

                        tab[x][y]=1;
                        continue;
                    }
                }
                else if (xd==xl[i] && yd<yl[i])
                {
                    rl=rand();
                    rl=rl%4;
                    if (rl==0)
                    {
                        x=xl[i];
                        y=yl[i]-1;
                    }
                    else if (rl==1)
                    {
                        x=xl[i]+1;
                        y=yl[i]-1;
                    }
                    else if (rl==2)
                    {
                        x=xl[i]-1;
                        y=yl[i]-1;
                    }
                    else
                    {
                        x=xl[i];
                        y=yl[i];
                        i++;

                        tab[x][y]=1;
                        continue;
                    }
                    // printf("i4\n");
                }
                else if (xd<xl[i] && yd<yl[i])
                {
                    rl=rand();
                    rl=rl%4;
//  printf("i5\n");
                    if (rl==0)
                    {
                        x=xl[i]-1;
                        y=yl[i]-1;
                    }
                    else if (rl==1)
                    {
                        y=yl[i]-1;
                        x=xl[i];
                    }
                    else if (rl==2)
                    {
                        y=yl[i];
                        x=xl[i]-1;
                    }
                    else
                    {
                        x=xl[i];
                        y=yl[i];
                        i++;

                        tab[x][y]=1;
                        continue;
                    }
                }

                else if (xd<xl[i] && yd==yl[i])
                {
                    rl=rand();
                    rl=rl%4;
                    if (rl==0)
                    {
                        y=yl[i];
                        x=xl[i]-1;
                    }
                    else if (rl==1)
                    {
                        x=xl[i]-1;
                        y=yl[i]-1;
                    }
                    else if (rl==2)
                    {
                        y=yl[i]+1;
                        x=xl[i]-1;
                    }
                    else
                    {
                        x=xl[i];
                        y=yl[i];
                        i++;

                        tab[x][y]=1;
                        continue;
                    }
                    // printf("i6\n");
                }
                else if (xd<xl[i] && yd>yl[i])
                {
                    rl=rand();
                    rl=rl%4;
                    // printf("i7\n");
                    if (rl==0)
                    {
                        y=yl[i]+1;
                        x=xl[i]-1;
                    }
                    else if (rl==1)
                    {
                        y=yl[i];
                        x=xl[i]-1;
                    }
                    else if (rl==2)
                    {
                        x=xl[i];
                        y=yl[i]+1;
                        // printf("i8\n");
                    }
                    else
                    {
                        x=xl[i];
                        y=yl[i];
                        i++;

                        tab[x][y]=1;
                        continue;
                    }
                }
                else if (xd==xl[i] && yd>yl[i])
                {
                    rl=rand();
                    rl=rl%4;
                    if (rl==0)
                    {
                        x=xl[i];
                        y=yl[i]+1;
                    }
                    else if (rl==1)
                    {
                        x=xl[i]+1;
                        y=yl[i]+1;
                    }
                    else if (rl==2)
                    {
                        y=yl[i]+1;
                        x=xl[i]-1;
                    }
                    else
                    {
                        x=xl[i];
                        y=yl[i];
                        i++;

                        tab[x][y]=1;
                        continue;
                    }
                }
                if (tab[xl[i]][yl[i]]==-1 || tab[x][y]==-1)
                {

                    tab[xl[i]][yl[i]]=1;
                    break;
                }

                else if (tab[x][y]==0)
                {
                    tab[xl[i]][yl[i]]=0;
                    xl[i]=x;
                    yl[i]=y;
                    cntp++;
                    //  printf("(%d,%d)\n",x,y);
                    tab[x][y]=1;
                }
                else
                {
                    //  printf("(%d,%d)\n(%dd,%dd)\n(%di,%di)",x,y,xd,yd,xl[i],yl[i]);
// printf("o\n");
                    continue;
                }
                i++;

            }
//printf("g\n");
        }
        for (i=0; i<n; i++)
        {
            for (j=0; j<m; j++)
            {
                if (tab[i][j]==1)
                {
                    printf("P");
                }
                else if (tab[i][j]==-1)
                {
                    printf("D");
                }
                else
                    printf(" ");
            }
            printf("\n");
        }
// printf("%d",g_dozd(xl,yl,p,xd,yd));
        Sleep(1000);
    }

    printf("Dozd gerefte shod!!!");
    printf("H-P = %d \n H-D = %d ",cntp,cntd);
    return 0;
}


