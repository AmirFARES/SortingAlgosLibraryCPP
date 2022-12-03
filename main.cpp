#include <iostream>
#include "GestTrie.h"

using namespace std;

int main()
{
    int n,meth;
    cout << "Donner la taille de tableau : " ;
    cin >> n;
    int tab[n];
    Creation(tab,n);
    Affichage(tab,n);
    cout << "La liste des methodes de trier un tableau : " << endl ;
    cout << "______________________________________" << endl ;
    cout << "1- Trie par selection." << endl ;
    cout << "2- Trie a bulle." << endl ;
    cout << "3- Trie par insertion." << endl ;
    cout << "4- Trie rapide." << endl ;
    cout << "5- Trie fusion." << endl ;
    cout << "______________________________________" << endl ;
    do
    {
        cout << "Choisir une methode pour trier le tableau : " ;
        cin >> meth;
        switch(meth)
        {
            case 1 : TriSelection(tab,n);break;
            case 2 : TriBulle(tab,n);break;
            case 3 : TriInsertion(tab,n);break;
            case 4 : TriRapide(tab,0,n-1);break;
            case 5 : TriFusion(tab,0,n-1);break;
            default : cout << "n'existe pas dans la liste des methodes : " << endl ;break;
        }
    }while((meth<1)||(meth>5));
    Affichage(tab,n);
    return 0;
}
