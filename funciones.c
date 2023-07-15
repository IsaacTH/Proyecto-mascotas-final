#include <stdio.h>
#include <string.h>

void datosMascota(char (*Mascota)[10]) {
    printf("Ingrese el ID de su mascota: ");
    scanf("%s", *(Mascota + 0));

    printf("Ingrese el nombre de su mascota: ");
    scanf("%s", *(Mascota + 1));

    printf("Ingrese el tipo de su mascota: ");
    scanf("%s", *(Mascota + 2));

    printf("Ingrese la edad de su mascota: ");
    scanf("%s", *(Mascota + 3));

    printf("Ingrese su nombre: ");
    scanf("%s", *(Mascota + 4));
}

void servicios(int (*Servicio)[20]) {
    int opcion3, contador = 0;

    printf("Elija el ID de los servicios que desea para su mascota:\n");
    printf("ID: 1111 Peluqueada $10 (servicio de corte de pelo con limpieza)\n");
    printf("ID: 2222 Desparasitacion $40 (servicio que garantiza la salud gastrointestinal)\n");
    printf("ID: 3333 Adiestramiento $90 (servicio que incluye 4 semanas de entrenamiento)\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion3);

    int *pServicio = Servicio[0];
    int *pPrecio = Servicio[1];

    switch (opcion3) {
        case 1111:
            *pPrecio = 10;
            contador += *pPrecio;
            break;

        case 2222:
            *pPrecio = 40;
            contador += *pPrecio;
            break;

        case 3333:
            *pPrecio = 90;
            contador += *pPrecio;
            break;

        default:
            printf("Error. Fuera de rango\n");
            return;
    }

    for (int i = 0; i < 20; i++) {
        if (*pServicio == 0) {
            *pServicio = opcion3;
            pPrecio++;
            pServicio++;
            *pPrecio = contador;
            break;
        }
        pServicio++;
        pPrecio++;
    }
}

void mascotaFactura(int Servicio[3][20], char Mascota[5][10]) {
    char idMascota[10];
    int i, j;
    int encontrado = 0;
    int totalPrecios = 0;

    printf("Ingrese el ID de la mascota para generar la factura: ");
    scanf("%s", idMascota);

    for (i = 0; i < 5; i++) {
        if (strcmp(Mascota[i], idMascota) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {

        FILE *f;
        f = fopen("mascotaFactura.txt", "a");

        printf("\n***** FACTURA *****\n");
        printf("ID de la mascota: %s\n", *(Mascota + i));
        printf("Nombre de la mascota: %s\n", *(Mascota + i + 1));
        printf("Tipo de mascota: %s\n", *(Mascota + i + 2));
        printf("Edad de la mascota: %s\n", *(Mascota + i + 3));
        printf("Nombre del propietario: %s\n", *(Mascota + i + 4));

        fprintf(f, "\n***** FACTURA *****\n");
        fprintf(f, "ID de la mascota: %s\n", *(Mascota + i));
        fprintf(f, "Nombre de la mascota: %s\n", *(Mascota + i + 1));
        fprintf(f, "Tipo de mascota: %s\n", *(Mascota + i + 2));
        fprintf(f, "Edad de la mascota: %s\n", *(Mascota + i + 3));
        fprintf(f, "Nombre del propietario: %s\n", *(Mascota + i + 4));

        int *pServicio = Servicio[0];
        int *pPrecio = Servicio[1];

        for (j = 0; j < 20; j++) {
            if (*pServicio != 0) {
                int servicioID = *pServicio;
                int servicioPrecio = *pPrecio;

                printf("Numero de servicio: %d\n", servicioID);
                fprintf(f, "Numero de servicio: %d\n", servicioID);
                if (servicioID == 1111) {
                    printf("Peluqueada: $%d\n", servicioPrecio);
                    fprintf(f, "Peluqueada: $%d\n", servicioPrecio);
                } else if (servicioID == 2222) {
                    printf("Desparasitacion: $%d\n", servicioPrecio);
                    fprintf(f, "Desparasitacion: $%d\n", servicioPrecio);
                } else if (servicioID == 3333) {
                    printf("Adiestramiento: $%d\n", servicioPrecio);
                    fprintf(f, "Adiestramiento: $%d\n", servicioPrecio);
                }
                totalPrecios += servicioPrecio;
            }
            pServicio++;
            pPrecio++;
        }
        printf("Total: $%d\n\n", totalPrecios);
        fprintf(f, "Total: $%d\n\n", totalPrecios);
        fclose(f);
    }
}

void servicioFactura(int Servicio[3][20], char Mascota[5][10]) {
    int idServicio;
    int i, j;
    int encontrado = 0;
    int totalPrecios = 0;

    printf("Ingrese el ID del servicio para generar la factura: ");
    scanf("%d", &idServicio);

    FILE *f;
    f = fopen("mascotaFactura.txt", "a");

    fprintf(f, "\n***** FACTURA *****\n");
    printf("\n***** FACTURA *****\n");
    fprintf(f, "ID del servicio: %d\n", idServicio);
    printf("ID del servicio: %d\n", idServicio);

    int *pServicio = Servicio[0];
    int *pPrecio = Servicio[1];

    for (i = 0; i < 20; i++) {
        if (*pServicio == idServicio) {
            encontrado = 1;
            break;
        }
        pServicio++;
        pPrecio++;
    }

    if (encontrado) {
        char idMascota[10];

        for (j = 0; j < 5; j++) {
            if (strcmp(Mascota[j], idMascota) == 0) {
                break;
            }
        }

        fprintf(f, "ID de la mascota: %s\n", *(Mascota + i));
        printf("ID de la mascota: %s\n", *(Mascota + i));
        fprintf(f, "Nombre de la mascota: %s\n", *(Mascota + i + 1));
        printf("Nombre de la mascota: %s\n", *(Mascota + i + 1));
        fprintf(f, "Tipo de mascota: %s\n", *(Mascota + i + 2));
        printf("Tipo de mascota: %s\n", *(Mascota + i + 2));
        fprintf(f, "Edad de la mascota: %s\n", *(Mascota + i + 3));
        printf("Edad de la mascota: %s\n", *(Mascota + i + 3));
        fprintf(f, "Nombre del propietario: %s\n", *(Mascota + i + 4));
        printf("Nombre del propietario: %s\n", *(Mascota + i + 4));

        int *pServicio = Servicio[0];
        int *pPrecio = Servicio[1];

        for (i = 0; i < 20; i++) {
            if (*pServicio != 0) {
                int servicioID = *pServicio;
                int servicioPrecio = *pPrecio;

                fprintf(f, "Numero de servicio: %d\n", servicioID);
                printf("Numero de servicio: %d\n", servicioID);
                if (servicioID == 1111) {
                    fprintf(f, "Peluqueada: $%d\n", servicioPrecio);
                    printf("Peluqueada: $%d\n", servicioPrecio);
                } else if (servicioID == 2222) {
                    fprintf(f, "Desparasitacion: $%d\n", servicioPrecio);
                    printf("Desparasitacion: $%d\n", servicioPrecio);
                } else if (servicioID == 3333) {
                    fprintf(f, "Adiestramiento: $%d\n", servicioPrecio);
                    printf("Adiestramiento: $%d\n", servicioPrecio);
                }
                totalPrecios += servicioPrecio;
            }
            pServicio++;
            pPrecio++;
        }
        fprintf(f, "Total: $%d\n\n", totalPrecios);
        printf("Total: $%d\n\n", totalPrecios);
        fclose(f);
    } 
}