#include <iostream>

class lista
{
    public:
    struct Noto
    {
        Noto* next;
        Noto* prev;
        char data;
        
        Noto(char d) : data(d), next(nullptr), prev(nullptr) {}
    };
    Noto* head;
    Noto* tail;
    int rozmiar=0;
    lista() : head(nullptr), tail(nullptr) {}
    lista(const lista& other) : head(nullptr), tail(nullptr) {

        kopiuj(other.head);
        this->rozmiar = other.rozmiar;
    }
    lista& operator=(const lista& other) {
        
        kopiuj(other.head);
        this->rozmiar = other.rozmiar;
    }
    int policzCyfry(Noto* node) {
        if (!node) return 0;
    
        if (node->data >= '0' && node->data <= '9')
            return 1 + policzCyfry(node->next);
        else
            return policzCyfry(node->next);
    }

    void zamiennainta(int& zmienna)
    {


        if (!tail) 
        {
            zmienna/=10;
            return; 
        }
        
    
        if (tail->data>='0' && tail->data<='9')
        {
        
        zmienna += tail->data - '0'; 
        }
        
        zmienna *= 10;
    
        
        pop_back();
    
        
        zamiennainta(zmienna);
    }
   
    void zamiennainta2(double& zmienna, bool isNegative = false)
    {
    if (!tail)
    {
        zmienna /= 10; 
        if (isNegative) 
            zmienna = -zmienna; 
        return;
    }
    
    if (tail->data == '-') 
    {
        isNegative = true;
        pop_back();
        zamiennainta2(zmienna, isNegative);
        return;
    }
    
    if (tail->data >= '0' && tail->data <= '9')
    {
        zmienna += tail->data - '0';
        zmienna *= 10;
    }
    
    pop_back();
    zamiennainta2(zmienna, isNegative);
}





    
    

    void push_back(char value)
    {
            Noto* newNoto = new Noto(value);
        if (!head)
        {
            head = tail = newNoto;
        }
        else {
            tail->next = newNoto;
            newNoto->prev = tail;
            tail = newNoto;
        }
        
    }

    void push_front(char value)
    {
        Noto* newNoto = new Noto(value);
        if (!head)
        {
            head = tail = newNoto;
            
        }
        else {
            newNoto->next = head;
            head->prev = newNoto;
            head = newNoto;

        }
        
    }
    void pop_back()
   {
        
    if (!tail) return; 
    
        if (head==tail)
        {
            
            head = tail = nullptr;
        }
        else{
            Noto* temp = tail;  
            tail = tail->prev;   
            tail->next = nullptr; 
            delete temp;   
        }
        
        
   }
   char pop_fornt()
    {
        
        if (!head) {
            
            std::cout <<"nie ma elementow w liscie";
        }

        Noto* temp = head;
        char value = temp->data;  

        if (head == tail) {
            
            head = tail = nullptr;
        } else {
            
            head = head->next;
            head->prev = nullptr;
        }

        
            delete temp;

            return value; 
         
   }
    
    void kopiuj(Noto* node) {
        if (!node) return;
        
        
        kopiuj(node->next);
        
        
        this->push_front(node->data);
    } 
    


    void wypiszliste(Noto* node) {
        if (!node) 
        {
            return;
        }
        std::cout << node->data;
        wypiszliste(node->next);
    }
    void wypiszdoplikulista(Noto* node, std::ostream& out) {
        if (!node) {
            return;
        }
        out << node->data;  
        wypiszdoplikulista(node->next, out);
    }
    
    char returndata(lista* lista)
    {
        
    }
    void polacz(lista* innaLista) {
        if (!innaLista->head) return;  
        
        if (!this->head) {
            this->head = innaLista->head;
            this->tail = innaLista->tail;
        } else {
            this->tail->next = innaLista->head;
            this->tail = innaLista->tail;
        }

        
        innaLista->head = innaLista->tail = nullptr;
    }

 


    
};