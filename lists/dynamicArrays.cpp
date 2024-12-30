#include<iostream>
using namespace std;


class car{
    
public:
    string*model,*brand;
    int year;
    car(const string& m,const string &b,const int &y){
        model=new string(m);
        brand=new string(b);
        year=y;
    }

    void display(){
        cout<<*model<<" "<<*brand<<" "<<year<<endl;
    }

};
int main(){
    car *c=new car("toyota","ha",123);
    c->display();
    cout<<*((*c).model)<<endl;
    delete c;
}