#!/bin/sh
echo "Executing programs"
LD_LIBRARY_PATH = "$LD_LIBRARY_PATH;./../lib-arm" ../bin-arm/AbstractFactory
LD_LIBRARY_PATH = "$LD_LIBRARY_PATH;./../lib-arm" ../bin-arm/AbstractFactorySerializer
LD_LIBRARY_PATH = "$LD_LIBRARY_PATH;./../lib-arm" ../bin-arm/Bridge
LD_LIBRARY_PATH = "$LD_LIBRARY_PATH;./../lib-arm" ../bin-arm/Builder
LD_LIBRARY_PATH = "$LD_LIBRARY_PATH;./../lib-arm" ../bin-arm/Facade
LD_LIBRARY_PATH = "$LD_LIBRARY_PATH;./../lib-arm" ../bin-arm/Prototype

