#include <iostream>
#include <cstdlib>

using namespace std;

enum Classes {Barbaro,Ladino, Mago, Clerigo};

//------------------------------Classe Principal---------------------------
class status{

protected:
    int m_stats;
    int m_mod;

public:
    status(): m_stats(1), m_mod(1){};
    status(int s, int m): m_stats(s), m_mod(m){};
    int retorno_stats(){ return m_stats;};
    int retorno_mod(){ return m_mod;};

    void Calc_mod(){ m_mod = (m_stats - 10)/2;};
    void Bota_status(int s) { m_stats = s;};
};

//------------------------------Sub-Classe Força---------------------------

class Forca: public status{

protected:
    int m_atletismo;

public:
    Forca(): m_atletismo(0){};
    void Pega_at(int at){ m_atletismo = at;};
    int retorno_atl(){return m_atletismo;};
    ~Forca(){};
};

//------------------------------Sub-Classe Destreza---------------------------

class Destreza: public status{

protected:
    int m_acrobacia, m_prestidigitacao, m_furtividade;

public:
    Destreza():m_acrobacia(0), m_prestidigitacao(0), m_furtividade(0){};
    void Pega_acr(int acr){ m_acrobacia = acr;};
    void Pega_pres(int pres){ m_prestidigitacao = pres;};
    void Pega_furt(int furt){ m_furtividade = furt;};

    void operator=(int acr){Pega_acr(acr);};

    int retorno_acr(){return m_acrobacia;};
    int retorno_pres(){return m_prestidigitacao;};
    int retorno_furt(){return m_furtividade;};

};

//------------------------------Sub-Classe Constituição---------------------------

class Constituicao: public status{

protected:
    

public:
    
};

//------------------------------Sub-Classe Inteligência---------------------------

class Inteligencia: public status{

protected:
    int m_arcanismo, m_natureza, m_investigacao, m_historia, m_religiao;

public:
    Inteligencia():m_arcanismo(0), m_natureza(0), m_investigacao(0), m_historia(0), m_religiao(0){};
    void Pega_arc(int arc){ m_arcanismo = arc;};
    void Pega_nat(int nat){ m_natureza = nat;};
    void Pega_inv(int inv){ m_investigacao = inv;};
    void Pega_his(int his){ m_historia = his;};
    void Pega_rel(int rel){ m_religiao = rel;};

    int retorno_arc(){ return m_arcanismo;};
    int retorno_nat(){ return m_natureza;};
    int retorno_inv(){ return m_investigacao;};
    int retorno_his(){ return m_historia;};
    int retorno_rel(){ return m_religiao;};
};

//------------------------------Sub-Classe Sabedoria---------------------------

class Sabedoria: public status{

protected:
    int m_adestrar_an, m_intuicao, m_percepcao,m_medicina,m_sobrevivencia;

public:
    Sabedoria():m_adestrar_an(0), m_intuicao(0), m_percepcao(0),m_medicina(0),m_sobrevivencia(0){};
    void Pega_ades(int ades){ m_adestrar_an = ades;};
    void Pega_intu(int intu){ m_intuicao = intu;};
    void Pega_per(int per){ m_percepcao = per;};
    void Pega_med(int med){ m_medicina = med;};
    void Pega_sob(int sob){ m_sobrevivencia = sob;};

    int retorno_ades(){ return m_adestrar_an;};
    int retorno_intu(){ return m_intuicao;};
    int retorno_per(){ return m_percepcao;};
    int retorno_med(){ return m_medicina;};
    int retorno_sob(){ return m_sobrevivencia;};
};

//------------------------------Sub-Classe Carisma---------------------------

class Carisma: public status{

protected:
    int m_intimidacao, m_enganacao, m_persuasao,m_atuacao;

public:
    Carisma():m_intimidacao(0), m_enganacao(0), m_persuasao(0),m_atuacao(0){};
    void Pega_inti(int inti){ m_intimidacao = inti;};
    void Pega_eng(int eng){ m_enganacao = eng;};
    void Pega_pers(int pers){ m_persuasao = pers;};
    void Pega_atu(int atu){ m_atuacao = atu;};

    int retorno_inti(){ return m_intimidacao;};
    int retorno_eng(){ return m_enganacao;};
    int retorno_pers(){ return m_persuasao;};
    int retorno_atu(){ return m_atuacao;};
};

//------------------------------Classe Jogador---------------------------

class jogador{

protected:
    Classes Classinha;
    int m_HP, m_CA, m_inici, m_prof;
    Forca* m_forc;
    Destreza* m_Des;
    Constituicao* m_Con;
    Inteligencia* m_Int;
    Sabedoria* m_Sab;
    Carisma* m_Car;

public:
    //------------Jeitos Diferetes de Pegar informações do jogador-----

    jogador(int hp,int ca, int prof): m_HP(hp),m_CA(ca),m_prof(prof){m_forc = new Forca; m_Des = new Destreza; m_Con = new Constituicao; m_Int = new Inteligencia;m_Sab = new Sabedoria; m_Car = new Carisma;}
    jogador(): m_HP(0),m_CA(0),m_prof(0), m_inici(0){ m_forc = new Forca; m_Des = new Destreza; m_Con = new Constituicao; m_Int = new Inteligencia; m_Sab = new Sabedoria; m_Car = new Carisma;}

    void Pega_hp(int ent){m_HP = ent;}
    void Pega_ca(int ent){m_CA = ent;}
    void Pega_prof(int ent){m_prof = ent;}


    void Entre_jog(); //Pega Informações do jogador, vida etc

    void Calc_BLMC(int F, int D, int C, int I, int S, int Ca, Classes X);

    void Calc_Profs(); //Pega todos os valores de habilidade e calcula as proficiências

    void Mostr_jog(){cout<<endl<<"HP: "<<m_HP<<" CA: "<<m_CA<<" Iniciativa: "<<m_Des->retorno_mod()<<" Proficiência: "<<m_prof<<endl<<endl;};
    void Mostr_Stats();

    ~jogador(){delete(m_forc);delete(m_Des);delete(m_Con);delete(m_Int);delete(m_Sab);delete(m_Car); }   

};

class jogador_Random: public jogador{

protected:

public:
    void Calc_Profs(); //Randomiza os valores de habilidade e calcula as proficiências
    void Entre_jog();  //Randomiza os valores do jogador e re-calcula o HP e CA

};

class jogador_Random_Forte: public jogador{

protected:

public:
    void Calc_Profs(); //Randomiza os valores de habilidade com valores altos e calcula as proficiências
    void Entre_jog();  //Randomiza os valores do jogador com valores altos e re-calcula o HP e CA

};