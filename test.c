//U11016032 資科一 郭啟霖
#include <stdio.h>
#define ARRAY_LENGTH 100
#define max(a,b) a >= b ? a : b
#define min(a,b) a <= b ? a : b

int main(){
    int again = 1;
    while(again){
        char a[ARRAY_LENGTH] = {0}, b[ARRAY_LENGTH] = {0}, c[ARRAY_LENGTH] = {0}, d[ARRAY_LENGTH] = {0};
        int aL, bL;
        printf("Input two number less than 100 digits\n");
        scanf("%s%s", &a, &b);

        int pOrM;

        printf("(add) input 1, (minus) input 0 \n");
        scanf("%d", &pOrM);

        //紀錄a的資料長度
        for(int i = 99; i >= 0; i--){
            if(a[i] != 0){
                aL = i;
                break;
            }
        }

        //紀錄b的資料長度
        for(int i = 99; i >= 0; i--){
            if(b[i] != 0){
                bL = i;
                break;
            }
        }
        if(pOrM == 0){
            for(int i = 0; i < ARRAY_LENGTH; i++){
                c[i] = '9';
            }
            c[99] += 1;

            for(int i = aL; i >= 0; i--){
                c[99 + i - aL] = c[99 + i - aL] - a[i] + '0';
            }

            for(int i = bL; i >= 0; i--){
                c[99 + i - bL] = c[99 + i - bL] + b[i] - '0';
            }
            if(c[0] > '9'){
                c[0] - 10;
            }

            for(int i = 99; i >= 0; i--){
                while(c[i] > '9'){
                    c[i] -= 10;
                    c[i - 1] += 1;
                }
            }
            if(c[0] == '9'){
                int k = 0;
                for(int i = 0; i < ARRAY_LENGTH; i++){
                    if(c[i] != '9'){
                        for(int j = i; j < ARRAY_LENGTH; j++){
                            d[0 + j - i] = '9' - c[j] + '0';
                        }
                        d[99 - i] += 1;
                        if(d[99 - i] == ':'){
                            d[0] = '1';
                            for(int l = 0; l < 100 - i; l++){
                                d[l + 1] = '0';
                            }
                        }
                        break;
                    }
                    k++;
                }
                if(k == 100){
                    d[0] = '1';
                }
            }

            if(c[0] == '0'){
                int k = 0;
                for(int i = 0; i < ARRAY_LENGTH; i++){
                    if(c[i] != '0'){
                        for(int j = i; j < ARRAY_LENGTH; j++){
                            d[0 + j - i] = c[j];
                        }
                        break;
                    }
                    k++;
                }
                if(k == 100){
                    d[0] = '0';
                }
            }
            printf("%s\n", d);
        }else{
            if(aL >= bL){
                for(int i = 0; i <= aL; i++){
                    c[i] = a[i];
                }
                for(int i = 0; i <= bL; i++){
                    d[i] = b[i];
                }
            }else{
                for(int i = 0; i <= aL; i++){
                    d[i] = a[i];
                }
                for(int i = 0; i <= bL; i++){
                    c[i] = b[i];
                }
            }

            int lL = max(aL,bL), sL = min(aL,bL);
            for(int i = sL; i >= 0; i--){
                c[lL + i - sL] = c[lL + i - sL] + d[i] - '0';
            }

            //測試是否超出範圍
            if(lL == 99 && c[0] > '9'){
                printf("Number out bound, unable to count");
                goto restart;
            }else if(lL == 99 && c[0] == '9'){
                for(int i = 1; i < ARRAY_LENGTH; i++){
                    if(c[i] == '9'){
                        continue;
                    }else if(c[i] >= '9'){
                        printf("Number out bound, unable to count");
                        goto restart;
                    }else{
                        break;
                    }
                }
            }

            int count = 0;
            for(int i = lL; i >= 0; i--){
                if(c[i] > '9'){
                    if(c[0] > '9'){
                        c[0] -= 10;
                        for(int j = 0; j <= lL; j++){
                            d[j + 1] = c[j];
                        }
                        d[0] = '1';
                        printf("%s\n", d);
                        break;
                    }
                    c[i-1] += 1 ;
                    c[i] -= 10;
                    count++;
                }
            }

            if(count == 0){
                printf("%s\n", c);
            }
        }
        restart:
        printf("(again) input 1, (end) input 0\n");
        scanf("%d", &again);
    }
}
