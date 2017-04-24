//
//  caller.cpp
//  OpenCVParser
//
//  Created by Guillaume GRANIE on 06/12/2016.
//

#include <stdio.h>
#include <iostream>
#include <tuple>
#include <time.h>
#include "parserV1.hpp"
//#include "router.hpp"




int main(){


    clock_t tStart = clock();
    Map * MyMap = new Map("heavy.osm");
    std::vector<tuple<string, double>> MyVectorOfUserDestination = MyMap->GetTupleOfDestinations();
    double ExamplePointLat = 43.569571;
    double ExamplePointLon = 1.467061;
    MyMap->SetPosition(ExamplePointLon,ExamplePointLat);
    printf("Time taken to parse: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    MyMap->Display(0);
    printf("Time taken to parse and render: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    MyMap->Display(1);
    MyMap->SetDestination(-8);
    MyMap->Display(0);

    delete MyMap;

    tStart = clock();
    Map MySecondMap("capitole.osm");
    printf("Time taken to parse: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    double ExamplePoint2Lat = 43.604409;
    double ExamplePoint2Lon =  1.446727;
    MySecondMap.SetPosition(ExamplePoint2Lon,ExamplePoint2Lat);
    MySecondMap.Display(0);

    return 1;
}
