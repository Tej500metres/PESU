#include "headers.h"

int main()
{
    player p=displayStartScreen1();
    p=displayStartScreen2(p);
    p=decideRocket(p);
    countdown(p);
    phase1(p);
    phase2(p);
    phase3(p);
    payloadDeployed(p);
}