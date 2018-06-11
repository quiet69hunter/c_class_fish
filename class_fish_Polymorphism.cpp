#include <iostream>

using namespace std;

class Ryba
{
protected:
    double waga, dlugosc, wysokosc;
public:
    int numerRuby;
    static int iter;
    void SetWaga(double waga);
    void GetWaga();
    void SetDl(double dlugosc);
    void GetDl();
    void SetWysok(double wysokosc);
    void GetWysok();

    virtual void Show(){
    cout<<"Waga = "<<waga<<endl;
    cout<<"Dlugosc = "<<dlugosc<<endl;
    cout<<"Wysokosc = "<<wysokosc<<endl;
    }

    Ryba(double waga, double dlugosc, double wysokosc){
    this->waga = waga;
    this->dlugosc = dlugosc;
    this->wysokosc = wysokosc;
    this->numerRuby = this->iter + 1;
    this->iter++;
    }

    Ryba(const Ryba &r) {
        this->waga = r.waga;
        this->dlugosc = r.dlugosc;
        this->wysokosc = r.wysokosc;
        this->numerRuby = r.numerRuby + 1;
        this->iter++;
        }

        friend void checkWiadro(const Ryba &r, int wysokosc_wiadra) {
            if(r.dlugosc <= wysokosc_wiadra){cout<<"Zmiesci"<<endl;}
            else cout<<"Nie zmiesci"<<endl;
        }

        double GetGenstosc() {
            return waga/(3.14*this->wysokosc*this->wysokosc*this->dlugosc);
        }
};

int Ryba::iter=0;

void Ryba::SetWaga(double waga){this->waga = waga;}
void Ryba::GetWaga(){cout<<"Waga = "<<waga<<endl;}
void Ryba::SetDl(double dlugosc){this->dlugosc = dlugosc;}
void Ryba::GetDl(){cout<<"Dlugosc = "<<dlugosc<<endl;}
void Ryba::SetWysok(double wysokosc){this->wysokosc = wysokosc;}
void Ryba::GetWysok(){cout<<"Wysokosc = "<<wysokosc<<endl;}

class Szczupak : public Ryba
{
protected:
    int ilosc_zebow;
public:
    Szczupak(double waga, double dlugosc, double wysokosc, int ilosc_zebow):Ryba(waga, dlugosc, wysokosc), ilosc_zebow(ilosc_zebow){}
    int GetIloscZebow(){return ilosc_zebow;}

    void Show(){
    Ryba::Show();
    cout<<"Ilosc zebow = "<<ilosc_zebow<<endl<<endl;
    }

};



int main()
{
    Ryba Ok(3.21, 22.1, 15.0);
    Ryba Szcz(Ok);
    checkWiadro(Ok,33);
    double gestosc = Ok.GetGenstosc();
    cout<<"Gestosc = "<<gestosc<<endl;
    Szcz.Show();

    Szczupak Pop(2.88, 15.1, 18.0, 45);
    Ryba *A = new Ryba(15.0, 11.11, 15.01);
    Ryba *B = new Szczupak(11.02, 54.0, 41.20, 65);
    Szczupak *C = new Szczupak(1.2, 12.0, 7.0, 32);
    Szczupak *D = new Szczupak(7.5, 55.65, 42.01, 78);
    D->Show();
    B->Show();

    C = dynamic_cast<Szczupak*>(A);

    if (C){
    int il = C->GetIloscZebow();
    cout<<il<<endl;
    } else cout<<"Nie mozliwe"<<endl;

    D = dynamic_cast<Szczupak*>(B);

    if(D){
    int ol = D->GetIloscZebow();
    cout<<ol<<endl;
    } else cout<<"Nie mozliwe"<<endl;

    return 0;
}
