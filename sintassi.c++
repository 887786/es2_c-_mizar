
int ric(List &l,int r){
    List pc=l;  /*pointer di scorrimento*/
    if(!l||r==0){ 
        return 0;
    }
    /*max non ricorsivo*/
    int max=pc->informazione;
    while(pc!=nullptr){
        if(max<pc->informazione){
            max=pc->informazione;
        }
        pc=pc->next;
    }
    /*invariato */
    if(l->informazione==max){
        List delete_me=l;
        l=l->next;
        delete delete_me;
    }else{
        pc=l; /*reset pointer di scorrimento alla testa della lista*/
        while(pc->next->informazione!=max){
            pc=pc->next;
        }
        List b=pc->next;
        pc->next=b->next;
        delete b;
    }
    return 1+ ric(l,r-1);
}
