#include <stdio.h>
#include <stdlib.h>

typedef struct Empresa
{
    int N_ticket;
    int N_remedio;
    int N_rubro;
    int Cantidad;
    float Valor_unitario;
    int N_Vendedor;
    struct Empresa *next;
} Empresa;

Empresa *AgregarFactura (Empresa *tail)
{
    Empresa *NuevoNodo = (Empresa*)malloc(sizeof(Empresa));

    printf("\n Ingrese :");
    printf("\n | Numero Ticket");
    scanf("%d", &NuevoNodo->N_ticket);
    printf("\n | Numero remedio [ 1 a 9 ]");
    scanf("%d", &NuevoNodo->N_remedio);
    while(NuevoNodo->N_remedio > 9 || NuevoNodo->N_remedio < 1)
    {
        printf("\n | Ingrese un numero del 1 al 9 para el Numero remedio");
        scanf("%d", &NuevoNodo->N_remedio);
    }
    printf("\n | Numero de Rubro");
    scanf("%d", &NuevoNodo->N_rubro);
    printf("\n | Cantidad");
    scanf("%d", &NuevoNodo->Cantidad);
    printf("\n | Valor unitario");
    scanf("%f", &NuevoNodo->Valor_unitario);
    printf("\n | Numero de Vendedor");
    scanf("%d", &NuevoNodo->N_Vendedor);
    while(NuevoNodo->N_Vendedor > 4 || NuevoNodo->N_Vendedor < 1 || NuevoNodo->N_Vendedor == 0)
    {
        printf("\n | Ingrese un numero del 1 al 4 para el Numero remedio");
        scanf("%d", &NuevoNodo->N_Vendedor);
    }

    NuevoNodo->next = NULL;

    if(tail != NULL)
    {
        tail->next = NuevoNodo;
    }
    return NuevoNodo;
}

void mayor_menor(int a, int b, int c, int d);

int main()
{
    Empresa *tail = NULL;
    Empresa *head = NULL;

    while(1)
    {
        tail = AgregarFactura(tail);

        if( head == NULL)
        {
            head = tail;
        }

        printf("\n Desea generar otra factura ? \n [0] Salir \n [1] Continuar");
        int opcion;
        scanf("%d",&opcion);

        if(opcion == 0)
        {
            break;
        }
    }

    int Facturacion_total_Empresa = 0;
    float Valor_Promedio_Tickets = 0, tickets = 0;
    int articulo_1 = 0, articulo_2 = 0, articulo_3 = 0, articulo_4 = 0;
    float total_uno = 0, su_Venta = 0;
    float total_dos = 0, su_Venta_2 = 0;
    float total_tres = 0, su_Venta_3 = 0;
    float total_cuatro = 0, su_Venta_4 = 0;


    Empresa *resultado = head;

    while (resultado != NULL)
    {
        Facturacion_total_Empresa += resultado->Valor_unitario * resultado->Cantidad;

        Valor_Promedio_Tickets = Facturacion_total_Empresa;
        tickets++;

        if(resultado->N_Vendedor == 1)
        {
            total_uno = (float)resultado->Cantidad * (float)resultado->Valor_unitario;
            su_Venta++;
        }

        if(resultado->N_Vendedor == 2)
        {
            total_dos = (float)resultado->Cantidad * (float)resultado->Valor_unitario;
            su_Venta_2++;
        }

        if(resultado->N_Vendedor == 3)
        {
            total_tres = (float)resultado->Cantidad * (float)resultado->Valor_unitario;
            su_Venta_3++;
        }

        if(resultado->N_Vendedor == 4)
        {
            total_cuatro = (float)resultado->Cantidad * (float)resultado->Valor_unitario;
            su_Venta_4++;
        }

        if(resultado->N_rubro == 1)
        {
            articulo_1 += resultado->Cantidad;
        }
        if(resultado->N_rubro == 2)
        {
            articulo_2 += resultado->Cantidad;
        }
        if(resultado->N_rubro == 3)
        {
            articulo_3+= resultado->Cantidad;
        }
        if(resultado->N_rubro == 4)
        {
            articulo_4+= resultado->Cantidad;
        }

        resultado = resultado->next;
    }

    Valor_Promedio_Tickets = Valor_Promedio_Tickets / tickets;
    total_uno = (total_uno * 3 ) / 100;
    total_dos = (total_dos * 2 ) / 100;
    total_tres = (total_tres * 2 ) / 100;
    total_cuatro = (total_cuatro * 2 ) / 100;


    printf("\n  1 -> Facturación total de la empresa = %d", Facturacion_total_Empresa);
    printf("\n  2 -> Valor promedio de los tickets = %f", Valor_Promedio_Tickets);
    printf("\n ---------------------------------------------\n ");
    printf("\n 3 -> Comisión a cobrar por cada empleado si es igual al 2 porciento del valor de su venta \n");
    printf("\n Farmaceutico 1 = %f ", total_uno);
    printf("\n Empleado 2 = %f ", total_dos);
    printf("\n Empleado 3 = %f ", total_tres);
    printf("\n Empleado 4 = %f ", total_cuatro);
    printf("\n ---------------------------------------------\n ");
    printf("\n 4 -> Si el farmaceutico cobra además un 3 porciento sobre la facturacion total, cuanto cobrara = %f", total_uno);
    mayor_menor(articulo_1,articulo_2,articulo_3,articulo_4);
    printf(" -> %d", articulo_1);
    printf(" -> %d", articulo_2);
    printf(" -> %d", articulo_3);
    printf(" -> %d", articulo_4);
    return 0;

}
void mayor_menor(int a, int b, int c, int d)
{
    if (a > b && a > c && a > d)
    {
       printf("\n 5 -> De que rubro se vendieron mas cantidad de articulos = Nro -> 1 \n");
    }
    if ( b > a && b > c && b > d)
    {
       printf("\n 5 -> De que rubro se vendieron mas cantidad de articulos = Nro -> 2 \n");
    }
    if ( c > b && c > a && c > d)
    {
       printf("\n 5 -> De que rubro se vendieron mas cantidad de articulos = Nro -> 3 \n");
    }
    if ( d > b && d > a && d > c)
    {
       printf("\n 5 -> De que rubro se vendieron mas cantidad de articulos = Nro -> 4 \n");
    }
}
