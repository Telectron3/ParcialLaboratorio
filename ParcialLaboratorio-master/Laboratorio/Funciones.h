#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM 10
#define TAMPla 10
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int Identificador;
    int Dni;
    char Nombres[TAM];
    int Edad;

}eProfesores;

typedef struct
{
    int Identificador;
    int Identifica;
    char Marca[50];
    char patente[TAM];
    char modelo[50];
    int Alta;

}eCoches;

typedef struct
{
    int Identificador;
    int Espacio;
    int hora;

}ePlayon;

void cargaProf(eProfesores[]);
void cargaCoche(eCoches[]);
void cargarPlayon(ePlayon[]);
void altaCoche(eCoches[],eProfesores[]);
void bajaCoche(eCoches[],eProfesores[]);
void ingresoPlayon(eCoches[],ePlayon[],eProfesores[]);
void egresoPlayon(eCoches[],ePlayon[],eProfesores[]);
void mostrar(eProfesores[],eCoches[],ePlayon[]);


#endif // FUNCIONES_H_INCLUDED
