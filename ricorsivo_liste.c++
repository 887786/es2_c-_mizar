#include <iostream>
class list{
    public:
    int informazione;
    list* next;
};
using namespace std;
typedef list* link_List;
int ric(link_List &l,int r){
    link_List scorri=l;
    if(!l||r==0){   /*se lista vuota oppure r==0*/
        return 0;
    }
    int max=scorri->informazione;
    while(scorri!=nullptr){
        if(max<scorri->informazione){
            max=scorri->informazione;
        }
        scorri=scorri->next;
    }

    if(l->informazione==max){
        link_List delete_me=l;
        l=l->next;
        delete delete_me;
    }else{
        link_List search=l;
        while(search->next->informazione!=max){
            search=search->next;
        }/*elemento precedente all'elemento da eliminare*/
        link_List delete_me  =search->next;
        search->next    =delete_me->next;
        delete delete_me;
    }
    return 1+ ric(l,r-1);
}
void stampaLista(link_List &testa_lista){
    link_List scorri=testa_lista;
    cout<<"contenuto lista\n\n";
    while (scorri!=nullptr)
    {
        cout<<scorri->informazione<<endl;
        scorri=scorri->next;
    }
    cout<<"\nend_list\n\n"<<endl;
}
void deleteList(link_List &lista){
    link_List delete_me;
    while (lista!=nullptr){
        delete_me=lista;
        lista=lista->next;
        delete delete_me;
    }
    
}
int main(){
    /*creazione lista manuale*/
    link_List lista=new list;
    lista->informazione=7;
    lista->next=new list;
    lista->next->informazione=20;
    lista->next->next=new list;
    lista->next->next->informazione=3;
    lista->next->next->next=nullptr;
    cout<<"lista originale\t";stampaLista(lista);






    int elementi_rimossi=ric(lista,4);
    cout<<"\nelementi effettivamente rimossi: "<<elementi_rimossi<<"\n"<<endl;







    cout<<"lista dopo le modifiche\t";stampaLista(lista);
    deleteList(lista);
}