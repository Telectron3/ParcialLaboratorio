#include "Funciones.h"

void cargaCoche(eCoches Coches[])
{
    int i;

    int iden[TAM] = {1,2,3,4,5,6,7,8,9,10};
    int IdenP[TAM] = {101,102,103,104,105,106,107,108,109,110};
    char patente[TAM][100] = {"GHJ 987","LLG 467","UYT 123","LOL 126","GGG 666","PAW 111","ARG 456","IFD 777","IBM 901","QWE 732"};
    char marca[TAM][100] = {"Ford","Volkswagen","Ford","Citroen","Ford","Audi","Mercedes Benz","Chevrolet","Shelby","Aston Martin"};
    char modelo[TAM][100] = {"Fiesta","Bora","Ranger","Picasso","K","TT","AMG","Camaro","Cobra","DB5"};
    int Alta[TAM] = {1,1,1,1,1,0,0,0,0,0};

    for(i=0; i<TAM; i++)
    {
        Coches[i].Identificador = iden[i];
        strcpy(Coches[i].patente,patente[i]);
        strcpy(Coches[i].Marca,marca[i]);
        strcpy(Coches[i].modelo,modelo[i]);
        Coches[i].Alta=Alta[i];
        Coches[i].Identifica=IdenP[i];
    }
}

void cargaProf(eProfesores Profes[])
{
    int i;

    int Iden[TAM] = {1,2,3,4,5,6,7,8,9,10};
    char Nomb[TAM][100] = {"Roberto","Carlos","Jorge","Maria","Luis","Florencia","Andrea","Lorena","Marcos","Jonatan"};
    int Edad[TAM] = {21,32,45,34,55,27,38,49,50,40};
    int Dni[TAM] = {39000000,49564827,30567829,29123579,23457839,27456371,28948572,22756513,19465783,30947562};

    for(i=0; i<TAM; i++)
    {
        Profes[i].Identificador = Iden[i];
        strcpy(Profes[i].Nombres,Nomb[i]);
        Profes[i].Dni=Dni[i];
        Profes[i].Edad=Edad[i];
    }
}

void cargarPlayon(ePlayon Playon[])
{
    int iden[TAM] = {101,102,103,104,105,106,107,108,109,110};
    int espacio[TAMPla] = {0,0,0,0,0,0,0,0,0,0};
    int i;
    for(i=0; i<TAM; i++)
    {
        Playon[i].Identificador=iden[i];
        Playon[i].Espacio=espacio[i];
    }
}

void altaCoche(eCoches Coche[],eProfesores Profesores[])
{
    int i;
    int a;
    int j;
    int h;
    int alta;
    int opcion;
    char nombre[50];
    printf("Profesores sin dar de alta\n");
    for(a=0; a<TAM; a++)
    {
        if(Coche[a].Alta ==0)
        {
            printf("%s\n",Profesores[a].Nombres);
        }
    }

    for(i=0; i<TAM; i++)
    {
        if(Coche[i].Alta == 0)
        {
            printf("\nHay profesores que no estan dados de alta desea dar de alta alguno\n");
            printf("\n 1_Si\n 2_No\n");
            scanf("%d",&opcion);

            if(opcion == 1)
            {
                printf("Escriba el nombre que desea dar de alta\n");
                fflush(stdin);
                gets(nombre);

                for(j=0; j<TAM; j++)
                {
                    if(strcmp(Profesores[j].Nombres,nombre)==0)
                    {
                        for(h=0; h<TAM; h++)
                        {
                            if(Profesores[j].Identificador == Coche[h].Identificador)
                            {
                                alta = 1;
                                Coche[h].Alta=alta;
                                printf("El profesor a sido dado de alta\n");
                            }
                        }

                    }

                }
            }
            if(opcion==2)
            {
                i=TAM;
            }
        }
    }
}

void bajaCoche(eCoches Coche[],eProfesores Profesor[])
{
    int a;
    int j;
    int i;
    int alta;
    char nombre[50];

    printf("Profesores que se pueden dar de baja\n\n");
    for(a=0;a<TAM;a++)
        if(Coche[a].Alta == 1)
        {
            printf("%s\n",Profesor[a].Nombres);
        }

    printf("\nEscriba el nombre del profesor que desea borrar\n");
    fflush(stdin);
    gets(nombre);
    for(i=0; i<TAM; i++)
    {
        if(strcmp(Profesor[i].Nombres,nombre)==0)
        {
            for(j=0; j<TAM; j++)
            {
                if(Profesor[i].Identificador == Coche[j].Identificador)
                {
                    alta = 0;
                    Coche[j].Alta=alta;
                    printf("El profesor a sido dado de baja\n");
                }
            }

        }
    }

}

