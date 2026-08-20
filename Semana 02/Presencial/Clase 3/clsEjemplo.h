#ifndef CLSEJEMPLO_H_INCLUDED
#define CLSEJEMPLO_H_INCLUDED

class Ejemplo{
    private:
        char codigo[5];
        int cantidad;
    public:
        void setCodigo(const char *);
        const char *getCodigo();
};

#endif // CLSEJEMPLO_H_INCLUDED
