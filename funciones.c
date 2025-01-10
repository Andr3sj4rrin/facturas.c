#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Array to store invoices
Factura facturas[MAX_FACTURAS];
int numFacturas = 0; // Current number of invoices

// Helper function to read a positive float
float leerPositivo(const char *mensaje) {
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor);
        if (valor < 0) {
            printf("Error: El valor no puede ser negativo. Por favor, inténtelo de nuevo.\n");
        }
    } while (valor < 0);
    return valor;
}

// Helper function to read a string (removes trailing newline)
void leerCadena(const char *mensaje, char *cadena, int longitud) {
    printf("%s", mensaje);
    getchar(); // Clear the newline left by previous input
    fgets(cadena, longitud, stdin);
    cadena[strcspn(cadena, "\n")] = 0; // Remove trailing newline
}

// Initializes the system by clearing invoice data
void inicializar() {
    numFacturas = 0;
    printf("Sistema inicializado correctamente.\n");
}

// Adds a new invoice
void ingresarFactura() {
    if (numFacturas >= MAX_FACTURAS) {
        printf("Error: No se pueden agregar más facturas.\n");
        return;
    }

    Factura nuevaFactura;

    printf("\nIngrese los datos de la nueva factura:\n");
    nuevaFactura.numeroFactura = numFacturas + 1;

    leerCadena("Nombre del cliente: ", nuevaFactura.nombreCliente, MAX_NOMBRE);
    leerCadena("Cédula del cliente: ", nuevaFactura.cedula, MAX_CEDULA);

    do {
        printf("Cantidad de productos (1-%d): ", MAX_PRODUCTOS);
        scanf("%d", &nuevaFactura.cantidadProductos);
        if (nuevaFactura.cantidadProductos <= 0 || nuevaFactura.cantidadProductos > MAX_PRODUCTOS) {
            printf("Error: Ingrese una cantidad válida de productos.\n");
        }
    } while (nuevaFactura.cantidadProductos <= 0 || nuevaFactura.cantidadProductos > MAX_PRODUCTOS);

    nuevaFactura.total = 0;

    for (int i = 0; i < nuevaFactura.cantidadProductos; i++) {
        printf("\nProducto %d:\n", i + 1);
        leerCadena("Nombre del producto: ", nuevaFactura.productos[i].nombre, MAX_NOMBRE);
        nuevaFactura.productos[i].precio = leerPositivo("Precio del producto: ");
        nuevaFactura.total += nuevaFactura.productos[i].precio;
    }

    facturas[numFacturas++] = nuevaFactura;
    printf("Factura ingresada correctamente.\n");
}

// Displays all invoices
void mostrarFacturas() {
    if (numFacturas == 0) {
        printf("No hay facturas registradas.\n");
        return;
    }

    printf("\nFacturas registradas:\n");
    for (int i = 0; i < numFacturas; i++) {
        printf("\nFactura #%d\n", facturas[i].numeroFactura);
        printf("Cliente: %s\n", facturas[i].nombreCliente);
        printf("Cédula: %s\n", facturas[i].cedula);
        printf("Productos:\n");
        for (int j = 0; j < facturas[i].cantidadProductos; j++) {
            printf("  - %s: %.2f\n", facturas[i].productos[j].nombre, facturas[i].productos[j].precio);
        }
        printf("Total: %.2f\n", facturas[i].total);
    }
}

// Searches for an invoice
void buscarFactura() {
    char criterio[MAX_NOMBRE];
    printf("\nIngrese el nombre del cliente, cédula o número de factura: ");
    leerCadena("", criterio, MAX_NOMBRE);

    for (int i = 0; i < numFacturas; i++) {
        if (strcmp(facturas[i].nombreCliente, criterio) == 0 ||
            strcmp(facturas[i].cedula, criterio) == 0 ||
            atoi(criterio) == facturas[i].numeroFactura) {
            printf("\nFactura encontrada:\n");
            printf("Factura #%d\n", facturas[i].numeroFactura);
            printf("Cliente: %s\n", facturas[i].nombreCliente);
            printf("Cédula: %s\n", facturas[i].cedula);
            printf("Productos:\n");
            for (int j = 0; j < facturas[i].cantidadProductos; j++) {
                printf("  - %s: %.2f\n", facturas[i].productos[j].nombre, facturas[i].productos[j].precio);
            }
            printf("Total: %.2f\n", facturas[i].total);
            return;
        }
    }
    printf("Factura no encontrada.\n");
}

// Edits an existing invoice
void editarFactura() {
    int numero;
    printf("\nIngrese el número de la factura a editar: ");
    scanf("%d", &numero);

    for (int i = 0; i < numFacturas; i++) {
        if (facturas[i].numeroFactura == numero) {
            printf("\nEditando factura #%d\n", numero);
            leerCadena("Nuevo nombre del cliente: ", facturas[i].nombreCliente, MAX_NOMBRE);
            leerCadena("Nueva cédula del cliente: ", facturas[i].cedula, MAX_CEDULA);

            do {
                printf("Nueva cantidad de productos (1-%d): ", MAX_PRODUCTOS);
                scanf("%d", &facturas[i].cantidadProductos);
                if (facturas[i].cantidadProductos <= 0 || facturas[i].cantidadProductos > MAX_PRODUCTOS) {
                    printf("Error: Ingrese una cantidad válida de productos.\n");
                }
            } while (facturas[i].cantidadProductos <= 0 || facturas[i].cantidadProductos > MAX_PRODUCTOS);

            facturas[i].total = 0;

            for (int j = 0; j < facturas[i].cantidadProductos; j++) {
                printf("\nProducto %d:\n", j + 1);
                leerCadena("Nombre del producto: ", facturas[i].productos[j].nombre, MAX_NOMBRE);
                facturas[i].productos[j].precio = leerPositivo("Precio del producto: ");
                facturas[i].total += facturas[i].productos[j].precio;
            }

            printf("Factura actualizada correctamente.\n");
            return;
        }
    }

    printf("Factura no encontrada.\n");
}

// Deletes an invoice
void eliminarFactura() {
    int numero;
    printf("\nIngrese el número de la factura a eliminar: ");
    scanf("%d", &numero);

    for (int i = 0; i < numFacturas; i++) {
        if (facturas[i].numeroFactura == numero) {
            for (int j = i; j < numFacturas - 1; j++) {
                facturas[j] = facturas[j + 1];
            }
            numFacturas--;
            printf("Factura eliminada correctamente.\n");
            return;
        }
    }

    printf("Factura no encontrada.\n");
}