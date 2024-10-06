#include <stdio.h>
//td_con = touch down converstion and is worth 8 points
//td_f = touch down field goal and is worth 7 points 
//td = touch down and is worth 6 points
//fg = field goal and is worth 3 points
//safety is worth 2 points
void find_combo(int td_con,int td_f,int td,int fg,int safety,int score, int call_from){
    // A recursive function that makes use of backtracking
        if (score == 0){
            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", td_con,td_f,td,fg,safety);
            return;
        }
        //Recursive calls that use varable call_from to avoid duplicates
        if ((score) >= 8 && call_from >= 8 ){
            find_combo(td_con+1,td_f,td,fg,safety,score-8,8);
        }  
            
        if (score >= 7 && call_from >= 7 ){
            find_combo(td_con,td_f+1,td,fg,safety,score-7,7);
        }
        if (score >= 6 && call_from >= 6){
            find_combo(td_con,td_f,td+1,fg,safety,score-6,7);
        }
        if (score >= 3 && call_from >= 3){
            find_combo(td_con,td_f,td,fg+1,safety,score-3,3);
        }
        if (score >= 2 && call_from >= 2){
            find_combo(td_con,td_f,td,fg,safety+1,score-2,2);
        }
        
    
}


int main(){
    int input;
    while (1){
        printf("Enter 1 or 0 to STOP");
        printf("Enter the score: ");
        scanf("%d",&input);
        if (input == 0 || input == 1){
            printf("Exiting...");
            break;
        }
        find_combo(0,0,0,0,0,input,8);
    }
}