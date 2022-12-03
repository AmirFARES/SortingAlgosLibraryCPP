#include <iostream>

using namespace std;

// Prototype ________________________
void Creation(int tab[],int n);
void Affichage(int tab[],int n);
void TriSelection(int tab[],int n);
void TriBulle(int tab[],int n);
void TriInsertion(int tab[],int n);
int Repartition(int tab[],int d,int f);
void TriRapide(int tab[],int d,int f);
void Fusion(int*tab[],int d,int f);
void TriFusion(int tab[],int d,int f);

// Function __________________________________
void Creation(int tab[],int n)
{
    cout << "Donner les valeur de tableau : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> tab[i];
    }
}

void Affichage(int tab[],int n)
{
    cout << "L'affichage de tableau : " << endl;
    for(int i=0;i<n;i++)
    {
        cout << tab[i] << "  " ;
    }
    cout << endl ;
}

void TriSelection(int tab[],int n)
{
    for(int i=0;i<n;i++)
    {
        int indmin=i;
        for(int j=i+1;j<n;j++)
        {
            if(tab[indmin]>tab[j])
            {
                indmin=j;
            }
        }
        int temp=tab[i];
        tab[i]=tab[indmin];
        tab[indmin]=temp;
    }
}

void TriBulle(int tab[],int n)
{
    while(n>0)
    {
        for(int j=0;j<n-1;j++)
        {
            if(tab[j]>tab[j+1])
            {
                int temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
        n--;
    }
}

void TriInsertion(int tab[],int n)
{
    for(int i=0;i<n;i++)
    {
        int val=tab[i];
        int j=i-1;
        while((j>=0)&&(val<tab[j]))
        {
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=val;
    }
}

int Repartition(int tab[],int d,int f)
{
    int pivot=tab[f],i=d,j=f;
    while(i<j)
    {
        while(tab[i]<pivot)
        {
            i++;
        }
        while((tab[j]>=pivot)&&(i<j))
        {
            j--;
        }
        //Echange de tab[i] et tab[j]
        int temp=tab[i];
        tab[i]=tab[j];
        tab[j]=temp;
        //Fin d'echange
    }
    if(i<j)
    {
        i++;
        j--;
    }
    //Echange de tab[i] et tab[j]
    int temp=tab[i];
    tab[i]=tab[f];
    tab[f]=temp;
    //Fin d'echange
    return i;
}

void TriRapide(int tab[],int d,int f)
{
    if(d<f)
    {
        int m=Repartition(tab,d,f);
        TriRapide(tab,d,m-1);
        TriRapide(tab,m+1,f);
    }
}

void Fusion(int tab[],int d,int f)
{
    int t[f-d+1];
    int m=(d+f)/2,i=d,j=m+1,k=0;
    while((i<=m)&&(j<=f))
    {
        if(tab[i]<=tab[j])
        {
            t[k]=tab[i];
            i++;
        }
        else
        {
            t[k]=tab[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        t[k]=tab[i];
        i++;
        k++;
    }
    while(j<=f)
    {
        t[k]=tab[j];
        j++;
        k++;
    }
    for(k=0;d+k<=f;k++)
    {
        tab[d+k]=t[k];
    }
}

void TriFusion(int tab[],int d,int f)
{
    int m;
    if(d<f)
    {
        m=(d+f)/2;
        TriFusion(tab,d,m);
        TriFusion(tab,m+1,f);
        Fusion(tab,d,f);
    }
}

