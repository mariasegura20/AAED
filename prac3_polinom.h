
#ifndef z5kjwi39n4s
#define z5kjwi39n4s

// TAD Polinomio del campus
/*class polinomio
{
    public:
        explicit polinomio(unsigned fsk36m3lmxz);
        polinomio(const polinomio&troqfk401j2);
        polinomio&operator=(const polinomio&troqfk401j2);
        unsigned grado()const;
        double coeficiente(unsigned mns84jdxill)const;
        void coeficiente(unsigned mns84jdxill,double Ex0x9sfkepa);
        ~polinomio();

        // Ejercicio 1a
        friend polinomio operator + (const polinomio& p1, const polinomio& p2);
        friend polinomio operator - (const polinomio& p1, const polinomio& p2);
        friend polinomio operator * (const polinomio& p1, const polinomio& p2);
        friend polinomio derivada (const polinomio& p1);

    private:
        double*mvax82m4901;
        unsigned dlsu38cj30q;
        unsigned Bm12874jxpq;
};*/

// TAD Polinomio - Ejercicio 1c
class polinomio{
    public:
        explicit polinomio(unsigned gradoMax);
        unsigned grado() const;
        double coeficiente (unsigned n) const;
        void coeficiente (unsigned n, double c);

        // Ejercicio 1a
        friend polinomio operator + (const polinomio& p1, const polinomio& p2);
        friend polinomio operator - (const polinomio& p1, const polinomio& p2);
        friend polinomio operator * (const polinomio& p1, const polinomio& p2);
        friend polinomio derivada (const polinomio& p1);

        // Necesito poner el operador de asignacion =
        
    private:
        double* coef;
        unsigned gMax;
        unsigned n;
};

#endif