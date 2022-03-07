#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXRGB 256

void saveSpiralPPM(char *filename, int size){
    FILE *file = fopen(filename, "wb");

    if(file == NULL)
        return;

    char R[size / 2];
    for(int i = 0; i < size / 2;i++)
        R[i] = rand() % MAXRGB;

    char G[size / 2];
    for(int i = 0; i < size / 2;i++)
        G[i] = rand() % MAXRGB;

    char B[size / 2];
    for(int i = 0; i < size / 2;i++)
        B[i] = rand() % MAXRGB;

    fprintf(file, "P6 %d %d %d\n", size, size, MAXRGB - 1);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int depth = 0;
            while(i != depth && j != depth &&
                  i != size - depth - 1 && j != size - depth - 1){
                depth++;
            }
            fwrite(&R[depth], 1, 1, file);
            fwrite(&G[depth], 1, 1, file);
            fwrite(&B[depth], 1, 1, file);
        }
    }

}

void savePPMTest(char *filename, int size){
    FILE *file = fopen(filename, "wb");

    if(file == NULL)
        return;

    char R[size / 2];
    for(int i = 0; i < size / 2;i++)
        R[i] = rand() % MAXRGB;

//    char G[size / 2];
//    for(int i = 0; i < size / 2;i++)
//        G[i] = rand() % MAXRGB;
//
//    char B[size / 2];
//    for(int i = 0; i < size / 2;i++)
//        B[i] = rand() % MAXRGB;

    fprintf(file, "P6 %d %d %d\n", size, size, MAXRGB - 1);
    for(int i = 0; i < size * 3; i++){
        for(int j = 0; j < size; j++){
            int depth = 0;
            int vali = i;
            i = i % size;
            while(i != depth && j != depth &&
                  i != size - depth - 1 && j != size - depth - 1){
                depth++;
            }
            fwrite(&R[depth], 1, 1, file);
            i = vali;
        }
        printf("\n");
    }

}

int main()
{
    srand(time(NULL));
//    saveSpiralPPM("pruebaEspiral100x100.ppm", 100);
//    saveSpiralPPM("pruebaEspiral10x10.ppm", 10);
//    saveSpiralPPM("pruebaEspiral1000x1000.ppm", 1000);
//    saveSpiralPPM("32x32.ppm", 32);
    savePPMTest("pruebaTest.ppm", 50);
    return 0;
}
