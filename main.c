#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXRGB 256

void savePPM(char *filename, int size){
    FILE *file = fopen(filename, "wb");
    if(file == NULL){
        return;
    }
    fprintf(file, "P6 %d %d %d\n", size, size, MAXRGB - 1);
    for(int i = 0;i < size;i++){
        for(int j = 0; j < size; j++){
            int r;
            r = 255;
            //fwrite(&colors[r], 1, 1, file);
            //fwrite(&colors[r], 1, 1, file);
            //fwrite(&colors[r], 1, 1, file);
            if(i == j || size - i - 1 == j) r = 0;
            fwrite(&r, 1, 1, file);
            fwrite(&r, 1, 1, file);
            fwrite(&r, 1, 1, file);
        }
    }
}

int main()
{
    srand(time(NULL));
//    savePPM("prueba1.ppm", 100);
//    savePPM("prueba2.ppm", 80);
//    savePPM("prueba3.ppm", 60);
//    savePPM("prueba4.ppm", 40);
//    savePPM("prueba5.ppm", 20);
//    savePPM("prueba6.ppm", 10);
//    savePPM("prueba7.ppm", 8);
//    savePPM("prueba8.ppm", 6);
//    savePPM("prueba9.ppm", 4);
//    savePPM("prueba10.ppm", 2);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(j != 0) printf("\t");
            //int val = i * j;
            //if(i + j > 10) val = (10 - i) * (10 - j) ;
            printf("%d", (i + j)/10);
        }
        printf("\n");
    }
    return 0;
}
