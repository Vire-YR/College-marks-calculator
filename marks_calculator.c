#include<stdio.h>
#include<string.h>

struct subMarks{
    char name[50];
    int credits;
    float cat[2],fat,da,addLearn,labDa,labFat;
    float theory,lab,total;
};

float check(float max)
{
    float mark=0.0;
    scanf("%f",&mark);
    while(mark>max || mark<0.0)
    {
        printf("Marks should be less than %f. Please re-enter the marks: ",max);
        scanf("%f",&mark);
    }
    return mark;
}


int main(){

    printf("This program can be made use for Only Theory and Theory+Lab subjects\n\n");

    int n;
    printf("Enter the number of subjects: ");
    scanf("%d",&n);
    struct subMarks user[n];

    for(int i=0;i<n;i++)
    {
        printf("\n\t\tSUBJECT %d\n",(i+1));
        printf("Name of subject  : ");
        scanf("%s",&user[i].name);
        printf("Number of credits: ");
        scanf("%d",&user[i].credits);

        if(user[i].credits<=4)
        {
            printf("\t\tPlease enter the following marks\n");
            printf("CAT1 (out of 50) : ");
            user[i].cat[0] = check(50.0)*15/50;
            printf("CAT2 (out of 50) : ");
            user[i].cat[1] = check(50.0)*15/50;

            float sum=0.0;
            for(int j=0;j<3;j++)
            {
                printf("DIGITAL ASSIGNMENT/QUIZ %d  : ",(j+1));
                sum+= check(10.0);
            }
            user[i].da=sum;

            printf("FAT  (out of 100): ");
            user[i].fat = check(100.0)*40/100;

            printf("Additional Learning : ");
            user[i].addLearn = check(10.0);

            if(user[i].credits==4)
            {
                printf("TOTAL lab assignments marks out of 60: ");
                user[i].labDa = check(60.0);
                printf("Lab FAT (out of 50) : ");
                user[i].labFat = check(50.0)*40/50;
            }
        }

        else {
            printf("Number of credits should be less than 4\n");
            printf("Please re-enter the details of the subject again\n\n");
            i-=1;
            continue;
        }

    user[i].theory = user[i].cat[0] + user[i].cat[1] + user[i].fat + user[i].da;
    user[i].total=user[i].addLearn;
    if(user[i].credits == 4)
    {
        user[i].lab = user[i].labDa + user[i].labFat;
        user[i].total+= (user[i].lab/4) + (user[i].theory*3/4);
    }

    else
        user[i].total+=user[i].theory;
    }

    printf("\n\n\tSUBJECT_NAME\tCREDITS\tTOTAL MARKS\n");
    for(int i=0;i<n;i++)
        printf("\t%s\t%d\t%f\n",user[i].name,user[i].credits,user[i].total);


    return 0;

}
