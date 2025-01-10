#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_FACTURAS 100
#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50
#define MAX_CEDULA 15

typedef struct {
    char nombre[MAX_NOMBRE];
    float precio;
} Producto;

typedef struct {
    int numeroFactura;
    char nombreCliente[MAX_NOMBRE];
    char cedula[MAX_CEDULA];
    Producto productos[MAX_PRODUCTOS];
    int cantidadProductos;
    float total;
} Factura;

void inicializar();
void ingresarFactura();
void mostrarFacturas();
void buscarFactura();
void editarFactura();
void eliminarFactura();

#endif
