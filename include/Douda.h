#ifndef _DOUDA_H_
#define _DOUDA_H_

#include <iostream>
#include <vector>
//#include "Piassa.h"


class Douda{

    public :
    Douda(float x, float y , float s);
    ~Douda();
    float getSize();

    private:

   // Piassa *head;
   // std::vector<Piassa> douda;
    float size;
    



};


#endif