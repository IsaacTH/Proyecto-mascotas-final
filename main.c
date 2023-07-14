#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    char Mascota[5][10];
    int Servicio[3][20] = {0};
    int opcion1, opcion2, opc;

    do {
        printf("1. Ingresar datos de mascota\n");
        printf("2. Servicios\n");
        printf("3. Facturar servicio\n");
        printf("4. Modificar datos\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion1);

        switch (opcion1) {
            case 1:
                datosMascota(Mascota);
                break;

            case 2:
                servicios(Servicio);
                break;

            case 3:
                printf("Escriba 1 para facturar con el ID de su mascota\n");
                printf("Escriba 2 para facturar con el ID del servicio\n");
                scanf("%d", &opcion2);

                switch (opcion2) {
                    case 1:
                        mascotaFactura(Servicio, Mascota);
                        break;

                    case 2:
                        servicioFactura(Servicio, Mascota);
                        break;

                    default:
                        printf("Error. Fuera de rango\n");
                        break;
                }
                break;

            case 4:
                printf("Ingrese el numero de lo que desea modificar\n");
                printf("1. ID de su mascota\n");
                printf("2. Nombre de su mascota\n");
                printf("3. Tipo de su mascota\n");
                printf("4. Edad de su mascota\n");
                printf("5. Su nombre\n");
                printf("Seleccione una opcion: ");
                scanf("%d", &opc);
                switch (opc)
                {
                case 1:
                    printf("Ingrese el ID correcto de su mascota: ");
                    scanf("%s", *(Mascota + 0));
                    break;

                case 2:
                    printf("Ingrese el nombre correcto de su mascota: ");
                    scanf("%s", *(Mascota + 1));
                    break;

                case 3:
                    printf("Ingrese el tipo correcto de su mascota: ");
                    scanf("%s", *(Mascota + 2));
                    break;

                case 4:
                    printf("Ingrese la edad correcta de su mascota: ");
                    scanf("%s", *(Mascota + 3));
                    break;

                case 5:
                    printf("Ingrese su nombre correctamente: ");
                    scanf("%s", *(Mascota + 4));
                    break;
                
                default:
                    printf("Error. Fuera de rango\n");
                    break;
                }
                break;

            case 5:
                printf("Gracias por preferirnos!\n");
                return 0;
                break;

            default:
                printf("Error. Fuera de rango\n");
                break;
        }
    } while (opcion1 != 5);
}