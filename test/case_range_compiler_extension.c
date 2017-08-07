#include <stdio.h>

int main(){
    int score;

    //Vraag de score
    printf( "Score:");
    scanf("%d", &score);

    //Switch
    switch(score){
      case 0 ... 9:
            printf( "b");
            break;
       case 11 ... 24:
            printf( "c");
            break;
       case 25 ... 49:
            printf( "d");
            break;
       case 50 ... 100:
            printf( "e");
            break;         
        default:
            printf( "BAD VALUE");
            break;
    }
    printf("\n");;
    return 0;
}
