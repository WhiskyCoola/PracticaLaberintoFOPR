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
//Pre:
//Post:
void moviments_en_laberint(char&matriu_1, char&matriu_2, esser&T, esser&M, int&comptador, char moviment, char&condicio_joc)
{
//Recordatorio: Mirar caso extremo 2 o mas salidas, acceder fuera de la matriz(segmentation fault)
    
    if(moviment == 'D')
    {
        if(matriu_1[T.Px][T.Py+1] == '_') matriu_1[T.Px][T.Py] = '_', ++T.Py, matriu_1[T.Px][T.Py] = 'T';
    }
    else if(moviment == 'U')
    {
        if(matriu_1[T.Px][T.Py-1] == '_') matriu_1[T.Px][T.Py] = '_', --T.Py, matriu_1[T.Px][T.Py] = 'T';
    }
    else if(moviment == 'L')
    {
        if(matriu_1[T.Px-1][T.Py] == '_') matriu_1[T.Px][T.Py] = '_', --T.Px, matriu_1[T.Px][T.Py] = 'T';
    }
    else if(moviment == 'R')
    {
        if(matriu_1[T.Px+1][T.Py] == '_') matriu_1[T.Px][T.Py] = '_', ++T.Px, matriu_1[T.Px][T.Py] = 'T';
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
    if(moviment == 'w')
    {
        //mirar como resolver el mover al minotauro por horizontal o vertical
        if((M.Px - T.Px) <= (M.Py - T.Py) ) //Movimiento horizontal
        {
            if(matriu_1[M.Px-1][M.Py] == 'T') condicio_joc = 'a';
        }
        else if((M.Px - T.Px) > (M.Py - T.Py)) //movimiento vertical
        {
            if(matriu_1[M.Px][M.Py+1] == 'T') condicio_joc = 'a';
        }
    
    }
}
//Pre:
//Post:
void menu_interaccions(char&matriu_1, char&matriu_2, esser&T, esser&M, int&comptador)
{
    int entrada, comptador_minotauro = 0;
    char estat = 'n'; // a = atrapat, p = perdut, g = guanyat;
    while(cin>>entrada and estat == 'n')
    {
        if(entrada == 'D')
        {
            moviments_en_laberint(matriu_1, matriu_2, T, M, comptador, entrada, estat), ++comptador_minotauro;
        }
        if(entrada == 'L')
        {
            moviments_en_laberint(matriu_1, matriu_2, T, M, comptador, entrada, estat), ++comptador_minotauro;
        }
        if(entrada == 'R')
        {
            moviments_en_laberint(matriu_1, matriu_2, T, M, comptador, entrada, estat), ++comptador_minotauro;
        }
        if(entrada == 'S')
        {
            veure_estat(matriu_2);
        }
        if(entrada == 'U')
        {
            moviments_en_laberint(matriu_1, matriu_2, T, M, comptador, entrada, estat), ++comptador_minotauro;
        }
        if(entrada == 'Z')
        {
            estat = 'p';
            veure_estat(matriu_2);
            cout<<"A reveure!"<<endl;
            cout<<"Has fet"<<" "<<comptador<<" "<<moviments<<endl;
        }
        ++comptador;
        if(comptador_minotauro == 2)
        {
            comptador_minotauro = 0;
            moviments_en_laberint(matriu_1, matriu_2, T, M, comptador, 'w', 'w')
        }
    }
    if(estat == 'a') cout<<"Has perdut! El Minotaure t'ha atrapat!"<<endl;
    if(estat == 'g') cout<<"Felicitats has arribat a la sortida!!"<<endl;
    cout<<"Has fet"<<" "<<comptador<<" "<<moviments<<endl;
}
//Pre:
//Post:
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
//Pre:
//Post:
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
            cin>>matriu_1[i][j]; //Matriz de referencia, este se utiliza de guia 
            if(entrada == 'T') T.Px = j, T.Py = i;
            else if(entrada == 'M') M.Px = j, M.Py = i;
        }
    }

    int matriu_2[mida_fila][mida_columna]; // Matriz que se utiliza para mostrar por pantalla
     for(int i = 0; i < mida_fila; ++i)
    {
        for(int j = 0; j < mida_columna; ++j)
        {
            matriu_2[i][j] = '.';
        }
    }
    int comptador = 0;
    moviments_en_laberint(matriu_1, matriu_2, T,M,comptador,'W','n');
    //He puesto veure estat abajo para que asi modifique primero y se vea en un rango 3x3 de casillas para luego veure_estat haga cout
    cout<<veure_estat(matriu_2)<<endl;
    menu_interaccions(matriu_1, matriu_2, T,M,comptador);
}
//Pre: Es cert
//Post: Retorna l'acabament del programa
int main()
{
    lectura_dades();
}