void altaPlayon(eCoches Coche[],ePlayon Playon[], eProfesores Profesor[])
{
    int i;
    int j;
    int h;
    int a;
    int opcion;
    int espacio;
    char nombre[50];
    int hora;
    int g;
    printf("Profesores\n\n");
    for(g=0;g<TAM;g++)
    {
        printf("%s\n",Profesor[g].Nombres);
    }
    for(i=0; i<TAMPla; i++)
    {
        if(Playon[i].Espacio == 0)
        {
            printf("\nHay espacio en playon\n Desea ingresar un profesor\n 1_Si\n 2_No\n");
            scanf("%d",&opcion);
            if(opcion == 1)
            {
                printf("Escriba el nombre:\n");
                fflush(stdin);
                gets(nombre);

                for(j=0; j<TAM; j++)
                {
                    if(strcmp(Profesor[j].Nombres,nombre) == 0)
                    {
                        for(a=0; a<TAM; a++)
                        {
                            if(Profesor[j].Identificador == Coche[a].Identificador)
                            {
                                if(Coche[a].Alta == 0)
                                {
                                    printf("Este profesor no ha sido dado de alta\n");
                                }
                                else
                                {
                                    for(h=0; h<TAMPla; h++)
                                    {
                                        if(Playon[h].Identificador == Coche[a].Identifica)
                                        {
                                            espacio = 1;
                                            Playon[h].Espacio = espacio;
                                            printf("A que hora ingresa:\t");
                                            scanf("%d",&hora);
                                            Playon[h].hora = hora;
                                            printf("El profesor ingreso\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                i=TAM;
            }
        }
    }
}

void egresoPlayon(eCoches Coche[], ePlayon Playon[], eProfesores Profesores[])
{
    int i;
    int j;
    int espacio;
    char nombre[50];
    int hora;
    int h;
    int contador=10;
    int g;

    printf("Profesores\n\n");
    for(g=0;g<TAM;g++)
    {
        printf("%s\n",Profesores[g].Nombres);
    }
    printf("\nEscriba el nombre del profesor que desea borrar:\n");
    fflush(stdin);
    gets(nombre);
    for(i=0; i<TAM; i++)
    {
        if(strcmp(Profesores[i].Nombres,nombre) == 0)
        {
            for(j=0; j<TAM; j++)
            {
                if(Coche[i].Identifica == Playon[j].Identificador)
                {
                    if(Playon[j].Espacio == 0)
                    {
                        printf("Este profesor nunca ingreso\n");
                    }
                    else
                    {
                        printf("A que hora egresa:\t");
                        scanf("%d",&hora);
                        if(hora<=24)
                        {
                            if(hora >= Playon[j].hora && hora <= (Playon[j].hora +4))
                            {
                                espacio = 0;
                                Playon[j].Espacio = espacio;
                                printf("El profesor egreso\n");
                            }
                            else if(hora < Playon[j].hora)
                            {
                                printf("No puede egresar antes de haber ingresado");
                            }
                            for(h=1; h<hora; h++)
                            {
                                if(hora == (Playon[j].hora+4+h))
                                {
                                    contador = contador * h;
                                    printf("El profesor debe pagar %d pesos\n",contador);
                                    espacio = 0;
                                    Playon[j].Espacio = espacio;
                                    printf("El profesor egreso\n");
                                }
                            }
                        }


                    }
                }
            }
        }
    }
}

void mostrar(eProfesores prof[],eCoches Cars[],ePlayon Playon[])
{
    int i;
    int j;

    eCoches auxCars;

    int a;
    int b;

    int total=0;

    printf("\nPatente con Duenio\n\n");


    for( a=0; a<TAM-1; a++)
    {
        for( b=a+1; b<TAM; b++)
        {
            if(strcmp(Cars[a].Marca,Cars[b].Marca)>0)
            {
                auxCars=Cars[a];
                Cars[a]=Cars[b];
                Cars[b]=auxCars;
            }
            else if(strcmp(Cars[a].Marca,Cars[b].Marca)==0)
            {
                if(strcmp(Cars[a].patente,Cars[b].patente)>0)
                {
                    auxCars=Cars[a];
                    Cars[a]=Cars[b];
                    Cars[b]=auxCars;
                }

            }

        }
    }

    for(a=0; a<TAM; a++)
    {
        if(Cars[a].Alta == 1)
        {
            printf("%s\t",Cars[a].patente);
            for(b=0; b<TAM; b++)
            {
                if (prof[b].Identificador == Cars[a].Identificador)
                {
                    printf("%30s\t\n",prof[b].Nombres);
                }
            }
        }
    }



    printf("\nAutos estacionados\n\n");
    for(i=0; i<TAM; i++)
    {
        if(Playon[i].Espacio == 1)
        {
            for(j=0; j<TAM; j++)
            {
                if(Playon[i].Identificador == Cars[j].Identifica)
                {
                    printf("%s\n",Cars[j].Marca);
                }
            }
        }
    }

    printf("\nTotal de Fords estacionados\n\n");
    for(i=0; i<TAMPla; i++)
    {
        if(Playon[i].Espacio == 1)
        {
            for(j=0; j<TAM; j++)
            {
                if(Playon[i].Identificador == Cars[j].Identifica)
                {
                    if(strcmp(Cars[j].Marca,"Ford") == 0)
                    {
                        total++;
                    }
                }
            }
        }
    }
    printf("%i\n",total);

    printf("\nAutos no estacionados\n\n");
    for(i=0; i<TAM; i++)
    {
        if(Playon[i].Espacio == 0)
        {
            for(j=0; j<TAM; j++)
            {
                if(Playon[i].Identificador == Cars[j].Identifica)
                {
                    printf("%s\n",Cars[j].Marca);
                }
            }
        }
    }



}




