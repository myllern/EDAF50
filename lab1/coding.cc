#include "coding.h"

unsigned char encode(unsigned char c)
{
    (int)c++;
    return (char)c;
}
unsigned char decode(unsigned char c)
{
    (int)c--;
    return (char)c;
}
