#include "Douda.h"


Douda::Douda(float x, float y, float s)
{
    /*
    head =  nullptr;
    head = new Piassa(x, y , s);
    douda.push_back(*head);*/
    size = s;
}

Douda::~Douda()
{
  //  delete head;
}

float Douda::getSize()
{
    return this->size;
}
