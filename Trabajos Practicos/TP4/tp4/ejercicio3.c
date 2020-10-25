#include <stdio.h>

#define PI 3.1415
#define VOLUMEN(r)  (4.0/3.0) * PI * (r) * (r) * (r)

int
main()
{
    int radio; //radio en cm.
    float volumen; //volumen en cm³
    
    for(radio = 1; radio <= 10; radio++)
    {
        volumen = VOLUMEN(radio);
        printf("Radio: %dcm\t Volumen: %.2fcm³\n", radio, volumen);
    }
}