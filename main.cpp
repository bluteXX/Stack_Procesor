#include <iostream>
#include <string>
#include "stack.cpp"
#include <fstream>
void dolaczliste(lista* dolocz, lista* dotej)
{
    
    if (dolocz==dotej)
    {
        return;
    }
    
    if (dolocz == nullptr || dolocz->head == nullptr)
    {
        return;  
    }

    
    dotej->push_back(dolocz->head->data);
    if (dolocz->head->data>='0' && dolocz->head->data<='9')
    {
        dotej->rozmiar++;
    }
    
    
    dolocz->pop_fornt();  

    
    dolaczliste(dolocz, dotej);  
}





void dodajInta(lista* lista,int liczba)
{
    if (liczba==0)
    {
        return;
    }
    dodajInta(lista,liczba/10);
    lista->push_front((liczba % 10) + '0');
    lista->rozmiar++;
    

}
void dodajdwielist(lista* a,lista* b,int znak=0)
{
    if (a->tail->data=='-' && b->tail->data=='-')
    {
        znak=1;

    }
    


}

void dodajdwiedodatnie(lista* a, lista* b, lista* wynik, int suma = 0) {
    




    if (a->head == nullptr && b->head == nullptr && suma == 0) {
        return;
    }

    
    int valA = (a->head != nullptr) ? (a->head->data - '0') : 0;
    int valB = (b->head != nullptr) ? (b->head->data - '0') : 0;

    
    int nowaSuma = valA + valB + suma;
    int cyfra = nowaSuma % 10;
    int nowePrzeniesienie = nowaSuma / 10;

    
    if (a->head != nullptr) a->head = a->head->next;
    if (b->head != nullptr) b->head = b->head->next;

    wynik->push_back(cyfra + '0');
    wynik->rozmiar++;

    dodajdwiedodatnie(a, b, wynik, nowePrzeniesienie);

    
    
}
void odejmijdwiedodatnie(lista* a, lista* b, lista* wynik) {
    
    if (a->head == nullptr && b->head == nullptr) {
        return;
    }

    
    int valA = (a->head != nullptr) ? (a->head->data - '0') : 0;
    int valB = (b->head != nullptr) ? (b->head->data - '0') : 0;

    
    int nowaRoznica = valA - valB;
    if (nowaRoznica<0 && a->head->next!=nullptr)
    {
        nowaRoznica+=10;
        a->head->next->data=a->head->next->data-1;
    }
    
    
    

    
    if (a->head != nullptr) a->head = a->head->next;
    if (b->head != nullptr) b->head = b->head->next;

    wynik->push_back(nowaRoznica + '0');
    wynik->rozmiar++;
    odejmijdwiedodatnie(a, b, wynik);

    
    
}








void usunWiodac(lista* lista, bool czyujemna = false) {
    if (lista->head == nullptr) return;

    if (lista->rozmiar == 1 && lista->tail->data == '0') {
        return;
    }

    if (lista->tail->data == '0') {
        lista->pop_back();
        lista->rozmiar--;
        usunWiodac(lista, czyujemna);
    }
    else if (lista->tail->data == '-') {
        czyujemna = true;
        lista->pop_back();

        usunWiodac(lista, czyujemna);
    }
    else {
        if (czyujemna && !(lista->rozmiar == 1 && lista->tail->data == '0')) {
            lista->push_back('-');
        }
    }
}







