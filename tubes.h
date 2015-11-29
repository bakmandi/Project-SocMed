#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <algorithm>

#define nil NULL
#define first(g) ((g).first)
#define last(g) ((g).last)
#define info(p) (p)->info
#define infoc(p) (p)->infoc
#define next(p) (p)->next
#define prev(p) (p)->prev
#define child(p) (p)->child
using namespace std;
typedef struct elemengrup *adrgrup;
typedef struct elemenchild *adrstatus;
struct grup
{
    int id;
    string nama_grup;
    string tanggaldibuat;
    string admin;

} ;

struct status
{
    int id;
    string tanggal;
    string status;
};

struct child
{
    adrstatus next;
    status info;
};


struct elemengrup
{
    adrgrup next,prev;
    grup info;
    adrstatus child;
};

struct elemenchild
{
    status infoc;
    adrstatus next;
};


struct list
{
    adrgrup first, last;
};

//Ricky
void deletefirst (list &, adrgrup &);
void creategroup(list &);
adrgrup alokasigrup(grup );
adrgrup find_idgrup (list , int );
void add_grup (list &, adrgrup );
void insertafter_g(list &, adrgrup ,adrgrup );
void insertlast_g(list &, adrgrup );
void sort_grupid (list &);
void sort_grupnama (list &);

//Ranny
void dealokasigrup (adrgrup );
void view_grup (list  );
adrgrup del_grupid (list &, int );
adrgrup del_grupnama (list &, string );
adrgrup find_namagrup (list , string );
adrgrup del_grup_danstatus (list &, adrgrup &);

//Fadhil
adrstatus findStatus_Status(adrgrup &, string );
void add_status_grup(adrgrup &, adrstatus );
void add_status_grup_last(adrgrup &, adrstatus );
void add_status_grup_after(adrgrup &,adrstatus ,int );
void view_status_grup(adrgrup );
adrstatus del_status_grup(adrgrup &, string );

//Christ
adrstatus alokasistatus(status );
adrstatus find_status (adrgrup , int );
void sort_tgl_post(adrgrup &);
void sort_status_id(adrgrup &);
int jumlah_status_dalam_grup(adrgrup &);
void edit_status_grup(adrgrup ,int );
