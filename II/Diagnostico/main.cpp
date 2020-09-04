#include <iostream>
#include <fstream>

using namespace std;

class Fraction{
    private:
        int numerator,denominator;
        int MCD(int num,int den){
            if(den==0) return num;
            int aux=num%den;
            return MCD(den,aux);
        }
    public:
        Fraction(){
            numerator=5;
            denominator=3;
        }
        Fraction(int myNum, int myDen){
            bool nu=1,de=1;
            if(myNum<0){
                nu=0;
                myNum*=-1;
            }
            if(myDen<0){
                de=0;
                myDen*=-1;
            }
            int divide=MCD(myNum,myDen);
            numerator=myNum/divide;
            denominator=myDen/divide;
            if(nu!=de)numerator*=-1;
        }
        int getNumerator(){return numerator;}
        int getDenominator(){return denominator;}
        void print(){
            cout<<numerator<<"/"<<denominator<<" ";
        }
        Fraction operator +(Fraction const &fracB){
            int auxN=(numerator*fracB.denominator)+(fracB.numerator*denominator);
            int auxD=denominator*fracB.denominator;
            Fraction fracC(auxN,auxD);
            return fracC;
        }
        Fraction operator *(Fraction const &fracB){
            int auxN=numerator*fracB.numerator;
            int auxD=denominator*fracB.denominator;
            Fraction fracC(auxN,auxD);
            return fracC;
        }
};
class MatFrac{
    private:
        Fraction mat[50][50];
        int columns,rows;
    public:
        MatFrac(){
            columns=0;
            rows=0;
        }
        MatFrac(string file){
            ifstream myfile;
            myfile.open(file);
            myfile>>rows>>columns;
            int auxN,auxD;
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    myfile>>auxN>>auxD;
                    mat[i][j]=Fraction(auxN,auxD);
                }
            }
            cout<<endl;
            myfile.close();
        }
        void setDimensions(int rowNum,int colNum){
            columns=colNum;
            rows=rowNum;
        }
        Fraction getFrac(int row,int col){return mat[row][col];}
        MatFrac operator +(MatFrac const &matB)
        {
            MatFrac matC=MatFrac();
            if(matB.columns==columns || matB.rows==rows){
                matC.setDimensions(rows,columns);
                for(int i=0;i<rows;i++){
                    for(int j=0;j<columns;j++) matC.mat[i][j]=mat[i][j]+matB.mat[i][j];
                }
            }
            return matC;
        }
        void print()
        {
            if(rows==0 || columns==0){
                cout<<"Operación imposible";
                return;
            }
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++) mat[i][j].print();
                cout<<'\n';
            }
        }
};

int main()
{
    string file1,file2;
    cout<<"Insert the file name: ";
    cin>>file1;
    cout<<"Insert the file name: ";
    cin>>file2;
    MatFrac m1=MatFrac(file1);
    MatFrac m2=MatFrac(file2);
    MatFrac m3=m1+m2;
    m3.print();
    return 0;
}
