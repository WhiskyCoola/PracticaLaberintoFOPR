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
// Matriu 1 y 2 comprobar si estan bien declarados.
void moviments_en_laberint(char&matriu_1, char&matriu_2, esser&T, esser&M, int&comptador, char moviment, char condicion_joc)
{
//Recordatorio: Mirar caso extremo 2 o mas salidas, acceder fuera de la matriz(segmentation fault)
    
    if(moviment == 'D')
    {
        if(matriu_1[T.Px][T.Py+1] == ' ') matriu_1[T.Px][T.Py] = ' ', ++T.Py, matriu_1[T.Px][T.Py] = 'T';
    }
    if(moviment == 'U')
    {
        if(matriu_1[T.Px][T.Py-1] == ' ') matriu_1[T.Px][T.Py] = ' ', --T.Py, matriu_1[T.Px][T.Py] = 'T';
    }
    if(moviment == 'L')
    {
        if(matriu_1[T.Px-1][T.Py] == ' ') matriu_1[T.Px][T.Py] = ' ', --T.Px, matriu_1[T.Px][T.Py] = 'T';
    }
    if(moviment == 'R')
    {
        if(matriu_1[T.Px+1][T.Py] == ' ') matriu_1[T.Px][T.Py] = ' ', ++T.Px, matriu_1[T.Px][T.Py] = 'T';
    }
        matriu_2[T.Px][T.Py] = 'T';
        
        matriu_2[T.Px-1][T.Py] = matriu_1[T.Px-1][T.Py];
        
        matriu_2[T.Px+1][T.Py] = matriu_1[T.Px+1][T.Py];
        
        matriu_2[T.Px][T.Py-1] = matriu_1[T.Px][T.Py-1];
        
        matriu_2[T.Px][T.Py+1] = matriu_1[T.Px][T.Py+1];
        
        matriu_2[T.Px-1][T.Py-1] = matriu_1[T.Px-1][T.Py-1];
        
        matriu_2[T.Px-1][T.Py+1] = matriu_1[T.Px-1][T.Py+1];
        
        matriu_2[T.Px+1][T.Py-1] = matriu_1[T.Px+1][T.Py-1];
        
        matriu_2[T.Px+1][T.Py+1] = matriu_1[T.Px+1][T.Py+1];
}

void menu_interaccions(char&matriu_1, char&matriu_2, esser&T, esser&M, int&comptador)
{
    int entrada;
    char estat = 'n'; // a = atrapat, p = perdut, g = guanyat;
    while(cin>>entrada and estat == 'n')
    {
        if(entrada == 'D')
        {
            moviments_en_laberint(matriu_1, matriu_2, T, M, comptador, entrada, estat);
        }
        if(entrada == 'L')
        {
            moviments_en_laberint(matriu_1, matriu_2, T, M, comptador, entrada, estat);
        }
        if(entrada == 'R')
        {
            moviments_en_laberint(matriu_1, matriu_2, T, M, comptador, entrada, estat);
        }
        if(entrada == 'S')
        {
            veure_estat(matriu_2);
        }
        if(entrada == 'U')
        {
            moviments_en_laberint(matriu_1, matriu_2, T, M, comptador, entrada, estat);
        }
        if(entrada == 'Z')
        {
            estat = 'p';
            veure_estat(matriu_2);
            cout<<"A reveure!"<<endl;
            cout<<"Has fet"<<" "<<comptador<<" "<<moviments"<<endl;
        }
        ++comptador;
    }
    if(estat == 'a') cout<<"Has perdut! El Minotaure t'ha atrapat!"<<endl;
    if(estat == 'g') cout<<"Felicitats has arribat a la sortida!!"<<endl;
    cout<<"Has fet"<<" "<<comptador<<" "<<moviments"<<endl;
}

void veure_estat(char&matriu_2)
{
    for(unsigned int i = 0; i < matriu_2.size(), ++i)
        {
        for(unsigned int j = 0; j < matriu_2[0].size(), ++j)
            {
                cout<<matriu_2[i][j];
            }
        }
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
    moviments_en_laberint(matriu_1, matriu_2, T,M,comptador);
    menu_interaccions(matriu_1, matriu_2, T,M,comptador);
}

int main()
{
    lectura_dades();
}
