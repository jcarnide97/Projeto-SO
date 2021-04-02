// João Filipe Carnide de Jesus Nunes   2017247442
// Rui Alexandre Coelho Tapadinhas      2018283200

#ifndef CORRIDAS_INCLUDED
#define CORRIDAS_INCLUDED

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
#include <pthread.h>
#include <sys/fcntl.h>
#include <semaphore.h>

#define PROCS_INCIAIS 2
#define MAX_CAR_TEAM 100
#define MAX_EQUIPAS 100
#define DEBUG
#define TIME_ABASTECIMENTO 2
#define TOP_FIVE 5

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
    float consumption;
    int reliability;
    int n_voltas;
    int n_paragens;
} carro;

typedef struct equipa {
    char* nome_equipa;
    char* box;
    carro* carros [MAX_CAR_TEAM];
} equipa;

typedef struct mem_structure {
    equipa* equipas [MAX_EQUIPAS];
    time_t init_time;
    int total_avarias;
    int n_paragens;
} mem_structure;

typedef struct Estatistica {
    carro* top_carros[TOP_FIVE];
    carro* ultimo_carro;
    int t_avarias;
    int n_paragens;
    int n_carros_pista;
} estatisticas;

dados* read_config(char* fname);
char* get_current_time();
void write_log(FILE *fp, char* message);
void gestor_corrida();
void gestor_avarias();
void gestor_equipa();
void init_shm();
void init_semaphores();
void *check_carros( void* id_thread);
void terminate();


#endif