int ktoraiweksza(lista* a, lista* b, bool czysprawdzamujemne = false) {
    
    if (a->tail == nullptr && b->tail == nullptr) return -1;

    if (a->tail != nullptr && a->tail->data == '-' && (b->tail == nullptr || b->tail->data != '-')) return 0;
    if (b->tail != nullptr && b->tail->data == '-' && (a->tail == nullptr || a->tail->data != '-')) return 1;

    if (a->tail != nullptr && a->tail->data == '-' && b->tail != nullptr && b->tail->data == '-') {
        lista nextA, nextB;
        nextA.tail = a->tail->prev;
        nextB.tail = b->tail->prev;
        nextA.head = a->head;
        nextB.head = b->head;
        nextA.rozmiar = a->rozmiar - 1;
        nextB.rozmiar = b->rozmiar - 1;

        int wynik = ktoraiweksza(&nextA, &nextB, true);
        if (wynik == -1) return -1; 
        return wynik == 1 ? 0 : 1;  
    }

    
        if (a->rozmiar > b->rozmiar) return 1;
        if (a->rozmiar < b->rozmiar) return 0;
    

    if (a->tail != nullptr && b->tail != nullptr) {
        if (a->tail->data > b->tail->data) return 1;
        if (a->tail->data < b->tail->data) return 0;

        lista nextA, nextB;
        nextA.tail = a->tail->prev;
        nextB.tail = b->tail->prev;
        nextA.head = a->head;
        nextB.head = b->head;
        nextA.rozmiar = a->rozmiar - 1;
        nextB.rozmiar = b->rozmiar - 1;

        return ktoraiweksza(&nextA, &nextB, czysprawdzamujemne);
    }

    if (a->tail == nullptr && b->tail == nullptr) return -1;
    if (a->tail == nullptr) return 0;
    if (b->tail == nullptr) return 1;

    return -1; 
}










    int main() 
    {
        //std::ofstream plik("wynik.txt");
        std::string program;
        std::getline(std::cin, program);  
        stack s; 
        int liczba=0; 
        for (size_t i = 0; i < program.size(); i++) {
            char instruction = program[i];

            /*plik << "=== STAN STOSU ===" << std::endl;
            plik << "Instrukcja " << liczba <<std::endl;
            plik << "i: " << i <<", array: " <<instruction << std::endl;
            plik << (int)instruction << std::endl; */
  
         
            
              
            
            //s.wypiszdopliku(s.top,plik);
            
            
            if (instruction == '\'') { 
                lista* new_list = new lista(); 
                s.pusch(new_list); 
                
            }
            else if (instruction == ',')
            {
                s.deletepick();
            }
            else if (instruction==':')
            {
                lista* original = s.szczyt();
                lista* copy = new lista(*original); 
                s.pusch(copy);
            }
            else if (instruction==';')
            {
                lista* first = s.pop();
                lista* second = s.pop();
 
                s.pusch(first);
                s.pusch(second);
            
            }
            else if (instruction=='@')
            {
                
                int liczba=0;
                s.szczyt()->zamiennainta(liczba);
                s.deletepick();
                stack kopia=s;
                
                lista* entyelement=kopia.wskaznikNAenty(liczba);
                

                lista* copy = entyelement;
                
   
                
                s.pusch(copy);
                
            }
            else if (instruction == '&') {

                
                s.wypisz(s.top);
            }
            else if (instruction =='.')
            {
                char znak;
                std::cin >>znak;
                s.szczyt()->push_front(znak);
                s.szczyt()->rozmiar++;
                

            }
            else if (instruction =='>')
            {
                char znak=s.szczyt()->head->data;
                std::cout << znak;
                s.deletepick();

            }
            else if (instruction =='-')
            {
                
                if (s.szczyt()->head==nullptr)
                {
                    s.szczyt()->push_front(instruction);
                }
                
                else if(s.szczyt()->tail->data=='-')
                {
                    s.szczyt()->pop_back();
                }
                else
                {
                    
                    s.szczyt()->push_back(instruction);
                }

            }
            else if (instruction=='^')
            {
                if (s.szczyt()==nullptr || s.top==nullptr ||s.szczyt()->head==nullptr)
                {
                    
                }
                else if(s.szczyt()->tail->data=='-')
                {
                    s.szczyt()->pop_back();
                }
            }
            else if(instruction==']')
            {
                int liczba=0;
                s.szczyt()->zamiennainta(liczba);
                s.deletepick();
                char znak=liczba;
      
                lista* nowa = new lista;
                nowa->push_front(znak);
                s.pusch(nowa);
                if (s.szczyt()->head->data >='0' && s.szczyt()->head->data <='9')
                {
            
                    s.szczyt()->rozmiar++;
                }
                
                
                
                
            }
            else if(instruction=='[')
            {  
                int KodAsciPierwszyZnak = s.szczyt()->head->data;
                s.deletepick();

  
                    lista* nowa = new lista;
                    dodajInta(nowa,KodAsciPierwszyZnak);
                    s.pusch(nowa);
                    
                
                
                
            }
            else if(instruction=='$')
            {
                
                char znak = s.szczyt()->head->data;
                if(s.szczyt()->head->data>='0' && s.szczyt()->head->data<='9')
                {
                    s.szczyt()->rozmiar--;
                }
                
                s.szczyt()->pop_fornt();
                
                lista* nowa=new lista;
                nowa->push_front(znak);
                s.pusch(nowa);
                
                

                    

            }
            else if(instruction=='#')
            {
                int n=1;
                dolaczliste(s.szczyt(),s.top->prev->data); 
                
                s.pop();
                


            }
            else if(instruction=='<')
            {

                usunWiodac(s.szczyt());
                usunWiodac(s.top->prev->data);
                

                int l=ktoraiweksza(s.szczyt(),s.top->prev->data);
                s.deletepick();
                s.deletepick();

            

                if (l==1)
                {
                    char znak='1';
                    lista* nowa=new lista;
                    nowa->push_back(znak);
                    s.pusch(nowa);
                    s.szczyt()->rozmiar++;
                }
                else
                {
                    char znak='0';
                    lista* nowa=new lista;
                    nowa->push_back(znak);
                    s.pusch(nowa);
                    s.szczyt()->rozmiar++;
                }
                
                
                
           
                
            }
            else if (instruction=='=')
            {

                
                  usunWiodac(s.szczyt());
                usunWiodac(s.top->prev->data);
                
                int l=ktoraiweksza(s.szczyt(),s.top->prev->data);
                s.deletepick();
                s.deletepick();
                if (l==-1)
                {
                    char znak='1';
                    lista* nowa=new lista;
                    nowa->push_back(znak);
                    s.pusch(nowa);
                    s.szczyt()->rozmiar++;
                }
                else
                {
                    char znak='0';
                    lista* nowa=new lista;
                    nowa->push_back(znak);
                    s.pusch(nowa);
                    s.szczyt()->rozmiar++;
                }
                
            }
            else if(instruction=='!')
            {
                if (s.szczyt()->head==nullptr || (s.szczyt()->head==s.szczyt()->tail && s.szczyt()->head->data=='0'))
                {
                    s.deletepick();
                    char znak='1';
                    lista* nowa=new lista;
                    nowa->push_back(znak);
                    s.pusch(nowa);
                    s.szczyt()->rozmiar++;
                }
                else
                {
                    s.deletepick();
                    char znak='0';
                    lista* nowa=new lista;
                    nowa->push_back(znak);
                    s.pusch(nowa);
                    s.szczyt()->rozmiar++;
                }
                
                
            }
            else if(instruction=='~')
            {
                if (i==0)
                {
                    char znak='0';
                    lista* nowa=new lista;
                    nowa->push_back('0');
                    s.pusch(nowa);
                    s.szczyt()->rozmiar++;
                }
                else
                {
                
                int liczba=i;
                
                lista* nowa= new lista;
                dodajInta(nowa,liczba);
                s.pusch(nowa);
                s.szczyt()->rozmiar++;
                }
                
            }
            else if(instruction=='?')
            {
                int liczba=0;
                usunWiodac(s.szczyt());
                s.szczyt()->zamiennainta(liczba);
                s.deletepick();
                usunWiodac(s.szczyt());
                if (s.szczyt()->head==nullptr || s.szczyt()->rozmiar==1 && s.szczyt()->head->data=='0')
                {
                    s.deletepick();
        
                }
                else
                {
                    s.deletepick();
                    i=--liczba;
                    
                }
                

            }
            else if(instruction=='+')
            {
    
                
                lista* A=s.szczyt();
                lista* B=s.top->prev->data;

                if((A->rozmiar==1 && A->head->data=='0') && (B->rozmiar==1 && B->head->data=='0'))
                {
                    s.deletepick();
                    s.deletepick();
                    lista* nowa=new lista;
                    nowa->push_back('0');
                    s.pusch(nowa);
                    s.szczyt()->rozmiar++;
                    continue;
                }
  
           
                
                
            

                if (!(A->rozmiar==1 && A->head->data=='0'))
                {
                    usunWiodac(s.szczyt());
                }
                if (!(B->rozmiar==1 && B->head->data=='0'))
                {
                    usunWiodac(s.top->prev->data);
                }
    
                

                lista* nowa= new lista;
                lista* nowa2= new lista;
        
                



                lista* AP= new lista(*A);
                lista* BP= new lista(*B);
                int L=ktoraiweksza(AP,BP);
  


                if (A->tail->data=='-'&& B->tail->data=='-')
                {
                   
                    
                    A->pop_back();
                    B->pop_back();
                    dodajdwiedodatnie(A,B,nowa);
                    s.deletepick();
                    s.deletepick();
                    nowa->push_back('-');
                    
                    s.pusch(nowa);
                }
                else if (A->tail->data=='-'&& B->tail->data!='-')
                {
                    AP->pop_back();
                    int L=ktoraiweksza(AP,BP);
                    A->pop_back();
                    
                    if (L==0)
                    {
                        
                        odejmijdwiedodatnie(B,A,nowa);
                        
                        s.deletepick();
                        s.deletepick();
                        usunWiodac(nowa);
                        s.pusch(nowa);
                    }
                    if (L==1)
                    {
                        
                        odejmijdwiedodatnie(A,B,nowa);
                        nowa->push_back('-');
                        s.deletepick();
                        s.deletepick();
                        usunWiodac(nowa);
                        s.pusch(nowa);

                    }
                    else  if (L==-1)
                    {  
                        
                        nowa->push_back('0');
                        
                        s.deletepick();  
                        s.deletepick();  
                        
                        s.pusch(nowa);
                        s.szczyt()->rozmiar++;  
                    }  
                    

                }
                else if (A->tail->data!='-'&& B->tail->data=='-')
                {

                    BP->pop_back();  
                    
                    int L = ktoraiweksza(BP, AP);  
                    B->pop_back(); 
                    
                    
                
                    if (L == 0)  
                    {  
                        
                        
                        odejmijdwiedodatnie(A, B, nowa);  
                        
                        s.deletepick();  
                        s.deletepick();  
                          
                        usunWiodac(nowa);
                        s.pusch(nowa);  
                    }  
                    else if (L == 1)  
                    {  
                        odejmijdwiedodatnie(B, A, nowa);  
                        nowa->push_back('-');  
                        s.deletepick();  
                        s.deletepick();
                        
                        usunWiodac(nowa);
                        s.pusch(nowa);  
                    }  
                    else  if (L==-1)

                    
                    {  
                        
                        nowa->push_back('0');
                        s.deletepick();  
                        s.deletepick();  
                        
                        s.pusch(nowa);  
                        s.szczyt()->rozmiar++;
                    }  
                    
                }
                else if (A->tail->data!='-'&& B->tail->data!='-')
                {
                    
             
                    
                    dodajdwiedodatnie(A,B,nowa);
                    s.deletepick();
                    s.deletepick();
                    usunWiodac(nowa);
                    s.pusch(nowa);
                    s.szczyt()->rozmiar++; 
                    
                }
 
                
                
                
                


            }
            
            
            
            
            
            
            
           else if(true)
           {
                if ((instruction >= '0'&& instruction <='9'))
                {
                    s.top->data->rozmiar++;
                }
                
                

                s.top->data->push_front(instruction);
           }
            liczba++;

        }
        
        
    }