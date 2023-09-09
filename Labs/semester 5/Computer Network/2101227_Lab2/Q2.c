#include <stdio.h>
#include <string.h>
#define HEADER_SIZE 64
void application_Layer(char *msg, int size);
void presentation_Layer(char *msg, int size);
void session_Layer(char *msg, int size);
void transport_Layer(char *msg, int size);
void network_Layer(char *msg, int size);
void dataLink_Layer(char *msg, int size);
void physical_Layer(char *msg, int size);

int main()
{
    char msg[] = "OSI-Model";
    int size = strlen(msg);
    application_Layer(msg, size);
    return 0;
}

void application_Layer(char *msg, int size)
{
    printf("\nApplication Layer: %s\n", msg);
    presentation_Layer(msg, size);
}

void presentation_Layer(char *msg, int size)
{
    char header[HEADER_SIZE];
    snprintf(header, HEADER_SIZE, "PresentationHeader %s", msg);
    printf("\nPresentation Layer: %s\n", header);
    session_Layer(header, size + strlen("PresentationHeader "));
}

void session_Layer(char *msg, int size)
{
    char header[HEADER_SIZE];
    snprintf(header, HEADER_SIZE, "SessionHeader %s", msg);
    printf("\nSession Layer: %s\n", header);
    transport_Layer(header, size + strlen("SessionHeader "));
}

void transport_Layer(char *msg, int size)
{
    char header[HEADER_SIZE];
    snprintf(header, HEADER_SIZE, "TransportHeader %s", msg);
    printf("\nTransport Layer: %s\n", header);
    network_Layer(header, size + strlen("TransportHeader "));
}

void network_Layer(char *msg, int size)
{
    char header[HEADER_SIZE];
    snprintf(header, HEADER_SIZE, "NetworkHeader %s", msg);
    printf("\nNetwork Layer: %s\n", header);
    dataLink_Layer(header, size + strlen("NetworkHeader "));
}

void dataLink_Layer(char *msg, int size)
{
    char header[HEADER_SIZE];
    snprintf(header, HEADER_SIZE, "DataLinkHeader %s", msg);
    printf("\nData Link Layer: %s\n", header);
    physical_Layer(header, size + strlen("DataLinkHeader "));
}

void physical_Layer(char *msg, int size)
{
    char header[HEADER_SIZE];
    snprintf(header, HEADER_SIZE, "PhysicalHeader %s", msg);
    printf("\nPhysical Layer: %s\n\n", header);
}
