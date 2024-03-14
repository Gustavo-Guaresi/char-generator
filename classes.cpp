#include "classes.hpp"

    //------------------------------------CALCULA AS ESTSTÍSTICAS  --------------------------------

    void jogador::Calc_BLMC(int F, int D, int C, int I, int S, int Ca, Classes X){
        int Com_Prof;
        int Sem_Prof;
        //Bota status de força
        m_forc->Bota_status(F);
        m_forc->Calc_mod();
        Com_Prof =  m_forc->retorno_mod() + m_prof;
        Sem_Prof = m_forc->retorno_mod();

        if(X == Mago){m_forc->Pega_at(Sem_Prof);}
        if(X == Clerigo){m_forc->Pega_at(Sem_Prof);}
        if(X == Ladino){m_forc->Pega_at(Sem_Prof);}
        if(X == Barbaro){m_forc->Pega_at(Com_Prof);}

        //Bota status de Destreza
        m_Des->Bota_status(D);
        m_Des->Calc_mod();
        Com_Prof =  m_Des->retorno_mod() + m_prof;
        Sem_Prof =  m_Des->retorno_mod();

        if(X == Mago){m_Des->Pega_acr(Sem_Prof) ;m_Des->Pega_furt(Sem_Prof); m_Des->Pega_pres(Sem_Prof);}
        if(X == Clerigo){m_Des->Pega_acr(Sem_Prof) ;m_Des->Pega_furt(Sem_Prof); m_Des->Pega_pres(Sem_Prof);}
        if(X == Ladino){m_Des->Pega_acr(Com_Prof) ;m_Des->Pega_furt(Com_Prof); m_Des->Pega_pres(Com_Prof);}
        if(X == Barbaro){m_Des->Pega_acr(Sem_Prof) ;m_Des->Pega_furt(Sem_Prof); m_Des->Pega_pres(Sem_Prof);}

        m_CA = m_CA + m_Des->retorno_mod();


        //Bota status de Constituição
        m_Con->Bota_status(C);
        m_Con->Calc_mod();
        Com_Prof =  m_Con->retorno_mod() + m_prof;
        Sem_Prof =  m_Con->retorno_mod();
        m_HP = m_HP + m_Con->retorno_mod();

        //Bota status de Inteligência
        m_Int->Bota_status(I);
        m_Int->Calc_mod();
        Com_Prof =  m_Int->retorno_mod() + m_prof;
        Sem_Prof =  m_Int->retorno_mod();

        if(X == Mago){m_Int->Pega_arc(Com_Prof); m_Int->Pega_nat(Sem_Prof); m_Int->Pega_inv(Com_Prof); m_Int->Pega_his(Sem_Prof); m_Int->Pega_rel(Sem_Prof);}
        if(X == Clerigo){m_Int->Pega_arc(Sem_Prof); m_Int->Pega_nat(Sem_Prof); m_Int->Pega_inv(Sem_Prof); m_Int->Pega_his(Sem_Prof); m_Int->Pega_rel(Sem_Prof);}
        if(X == Ladino){m_Int->Pega_arc(Sem_Prof); m_Int->Pega_nat(Sem_Prof); m_Int->Pega_inv(Sem_Prof); m_Int->Pega_his(Sem_Prof); m_Int->Pega_rel(Sem_Prof);}
        if(X == Barbaro){m_Int->Pega_arc(Sem_Prof); m_Int->Pega_nat(Sem_Prof); m_Int->Pega_inv(Sem_Prof); m_Int->Pega_his(Sem_Prof); m_Int->Pega_rel(Sem_Prof);}
        
        //Bota status de Sabedoria
        m_Sab->Bota_status(S);
        m_Sab->Calc_mod();
        Com_Prof =  m_Sab->retorno_mod() + m_prof;
        Sem_Prof =  m_Sab->retorno_mod();
        
       if(X == Mago){m_Sab->Pega_ades(Sem_Prof); m_Sab->Pega_intu(Sem_Prof); m_Sab->Pega_per(Sem_Prof); m_Sab->Pega_med(Sem_Prof); m_Sab->Pega_sob(Sem_Prof);}
       if(X == Clerigo){m_Sab->Pega_ades(Sem_Prof); m_Sab->Pega_intu(Com_Prof); m_Sab->Pega_per(Sem_Prof); m_Sab->Pega_med(Com_Prof); m_Sab->Pega_sob(Sem_Prof);}
       if(X == Ladino){m_Sab->Pega_ades(Sem_Prof); m_Sab->Pega_intu(Sem_Prof); m_Sab->Pega_per(Sem_Prof); m_Sab->Pega_med(Sem_Prof); m_Sab->Pega_sob(Sem_Prof);}       
       if(X == Barbaro){m_Sab->Pega_ades(Sem_Prof); m_Sab->Pega_intu(Sem_Prof); m_Sab->Pega_per(Sem_Prof); m_Sab->Pega_med(Sem_Prof); m_Sab->Pega_sob(Sem_Prof);}

        //Bota status de Carisma
        m_Car->Bota_status(S);
        m_Car->Calc_mod();
        Com_Prof =  m_Car->retorno_mod() + m_prof;
        Sem_Prof =  m_Car->retorno_mod();
        
        if(X == Mago){m_Car->Pega_inti(Sem_Prof); m_Car->Pega_eng(Sem_Prof); m_Car->Pega_pers(Sem_Prof); m_Car->Pega_atu(Sem_Prof);}
        if(X == Clerigo){m_Car->Pega_inti(Sem_Prof); m_Car->Pega_eng(Sem_Prof); m_Car->Pega_pers(Sem_Prof); m_Car->Pega_atu(Sem_Prof);}
        if(X == Ladino){m_Car->Pega_inti(Sem_Prof); m_Car->Pega_eng(Com_Prof); m_Car->Pega_pers(Sem_Prof); m_Car->Pega_atu(Sem_Prof);}
        if(X == Barbaro){m_Car->Pega_inti(Com_Prof); m_Car->Pega_eng(Sem_Prof); m_Car->Pega_pers(Sem_Prof); m_Car->Pega_atu(Sem_Prof);}
        
    }


    //------------------------Escolhe Qual a classe do jogador e então calcula tudo com base nela-------------

    void jogador::Calc_Profs(){
        int fors,des,co,in,sab,caris;
        cout<<endl<<"Informe seus valores de habilidade na ordem de: Força, Destreza, Constituição, Inteligência, Sabedoria, Carisma "<<endl<<endl;
        cin>>fors;
        cin>>des;
        cin>>co;
        cin>>in;
        cin>>sab;
        cin>>caris;
        if(Classinha == Barbaro){Calc_BLMC(fors, des, co, in, sab, caris, Barbaro);}
        if(Classinha == Ladino){Calc_BLMC(fors, des, co, in, sab, caris, Ladino);}
        if(Classinha == Mago){Calc_BLMC(fors, des, co, in, sab, caris, Mago);}
        if(Classinha == Clerigo){Calc_BLMC(fors, des, co, in, sab, caris, Clerigo);}
    }

    // ------------------------------ Entrando com as Informações do Jogador ------------------------------------

    void jogador::Entre_jog(){
        int info;

        cout<<"Quanto de vida inicial você tem? "<<endl;
        cin>>info;
        Pega_hp(info);

        cout<<"Quanto de Classe de Armadura inicial você tem? "<<endl;
        cin>>info;
        Pega_ca(info);

        cout<<"Quanto de proficiência você tem? "<<endl;
        cin>>info;
        Pega_prof(info);

        cout<<"Qual a sua Classe? Opção 1: Bárbaro -- Opção 2: Ladino -- Opção 3: Mago -- Opção 4 Clérigo"<<endl<<endl;
        cin>>info;
        if(info == 1){ Classinha = Barbaro;}
        if(info == 2){ Classinha = Ladino;}
        if(info == 3){ Classinha = Mago;}
        if(info == 4){ Classinha = Clerigo;}
        if(info <1 || info >4 ){ cout<<"Ótimo, você irá de Bárbaro"<<endl<<endl;Classinha = Barbaro;}

    }
    //----------------------- Função Randomizadora de Calcula as Proficiências ------------------------

    void jogador_Random::Calc_Profs(){

        int fors,des,co,in,sab,caris;

        fors = (rand() % 20);
        des = (rand() % 20);
        co = (rand() % 20);
        in = (rand() % 20);
        sab = (rand() % 20);
        caris = (rand() % 20);

        if(Classinha == Barbaro){Calc_BLMC(fors, des, co, in, sab, caris, Barbaro);}
        if(Classinha == Ladino){Calc_BLMC(fors, des, co, in, sab, caris, Ladino);}
        if(Classinha == Mago){Calc_BLMC(fors, des, co, in, sab, caris, Mago);}
        if(Classinha == Clerigo){Calc_BLMC(fors, des, co, in, sab, caris, Clerigo);}

    }

    void jogador_Random::Entre_jog(){
        int info;

        info = (rand() % 30);
        Pega_hp(info);

        info = (rand() % 22);
        Pega_ca(info);

        info = (rand() % 3);
        Pega_prof(info);

        info = (rand() % 4);
        if(info == 1){ Classinha = Barbaro;}
        if(info == 2){ Classinha = Ladino;}
        if(info == 3){ Classinha = Mago;}
        if(info == 4){ Classinha = Clerigo;}
        if(info <1 || info >4 ){ cout<<"Ótimo, você irá de Bárbaro"<<endl<<endl;Classinha = Barbaro;}
    }

    //----------------------- Função Randomizadora Mais Forte que Calcula as Proficiências ------------------------

    void jogador_Random_Forte::Calc_Profs(){

        int fors,des,co,in,sab,caris;

        fors = (rand() % 10) + 10; 
        des = (rand() % 10) + 10; 
        co = (rand() % 10)+ 10; 
        in = (rand() % 10)+ 10; 
        sab = (rand() % 10)+ 10; 
        caris = (rand() % 10)+ 10;
        
        if(Classinha == Barbaro){Calc_BLMC(fors, des, co, in, sab, caris, Barbaro);}
        if(Classinha == Ladino){Calc_BLMC(fors, des, co, in, sab, caris, Ladino);}
        if(Classinha == Mago){Calc_BLMC(fors, des, co, in, sab, caris, Mago);}
        if(Classinha == Clerigo){Calc_BLMC(fors, des, co, in, sab, caris, Clerigo);}

    }

    void jogador_Random_Forte::Entre_jog(){
        int info;

        info = (rand() % 10) + 20;
        Pega_hp(info);

        info = (rand() % 10) + 15;
        Pega_ca(info);

        info = 4;
        Pega_prof(info);

        info = (rand() % 4);
        if(info == 1){ Classinha = Barbaro;}
        if(info == 2){ Classinha = Ladino;}
        if(info == 3){ Classinha = Mago;}
        if(info == 4){ Classinha = Clerigo;}
        if(info <1 || info >4 ){ cout<<"Ótimo, você irá de Bárbaro"<<endl<<endl;Classinha = Barbaro;}
    }

    //------------------------------- Mostra as Informações --------------------------- 

    void jogador::Mostr_Stats(){
        if(Classinha == Barbaro){cout<<"Você é um Bárbaro e seus status são: "<<endl<<endl;}
        if(Classinha == Ladino){cout<<"Você é um Ladino e seus status são: "<<endl<<endl;}
        if(Classinha == Mago){cout<<"Você é um Mago e seus status são: "<<endl<<endl;}
        if(Classinha == Clerigo){cout<<"Você é um Clérigo e seus status são: "<<endl<<endl;}

        cout<<"Status Força: "<< m_forc->retorno_stats() <<" Mod: "<< m_forc->retorno_mod() <<" Atletismo: "<< m_forc->retorno_atl() <<endl;
        cout<<"Status Destreza: "<<m_Des->retorno_stats()<<" Mod: "<<m_Des->retorno_mod()<<" Acrobacia: "<<m_Des->retorno_acr()<<" Furtividade: "<<m_Des->retorno_furt()<<" Prestidigitação: "<<m_Des->retorno_pres()<<" - "<<endl;
        cout<<"Status Constituição: "<<m_Con->retorno_stats()<<" Mod: "<<m_Con->retorno_mod()<<endl;
        cout<<"Status Inteligência: "<<m_Int->retorno_stats()<<" Mod: "<<m_Int->retorno_mod()<<" Investigação: "<<m_Int->retorno_inv()<<" História: "<<m_Int->retorno_his()<<" Religião: "<<m_Int->retorno_rel()<<" Natureza: "<<m_Int->retorno_nat()<<" Arcanismo: "<<m_Int->retorno_arc()<<endl;
        cout<<"Status Sabedoria: "<<m_Sab->retorno_stats()<<" Mod: "<<m_Sab->retorno_mod()<<" Percepção: "<<m_Sab->retorno_per()<<" Intuição: "<<m_Sab->retorno_intu()<<" Medicina: "<<m_Sab->retorno_med()<<" Adestrar Animais: "<<m_Sab->retorno_ades()<<" Sobrevivência: "<<m_Sab->retorno_sob()<<endl;
        cout<<"Status Carisma: "<<m_Car->retorno_stats()<<" Mod: "<<m_Car->retorno_mod()<<" Enganação: "<<m_Car->retorno_eng()<<" Atuação: "<<m_Car->retorno_atu()<<" Persuasão: "<<m_Car->retorno_pers()<<" Intimidação: "<<m_Car->retorno_inti()<<endl;
    }
