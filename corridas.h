// João Filipe Carnide de Jesus Nunes   2017247442
// Rui Alexandre Coelho Tapadinhas      2018283200

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <string.h>

#define PROCS_INCIAIS 2
#define MAX_CAR_TEAM 100
#define MAX_EQUIPAS 100

// estrutura com as configurações do ficheiro config.txt
typedef struct Dados {
    int unidades_sec;
    int d_volta, n_voltas;
    int equipas;
    int max_cars_team;
    int T_Avaria;
    int T_Box_min, T_Box_Max;
    int capacidade;
} dados;
typedef dados* config;

typedef struct carro {
    int num;
    int speed;
    int consumption;
    int reliability;
} carro;

typedef struct equipa {
    char* nome_equipa;
    char* box;
    carro* carros [MAX_CAR_TEAM];
} equipa;

typedef struct mem_structure {
    equipa* equipas [MAX_EQUIPAS];
    time_t init_time;
} mem_structure;


dados* read_config(char* fname);
char* get_current_time();
void gestor_corrida();
void gestor_avarias();
void gestor_equipa();
void init_shm();
void terminate();