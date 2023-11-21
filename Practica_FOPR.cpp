#include <iostream>
#include <vector>
using namespace std;

struct esser 
{
    int Px;
    int Py;
    char antiga_casella;
};
//modificar matriz en esta funcion(?)
// Matriu 1 y 2 comprobar si estan bien declarados.
//Pre:
//Post:
void eliminar_boira(char&matriu_1, char&matriu_2, esser&T, esser&M)
{
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
        eliminar_boira(matriu_1, matriu_2, T, M);

    if(moviment == 'w')
    {
        //mirar como resolver el mover al minotauro por horizontal o vertical
        int absX = T.Px - M.Px;
        if(absX < 0) absX * -1;
        int absY = T.Py - M.Py;
        if(absY < 0) absY * -1;
    /*  Dentro de la matriz calculamos la distancia entre T y M en valor absoluto     */
        //Movimiento en horizontal
        if(absX <= absY)
        {
            if(T.Px < M.Px)
            {
               //mover a la izquierda
            //guardamos el caracter de la casilla a la que queremos acceder, movemos la M, y la posicion inicial de M es sustituida
            //por un espacio vacio o la anterior estructura, ya que M pasa por encima y no los destruye
            //matriz 1 que es la matriz de referencia es modificada de forma que cuando T llegue a encontrarse con M
            //Este se mostrara si se encuentra dentro del rango 3x3, y no fuera de su rango.
            char aux = matriu_1[M.Px-1][M.Py];
                if(aux == 'T') condicio_joc = 'a';
                else
                {
                    matriu_1[M.Px][M.Py] = M.antiga_casella, --M.Px, matriu_1[M.Px][M.Py] = 'M';
                    M.antiga_casella = aux; 
                }
            
            }
            else //mover a la derecha
            {
                char aux = matriu_1[M.Px+1][M.Py];
                if(aux == 'T') condicio_joc = 'a';
                else 
                {
                    matriu_1[M.Px][M.Py] = M.antiga_casella, ++M.Px, matriu_1[M.Px][M.Py] = 'M';
                    M.antiga_casella = aux;   
                }
                 
            }
            
        }
            //Movimiento vertical
        else if(absX > absY)
        {
            if(T.Py < M.Py) // Mover hacia arriba
            {
                 char aux = matriu_1[M.Px][M.Py-1];
                if(aux == 'T') condicio_joc = 'a';
                else 
                {
                    matriu_1[M.Px][M.Py] = M.antiga_casella, --M.Py, matriu_1[M.Px][M.Py] = 'M';
                    M.antiga_casella = aux;
                }
            ; 
            }
            else // mover hacia abajo
            {
                char aux = matriu_1[M.Px][M.Py+1];
                if(aux == 'T') condicio_joc = 'a';
                else 
                {
                    matriu_1[M.Px][M.Py] = M.antiga_casella, ++M.Py, matriu_1[M.Px][M.Py] = 'M';
                    M.antiga_casella = aux;
                }
            }
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
