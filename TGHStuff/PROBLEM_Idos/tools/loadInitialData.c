#include <stdio.h>
#include <unistd.h>
#include "../data/IdosData.h"

IdosData* loadInitialData()
{
    char buffer[256];
    IdosData* initialData = sbrk(sizeof(IdosData));
    initialData->connectCount = sbrk(sizeof(unsigned long));
    initialData->stationCount = sbrk(sizeof(unsigned long));

    // load 1st line of input
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%lu %lu", initialData->connectCount, initialData->stationCount); // NOLINT(cert-err34-c)

    // caller takes the ownership of the memory
    return initialData;
}