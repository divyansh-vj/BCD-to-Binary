#include <stdio.h>
#include <stdlib.h>

int check_if_empty(int ** a, int n){
    for(int i=0; i<n;i++){
        for(int j=0; j<4; j++){
            if(a[i][j]!=0)
                return 0;
        }
    }
    return 1;
}

int right_shift(int ** a, int d){

    //printf("\n");
    int t0,t1,t2,t;
    for(int i=0;i<d;i++){
        t0 = a[i][0];
        if(i==0){
            a[i][0] = 0;
        }
        else{
            a[i][0] = t;
        }
        t1 = a[i][1];
        a[i][1] = t0;
        t2=a[i][2];
        a[i][2] = t1;
        t = a[i][3];
        a[i][3] = t2;
        if(i==(d-1))
            return t;
    }
}

void make_valid(int **BCD, int d){
    int num,check=0;
    //printf("\n");
    int *ar=(int*)malloc(d*sizeof(int));
    for(int i=0;i<d;i++){
        num = 8*BCD[i][0] + 4*BCD[i][1] + 2*BCD[i][2] + 1*BCD[i][3];
        //printf("  %d  ",num);
        switch(num){
        case 8:
            check=1;
            ar[i] = 1;
            BCD[i][0] = 0;
            BCD[i][1] = 1;
            BCD[i][2] = 0;
            BCD[i][3] = 1;
            break;

        case 9:
            check=1;
            ar[i] = 1;
            BCD[i][0] = 0;
            BCD[i][1] = 1;
            BCD[i][2] = 1;
            BCD[i][3] = 0;
            break;

        case 10:
            check=1;
            ar[i] = 1;
            BCD[i][0] = 0;
            BCD[i][1] = 1;
            BCD[i][2] = 1;
            BCD[i][3] = 1;
            break;

        case 11:
            check=1;
            ar[i] = 1;
            BCD[i][0] = 1;
            BCD[i][1] = 0;
            BCD[i][2] = 0;
            BCD[i][3] = 0;
            break;

        case 12:
            check=1;
            ar[i] = 1;
            BCD[i][0] = 1;
            BCD[i][1] = 0;
            BCD[i][2] = 0;
            BCD[i][3] = 1;
            break;
        }
    }
    if(check==1){
        printf("sub 3 in ");
        for(int i=0; i<d;i++){
            if(ar[i]==1){
                printf("D[%d]  ", ((d-1)-i));
            }
        }
        for(int i=0; i<d;i++){
            for(int j=0;j<4;j++){
                printf("%d",BCD[i][j]);
            }
            printf("   ");
        }
        printf("\n");
    }
    free(ar);
}

int main(){
    int d,c,n,i,j,digit,entry,index=0;
    printf("Do you want to convert from BCD to binary (1) or binary to BCD (0)");
    scanf("%d",&c);
    if(c==1){
        printf("enter no. of digits");
        scanf("%d",&d);
        printf("Enter the number");
        scanf("%d",&n);
        int binary[100];
        int** BCD;
        BCD = (int**)malloc(d*sizeof(int*));
        for(i=(d-1); i>=0;i--){
            BCD[i]=(int*)malloc(4*sizeof(int));
            digit = n%10;
            n = n/10;
            switch(digit){
            case 0:
                BCD[i][0] = 0;
                BCD[i][1] = 0;
                BCD[i][2] = 0;
                BCD[i][3] = 0;
                break;

            case 1:
                BCD[i][0] = 0;
                BCD[i][1] = 0;
                BCD[i][2] = 0;
                BCD[i][3] = 1;
                break;

            case 2:
                BCD[i][0] = 0;
                BCD[i][1] = 0;
                BCD[i][2] = 1;
                BCD[i][3] = 0;
                break;

            case 3:
                BCD[i][0] = 0;
                BCD[i][1] = 0;
                BCD[i][2] = 1;
                BCD[i][3] = 1;
                break;

            case 4:
                BCD[i][0] = 0;
                BCD[i][1] = 1;
                BCD[i][2] = 0;
                BCD[i][3] = 0;
                break;

            case 5:
                BCD[i][0] = 0;
                BCD[i][1] = 1;
                BCD[i][2] = 0;
                BCD[i][3] = 1;
                break;

            case 6:
                BCD[i][0] = 0;
                BCD[i][1] = 1;
                BCD[i][2] = 1;
                BCD[i][3] = 0;
                break;

            case 7:
                BCD[i][0] = 0;
                BCD[i][1] = 1;
                BCD[i][2] = 1;
                BCD[i][3] = 1;
                break;

            case 8:
                BCD[i][0] = 1;
                BCD[i][1] = 0;
                BCD[i][2] = 0;
                BCD[i][3] = 0;
                break;

            case 9:
                BCD[i][0] = 1;
                BCD[i][1] = 0;
                BCD[i][2] = 0;
                BCD[i][3] = 1;
                break;
            }
        }
        printf("original number  ");
        for(int i=0; i<d;i++){
            for(int j=0;j<4;j++){
                printf("%d",BCD[i][j]);
            }
            printf("   ");
        }
        printf("\n");
        while(1){
            if(!check_if_empty(BCD,d)){
                entry = right_shift(BCD,d);
                printf("right shift  ");
                for(int i=0; i<d;i++){
                    for(int j=0;j<4;j++){
                        printf("%d",BCD[i][j]);
                    }
                    printf("   ");
                }
                printf("\n");
                binary[index++] = entry;
                make_valid(BCD,d);
            }
            else
                break;
        }
        binary[index] = -1;
        i=0;
        //printf("%d",binary[1]);
        while(binary[i]!=-1){
            //printf("%d",binary[i]);
            i++;
        }
        i--;
        printf("\n");
        while(i!=-1){
            printf("%d",binary[i]);
            i--;
        }
    }
}
