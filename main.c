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
                  i != size - 1 - depth && j != size - depth - 1){
                depth++;
            }
            fwrite(&R[depth], 1, 1, file);
            fwrite(&G[depth], 1, 1, file);
            fwrite(&B[depth], 1, 1, file);
        }
    }
    fclose(file);
}

void savePPMMultipleSpiral(char *filename, int size, int slices){
    FILE *file = fopen(filename, "wb");

    if(file == NULL)
        return;

    while(size % slices != 0 && slices < size)
        slices++;

    printf("slices %d", slices);

    char R[size / 2 / slices];
    for(int i = 0; i < size / 2 / slices;i++)
        R[i] = rand() % MAXRGB;

    char G[size / 2 / slices];
    for(int i = 0; i < size / 2 / slices;i++)
        G[i] = rand() % MAXRGB;

    char B[size / 2 / slices];
    for(int i = 0; i < size / 2 / slices;i++)
        B[i] = rand() % MAXRGB;

    fprintf(file, "P6 %d %d %d\n", size, size, MAXRGB - 1);
    for(int pos = 0; pos < slices * slices; pos++){
        for(int i = size/slices * pos/slices; i < size/slices * (pos/slices + 1); i++){
            for(int j = size/slices * pos % slices; j < size / slices * (pos % slices + 1); j++){
                int depth = 0;
                while(i != depth + size/slices * pos/slices && j != (depth + size/slices * pos % slices) &&
                    i != (size/slices * (pos / slices + 1) - 1 - depth) && j != size / slices * (pos % slices + 1) - 1 - depth){
                    depth++;
                }
                fwrite(&R[depth], 1, 1, file);
                fwrite(&G[depth], 1, 1, file);
                fwrite(&B[depth], 1, 1, file);
            }
        }
    }

    fclose(file);
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
    fclose(file);
}

int main()
{
    srand(time(NULL));
//    saveSpiralPPM("pruebaEspiral100x100.ppm", 100);
//    saveSpiralPPM("pruebaEspiral10x10.ppm", 10);
//    saveSpiralPPM("pruebaEspiral1000x1000.ppm", 1000);
    saveSpiralPPM("32x33.ppm", 32);
    //savePPMTest("pruebaTest.ppm", 50);
    savePPMMultipleSpiral("test.ppm", 4, 2);
    return 0;
}
