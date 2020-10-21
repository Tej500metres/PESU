#include "headers.h"

int main()
{
    player p=displayStartScreen1();
    p=displayStartScreen2(p);
    p=decideRocket(p);
    short c=countdown(p);
    short p1=phase1(p);
    short p2=phase2(p);
    short p3=phase3(p);
    short s=payloadDeployed(p);
}