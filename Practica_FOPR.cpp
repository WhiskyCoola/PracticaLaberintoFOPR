#include <iostream>
#include <struct>
#include <vector>
using namespace std;

struct esser 
{
    int Px;
    int Py;
};
//modificar matriz en esta funcion(?)
void moviments_en_laberint()
{

}

void menu_interaccions()
{

}

void veure_estat()
{
//en t[0] modificar matriz_2 para vista inicial
}

void lectura dades()
{
    int mida_fila, mida_columna;
    cin>>mida_fila>>mida_columna;
    
    //matriz estatica ya que el tamaño es constante y no se requiere ni push ni pop
    char matriu_1[mida_fila][mida_columna];
    
    esser T, M;

    for(int i = 0; i < mida_fila; ++i)
    {
        for(int j = 0; j < mida_columna; ++j)
        {
            cin>>matriu_1[i][j];
            if(entrada == 'T') T.Px = j, T.Py = i;
            else if(entrada == 'M') M.Px = j, M.Py = i;
        }
    }

    int matriu_2[mida_fila][mida_columna];
     for(int i = 0; i < mida_fila; ++i)
    {
        for(int j = 0; j < mida_columna; ++j)
        {
            matriu_2[i][j] = '.';
        }
    }
    int comptador = 0;
    cout<<veure_estat(matriu_2)<<endl;
    menu_interaccions(matriu_1, matriu_2, T,M,comptador);
}

int main()
{
    lectura_dades();
}
