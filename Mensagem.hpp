#include <string>
#include <iostream>

using namespace std;

class Mensagem {
protected:
    string m_mens1;
    string m_mens2;
    string m_mens3;
    string m_mens4;
    string m_mens5;

public:
    Mensagem(){m_mens1 = "", m_mens2 = "", m_mens3 = "", m_mens4 = "", m_mens5 = "";};
    Mensagem(string m1, string m2,string m3,string m4,string m5){ m_mens1 = m1; m_mens2 = m2;m_mens3 = m3;m_mens4 = m4;m_mens5 = m5;};

    string Pega_m1(){return m_mens1;};
    string Pega_m2(){return m_mens2;};
    string Pega_m3(){return m_mens3;};
    string Pega_m4(){return m_mens4;};
    string Pega_m5(){return m_mens5;};

    string operator++(){return Pega_m1();};
    string operator+(int d){return Pega_m2();};
    string operator--(){return Pega_m3();};
    string operator-(int d){return Pega_m4();};
    string operator()(int d){return Pega_m5();};
};