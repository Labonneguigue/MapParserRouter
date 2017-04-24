#ifdef __APPLE__
   #include <Python/Python.h>
#else
    #include <Python.h>
#endif


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stdlib.h>

#include "router.hpp"

using namespace std;

void Router::getpath(char pointA[] ,char pointB[], std::vector<char*>& path)
{
    PyObject *pName, *pModule, *pDict, *pFunc,  *pPath, *pListItem;
    PyObject *arglist;
    char *pycpp_path_result;
    //std::vector<char*> path;
    std::vector<char*>::iterator itpath;

    int element_num,k;
    printf("%s...getpath..%s\n",pointA,pointB);
    arglist = Py_BuildValue("ss",pointA,pointB);

    //system("echo -------------lajsldklajsdjlsajdlkjsaljlkdlksaljdlkjsa");
    //system("echo export PYTHONPATH=$PWD");
    Py_Initialize();
    if(!Py_IsInitialized())
    {
        printf("init error\n");
    }
    PyRun_SimpleString("import re,string,sys");
    PyRun_SimpleString("import xml.sax as sax ");
    PyRun_SimpleString("from math import radians,cos,sin,asin,sqrt");

    // Build the name object
    pName = PyString_FromString(PY_router);

    // Load the module object
    pModule = PyImport_Import(pName);
    if(!pModule)
    {
        PyErr_Print();
        std::cout << "can't find : " << PY_router << ".py\n";
        //return path;
    }

    // pDict is a borrowed reference
    pDict = PyModule_GetDict(pModule);
    if(!pDict)
    {
        printf("Pymodule_getDict() fail\n");
        //return path;
    }

    // Build the name of a callable class
    pFunc = PyDict_GetItemString(pDict, "cpp_call");
    pPath = PyObject_CallFunctionObjArgs(pFunc,arglist,NULL);

    element_num = PyObject_Length(pPath);
    k = PyObject_Size(pPath);
    printf("ROUTER_CPP: pPath size or length -:%d, %d\n",element_num,k);
    itpath = path.begin();
    for (int i = 0; i < element_num; i++)
    {
        pListItem = PyList_GetItem(pPath, i);
        pycpp_path_result = PyString_AsString(pListItem);
        itpath = path.insert(itpath,pycpp_path_result);
        printf("ROUTER_CPP : path via - %s\n",pycpp_path_result);
    }
    for(itpath=path.begin();itpath<path.end();itpath++)
        std::cout<<' '<<*itpath;
    std::cout<<'\n';
    Py_Finalize();
    for (int i = 0 ; i < path.size() ; i++){
        cout << path[i];
    }
    cout << "\n" << path.size() << "\n";
    //return path;
}
