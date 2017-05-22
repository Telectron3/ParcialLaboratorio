#include "Funciones.h"


int main()
{
    int opcion = 0;
    char seguir = 's';
    eProfesores Profesores[TAM];
    eCoches Coches[TAM];
    ePlayon Playon[TAM];

    cargarPlayon(Playon);
    cargaProf(Profesores);
    cargaCoche(Coches);

while(seguir == 's')
{
    system("cls");
    printf("\nOpcion: ");
    printf("\n1_Alta de Coche");
    printf("\n2_Baja de Coche");
    printf("\n3_Ingreso en playon");
    printf("\n4_Egreso del playon");
    printf("\n5_Mostrar informacion");
    printf("\n6_Salir\n");
    printf("\nElija una opcion: ");



scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
        altaCoche(Coches,Profesores);
        break;
    case 2:
        bajaCoche(Coches,Profesores);
        system("pause");
        break;
    case 3:
        altaPlayon(Coches,Playon,Profesores);
        break;
    case 4:
        egresoPlayon(Coches,Playon,Profesores);
        system("pause");
        break;
    case 5:
            mostrar(Profesores,Coches,Playon);
            system("pause");
        break;
    case 6:
            seguir = 'n';
        break;

    }

}

    return 0;
}
