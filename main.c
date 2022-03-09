#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXRGB 256
#define MINSLICES 2

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

void savePPMMultipleSpiral(char *filename, int size){
    FILE *file = fopen(filename, "wb");

    if(file == NULL)
        return;

    int slices = MINSLICES;
    while(size % slices != 0 && slices < size)
        slices++;

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

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int pos = 0;
            while(i >= size/slices * (pos/slices + 1) || j >= size/slices * (pos % slices + 1)){
                pos++;
            }
            int depth = 0;
            while(i != depth + size/slices * pos/slices && j != (depth + size/slices * pos % slices) &&
                i != (size/slices * (pos / slices + 1) - 1 - depth) && j != size / slices * (pos % slices + 1) - 1 - depth){
                depth++;
            }

            printf("pos(%d) = %d, ", pos, depth);
            fwrite(&R[depth], 1, 1, file);
            fwrite(&G[depth], 1, 1, file);
            fwrite(&B[depth], 1, 1, file);
        }
        printf("\n");
    }


    fclose(file);
}

void savePPMMultipleSpiral2(char *filename, int size){
    FILE *file = fopen(filename, "wb");

    if(file == NULL)
        return;

    int slices = MINSLICES;
    while(size % slices != 0 && slices < size)
        slices++;

    char R[size / 2 / slices];
    for(int i = 0; i < size / 2 / slices;i++)
        R[i] = rand() % MAXRGB;

    char G[size / 2 / slices];
    for(int i = 0; i < size / 2 / slices;i++)
        G[i] = rand() % MAXRGB;

    char B[size / 2 / slices];
    for(int i = 0; i < size / 2 / slices;i++)
        B[i] = rand() % MAXRGB;

    fprintf(file, "P2 %d %d %d\n", size, size, MAXRGB - 1);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int pos = 0;
            while(i >= size/slices * (pos/slices + 1) || j >= size/slices * (pos % slices + 1)){
                pos++;
            }
            int depth = 0;
            while(i != depth + size/slices * pos/slices && j != (depth + size/slices * pos % slices) &&
                i != (size/slices * (pos / slices + 1) - 1 - depth) && j != size / slices * (pos % slices + 1) - 1 - depth){
                depth++;
            }
            printf("pos(%d) = %d, ", pos, depth);
            fprintf(file, "%d\t", R[depth]);
        }
        printf("\n");
        fprintf(file, "\n");
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
//    saveSpiralPPM("32x33.ppm", 32);
//    savePPMMultipleSpiral2("test.ppm", 8, 2);

    saveSpiralPPM("32x32.ppm", 32);
    savePPMMultipleSpiral2("test.pgm", 8);


    return 0;
}
