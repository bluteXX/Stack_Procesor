#include <iostream>
#include "lista.cpp"



class stack
{
    public:
    struct Noto
    {
       
        Noto* prev;
        lista* data;
        
        Noto(lista* d) : data(d),  prev(nullptr) {}
    };
    stack() : top(nullptr) {}
    Noto* top;
    int rozmiar=0;

    stack(const stack& other) : top(nullptr), rozmiar(0) {
        kopiuj(other.top);
    }

   void pusch(lista* value)
   {
        Noto* newNoto = new Noto(value);
        if(!top)
        {
            top = newNoto;
        }
        else
        {
            newNoto->prev = top;
            top = newNoto;
        }
    rozmiar++;
   }

   void deletepick()
   {
        if(top)
        {
            Noto* temp = top;
            top = top->prev;
            delete temp->data;
            delete temp;
        }
        rozmiar--;
   }
   lista* wskaznikNAenty(int& n)
{
    
    if (top == nullptr || n == 0) {
        return top ? top->data : nullptr; 
    }

    
    top = top->prev;
    n--;
    return wskaznikNAenty(n);  
}
   void kopiuj(Noto* node) {
    if (!node) return;

    kopiuj(node->prev);  

    this->pusch(new lista(*(node->data)));  
    }
  

   lista* pop()
   {
        if (top)
        {
            Noto* temp = top;
            top = top->prev;
            lista* data = temp->data;
            delete temp;
            return data;
        }
        rozmiar--;
        return nullptr;
   }
   lista* szczyt()
   {
         if (top)
         {
              return top->data;
         }
         return nullptr;
   }

   void wypisz(Noto* pierwszy,int rozmiar=-1) {
    if (!pierwszy || !pierwszy->data) return;
    
    
    wypisz(pierwszy->prev,++rozmiar); 
    
    std::cout << rozmiar << ": ";
    
    pierwszy->data->wypiszliste(pierwszy->data->head); 
    std::cout << std::endl;
    
}
void wypiszdopliku(Noto* pierwszy, std::ostream& out, int rozmiar = -1) {
    if (!pierwszy || !pierwszy->data) return;

    wypiszdopliku(pierwszy->prev, out, ++rozmiar);

    out << rozmiar << ": ";
    pierwszy->data->wypiszdoplikulista(pierwszy->data->head,out);
    
    out << std::endl;
}



};
    


