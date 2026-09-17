//#include <iostream>
//#include <cstring>
//#include "clsArchivoMaterias.h"
//
//using namespace std;
//
//ArchivoMaterias::ArchivoMaterias(const char *n){
//    strcpy(nombre, n);
//}
//
//Materia ArchivoMaterias::leerRegistro(int pos){
//    FILE *p=fopen(nombre ,"rb");
//    Materia obj;
//    if(p == nullptr){
//        obj.setNumero(-1);
//        return obj;
//    }
//    fseek(p, pos * sizeof obj, 0);
//    fread(&obj, sizeof obj, 1, p);
//    fclose(p);
//    return obj;
//}
//
//int ArchivoMaterias::contarRegistros(){
//    FILE *p = fopen(nombre, "rb");
//    if(p == nullptr){
//        return -1;
//    }
//    fseek(p, 0, 2);
//    int bytes = ftell(p);
//    fclose(p);
//    return bytes/sizeof(Materia);
//}
//
//bool ArchivoMaterias::grabarRegistro(Materia obj){
//    FILE *p = fopen(nombre, "ab");
//    if(p == nullptr){
//        return false;
//    }
//    bool escribio = fwrite(&obj, sizeof obj, 1, p);
//    fclose(p);
//    return escribio;
//}
//
//int ArchivoMaterias::buscarRegistro(int leg){
//    int cantReg = contarRegistros();
//    for(int i=0; i<cantReg; i++){
//        Materia obj = leerRegistro(i);
//        if(obj.getLegajo() == leg) return i;
//    }
//    return -1;
//}
//
//void ArchivoMaterias::listarRegistros(){
//    int cantReg = contarRegistros();
//    for(int i=0; i<cantReg; i++){
//        Materia obj = leerRegistro(i);
//        obj.Mostrar();
//        cout<<"======================="<<endl;
//    }
//}
