#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion; // Variable to store the user's menu selection

    // Initialize the invoice system
    inicializar();

    // Main loop to display the menu until the user decides to exit
    do {
        printf("\n--- Sistema de Facturacion ---\n");
        printf("1. Ingresar Factura\n"); // Option to add a new invoice
        printf("2. Mostrar Facturas\n"); // Option to display all invoices
        printf("3. Buscar Factura\n");  // Option to search for a specific invoice
        printf("4. Editar Factura\n");  // Option to edit an existing invoice
        printf("5. Eliminar Factura\n"); // Option to delete an invoice or products
        printf("6. Salir\n");            // Option to exit the program
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion); // Read the user's input
        getchar(); // Clear the input buffer

        // Perform actions based on the selected menu option
        switch(opcion) {
            case 1:
                ingresarFactura(); // Call function to add a new invoice
                break;
            case 2:
                mostrarFacturas(); // Call function to display all invoices
                break;
            case 3:
                buscarFactura(); // Call function to search for an invoice
                break;
            case 4:
                editarFactura(); // Call function to edit an existing invoice
                break;
            case 5:
                eliminarFactura(); // Call function to delete an invoice or its products
                break;
            case 6:
                printf("Saliendo del sistema...\n"); // Exit message
                break;
            default:
                // Handle invalid menu options
                printf("Opcion invalida, intente de nuevo.\n");
        }
    } while(opcion != 6); // Continue looping until the user selects the exit option

    return 0; // End of program
}