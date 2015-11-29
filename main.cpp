#include "tubes.h"

//Ricky
int main()
{
    list g;
    grup x,x2,x3,x4,xnew;
    adrgrup p;
    adrgrup gr;
    string nm,tgl,admon;
    int idwow;

    creategroup(g);

    /*x2.admin="Ricky";
    x2.id=2;
    x2.nama_grup="falchion";
    x2.tanggaldibuat="10 mei 2008";
    p=alokasigrup(x2);
    add_grup(g,p);

    x.admin="Ranny";
    x.id=1;
    x.nama_grup="vanguard";
    x.tanggaldibuat="8 Januari 2009";
    p=alokasigrup(x);
    add_grup(g,p);

    x3.admin="Ricky";
    x3.id=4;
    x3.nama_grup="breakout";
    x3.tanggaldibuat="6 September 2009";
    p=alokasigrup(x3);
    add_grup(g,p);

    x4.admin="Ranny";
    x4.id=3;
    x4.nama_grup="bloodhound";
    x4.tanggaldibuat="19 Desember 2010";
    p=alokasigrup(x4);
    add_grup(g,p);*/

    int pil;
    while(pil!=99)
    {
        system("cls");
        cout<<"========================"<<endl;
        cout<<"1. Add Group"<<endl;
        cout<<"2. Sort Group (id)"<<endl;                   //List menu berdasarkan urutan pembagian pekerjaan
        cout<<"3. Sort Group (name)"<<endl;
        cout<<"4. Search Group (id)"<<endl;
        cout<<"5. Group List"<<endl;
        cout<<"6. Deactivate Group (id)"<<endl;
        cout<<"7. Deactivate Group (name)"<<endl;
        cout<<"8. Search Group (name)"<<endl;
        cout<<"9. Add Status Group (id group)"<<endl;
        cout<<"10. List Status Group (id group)"<<endl;
        cout<<"11. Search Status Group (id status)"<<endl;
        cout<<"12. Delete Status Group (status)"<<endl;
        cout<<"13. Sort Status Group (id)"<<endl;
        cout<<"14. Total Post (Group)"<<endl;
        cout<<"15. Edit Post (id)"<<endl;

        cout<<"99.exit"<<endl;
        cout<<"Pilihan : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            ulang:
            system("cls");
            cout<<"ID : ";
            if (!(cin>>x.id))
            {
                cout<<"blablabla";
                cin.clear();
                cin.ignore(10000,'\n');
                getch();
                goto ulang;
            }
            cout<<"Nama Group : ";
            cin>>x.nama_grup;
            cout<<"tanggal : ";
            cin>>x.tanggaldibuat;
            cout<<"admin : ";
            cin>>x.admin;
            gr=find_idgrup(g,x.id);
            if(gr!=NULL)
            {
                cout<<"Sudah ada Group dengan ID tersebut"<<endl;
                break;
            }
            else
            {
                adrgrup suk=alokasigrup(x);
                add_grup(g,suk);
                break;
            }
            break;
        case 2:
            system("cls");
            sort_grupid(g);
            view_grup(g);
            cout<<"sorted";
            getch();
            break;
        case 3:
            system("cls");
            sort_grupnama(g);
            view_grup(g);
            getch();
            break;
        case 4:
            cout<<"ID yang anda cari : ";
            cin>>idwow;
            p=find_idgrup(g,idwow);
            if (p != NULL){
            cout<<"id grup: "<<info(p).id<<endl;
            cout<<"nama grup: "<<info(p).nama_grup<<endl;
            cout<<"tanggal dibuat: "<<info(p).tanggaldibuat<<endl;
            cout<<"nama admin: "<<info(p).admin<<endl;
            cout<<endl;}
            else {
                cout << "Tidak Ditemukan" << endl;
            }
            getch();
            break;
        case 5:
            view_grup(g);
            getch();
            break;
        case 6:
            int id;
            cout<<"ID group yang akan di hapus : ";
            cin>>id;
            p = del_grupid(g,id);
            if (p  != NULL) cout << info(p).nama_grup << " Telah di hapus" << endl;
            getch();
            break;
        case 7:
            {
            cout<<"Nama group yang akan di hapus : ";
            cin>>nm;
            adrgrup d=del_grupnama(g,nm);
            dealokasigrup(d);
            getch();
            break;
            }
        case 8:
            cout<<"Nama group yang anda cari : ";
            cin>>nm;
            p=find_namagrup(g,nm);
            if (p != NULL){
            cout<<"id grup: "<<info(p).id<<endl;
            cout<<"nama grup: "<<info(p).nama_grup<<endl;
            cout<<"tanggal dibuat: "<<info(p).tanggaldibuat<<endl;
            cout<<"nama admin: "<<info(p).admin<<endl;
            cout<<endl;}
            else {
                cout << "Tidak Ditemukan" << endl;
            }
            getch();
            break;
        case 9:{
            cout<<"ID group yang akan di posting : ";
            cin>>id;
            adrgrup z=find_idgrup(g,id);
            status ss;
            cout<<"ID Status : ";
            cin>>ss.id;
            cout<<"tanggal : ";
            cin>>ss.tanggal;
            cout<<"Status : ";
            cin>>ss.status;
            adrstatus in = alokasistatus(ss);
            add_status_grup(z,in);
            getch();
            break;
            }
        case 10:
            cout<<"ID yang anda cari : ";
            cin>>idwow;
            p=find_idgrup(g,idwow);
            view_status_grup(p);
            getch();
            break;
        case 11:{
            cout<<"ID group yang anda cari : ";
            cin>>idwow;
            p=find_idgrup(g,idwow);
            cout<<"masukan ID status : ";
            cin>>idwow;
            adrstatus z=find_status(p,idwow);
            cout<<"ID : "<<(z->infoc).id;
            cout<<"Status : "<<(z->infoc).status;
            cout<<"Tanggal : "<<(z->infoc).tanggal;
            getch();
            break;
            }
        case 12:{
            string stats;
            cout<<"ID group yang anda cari : ";
            cin>>idwow;
            p=find_idgrup(g,idwow);
            cout<<"masukan status yang akan dihapus : ";
            cin>>stats;
            del_status_grup(p,stats);
            getch();
            break;
            }
        case 13:{
            cout<<"ID group : ";
            cin>>idwow;
            adrgrup p=find_idgrup(g,idwow);
            sort_status_id(p);
            cout<<"sorted"<<endl;
            getch();
            break;
            }
        case 14:{
            cout<<"ID group : ";
            cin>>idwow;
            adrgrup p=find_idgrup(g,idwow);
            int jum=jumlah_status_dalam_grup(p);
            cout<<"jumlah postingan : "<<jum;
            getch();
            break;
            }
        case 15:{
            cout<<"ID group : ";
            cin>>idwow;
            adrgrup p=find_idgrup(g,idwow);
            edit_status_grup(p,idwow);
            getch();
            break;
            }
        case 99:
            break;
        default:
            cout<<"tidak ada menu tersebut..."<<endl;
            break;
        }
    }
    getch();
    return 0;
}
