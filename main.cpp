#include "classes.hpp"
#include "Mensagem.hpp"

int main(){
    srand((unsigned) time(0)); //Garante que os falores sejam randômicos nas funções Random
    int op;
    Mensagem M("Bem vindo ao criador de fichas de D&D, Aqui podemos criar fichas automáticas baseado no que escolher","Você deseja: ","1 - criar um personagem colocando dados arbitrários","2 - Criar um personagem com valores aleatórios","3 - Criar um personagem forte com valores aleatórios");

    /* cout<<"Você deseja: "<<endl<<"1 - criar um personagem colocando dados arbitrários"<<endl;
    cout<<"2 - Criar um personagem com valores aleatórios"<<endl;
    cout<<"3 - Criar um personagem forte com valores aleatórios"<<endl; */
    cout<<++M<<endl<<M+1<<endl<<--M<<endl<<(M-2)<<endl<<M(1)<<endl<<endl;;


    cin>>op;

    if(op <= 1){ 
        jogador *GG = new jogador;

        GG->Entre_jog();
        GG->Calc_Profs();
        GG->Mostr_jog();
        GG->Mostr_Stats();

        delete(GG);
    }

    if(op == 2){ 
        jogador_Random *GG = new jogador_Random;

        GG->Entre_jog();
        GG->Calc_Profs();
        GG->Mostr_jog();
        GG->Mostr_Stats();

        delete(GG);
    }

    if(op >= 3){
        jogador_Random_Forte *GG = new jogador_Random_Forte;

        GG->Entre_jog();
        GG->Calc_Profs();
        GG->Mostr_jog();
        GG->Mostr_Stats();

        delete(GG);
    }      

    return 0;
}